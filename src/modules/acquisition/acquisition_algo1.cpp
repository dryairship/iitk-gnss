#include <iostream>

#include <gnss-utils.h>

using namespace std;

bool start_acquisition(int satellite_id) {
    sleep_milliseconds(get_random_number(0, 1000));
    cout << "Started acquisition algorithm 1 for satellite " << satellite_id << endl;

    while(true) {
        sleep_milliseconds(1000);
        /* do some work here */
        int num = get_random_number(0, 10);
        if(num < 4) {
            cout << "Acquisition complete for satellite " << satellite_id << endl;
            return true;
        } else if(num < 6) {
            cout << "Acquisition failed for satellite " << satellite_id << endl;
            return false;
        } else {
            cout << "Still trying to acquire satellite " << satellite_id << endl;
        }
    }
}
