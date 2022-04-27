#include "date.h"

/**********************************************************
*
* Method isLeap: Class Date
*_________________________________________________________
* This method returns true if the year is a leap year
*_________________________________________________________
* PRE-CONDITIONS
*   The following needs to be properly initialized with defined values:
*       Date object
*       unsigned y
*
* POST-CONDITIONS
*     This function will return true or false if leap year
***********************************************************/
bool Date::isLeap(unsigned y) const
{
    bool leap;
    if(y%4==0 && y%100==0 && y%400==0)
        leap = true;
    else
        leap = false;
    return leap;
}
/**********************************************************
*
* Method daysPerMonth: Class Date
*_________________________________________________________
* This method returns how many days are in a month
*_________________________________________________________
* PRE-CONDITIONS
*   The following needs to be properly initialized with defined values:
*       Date object
*       unsigned m
*       unsigned y
*
* POST-CONDITIONS
*     This function will return number of days in the month
***********************************************************/
unsigned Date::daysPerMonth( unsigned m, unsigned y ) const
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 , 30, 31};
    for (int i = 1; i < 13; ++i) {
        if (m == i)
        {
            return days[i];
        }
        if (m==2)
        {
            if (isLeap(y))
                return 29;
            else
                return days[2];
        }
    }
    return 0;
}
/**********************************************************
*
* Method name: Class Date
*_________________________________________________________
* This method returns the name of the month given a numerical value
*_________________________________________________________
* PRE-CONDITIONS
*   The following needs to be properly initialized with defined values:
*       Date object
*       unsigned m
*
* POST-CONDITIONS
*     This function will a string of the month name
***********************************************************/
std::string Date::name( unsigned m ) const
{
    switch (m) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }

    return "ERROR";
}
/**********************************************************
*
* Method number: Class Date
*_________________________________________________________
* This method returns the numerical value of the month given a name
*_________________________________________________________
* PRE-CONDITIONS
*   The following needs to be properly initialized with defined values:
*       Date object
*       std::string mn
*
* POST-CONDITIONS
*     This function will an unsigned number of month
***********************************************************/
unsigned Date::number( const std::string &mn ) const
{

    if (mn=="January")
        return 1;
    else if(mn=="February")
        return 2;
    else if (mn=="March")
        return 3;
    else if(mn=="April")
        return 4;
    else if (mn=="May")
        return 5;
    else if(mn=="June")
        return 6;
    else if (mn=="July")
        return 7;
    else if(mn=="August")
        return 8;
    else if (mn=="September")
        return 9;
    else if(mn=="Cctober")
        return 10;
    else if (mn=="November")
        return 11;
    else if(mn=="December")
        return 12;

    return 0;
}
Date::Date()
{
    day=1;
    month = 1;
    year = 2000;
    monthName = "January";
}
Date::Date( unsigned m, unsigned d, unsigned y )
{
    bool invalid;
    year=y;
    if (m >=1 && m<=12) // check months
    {
        month=m;
        monthName= name(m);
    }
    else if (m>12)
    {
        invalid = true;
        month=12;
        monthName="December";
    }
    else if (m<1)
    {
        invalid=true;
        month=1;
        m=1;
        monthName="January";
    }
    if (d> daysPerMonth(m,y))
    {
        invalid=true;
        while (d> daysPerMonth(m,y))
        {
            d--;
        }
        day=d;
    }
    else if (d <= 0)
    {
        day=1;
        invalid=true;
    }
    else
    {
        day=d;
    }
    if(invalid)
        std::cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << ".\n";
}
Date::Date( const std::string &mn, unsigned d, unsigned y ) {
    year=y;
    bool invalidM;
    bool invalid;
    if (mn == "january" || mn == "January")
    {
        month = 1;
        monthName=mn;
        if (d> daysPerMonth(1,y))
        {
            invalid=true;
            while (d> daysPerMonth(1,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }

    }
    else if(mn=="february" || mn == "February")
    {
        month = 2;
        monthName=mn;
        if (d> daysPerMonth(2,y))
        {
            invalid=true;
            while (d> daysPerMonth(2,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if (mn=="march" || mn == "March")
    {
        month = 3;
        monthName=mn;
        if (d> daysPerMonth(3,y))
        {
            invalid=true;
            while (d> daysPerMonth(3,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if(mn=="april" || mn == "April")
    {
        month = 4;
        monthName=mn;
        if (d> daysPerMonth(4,y))
        {
            invalid=true;
            while (d> daysPerMonth(4,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if (mn=="may" || mn == "May")
    {
        month = 5;
        monthName=mn;
        if (d> daysPerMonth(5,y))
        {
            invalid=true;
            while (d> daysPerMonth(5,y))
            {
                d--;
            }
        }
        day=d;
          if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if(mn=="june"|| mn == "June")
    {
        month = 6;
        monthName=mn;
        if (d> daysPerMonth(6,y))
        {
            invalid=true;
            while (d> daysPerMonth(6,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if (mn=="july"|| mn == "July")
    {
        month = 7;
        monthName=mn;
        if (d> daysPerMonth(7,y))
        {
            invalid=true;
            while (d> daysPerMonth(7,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if(mn=="august"|| mn == "August")
    {
        month = 8;
        monthName=mn;
        if (d> daysPerMonth(8,y))
        {
            invalid=true;
            while (d> daysPerMonth(8,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if (mn=="september"|| mn == "September")
    {
        month = 9;
        monthName=mn;
        if (d> daysPerMonth(9,y))
        {
            invalid=true;
            while (d> daysPerMonth(9,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if(mn=="october"|| mn == "October")
    {
        month = 10;
        monthName=mn;
        if (d> daysPerMonth(10,y))
        {
            invalid=true;
            while (d> daysPerMonth(10,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if (mn=="november"|| mn == "November")
    {
        month = 11;
        monthName=mn;
        if (d> daysPerMonth(11,y))
        {
            invalid=true;
            while (d> daysPerMonth(11,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else if(mn=="december"|| mn == "December")
    {
        month = 12;
        monthName=mn;
        if (d> daysPerMonth(12,y))
        {
            invalid=true;
            while (d> daysPerMonth(12,y))
            {
                d--;
            }
        }
        day=d;
         if (d <= 0)
        {
            day=1;
            invalid=true;
        }
    }
    else
    {
        invalidM=true;
        month = 1;
        day = 1;
        year = 2000;
        monthName = "January";
    }
    if(invalid)
        std::cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << ".\n";
    if(invalidM)
        std::cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << ".\n";
}
/**********************************************************
*
* Method printNumeric: Class Date
*_________________________________________________________
* This method prints out the numerical values of the date
*_________________________________________________________
* PRE-CONDITIONS
*   The following needs to be properly initialized with defined values:
*       Date object
*       unsigned month
*       unsigned day
*       unsigned year
*
* POST-CONDITIONS
*     This function will not change any variables
***********************************************************/
void Date::printNumeric( )  const
{
    std::cout << month << "/" << day << "/" << year;

}
/**********************************************************
*
* Method printAlpha: Class Date
*_________________________________________________________
* This method prints out the alpha values of the date
*_________________________________________________________
* PRE-CONDITIONS
*   The following needs to be properly initialized with defined values:
*       Date object
*       std::string mn
*       unsigned day
*       unsigned year
*
* POST-CONDITIONS
*     This function will not change any variables
***********************************************************/
void Date::printAlpha( )  const
{
    std::cout << monthName << " " << day << ", " << year;
}

Date Date::addDays(int d) const
{
    return Date();
}
