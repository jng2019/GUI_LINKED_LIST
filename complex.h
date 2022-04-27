/***************************************************
* AUTHOR   : Jonathan Ng & Teddy Barker
* LAB #8   : Complex Class
* CLASS    : CS003A
* SECTION  : 31195
* DUE DATE : Feb 8, 2022
****************************************************/
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex
{
  public:
    /***************
    ** CONSTRUCTORS **
    ***************/
    Complex();      //CONSTRUCTOR
    Complex(double real_part);      //CONSTRUCTOR
    Complex(double real_part, double imaginary_part);       //CONSTRUCTOR

    /***************
    ** ACCESSORS **
    ***************/
    friend bool operator==(const Complex &com1, const Complex &com2);
    const Complex operator+(const Complex&) const;
    const Complex operator-(const Complex&) const;
    const Complex operator*(const Complex&) const;
    friend ostream & operator << (ostream &cout, const Complex &c);
    friend istream & operator >> (istream &cin,  Complex &c);
  private:
    double real;           //IN/OUT - real_part of copmplex number
    double imaginary;           //IN/OUT - imaginary part of complex number
};

const Complex i(0,1); //Constant object "i" to represent 0 + 1i

#endif //COMPLEX_H


/****************************************************************
* Complex Class
*   This class represents a complex number. It manages 2 attributes,
*   the real and imaginary part of the complex number
***************************************************************/
/******************************
** CONSTRUCTORS **
******************************/
/****************************************************************
* Complex();
*   Constructor; Initialize class attributes
    real_part to 0 and imaginary_part to 0
*   Parameters: none
*   Return: none
***************************************************************/
/****************************************************************
* Complex(double a);
*   Constructor; Initializes real number to parameter value
*   and sets imaginary value to zero
*   Parameters: double a
*   Return: none
***************************************************************/
/****************************************************************
* Distance(double a, double b);
*   Constructor; Initializes real and imaginary numbers to parameter
*   values
*   Parameters: double a, double b
*   Return: none
***************************************************************/
/***************
** ACCESSORS **
***************/
/****************************************************************
* friend bool operator==(const Complex &com1, const Complex &com2);
*
*   Accessor; This method will compare two complext numbers and
*   return if they are equal
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: bool
***************************************************************/
/****************************************************************
*   const Complex operator+(const Complex&) const;
*
*   Accessor; This method will return the sum of the two distances
*   as a new Complex object
* --------------------------------------------------------------
*   Parameters: const Complex
* --------------------------------------------------------------
*   Return:  sum of two complex numbers (Complex)
***************************************************************/
/****************************************************************
* const Complex operator-(const Complex &) const;
*
*   Accessor; This method will return the difference of the two complex
*   numbers as a new Complext object
* --------------------------------------------------------------
*   Parameters: const Complex object
* --------------------------------------------------------------
*   Return: a new Complex object
***************************************************************/
/****************************************************************
*   const Complex operator*(const Complex&) const;
*
*   Accessor; This method will return the product of two complex numbers
* --------------------------------------------------------------
*   Parameters: const Complex
* --------------------------------------------------------------
*   Return: a new Complext object
***************************************************************/
/****************************************************************
*   friend ostream operator<<(ostream &cout, const Complex &c) const;
*
*   Accessor; This method will print a complext number to the console
* --------------------------------------------------------------
*   Parameters: ostream cout, const Complex
* --------------------------------------------------------------
*   Return: ostream
***************************************************************/
/****************************************************************
*   friend istream operator>>(istream &cin, Complex &c) const;
*
*   Accessor; This method will take in a complext number as input
*   from the console
* --------------------------------------------------------------
*   Parameters: istream cin, Complex
* --------------------------------------------------------------
*   Return: istream
***************************************************************/

