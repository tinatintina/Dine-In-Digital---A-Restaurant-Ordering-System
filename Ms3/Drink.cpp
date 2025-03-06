// Drink.cpp
#include <iomanip>
#include <string>
#include "Drink.h"
namespace seneca {
    std::ostream& Drink::print(std::ostream& ostr) const {
        if (const char* n = *this) {
            ostr.fill('.');
            ostr.width(28);
            ostr.setf(ios::left);
            ostr << n;
            ostr.unsetf(ios::left);
            
            if (ordered()) {
                if (m_size == 'S') ostr << "SML..";
                else if (m_size == 'M') ostr << "MID..";
                else if (m_size == 'L') ostr << "LRG..";
                else if (m_size == 'X') ostr << "XLR..";
            }
            else ostr << ".....";
            
            ostr << "   ";
            ostr.width(4);
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << price();
        }
        return ostr;
    }
    // .......................Pepsi.....
    
    bool Drink::order() {
        bool ordered = false;
        cout << "         Drink Size Selection\n";
        cout << "          1- Small\n";
        cout << "          2- Medium\n";
        cout << "          3- Larg\n";
        cout << "          4- Extra Large\n";
        cout << "          0- Back\n";
        cout << "         > ";
        
        int choice;
        cin >> choice;
        cin.ignore(1000, '\n');
        
        switch (choice) {
            case 1: m_size = 'S'; ordered = true; break;
            case 2: m_size = 'M'; ordered = true; break;
            case 3: m_size = 'L'; ordered = true; break;
            case 4: m_size = 'X'; ordered = true; break;
            case 0: m_size = 0; break;
        }
        
        return ordered;
    }
    
    bool Drink::ordered() const {
        return m_size != 0;
    }
    
std::ifstream& Drink::read(std::ifstream& file) {
    if (file) {
        char nameStr[256]{};
        file.getline(nameStr, 256, ',');
        double priceVal{};
        file >> priceVal;
        file.ignore(1000, '\n');
        
        if (file) {
            // Fix: Use protected member functions from Billable directly
            Billable::name(nameStr);     // Call base class protected function
            Billable::price(priceVal);   // Call base class protected function
            m_size = 0;
        }
    }
    return file;
}
    
    double Drink::price() const {
        double basePrice = Billable::price();
        if (!ordered()) return basePrice;
        
        switch (m_size) {
            case 'S': return basePrice * 0.5;
            case 'M': return basePrice * 0.75;
            case 'X': return basePrice * 1.5;
            default: return basePrice;
        }
    }
}