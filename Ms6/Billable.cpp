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


#include "Billable.h"
#include "Utils.h"
using namespace std;

namespace seneca {
    Billable::Billable(const Billable& source) {
        *this = source;
    }

    Billable& Billable::operator=(const Billable& source) {
        if (this != &source) {
            ut.alocpy(m_instructions, source.m_instructions);
            m_price = source.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_instructions;
    }

    void Billable::setInstructions(const char* instructions) {
        ut.alocpy(m_instructions, instructions);
    }

    const char* Billable::getInstructions() const {
        return m_instructions;
    }

    double Billable::getPrice() const {
        return m_price;
    }

    void Billable::setPrice(double price) {
        m_price = price;
    }
}
