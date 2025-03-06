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


#define _CRT_SECURE_NO_WARNINGS
#include "Ordering.h"
#include "Utils.h"
#include "Menu.h"
#include <fstream>
#include <iomanip>
using namespace std;

namespace seneca {
    size_t Ordering::countRecords(const char* file) const {
        size_t count = 0;
        ifstream fin(file);
        char ch;
        while (fin.get(ch)) {
            if (ch == '\n') count++;
        }
        return count;
    }

    void Ordering::printBillTitle(std::ostream& os) const {
        os << "Bill # " << setw(3) << setfill('0') << m_billNumber
            << " =============================" << endl;
    }

    void Ordering::printTotals(std::ostream& os, double total) const {
        os << setfill(' ') << right;
        os << "                     Total:" << setw(13) << fixed << setprecision(2) << total << endl;
        double tax = total * Tax;
        os << "                     Tax:" << setw(15) << tax << endl;
        os << "                     Total+Tax:" << setw(9) << (total + tax) << endl;
        os << "========================================" << endl;
    }

    Ordering::Ordering(const char* drinksFile, const char* foodsFile) {
        size_t drinkCount = countRecords(drinksFile);
        size_t foodCount = countRecords(foodsFile);

        ifstream drinkData(drinksFile);
        ifstream foodData(foodsFile);

        if (drinkData && foodData) {
            m_drinks = new Drink[drinkCount];
            m_foods = new Food[foodCount];

            size_t i;
            for (i = 0; i < drinkCount && m_drinks[i].read(drinkData); i++);
            if (i != drinkCount) {
                delete[] m_drinks;
                delete[] m_foods;
                m_drinks = nullptr;
                m_foods = nullptr;
            }
            else {
                m_noOfDrinks = drinkCount;
                for (i = 0; i < foodCount && m_foods[i].read(foodData); i++);
                if (i != foodCount) {
                    delete[] m_drinks;
                    delete[] m_foods;
                    m_drinks = nullptr;
                    m_foods = nullptr;
                }
                else {
                    m_noOfFoods = foodCount;
                }
            }
        }
    }

    Ordering::~Ordering() {
        delete[] m_foods;
        delete[] m_drinks;
        for (size_t i = 0; i < m_noOfBills; i++) {
            delete m_bill[i];
        }
    }

    Ordering::operator bool() const {
        return m_drinks != nullptr && m_foods != nullptr;
    }

    size_t Ordering::noOfBillItems() const {
        return m_noOfBills;
    }

    bool Ordering::hasUnsavedBill() const {
        return m_noOfBills > 0;
    }

    void Ordering::listFoods() const {
        for (size_t i = 0; i < m_noOfFoods; i++) {
            m_foods[i].print(cout);
            cout << endl;
        }
    }

    void Ordering::listDrinks() const {
        for (size_t i = 0; i < m_noOfDrinks; i++) {
            m_drinks[i].print(cout);
            cout << endl;
        }
    }

    void Ordering::orderFood() {
        if (m_noOfBills < MaximumNumberOfBillItems) {
            Menu foodMenu("Food Menu", 2);
            for (size_t i = 0; i < m_noOfFoods; i++) {
                foodMenu.add(m_foods[i].getName());
            }

            int selection = foodMenu.run();
            if (selection > 0) {
                Food* newFood = new Food(m_foods[selection - 1]);
                if (newFood->order()) {
                    m_bill[m_noOfBills++] = newFood;
                }
                else {
                    delete newFood;
                }
            }
        }
    }

    void Ordering::orderDrink() {
        if (m_noOfBills < MaximumNumberOfBillItems) {
            Menu drinkMenu("Drink Menu", 2);
            for (size_t i = 0; i < m_noOfDrinks; i++) {
                drinkMenu.add(m_drinks[i].getName());
            }

            int selection = drinkMenu.run();
            if (selection > 0) {
                Drink* newDrink = new Drink(m_drinks[selection - 1]);
                if (newDrink->order()) {
                    m_bill[m_noOfBills++] = newDrink;
                }
                else {
                    delete newDrink;
                }
            }
        }
    }

    void Ordering::printBill(std::ostream& os) const {
        if (m_noOfBills > 0) {
            double total = 0;
            printBillTitle(os);
            for (size_t i = 0; i < m_noOfBills; i++) {
                m_bill[i]->print(os);
                total += m_bill[i]->getPrice();
                os << endl;
            }
            printTotals(os, total);
        }
    }

    void Ordering::resetBill() {
        if (m_noOfBills > 0) {
            char filename[256];
            ut.makeBillFileName(filename, m_billNumber);
            ofstream file(filename);
            if (file) {
                printBill(file);
                cout << "Saved bill number " << m_billNumber << endl;
                cout << "Starting bill number " << m_billNumber + 1 << endl;

                for (size_t i = 0; i < m_noOfBills; i++) {
                    delete m_bill[i];
                    m_bill[i] = nullptr;
                }
                m_noOfBills = 0;
                m_billNumber++;
            }
        }
    }
}
