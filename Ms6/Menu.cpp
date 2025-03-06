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
#include "Menu.h"
#include "Utils.h"
#include <cstring>
using namespace std;

namespace seneca {
    Menu::Menu(const char* title, int indent) : m_indent(indent) {
        ut.alocpy(m_title, title);
    }

    Menu::~Menu() {
        delete[] m_title;
        for (int i = 0; i < m_count; i++) {
            delete[] m_items[i];
        }
    }

    void Menu::add(const char* item) {
        if (m_count < MAX_MENU_ITEMS) {
            ut.alocpy(m_items[m_count], item);
            m_count++;
        }
    }

    Menu& Menu::operator<<(const char* item) {
        add(item);
        return *this;
    }

    int Menu::run() const {
        if (m_title && m_indent > 0) {
            cout << string(m_indent * 3, ' ') << m_title << endl;
        }

        for (int i = 0; i < m_count; i++) {
            cout << string((m_indent * 3) + 1, ' ') << (i + 1) << "- " << m_items[i] << endl;
        }

        if (m_indent == 0 && m_count == 1 && strcmp(m_items[0], "Yes") == 0) {
            cout << string((m_indent * 3) + 1, ' ') << "0- No" << endl;
        }
        else if (m_indent == 0) {
            cout << string((m_indent * 3) + 1, ' ') << "0- End Program" << endl;
        }
        else if (strcmp(m_title, "Food Size Selection") == 0 || strcmp(m_title, "Drink Size Selection") == 0) {
            cout << string((m_indent * 3) + 1, ' ') << "0- Back" << endl;
        }
        else if (m_indent == 1) {
            cout << string((m_indent * 3) + 1, ' ') << "0- Back to main menu" << endl;
        }
        else {
            cout << string((m_indent * 3) + 1, ' ') << "0- Back to Order" << endl;
        }
        
        cout << string(m_indent * 3, ' ') << "> ";

        return ut.getInt(0, m_count);
    }
}
