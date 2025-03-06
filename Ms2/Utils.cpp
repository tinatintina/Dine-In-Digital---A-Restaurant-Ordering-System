/*/////////////////////////////////////////////////////////////////////////
                          OOP244 - MS2, Utils.cpp
Name       : Tina Srivastava
Student ID#: 103297230
Email      : tsrivastava5@myseneca.ca
Section    : ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <limits>
#include "Utils.h"

using namespace std;

namespace seneca {
    int getInt() {
        int value;
        bool valid = false;

        while (!valid) {
            if (cin.peek() == '\n') {
                cin.ignore();
                cout << "You must enter a value: ";
                continue;
            }

            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid integer: ";
                continue;
            }

            if (cin.get() != '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Only an integer please: ";
                continue;
            }

            valid = true;
        }

        return value;
    }

    int getInt(int min, int max) {
        int value;
        bool valid = false;

        while (!valid) {
            value = getInt();

            if (value < min || value > max) {
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
                continue;
            }

            valid = true;
        }

        return value;
    }
}
