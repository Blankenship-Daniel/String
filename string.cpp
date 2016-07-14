#include "string.h"

/*******************************************************************************
 * GROW
 * Double the size of capacity, and reallocate the data array with additional
 * space.
 ******************************************************************************/
void String::grow()
{
   String temp;
   temp.size = size;
   temp.capacity = capacity;
   temp.data = new char[capacity];

   for(int i = 0; i <= size; i++)
      temp.data[i] = data[i];

   this->capacity *=2;
   delete [] this->data;
   this->data = new char[capacity];

   for(int i = 0; i <= size; i++)
      this->data[i] = temp.data[i];
}

/*******************************************************************************
 * CONSTRUCTOR
 * Sets the initial values of data, size, and capacity.
 ******************************************************************************/
String::String()
{
   this->capacity = 1000;
   this->data = new char[this->capacity];
   this->size = 0;
}

/*******************************************************************************
 * CONSTRUCTOR
 * Sets the initial values of data, size, and capacity.
 ******************************************************************************/
String::String(char* c)
{
   this->size = 0;
   this->capacity = 1000;
   this->data = new char[this->capacity];

   int i = 0;

   while (c[i] != '\0')
   {
      this->data[i] = c[i];
      this->size++;
      i++;

      if (this->size + 1 >= this->capacity)
         this->grow();
   }
}

/*******************************************************************************
 * DESTRUCTOR
 * Frees the memory allocated for the data char array.
 ******************************************************************************/
String::~String()
{
   delete [] this->data;
}

/*******************************************************************************
 * CLEAR
 * Reset the size and capacity variables.
 ******************************************************************************/
void String::clear()
{
   this->size = 0;
   this->capacity = 1000;
}

/*******************************************************************************
 * GET LINE
 ******************************************************************************/
void String::getline(istream & in)
{
   int i = 0;
   this->size = 0;

   while (in.peek() != '\n')
   {
      this->data[i] = in.get();
      this->size++;
      i++;

      if (this->size + 1 >= this->capacity)
         this->grow();
   }

   // consumes the \n character
   in.get();

   this->data[this->size] = '\0';
}

/*******************************************************************************
 * LENGTH
 * Returns the size of the string.
 ******************************************************************************/
int String::length() const
{
   return this->size;
}

/*******************************************************************************
 * MAX
 * Returns the capacity of the string.
 ******************************************************************************/
int String::max() const
{
   return this->capacity;
}

/*******************************************************************************
 * OPERATOR []
 ******************************************************************************/
char & String::operator [] (unsigned int i) const
{
   return this->data[i];
}

/*******************************************************************************
 * OPERATOR +=
 * Appends a String to another String.
 ******************************************************************************/
String & String::operator += (const String & str)
{
   for (int i = 0; i < str.length(); i++)
   {
      if (this->size + 1 >= capacity)
         this->grow();

      this->data[this->size] = str[i];
      this->size++;
   }

   this->data[this->size] = '\0';

   return *this;
}

/*******************************************************************************
 * OPERATOR +=
 * Appends a char* to another String.
 ******************************************************************************/
String & String::operator += (const char* s)
{
   assert(s != NULL);

   int charSize = 0;
   while (s[charSize] != '\0') charSize++;

   for (int i = 0; i < charSize; i++)
   {
      if (this->size + 1 >= capacity)
         this->grow();

      this->data[this->size] = s[i];
      this->size++;
   }

   this->data[this->size] = '\0';

   return *this;
}

/*******************************************************************************
 * OPERATOR +=
 * Appends a char to another String.
 ******************************************************************************/
String & String::operator += (char c)
{
   if (this->size + 2 >= capacity)
      this->grow();

   this->data[this->size] = c;
   this->size++;

   if (this->size + 1 >= capacity)
      this->grow();

   this->data[this->size] = '\0';

   return *this;
}

/*******************************************************************************
 * OPERATOR =
 * Assigns a String to *this String.
 ******************************************************************************/
String & String::operator = (const String & str)
{
   this->size = str.length();
   delete [] this->data;
   this->data = new char[str.max()];

   for (int i = 0; i < this->size; i++)
      this->data[i] = str[i];

   this->data[this->size] = '\0';

   return *this;
}

/*******************************************************************************
 * OPERATOR =
 * Assigns a char* to *this String.
 ******************************************************************************/
String & String::operator = (const char* s)
{
   assert (s != NULL);

   int charSize = 0;
   while (s[charSize] != '\0') charSize++;

   if (charSize >= this->capacity)
      this->grow();

   this->size = charSize;
   delete [] this->data;
   this->data = new char[this->capacity];

   for (int i = 0; i < this->size; i++)
      this->data[i] = s[i];

   this->data[this->size] = '\0';

   return *this;
}

/*******************************************************************************
 * OPERATOR =
 * Assigns a char to *this String.
 ******************************************************************************/
String & String::operator = (char c)
{
   this->size = 1;
   delete [] this->data;
   this->data = new char[this->capacity];
   this->data[0] = c;
   this->data[this->size] = '\0';
   return *this;
}

