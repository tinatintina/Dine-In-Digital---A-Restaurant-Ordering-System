/* Citation and Sources...
Final Project Milestone 5
Module  : Utils.h
Filename: Utils.h
Author	: tina Srivastava
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
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <iostream>

namespace seneca {
    class Utils {
    public:
        size_t strlen(const char* str) const;
        char* strcpy(char* des, const char* src) const;
        char* alocpy(const char* src) const;
        char* alocpy(char*& des, const char* src) const;
        int getInt(int min, int max) const;
        void makeBillFileName(char* fileName, size_t billNumber) const;
        bool isspace(const char* str) const;
    };
    extern Utils ut;  // Global ut declaration
}
#endif
