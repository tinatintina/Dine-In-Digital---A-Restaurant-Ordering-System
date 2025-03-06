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
#include "Drink.h"
#include "Utils.h"
#include "Menu.h"
using namespace std;

namespace seneca {
    Drink::Drink(const Drink& source) {
        *this = source;
    }

    Drink& Drink::operator=(const Drink& source) {
        if (this != &source) {
            Billable::operator=(source);
            ut.alocpy(m_name, source.m_name);
            m_size = source.m_size;
            m_basePrice = source.m_basePrice;
        }
        return *this;
    }

    Drink::~Drink() {
        delete[] m_name;
    }

    bool Drink::read(std::istream& is) {
        char name[1024];
        if (is.getline(name, 1024, ',')) {
            ut.alocpy(m_name, name);
            double price;
            is >> price;
            m_basePrice = price;
            setPrice(price);
            is.ignore(1000, '\n');
            return true;
        }
        return false;
    }

    const char* Drink::getName() const {
        return m_name;
    }

    bool Drink::order() {
        Menu sizeMenu("Drink Size Selection", 3);
        sizeMenu.add("Small");
        sizeMenu.add("Medium");
        sizeMenu.add("Larg");
        sizeMenu.add("Extra Large");

        int selection = sizeMenu.run();
        if (selection > 0) {
            char sizes[] = "SMLX";
            m_size = sizes[selection - 1];
            double factors[] = { 0.5, 0.75, 1.0, 1.25 };
            setPrice(m_basePrice * factors[selection - 1]);
            return true;
        }
        return false;
    }

    void Drink::print(std::ostream& os) const {
        if (m_name) {
            os.fill('.');
            os.width(28);
            os << left << m_name;

            os.width(5);
            os << left << (m_size == 'S' ? "SML.." :
                          m_size == 'M' ? "MID.." :
                          m_size == 'L' ? "LRG.." :
                          m_size == 'X' ? "XLG.." : "");
            
            os.fill(' ');
            os.width(7);
            os.precision(2);
            os << fixed << right << getPrice();
        }
    }
}
