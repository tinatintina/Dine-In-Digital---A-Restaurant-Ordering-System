/*/////////////////////////////////////////////////////////////////////////
                        Milestone 5
Full Name  : Tina Srivastava
Student ID#: 103297230
Email      : tsrivastava5@myseneca.ca
Section    : ZRA
File       : Ordering.h
Date       : 05-12-2024

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;

int main() {
    cout << "Testing Invalid Ordering if bad data is in data file!" << endl;
    Ordering badord("drinks.csv", "badfoods.csv");
    if (badord) {
        cout << "The ordering should have been invalid" << endl;
    }
    else {
        cout << "Passed!" << endl;
    }

    cout << "Testing fool proofint..............................." << endl;
    Ordering ord("drinks.csv", "foods.csv");
    if (ord) {
        ord.orderDrink();
    }
    return 0;
}
