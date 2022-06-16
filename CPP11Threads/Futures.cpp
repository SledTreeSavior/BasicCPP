#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

using namespace std;

int square(int x) {
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "x == " << x << ", this_thread::get_id() == " << this_thread::get_id() << endl;
    return x * x;
}

int main() {
    vector<future<int>> v;
    for (int i = 1; i <= 20; i++) {
        v.push_back(async(launch::async, &square, i));
//        v.push_back(async(launch::deferred, &square, i));
//        v.push_back(async(launch::async|launch::deferred, &square, i));
    }
    
    int sum = 0;
    for (int i = 0; i < 20; i++) {
        sum += v[i].get();
    }

    cout << "The threads returned the sum == " << sum << ". this_thread::get_id() == " << this_thread::get_id() << endl;

    return 0;
}
