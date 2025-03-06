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

#include "Food.h"
#include "Utils.h"
#include "Menu.h"
using namespace std;

namespace seneca {
    Food::Food(const Food& source) {
        *this = source;
    }

    Food& Food::operator=(const Food& source) {
        if (this != &source) {
            Billable::operator=(source);
            ut.alocpy(m_name, source.m_name);
            m_type = source.m_type;
            m_basePrice = source.m_basePrice;
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_name;
    }

    bool Food::read(std::istream& is) {
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

    const char* Food::getName() const {
        return m_name;
    }

    bool Food::order() {
        Menu sizeMenu("Food Size Selection", 3);
        sizeMenu.add("Adult");
        sizeMenu.add("Child");

        int selection = sizeMenu.run();
        if (selection > 0) {
            m_type = (selection == 1) ? 'A' : 'C';
            setPrice(m_basePrice * (selection == 1 ? 1.0 : 0.5));

            cout << "Special instructions" << endl << "> ";
            char instructions[1024];
            cin.getline(instructions, 1024);
            if (!ut.isspace(instructions)) {
                setInstructions(instructions);
            }
            return true;
        }
        return false;
    }

    void Food::print(std::ostream& os) const {
        if (m_name) {
            os.fill('.');
            os.width(28);
            os << left << m_name;

            os.fill(' ');
            os.width(6);
            os << left << (m_type == 'A' ? "Adult" : "Child");
            
            os.fill(' ');
            os.width(6);
            os.precision(2);
            os << fixed << right << getPrice();

            if (getInstructions() && !ut.isspace(getInstructions())) {
                os << " >> " << getInstructions();
            }
        }
    }
}
