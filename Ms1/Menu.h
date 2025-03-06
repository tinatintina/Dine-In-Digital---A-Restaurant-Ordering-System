#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include<iostream>

namespace seneca {
   class MenuItem {
	   char* m_content = nullptr;
	   size_t m_indent = 0;
	   size_t m_indentSize = 0;
	   int m_rowNumber = 0;
	   void setEmpty();
	   bool isValid()const;
   public:
	   MenuItem();
	   MenuItem(const char* content, int indent, int indentSize, int rowNumber);
	   ~MenuItem();
	   MenuItem(const MenuItem&) = delete;
	   MenuItem& operator=(MenuItem&) = delete;
	   std::ostream& display() const;
	   std::ostream& display(std::ostream& ostr) const;
	   operator bool() const;
   };

}
#endif // !SENECA_MENU_H


