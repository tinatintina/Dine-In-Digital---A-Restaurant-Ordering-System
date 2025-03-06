/* Citation and Sources...
Final Project Milestone 5
Module  : Utills.cpp
Filename: Utills.cpp
Author	: Tina Srivastava
Revision History
-----------------------------------------------------------
Date: 12.05.2024
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include <cstring>
using namespace std;

namespace seneca {
    Utils ut;  // Global ut definition

    size_t Utils::strlen(const char* str) const {
        return str ? ::strlen(str) : 0;
    }

    char* Utils::strcpy(char* des, const char* src) const {
        return src ? ::strcpy(des, src) : nullptr;
    }

    char* Utils::alocpy(const char* src) const {
        char* des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char* Utils::alocpy(char*& des, const char* src) const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    int Utils::getInt(int min, int max) const {
        int value;
        bool valid = false;
        string input;

        while (!valid) {
            getline(cin, input);
            
            if (input.empty()) {
                cout << "You must enter a value: ";
                continue;
            }

            try {
                size_t endPos = 0;
                value = stoi(input, &endPos);
                
                if (endPos < input.length()) {
                    cout << "Only an integer please: ";
                    continue;
                }
                
                if (value < min || value > max) {
                    cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
                }
                else {
                    valid = true;
                }
            }
            catch (...) {
                cout << "Invalid integer: ";
            }
        }

        return value;
    }

    void Utils::makeBillFileName(char* fileName, size_t billNumber) const {
        sprintf(fileName, "Bill%06d.txt", (int)billNumber);
    }

    bool Utils::isspace(const char* str) const {
        bool result = true;
        if (str) {
            int i = 0;
            while (str[i] && result) {
                result = result && ::isspace(str[i]);
                i++;
            }
        }
        return result;
    }
}
