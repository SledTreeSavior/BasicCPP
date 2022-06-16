// RaceCondition.cpp -- shows effect of random instruction interleaving

#include <iostream>
#include <vector>
#include <thread>
#include <random>

using namespace std;


int accum = 0;
bool no_race = true; // change this to false to demo race condition

// obtain a seed from the system clock, and initialize a uniform distribution
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_int_distribution<int> sleepDistribution(1, 100);


void square(int x) {

	auto sleep_time = sleepDistribution(generator);

	if (no_race) {
	       	// likely uninterrupted sequence of instructions
		accum += x * x;

 		cout << "x == " << x << ", accum == " << accum
		     <<	", thread_id == " << this_thread::get_id() << endl;
	} else {
	       	// simulate a "heavy" computation likely to be interrupted
		int local_accum = accum;
		this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
		accum = local_accum + (x * x);

		cout << "x == " << x <<  ", accum == " << accum
		     <<	", thread_id == " << this_thread::get_id()
		     << ", slept for " << sleep_time << " msec\n";
	}
}

int main() {
	vector<thread> ths;
	for (int i = 1; i <= 20; i++) {
		ths.push_back(thread(&square, i));
	}

	for (auto& th : ths) {
		th.join();
	}
	cout << "accum = " << accum << endl;
	return 0;
}
