/***********************************************************************
 * Program:
 *    Unit 2, Safe String
 *    Brother Wilson, CS470
 * Author:
 *    Daniel Blankenship
 * Summary:
 *    This program attempts to emulate the Secure String Class in C++.
 ************************************************************************/
#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cassert>
using namespace std;

class String
{
private:

   // variables
   int size;
   int capacity;
   char* data;

   // functions
   void grow();

public:
   String();
   String(char* c);
   ~String();
   void getline(istream & in);
   void clear();
   int length() const;
   int max() const;

   // operators
   char & operator [] (unsigned int i) const;
   String & operator += (const String & str);
	String & operator += (const char* s);
   String & operator += (char c);
   String & operator =  (const String & str);
   String & operator =  (const char* s);
   String & operator =  (char c);

   friend istream& operator >> (istream & input, String& s);
   friend ostream& operator << (ostream & output, const String& s);
   friend bool operator >  (const String & lhs, const String & rhs);
   friend bool operator >= (const String & lhs, const String & rhs);
   friend bool operator <  (const String & lhs, const String & rhs);
   friend bool operator <= (const String & lhs, const String & rhs);
   friend bool operator == (const String & lhs, const String & rhs);
   friend bool operator != (const String & lhs, const String & rhs);
   friend String operator + (const String & lhs, const String & rhs);
   friend String operator + (const String & lhs, const char*   rhs);
   friend String operator + (const char*    lhs, const string& rhs);
   friend String operator + (const String & lhs, char          rhs);
   friend String operator + (char           lhs, const string& rhs);
};

#endif
