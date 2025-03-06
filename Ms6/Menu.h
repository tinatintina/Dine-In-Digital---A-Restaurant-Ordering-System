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

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
    const int MAX_MENU_ITEMS = 20;
    class Menu {
        char* m_title{ nullptr };
        char* m_items[MAX_MENU_ITEMS]{};
        int m_count{ 0 };
        int m_indent{ 0 };
    public:
        Menu(const char* title = nullptr, int indent = 0);
        Menu(const Menu& source) = delete;
        Menu& operator=(const Menu& source) = delete;
        ~Menu();

        void add(const char* item);
        Menu& operator<<(const char* item);
        int run() const;
    };
}
#endif