/*******************************************************************************
 * OPERATOR >>
 ******************************************************************************/
istream& operator >> (istream & input, String & s)
{
   s.getline(input);
   return input;
}

/*******************************************************************************
 * OPERATOR <<
 ******************************************************************************/
ostream& operator << (ostream & output, const String & s)
{
   for (int i = 0; i < s.length(); i++)
      output << s[i];

   return output;
}

/*******************************************************************************
 * OPERATOR >
 * Compares the size of each string. Returns true if the lhs is greater than
 * the rhs.
 ******************************************************************************/
bool operator > (const String & lhs, const String & rhs)
{
   return (lhs.length() > rhs.length());
}

/*******************************************************************************
 * OPERATOR >=
 * Compares the size of each string. Returns true if the lhs is greater than
 * or equal to the rhs.
 ******************************************************************************/
bool operator >= (const String & lhs, const String & rhs)
{
   return (lhs.length() >= rhs.length());
}

/*******************************************************************************
 * OPERATOR <
 * Compares the size of each string. Returns true if the lhs is less than
 * the rhs.
 ******************************************************************************/
bool operator < (const String & lhs, const String & rhs)
{
   return (lhs.length() < rhs.length());
}

/*******************************************************************************
 * OPERATOR <=
 * Compares the size of each string. Returns true if the lhs is less than
 * or equal to the rhs.
 ******************************************************************************/
bool operator <= (const String & lhs, const String & rhs)
{
   return (lhs.length() <= rhs.length());
}

/*******************************************************************************
 * OPERATOR ==
 * Compares each string for equality. Equality in this case means they have the
 * same size and each char is the same value.
 ******************************************************************************/
bool operator == (const String & lhs, const String & rhs)
{
   if (lhs.length() != rhs.length())
      return false;

   for (int i = 0; i < lhs.length(); i++)
   {
      if (lhs[i] != rhs[i])
         return false;
   }

   return true;
}

/*******************************************************************************
 * OPERATOR !=
 * Compares each string for inequality. Inequality in this case means they
 * either don't have the same size or each char is not the same value.
 ******************************************************************************/
bool operator != (const String & lhs, const String & rhs)
{
   if (lhs.length() == rhs.length())
      return false;

   for (int i = 0; i < lhs.length(); i++)
   {
      if (lhs[i] != rhs[i])
         return true;
   }

   return false;
}

/*******************************************************************************
 * OPERATOR +
 * Concatenates two Strings together.
 ******************************************************************************/
String operator + (const String & lhs, const String & rhs)
{
   int newSize = lhs.length() + rhs.length();
   char* c = new char[newSize];

   int i = 0;
   for (; i < lhs.length(); i++)
      c[i] = lhs[i];

   for (int j = 0; j < rhs.length(); j++, i++)
      c[i] = rhs[j];

   c[newSize] = '\0';

   return String(c);
}

/*******************************************************************************
 * OPERATOR +
 * Concatenates a String and a char* together.
 ******************************************************************************/
String operator + (const String & lhs, const char* rhs)
{
   assert(rhs != NULL);

   int rhsSize = 0;
   while (rhs[rhsSize] != '\0') rhsSize++;
   int newSize = lhs.length() + rhsSize;
   char* c = new char[newSize];

   int i = 0;
   for (; i < lhs.length(); i++)
      c[i] = lhs[i];

   for (int j = 0; j < rhsSize; j++, i++)
      c[i] = rhs[j];

   c[newSize] = '\0';

   return String(c);
}

/*******************************************************************************
 * OPERATOR +
 * Concatenates a char* and a String together.
 ******************************************************************************/
String operator + (const char* lhs, const String & rhs)
{
   assert(lhs != NULL);

   int lhsSize = 0;
   while (lhs[lhsSize] != '\0') lhsSize++;
   int newSize = lhsSize + rhs.length();
   char* c = new char[newSize];

   int i = 0;
   for (; i < lhsSize; i++)
      c[i] = lhs[i];

   for (int j = 0; j < rhs.length(); j++, i++)
      c[i] = rhs[j];

   c[newSize] = '\0';

   return String(c);
}

/*******************************************************************************
 * OPERATOR +
 * Concatenates a char* and a String together.
 ******************************************************************************/
String operator + (const String & lhs, char rhs)
{
   int newSize = lhs.length() + 1;
   char* c = new char[newSize];

   int i = 0;
   for (; i < lhs.length(); i++)
      c[i] = lhs[i];

   c[lhs.length()] = rhs;
   c[newSize] = '\0';

   return String(c);
}

/*******************************************************************************
 * OPERATOR +
 * Concatenates a char* and a String together.
 ******************************************************************************/
String operator + (char lhs, const String & rhs)
{
   int newSize = rhs.length() + 1;
   char* c = new char[newSize];

   int i = 0;
   c[i] = lhs;
   i++;

   for (; i < newSize; i++)
      c[i] = rhs[i];

   c[newSize] = '\0';

   return String(c);
}
