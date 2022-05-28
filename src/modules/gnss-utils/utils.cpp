#include <chrono>
#include <thread>
#include <random>

using namespace std;

static random_device rd;
static mt19937 rng{rd()}; 

int get_random_number(int min, int max) {
    if (max <= min) return min;
    return min + (rng()%(max-min));
}

void sleep_milliseconds(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}
