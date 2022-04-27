#ifndef DATE_H
#define DATE_H


/***************************************************
* AUTHOR   : Jonathan Ng
* Assignment #3   : Date
* CLASS    : CS003A
* SECTION  : 31195
* DUE DATE : Feb 3, 2022
****************************************************/
#include <iostream>
class Date
{
private:
    unsigned day;           //IN/OUT - number of days in month
    unsigned month;         //IN/OUT - month variable
    std::string monthName;  //IN/OUT - name of month
    unsigned year;          //IN/OUT - year

    /***************
    ** ACCESSORS **
    ***************/

    bool isLeap(unsigned y) const;
    unsigned daysPerMonth( unsigned m, unsigned y ) const;
    std::string name( unsigned m ) const;
    unsigned number( const std::string &mn ) const;
public:

    /***************
    ** CONSTRUCTORS **
    ***************/
    Date();
    Date( unsigned m, unsigned d, unsigned y );
    Date( const std::string &mn, unsigned d, unsigned y );

    /***************
    ** ACCESSORS **
    ***************/
    void printNumeric( )  const;
    void printAlpha( )  const;

    /***************
    ** MUTATORS **
    ***************/
    Date addDays(int d) const;
};
/****************************************************************
* Date Class
*   This class represents a Date object. It manages 4 attributes,
*   the month, day, year and name of the month
***************************************************************/
/******************************
** CONSTRUCTORS **
******************************/
/****************************************************************
* Date();
*   Constructor; Initialize class attributes
*   Date set to Jan 1, 2000
*   Parameters: none
*   Return: none
***************************************************************/
/****************************************************************
* Date(unsigned m, unsigned d, unsigned y);
*   Constructor; Checks for a valid month and day
*   Initializes month, day and years to parameter values
*   Parameters: unsigned m, unsigned d, unsigned y
*   Return: none
***************************************************************/
/****************************************************************
* Date(std::string &mn, unsigned d, unsigned y);
*   Constructor; Checks for a valid month name and day
*   Initializes month name, day, and years to parameter value
*   Parameters: string &mn, unsigned d, unsigned y
*   Return: none
***************************************************************/
/***************
** ACCESSORS **
***************/
/****************************************************************
* bool isLeap(unsigned y) const;
*
*   Accessor; This method will true if the year is a leap year
*   false if not
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: bool
***************************************************************/
/****************************************************************
* unsigned  daysPerMonth(unsigned m, unsigned y) const;
*
*   Accessor; This will determine if the year is a leap year
*   and return the number of days each month. If the year is
*   a leap year, and the month is february return 29 days
*   if not a leap year return 28 days
* --------------------------------------------------------------
*   Parameters: unsigned m, unsigned y
* --------------------------------------------------------------
*   Return:  unsigned
***************************************************************/
/****************************************************************
* std::string name( unsigned m ) const;
*
*   Accessor; This method will return the name of the month
* --------------------------------------------------------------
*   Parameters: unsigned month
* --------------------------------------------------------------
*   Return: string month name
***************************************************************/
/****************************************************************
* unsigned number( const std::string &mn ) const;
*
*   Accessor; This method will return numeric value of month
* --------------------------------------------------------------
*   Parameters: const std::string &mn
* --------------------------------------------------------------
*   Return: unsigned month
***************************************************************/
/****************************************************************
* void printNumeric( )  const;
*
*   Accessor; This method will print out the month day and years
*   to the console separated with slashes
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: none
***************************************************************/
/****************************************************************
* void printAlpha( )  const;
*
*   Accessor; This method will print out the month day and years
*   to the console with the month name day followed by comma and years
* --------------------------------------------------------------
*   Parameters: none
* --------------------------------------------------------------
*   Return: none
***************************************************************/
/***************
 ** MUTATORS **
***************/
/****************************************************************
* Date addDays (int d) const;
*
*   Mutator; This method will add number of days negative or positive
*   return the new Date object
* --------------------------------------------------------------
*   Parameters: int d
* --------------------------------------------------------------
*   Return: Date object
***************************************************************/

#endif // DATE_H
