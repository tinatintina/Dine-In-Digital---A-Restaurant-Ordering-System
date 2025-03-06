/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.5
// Date 2024-11-13
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <iostream>

namespace seneca {
   class Utils {
   public:

      int getint(int defaultValue)const;
      int getInt(int min, int max)const;
      int getInt()const;

      char* alocpy(const char* src)const;
      char* alocpy(char*& des, const char* src)const;
      char* strcpy(char* des, const char* src)const;
      char* strcpy(char* des, const char* src, int len)const;
      char* strncpy(char* des, const char* src, int len)const;

      int strlen(const char* str)const;
      bool isspace(char ch)const;
      bool isspace(const char* cstring)const;

      char* read(char*& toRet, std::istream& istr, char delimiter = '\n')const;

      std::ostream& print(std::ostream& ostr, const char* cstring, size_t maxlen)const;
   };
   extern Utils ut;
   extern bool debug;
}

#endif // !SENECA_UTILS_H
