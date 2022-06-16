//this is the model command for this program
	//sort < Names.txt | uniq | wc -l
	
//header includes
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

//define statements
#define READ_END 0
#define WRITE_END 1

//main
int main(int argc, char *argv[]){
	//init vars
	pid_t pid;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//create first pipe fd1
	int fd1[2];
	if(pipe(fd1)==-1){
		fprintf(stderr,"Pipe failed...");
		return 1;
	}

	//fork first child
	pid=fork();
	if(pid<0){
		fprintf(stderr,"Fork failed...");
		return 1;
	}
	else if(pid>0){
		//print
		printf("PROCESS 1 ('sort'): %d\n", pid);
	}
	else if(pid==0){
		//first child process, run sort
		//
        	//tie write end of the pipe fd1 to stdout (file descriptor 1)
		dup2(fd1[1],1);
        	//close read end of fd1
		close(fd1[0]);
        	//start the sort cmd using execlp
		execlp("/usr/bin/sort","sort",NULL);
        	//should not get here
		printf("Should not get here after execlp to sort...\n");
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//create second pipe fd2
	int fd2[2];
	if(pipe(fd2)==-1){
		fprintf(stderr,"Pipe failed...");
		return 1;
	}

	//fork second child
	pid=fork();
	if(pid<0){
		fprintf(stderr,"Fork failed...");
		return 1;
	}
	else if(pid>0){
		//print
		printf("PROCESS 2 ('uniq'): %d\n", pid);
	}
	if(pid==0){
		//second child process, run uniq
		//
		//tie read end of fd1 to standard input (file descriptor 0)
		dup2(fd1[0],0);
		//tie write end of fd2 to standard output (file descriptor 1)
		dup2(fd2[1],1);
		//close write end of pipe fd1
		close(fd1[1]);
		//close read end of pipe fd2
		close(fd2[0]);
		//start the uniq command using execlp
		execlp("/usr/bin/uniq","uniq",NULL);
		//should not get here
		printf("Should not get here after execlp to uniq...\n");
	}

	//fork third child
	pid=fork();
	if(pid<0){
                fprintf(stderr,"Fork failed...");
                return 1;
        }
	else if(pid>0){
		//print
        	printf("PROCESS 3 ('wc -l'): %d\n", pid);
	}
	if(pid==0){
		//third child process, run wc -l
		//
		//tie read end of fd2 to standard input (file descriptor 0)
		dup2(fd2[0],0);
		//close write end of pipe fd2
		close(fd2[1]);
		//close read end of pipe fd1
		close(fd1[0]);
		//close write end of pipe fd1
		close(fd1[1]);
	        //start the wc -l command using execlp
		execlp("/usr/bin/wc","wc","-l",NULL);
	        //should not get here
		printf("Should not get here after execlp to wc -l...\n");
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//parent process code
		//close both ends of pipes fd1 and fd2
			//close both ends of fd1
			close(fd1[0]);
			close(fd1[1]);
			//close both ends of fd2
			close(fd2[0]);
			close(fd2[1]);
		//wait for third processes to end
		waitpid(pid,NULL,0);
		printf("The last child process has finished executing with pid: %d\n", pid);
}
