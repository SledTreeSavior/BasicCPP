#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int square(int x) {
	return x * x;
}

int main() {
	auto a = async(&square, 10); // promise & future pair: async makes a promise; return type is future<int>
	int v = a.get(); // a.get() will wait until promise is fulfilled, and future value is ready

	cout << "The thread returned " << v << endl;
	return 0;
}