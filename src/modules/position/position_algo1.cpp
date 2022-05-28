#include <iostream>
#include <queue>
#include <thread>

#include <gnss-utils.h>

using namespace std;

bool calculate_position(vector<queue<float>> &satellite_data, atomic<int> *numThreadsTracking, int maxThreads) {
    while (true) {
        if (*numThreadsTracking == maxThreads) {
            float sum = 0;
            int cnt = 0;
            for(int i=0; i<*numThreadsTracking; i++) {
                if(!(satellite_data)[i].empty()) {
                    sum += (satellite_data)[i].front();
                    (satellite_data)[i].pop();
                    cnt ++;
                }
            }
            float avg = sum/cnt;
            cout << "\033[1;32m [POSITION] Calculated Average " << avg << "\033[0m" << endl;
        }
        sleep_milliseconds(250);
    }
}
