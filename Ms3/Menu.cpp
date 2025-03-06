#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
#include "constants.h"

using namespace std;

namespace seneca {
    // MenuItem implementation
    MenuItem::MenuItem(const char* content, unsigned indent, unsigned indentSize, unsigned row) {
        m_content = nullptr;
        m_indent = indent;
        m_indentSize = indentSize;
        m_row = row;
        
        if (content) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (m_content) {
            // Add indentation
            for (unsigned i = 0; i < m_indent * m_indentSize; i++) {
                os << " ";
            }
            
            // Handle row number display
            if (m_row) {
                if (m_row >= 10) {
                    os << m_row << "- ";
                }
                else {
                    os << " " << m_row << "- ";  // Extra space for single digits
                }
            }
            
            os << m_content << endl;
        }
        return os;
    }

    // Menu implementation
    Menu::Menu(const char* title, const char* exit, unsigned indent, unsigned indentSize)
        : m_title(title, indent, indentSize, 0)
        , m_exitOption(exit ? exit : "Exit", indent, indentSize, 0)
        , m_selectionPrompt("> ", indent, indentSize, 0) {
        m_indentNum = indent;
        m_indentSize = indentSize;
        m_numItems = 0;
        for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++) {
            m_menuItems[i] = nullptr;
        }
    }

    Menu::~Menu() {
        for (unsigned i = 0; i < m_numItems; i++) {
            delete m_menuItems[i];
            m_menuItems[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* content) {
        if (m_numItems < MaximumNumberOfMenuItems && content) {
            m_menuItems[m_numItems] = new MenuItem(content, m_indentNum, m_indentSize, m_numItems + 1);
            m_numItems++;
        }
        return *this;
    }

    size_t Menu::select() const {
        // Display title
        if (m_title.m_content) {
            m_title.display(cout);
        }
        
        // Display menu items
        for (unsigned i = 0; i < m_numItems; i++) {
            m_menuItems[i]->display(cout);
        }
        
        // Display exit option
        for (unsigned i = 0; i < m_indentNum * m_indentSize; i++) {
            cout << " ";
        }
        cout << " 0- " << m_exitOption.m_content << endl;
        
        // Display selection prompt
        for (unsigned i = 0; i < m_indentNum * m_indentSize; i++) {
            cout << " ";
        }
        cout << "> ";
        
        return static_cast<size_t>(ut.getInt(0, m_numItems));
    }

    size_t operator<<(std::ostream& os, const Menu& menu) {
        if (&os == &std::cout) {
            return menu.select();
        }
        return 0;
    }
}