#include <iostream>
#include <queue>

#include <gnss-utils.h>

using namespace std;

bool start_tracking(int satellite_id, queue<float> &satellite_data) {
    cout << "Tracking started (using algorithm 1) for satellite " << satellite_id << endl;

    int sf = 0;
    while(true) {
        sleep_milliseconds(1000);
        int num = get_random_number(0, 20);
        if(num == 0) {
            cout << "Loss of lock in satellite " << satellite_id << endl;
            return false;
        } else {
            cout << "Subframe " << ((sf++)%6) << " received from satellite " << satellite_id << endl;
            satellite_data.push(get_random_number(0, 10));
            satellite_data.push(get_random_number(0, 10));
            satellite_data.push(get_random_number(0, 10));
            satellite_data.push(get_random_number(0, 10));
        }
    }
}
