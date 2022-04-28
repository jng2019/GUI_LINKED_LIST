#ifndef RATIONAL_H
#define RATIONAL_H

/***************************************************
* AUTHOR   : Jonathan Ng & Darren Liang & Isaac Marinero
* LAB #4   : Rational
* CLASS    : CS003A
* SECTION  : 31195
* DUE DATE : Jan 25, 2022
****************************************************/
#include <iostream>

class Rational
{
   private:
      int numer;              //IN/OUT - number's numerator
      int denom;              //IN/OUT - number's denominator
   public:

      /***************
      ** CONSTRUCTORS **
      ***************/
      Rational();             //constructor
      Rational(int);          //constructor
      Rational(int, int);     //constructor
      /***************
      ** ACCESSORS **
      ***************/
      const Rational add(const Rational &rhs) const;
      const Rational subtract(const Rational &rhs) const;
      const Rational multiply(const Rational &rhs) const;
      const Rational divide(const Rational &rhs) const;

      std::string getNum() const;
      bool operator==(Rational &right) const;
      bool operator!=(Rational &right) const;
      bool operator<(Rational &right) const;

      void display() const;
};

/****************************************************************
* Rational Class
*   This class represents a fraction object. It manages 2 attributes,
*   the numerator and denominator
***************************************************************/
/******************************
** CONSTRUCTORs **
******************************/
/****************************************************************
* Rational();
*   Constructor; Initialize class attributes
    numer to 0 and denom to 1
*   Parameters: none
*   Return: none
***************************************************************/
/****************************************************************
* Rational(int numerator);
*   Constructor; Initializes numerator to parameter
    value and initializes denominator to 1
*   Parameters: int numerator
*   Return: none
***************************************************************/
/****************************************************************
* Rational(int numerator, int denominator);
*   Constructor; Initializes numerator to parameter
*   value and initializes  denominator to parameter value
*   Parameters: int numerator & int denominator
*   Return: none
***************************************************************/
/***************
** ACCESSORS **
***************/
/****************************************************************
* const Rational add(const Rational &rhs) const;
*
*   Accessor; This method will return the sum of the two fractions
* --------------------------------------------------------------
*   Parameters: const Rational object
* --------------------------------------------------------------
*   Return: a new fraction (Rational)
***************************************************************/
/****************************************************************
* const Rational subtract(const Rational &rhs) const;
*
*   Accessor; This method will return the difference of the two fractions
* --------------------------------------------------------------
*   Parameters: const Rational object
* --------------------------------------------------------------
*   Return: a new fraction (Rational)
***************************************************************/
/****************************************************************
* const Rational multiply(const Rational &rhs) const;
*
*   Accessor; This method will return the product of the two fractions
* --------------------------------------------------------------
*   Parameters: const Rational object
* --------------------------------------------------------------
*   Return: a new fraction (Rational)
***************************************************************/
/****************************************************************
* const Rational divide(const Rational &rhs) const;
*
*   Accessor; This method will return the quotient of the two fractions
* --------------------------------------------------------------
*   Parameters: const Rational object
* --------------------------------------------------------------
*   Return: a new fraction (Rational)
***************************************************************/

#endif // RATIONAL_H
