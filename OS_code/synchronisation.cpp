#include <iostream>
#include <thread>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

mutex mtx[5];
bool flag[2];
int turn=-1;
int empty=n;
int full=0,mutex=1;

void producer(){
    wait(empty);
    wait(mutex);
    //producing  work has done;
    signal(mutex);
    signal(full);
}
void consumer(){
    wait(full);
    wait(mutex);
    //consuming wosrk has done
    signal(mutex);
    signal(empty);
    
}
void philosopher(int id) {
    int left = id;
    int right = (id + 1) % 5;

    while (true) {
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::milliseconds(1000)); // Thinking

        // Try to acquire left fork
        unique_lock<mutex> left_lock(mtx[left]);
        cout << "Philosopher " << id << " picked up left fork.\n";

        // Try to acquire right fork
        unique_lock<mutex> right_lock(mtx[right]);
        cout << "Philosopher " << id << " picked up right fork.\n";

        // Eating
        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::milliseconds(1000)); // Eating

        // Release forks
        cout << "Philosopher " << id << " put down right fork.\n";
        right_lock.unlock();
        cout << "Philosopher " << id << " put down left fork.\n";
        left_lock.unlock();
    }
}
void peterson(int j){
    do{
        turn=j;
        flag[j]=true;
        while(turn==j && flag[1-j]==true);
        //critical section
        flag[j]=false;
    }while(true);
}
void wait(semaphore s){
    while(s.value==0);
    s.value--;
}
void signal(semaphore s){
    s.value++;
}
int main() {
    memset(flag,false,sizeof(flag));

    return 0;
}
