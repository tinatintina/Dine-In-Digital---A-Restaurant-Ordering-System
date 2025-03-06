
#include <iostream>
#include "Menu.h"
#include "constants.h"
#include "Utils.h"

using namespace std;
namespace seneca {

	void MenuItem::setEmpty()
	{
		if (!(m_content == nullptr)) {
			ut.strcpy(m_content, "");
		}
		m_indent = 0u;
		m_indentSize = 0u;
		m_rowNumber = 0;
	}

	bool MenuItem::isValid() const
	{
		return !(m_content == nullptr || isspace(*m_content) || m_indent > 4 || m_indentSize > 4);
	}

	MenuItem::MenuItem()
	{
		m_content = nullptr;
		setEmpty();
	}

	MenuItem::MenuItem(const char* content, int indent, int indentSize, int rowNumber)
	{
		if (rowNumber < 0) {
			if (!(content == nullptr || indent > 4 || indentSize > 4))
			{
				m_content = new char[ut.strlen(content) + 1];
				ut.alocpy(m_content, content);
				m_indent = indent;
				m_indentSize = indentSize;
				m_rowNumber = rowNumber;
			}
		}
		else if (!(content == nullptr || indent > 4 || indentSize > 4))
		{
			m_content = new char[ut.strlen(content) + 1];
			ut.alocpy(m_content, content);
			m_indent = indent;
			m_indentSize = indentSize;
			m_rowNumber = rowNumber;
		}
		else if (rowNumber < 0)
		{
			;
		}
		else
		{
			setEmpty();
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
	}

	ostream& MenuItem::display() const
	{
		return display(cout);
	}

	ostream& MenuItem::display(ostream& ostr) const
	{
		if (m_content != nullptr) {
			int indent = m_indent;
			int indentSize = m_indentSize;
			if (m_rowNumber >= 0 && m_rowNumber < 10)
			{
				for (int i = 0; i < indent * indentSize + 1; i++)
				{
					ostr << " ";
				}
				ostr << m_rowNumber << "- ";
			}
			else if (m_rowNumber >= 0 && m_rowNumber >= 10) {
				for (int i = 0; i < indent * indentSize; i++)
				{
					ostr << " ";
				}
				ostr << m_rowNumber << "- ";
			}
			const char* content = m_content;
			while (isspace(*content)) {
				content++;
			}
			ostr << content;
		}
		else {
			ostr << "??????????";
		}

		return ostr;
	}

	MenuItem::operator bool() const
	{
		return isValid();
	}
}

