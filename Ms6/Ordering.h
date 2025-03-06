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


#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include <iostream>
namespace seneca {
    class Ordering {
        Food* m_foods{ nullptr };
        Drink* m_drinks{ nullptr };
        Billable* m_bill[MaximumNumberOfBillItems]{};
        size_t m_noOfFoods{ 0 };
        size_t m_noOfDrinks{ 0 };
        size_t m_noOfBills{ 0 };
        size_t m_billNumber{ 1 };

        size_t countRecords(const char* file) const;
        void printBillTitle(std::ostream& os) const;
        void printTotals(std::ostream& os, double total) const;
    public:
        Ordering(const char* drinksFile, const char* foodsFile);
        Ordering(const Ordering& source) = delete;
        Ordering& operator=(const Ordering& source) = delete;
        ~Ordering();

        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;

        void listFoods() const;
        void listDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream& os) const;
        void resetBill();
    };
}
#endif
