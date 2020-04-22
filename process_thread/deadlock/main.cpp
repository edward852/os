#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx1;
mutex mtx2;

void job1()
{
    cout << "job1 started" << endl;

    mtx1.lock();
    this_thread::sleep_for(chrono::milliseconds(10));
    mtx2.lock();
}

void job2()
{
    cout << "job2 started" << endl;

    mtx2.lock();
    this_thread::sleep_for(chrono::milliseconds(10));
    mtx1.lock();
}

int main() {
    thread t1(job1);
    thread t2(job2);

    t1.join();
    t2.join();

    return 0;
}
