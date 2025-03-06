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


#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <iostream>
namespace seneca {
    class Billable {
        char* m_instructions{ nullptr };
    protected:
        double m_price{ 0 };
        void setPrice(double price);
    public:
        Billable() = default;
        Billable(const Billable& source);
        Billable& operator=(const Billable& source);
        virtual ~Billable();

        void setInstructions(const char* instructions);
        const char* getInstructions() const;
        double getPrice() const;

        virtual bool order() = 0;
        virtual void print(std::ostream& os) const = 0;
    };
}
#endif
