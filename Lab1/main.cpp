// Put your name here

#include <iostream>
#include <iomanip>
#include <string>

#include "functions.h"

using namespace std;

int main(){
    const int CAR_COUNT = 4;
    const double distance = convertDistance(getInput("Enter the distance between the wires (inches): "));
    double cars[CAR_COUNT];
    int i = 0;
    for (i = 0; i < CAR_COUNT; ++i) {
        cars[i] = getInput("Enter time recorded (seconds): ");
    }
    cout << left << setw(20) << "Vehicle" << setw(20) << "Time (seconds)" << setw(20) << "Speed (m/s)" << setw(20) << "Speed (mph)" << endl;
    for (i = 0; i < CAR_COUNT; ++i) {
    	cout << left << setw(20) << i + 1 << setw(20) << cars[i] << setw(20) << getSpeed(distance, cars[i]) << setw(20) << convertSpeed(getSpeed(distance, cars[i])) << endl;
    }

    return 0;
}
