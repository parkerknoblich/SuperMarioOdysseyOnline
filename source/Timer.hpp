#pragma once

#include <functional>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

class Timer {
    public:
        Timer() : running(false) {}

        void start(int interval, function<void()> func) {
            running = true;
            thread([this, interval, func]() {
                this_thread::sleep_for(chrono::milliseconds(interval));
                if (running.load()) {
                    func();
                }
            }).detach();
        }

        void stop() {
            running = false;
        }
        
    private:
        atomic<bool> running;
};