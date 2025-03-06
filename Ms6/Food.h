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

#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H
#include "Billable.h"
namespace seneca {
    class Food : public Billable {
        char* m_name{ nullptr };
        char m_type{ 'N' };  // N-None, A-Adult, C-Child
        double m_basePrice{ 0 };
    public:
        Food() = default;
        Food(const Food& source);
        Food& operator=(const Food& source);
        ~Food();

        bool read(std::istream& is);
        const char* getName() const;
        virtual bool order() override;
        virtual void print(std::ostream& os) const override;
    };
}
#endif
