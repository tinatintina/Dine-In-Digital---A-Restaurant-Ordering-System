// Food.cpp
#include <iomanip>
#include <string>
#include "Food.h"
#include "Utils.h"
namespace seneca {
    Food::Food(const Food& src) {
        *this = src;
    }
    
    Food& Food::operator=(const Food& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_ordered = src.m_ordered;
            m_child = src.m_child;
            ut.alocpy(m_customize, src.m_customize);
        }
        return *this;
    }
    
    Food::~Food() {
        delete[] m_customize;
    }
    
    // std::ostream& Food::print(std::ostream& ostr) const {
    //     if (const char* n = *this) {
    //         ostr.fill('.');
    //         ostr.width(28);
    //         ostr.setf(ios::left);
    //         ostr << n;
    //         ostr.unsetf(ios::left);
            
    //         if (ordered()) {
    //             if (m_child) ostr << "Child";
    //             else ostr << "Adult";
    //         }
    //         else ostr << ".....";
            
    //         ostr << "  ";
    //         ostr.setf(ios::fixed);
    //         ostr.precision(2);
    //         ostr << price();
            
    //         if (&ostr == &cout && m_customize && !ut.isspace(m_customize)) {
    //             ostr << " >> " << m_customize;
    //         }
    //     }
    //     return ostr;
    // }

    std::ostream& Food::print(std::ostream& ostr) const {
    if (const char* n = *this) {  // Check for valid food name
        ostr.fill('.');
        ostr.width(28);
        ostr.setf(std::ios::left);  // Align food name to the left
        ostr << n;
        ostr.unsetf(std::ios::left);  // Reset alignment
        
        if (ordered()) {
            if (m_child) {
                ostr << "Child";
            } else {
                ostr << "Adult";
            }
        } else {
            ostr << ".....";
        }

        double p = price();
        int intPart = static_cast<int>(p); 
        int spaceAdjustment = (intPart < 10) ? 3 : 2; 
        ostr << std::string(spaceAdjustment, ' '); 

        ostr.setf(std::ios::fixed);
        ostr.precision(2);
        ostr << p;

        // Print customization if present
        if (&ostr == &std::cout && m_customize && !ut.isspace(m_customize)) {
            ostr << " >> " << m_customize;
        }
    }
    return ostr;
}

    
    bool Food::order() {
        cout << "         Food Size Selection\n";
        cout << "          1- Adult\n";
        cout << "          2- Child\n";
        cout << "          0- Back\n";
        cout << "         > ";
        
        int choice;
        cin >> choice;
        cin.ignore(1000, '\n');
        
        if (choice == 1 || choice == 2) {
            m_ordered = true;
            m_child = (choice == 2);
            
            cout << "Special instructions\n> ";
            char* temp{};
            ut.read(temp, cin);
            
            if (ut.isspace(temp)) {
                delete[] temp;
                delete[] m_customize;
                m_customize = nullptr;
            }
            else {
                ut.alocpy(m_customize, temp);
                delete[] temp;
            }
        }
        else {
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        
        return m_ordered;
    }
    
    bool Food::ordered() const {
        return m_ordered;
    }
std::ifstream& Food::read(std::ifstream& file) {
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
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
    }
    return file;
}
    
    double Food::price() const {
        double basePrice = Billable::price();
        if (ordered() && m_child) return basePrice * 0.5;
        return basePrice;
    }
}