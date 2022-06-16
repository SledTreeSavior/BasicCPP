#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
const int UPPER = 250;
int sum; // shared variable
void increment() {
for (int i = 1; i <= UPPER; ++i){
++sum; }
}
int main() { sum = 0;
// create concurrent instances of function increment #pragma omp parallel
{
               increment();
          }
          printf("sum == %d\n", sum);
return 0; }
