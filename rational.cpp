#include "rational.h"

Rational::Rational(int numerator, int denominator)
{
  numer = numerator;
  denom = denominator;
}

Rational::Rational(int numerator)
{
  numer = numerator;
  denom = 1;
}

Rational::Rational()
{
  numer = 0;
  denom = 1;
}
/**********************************************************
*
* Method add: Class Rational
*_________________________________________________________
* This method receives a fraction containing a numerator
*   and denominator for a rational object and adds the fraction
*   calling the method with the fraction passed in the
*   parameter ? returns a new Rational object.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* numer: rhs fraction's numerator
* denom: rhs fraction's denominator
*
* POST-CONDITIONS
*     This function will add the two fractions and
*      return the sum as a rational object.
*      The reference parameters are not modified because both
*      the parameter and the caller's variables are constant
***********************************************************/
const Rational Rational::add(const Rational &rhs) const
{
  Rational temp;
  temp.numer = numer * rhs.denom + denom * rhs.numer;
  temp.denom = denom * rhs.denom;
  return temp;
}
/**********************************************************
*
* Method subtract: Class Rational
*_________________________________________________________
* This method receives a fraction containing a numerator
*   and denominator for a rational object
*   and subtracts the fraction
*   calling the method with the fraction passed in the
*   parameter ? returns a new Rational object.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* numer: rhs fraction's numerator
* denom: rhs fraction's denominator
*
* POST-CONDITIONS
*     This function will subtracts the two fractions and
*      return the difference as a rational object.
*      The reference parameters are not modified because both
*      the parameter and the caller's variables are constant
***********************************************************/
const Rational Rational::subtract(const Rational &rhs) const
{
  Rational temp;
  temp.numer = numer * rhs.denom - denom * rhs.numer;
  temp.denom = denom * rhs.denom;
  return temp;
}

/**********************************************************
*
* Method multiply: Class Rational
*_________________________________________________________
* This method receives a fraction containing a numerator
*   and denominator for a rational object
*   and multplies the fraction
*   calling the method with the fraction passed in the
*   parameter ? returns a new Rational object.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* numer: rhs fraction's numerator
* denom: rhs fraction's denominator
*
* POST-CONDITIONS
*     This function will multiply the two fractions and
*      return the product as a rational object.
*      The reference parameters are not modified because both
*      the parameter and the caller's variables are constant
***********************************************************/
const Rational Rational::multiply(const Rational &rhs) const
{
  Rational temp;
  temp.numer = numer * rhs.numer;
  temp.denom = denom * rhs.denom;
  return temp;
}

/**********************************************************
*
* Method divide: Class Rational
*_________________________________________________________
* This method receives a fraction containing a numerator
*   and denominator for a rational object
*   and divides the fraction
*   calling the method with the fraction passed in the
*   parameter ? returns a new Rational object.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* numer: rhs fraction's numerator
* denom: rhs fraction's denominator
*
* POST-CONDITIONS
*     This function will divide the two fractions and
*      return the quotient as a rational object.
*      The reference parameters are not modified because both
*      the parameter and the caller's variables are constant
***********************************************************/
const Rational Rational::divide(const Rational &rhs) const
{
  Rational temp;
  temp.numer = numer * rhs.denom;
  temp.denom = denom * rhs.numer;
  return temp;
}

/**********************************************************
*
* Method display: Class Rational
*_________________________________________________________
* This method does not take in any
*   parameters. Displays the numerator
*   and the denominator separated with a /
*   returns nothing
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* numer:  fraction's numerator
* denom:  fraction's denominator
*
* POST-CONDITIONS
*     This function will display the fraction in the console
*      The member variables are not modified because
*      the variables are constant
***********************************************************/
void Rational::display() const
{
  std::cout << numer  << "/" << denom;
}


std::string Rational::getNum() const
{
    std::string ret;
    ret += std::to_string(numer);
    ret += "/";
    ret += std::to_string(denom);
    return ret;

}


bool Rational::operator==(Rational &right) const
{
    return (numer==right.numer && denom == right.denom);
}

bool Rational::operator!=(Rational &right) const
{
    return (numer!=right.numer && denom != right.denom);
}

bool Rational::operator<(Rational &right) const
{

    double left, ri;
    left = static_cast<double> (numer) / denom;
    ri = static_cast<double> (right.numer) / right.denom;

    return (left < ri);
}
