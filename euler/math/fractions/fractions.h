#ifndef FRACTION_H
#define FRACTION_H

#include <iosfwd>

namespace euler::math {

typedef int Type; // Change this to size_t if we have > 32-bit numbers.

class Fraction
{
    Type d_num;                                 // Numerator.
    Type d_den;                                 // Denominator.

    public:                                     // Constructor.
        explicit Fraction(Type numerator, Type denominator = 1);
        Fraction(Fraction const &other);        // Copy constructor.
        Fraction(Fraction &&tmp);               // Move constructor.

        Type &num();                            // Return/edit the numerator.
        Type &denom();                          // Return/edit the denominator.
        Fraction reduce() const;                // Reduce fraction.
        double approx() const;                  // Return the decimal value.
        
        Fraction &operator=(Fraction const &other); // Copy-assignment operator.
        Fraction &operator=(Fraction &&other);      // Move-assignment operator.

        friend std::ostream &operator<<(std::ostream &out, Fraction &obj);
        friend std::ostream &operator<<(std::ostream &out, Fraction &&obj);

        Fraction &operator+=(Fraction const &rhs);      // Add Fraction.
        Fraction &operator-=(Fraction const &rhs);      // Subtract Fraction.
        Fraction &operator*=(Fraction const &rhs);      // Multiply Fraction.
        Fraction &operator/=(Fraction const &rhs);      // Divide Fraction.

        Fraction &operator+=(Type scalar);              // Add scalar.
        Fraction &operator-=(Type scalar);              // Subtract scalar.
        Fraction &operator*=(Type scalar);              // Multiply scalar.
        Fraction &operator/=(Type scalar);              // Divide scalar.

        bool operator==(Fraction const &other) const;   // Compare w. Fraction.
        bool operator!=(Fraction const &other) const;   // Compare w. Fraction.
        bool operator<(Fraction const &other) const;    // Compare w. Fraction.
        bool operator>(Fraction const &other) const;    // Compare w. Fraction.
};

// Constructor.
inline Fraction::Fraction(Type numerator, Type denominator)
:
    d_num(numerator),
    d_den(denominator)
{}

// Copy constructor.
inline Fraction::Fraction(Fraction const &other)
:
    d_num(other.d_num),
    d_den(other.d_den)
{}

// Move constructor.
inline Fraction::Fraction(Fraction &&tmp)
:
    d_num(tmp.d_num),
    d_den(tmp.d_den)
{}

// Return/edit the numerator.
inline Type &Fraction::num()
{
    return d_num;
}

// Return/edit the denominator.
inline Type &Fraction::denom()
{
    return d_den;
}

// Return the decimal value.
inline double Fraction::approx() const
{
    return static_cast<double>(d_num) / d_den;
}

// Copy-assignment operator.
inline Fraction &Fraction::operator=(Fraction const &other)
{
    return *this = Fraction{other};
}

// Add Fraction.
inline Fraction &Fraction::operator+=(Fraction const &rhs)
{
    d_num  = d_num * rhs.d_den + d_den * rhs.d_num;
    d_den *= rhs.d_den;
    return *this;
}

// Subtract Fraction.
inline Fraction &Fraction::operator-=(Fraction const &rhs)
{
    d_num  = d_num * rhs.d_den - d_den * rhs.d_num;
    d_den *= rhs.d_den;
    return *this;
}

// Multiply Fraction.
inline Fraction &Fraction::operator*=(Fraction const &rhs)
{
    d_num *= rhs.d_num; d_den *= rhs.d_den;
    return *this;
}

// Divide Fraction.
inline Fraction &Fraction::operator/=(Fraction const &rhs)
{
    d_num *= rhs.d_den; d_den *= rhs.d_num;
    return *this;
}

// Add scalar.
inline Fraction &Fraction::operator+=(Type scalar)
{
    d_num += scalar * d_den;
    return *this;
}

// Subtract scalar.
inline Fraction &Fraction::operator-=(Type scalar)
{
    d_num -= scalar * d_den;
    return *this;
}

// Multiply Scalar.
inline Fraction &Fraction::operator*=(Type scalar)
{
    d_num *= scalar;
    return *this;
}

// Divide scalar.
inline Fraction &Fraction::operator/=(Type scalar)
{
    d_num /= scalar;
    return *this;
}

// Compare w. Fraction.
inline bool Fraction::operator==(Fraction const &other) const
{
    return (d_num * other.d_den == other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator!=(Fraction const &other) const
{
    return (d_num * other.d_den != other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator>(Fraction const &other) const
{
    return (d_num * other.d_den > other.d_num * d_den);
}

// Compare w. Fraction.
inline bool Fraction::operator<(Fraction const &other) const
{
    return (d_num * other.d_den < other.d_num * d_den);
}

// Add Fraction.
inline Fraction operator+(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} += rhs;
}

// Subtract Fraction.
inline Fraction operator-(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} -= rhs;
}

// Multiply Fraction.
inline Fraction operator*(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} *= rhs;
}

// Divide Fraction.
inline Fraction operator/(Fraction const &lhs, Fraction const &rhs)
{
    return Fraction{lhs} /= rhs;
}

// Add scalar.
inline Fraction operator+(Fraction const &lhs, Type scalar)
{
    return Fraction{lhs} += scalar;
}

// Add scalar.
inline Fraction operator+(Type scalar, Fraction const &rhs)
{
    return Fraction{rhs} += scalar;
}

// Subtract scalar.
inline Fraction operator-(Fraction const &lhs, Type scalar)
{
    return Fraction{lhs} -= scalar;
}

// Subtract scalar.
inline Fraction operator-(Type scalar, Fraction const &rhs)
{
    return Fraction{rhs} -= scalar;
}

// Multiply scalar.
inline Fraction operator*(Fraction const &lhs, Type scalar)
{
    return Fraction{lhs} *= scalar;
}

// Multiply scalar.
inline Fraction operator*(Type scalar, Fraction const &rhs)
{
    return Fraction{rhs} *= scalar;
}

// Divide scalar.
inline Fraction operator/(Fraction const &lhs, Type scalar)
{
    return Fraction{lhs} /= scalar;
}

// Divide scalar.
inline Fraction operator/(Type scalar, Fraction const &rhs)
{
    return Fraction{rhs} /= scalar;
}

} // Namespace.

#endif
