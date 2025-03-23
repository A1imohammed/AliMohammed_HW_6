#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstdlib>

using namespace std;

void blink_led(int n) {
    const string led_path = "/sys/class/leds/beaglebone:green:usr3/";
    for (int i = 0; i < n; ++i) {
      
        ofstream(led_path + "brightness") << "1";
        sleep(1); // Sleep for 1 second

        ofstream(led_path + "brightness") << "0";
        sleep(1); // Sleep for 1 second
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " blink <n>" << endl;
        return 1;
    }

    string action = argv[1];
    int n = atoi(argv[2]);

    if (action == "blink") {
        if (n <= 0) {
            cerr << "Error: Number of blinks (n) must be a positive integer." << endl;
            return 1;
        }
        blink_led(n);
    } else {
        cerr << "Error: Unknown action '" << action << "'." << endl;
        return 1;
    }

    return 0;
}
