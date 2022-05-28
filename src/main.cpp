#include <iitk-gnss-config.h>
#include <acquisition.h>
#include <tracking.h>
#include <position.h>
#include <gnss-utils.h>

#include <queue>
#include <vector>
#include <iostream>
#include <thread>

using namespace std;

const int NUM_MAX_THREADS = 4;

atomic<int> numActiveThreads = 0;
atomic<int> numThreadsTracking = 0;

vector<queue<float>> satellite_data(NUM_MAX_THREADS);

void process_satellite(int thread_id, int satellite_id) {
    bool acquired = start_acquisition(satellite_id);
    if(acquired) {
        numThreadsTracking += 1;
        start_tracking(satellite_id, satellite_data[thread_id]);
        numThreadsTracking -= 1;
    }
    numActiveThreads -= 1;
}

int main() {
    cout << "IITK GNSS version " << IITK_GNSS_VERSION_MAJOR << "." << IITK_GNSS_VERSION_MINOR << endl;
    thread pos(calculate_position, ref(satellite_data), &numThreadsTracking, NUM_MAX_THREADS);
    pos.detach();
    while(true) {
        if(numActiveThreads < NUM_MAX_THREADS) {
            int threadId = numActiveThreads;
            numActiveThreads += 1;
            thread t(process_satellite, threadId, get_random_number(1, 33));
            t.detach();
        }
    }
}
