//
// Created by Nisim Atiya on 14/04/2023.
//

#ifndef SP_Y2S2M3_FRACTION_H
#define SP_Y2S2M3_FRACTION_H

namespace ariel{}
#include <string>
using namespace std;

class Fraction {
private:
    int up_;
    int down_;
    int findGCD(int, int);
    void reduce();


public:
    Fraction(int,int);
    Fraction(float);
    Fraction();
    int getNumerator() const;
    int getDenominator() const;
    string toString();


    Fraction operator+(const Fraction&) const;
    Fraction operator+(float)const;
    friend Fraction operator+(float ,const Fraction&);

    Fraction operator-(const Fraction&) const;
    Fraction operator-(float)const;
    friend Fraction operator-(float ,const Fraction&);

    Fraction operator*(const Fraction&) const;
    Fraction operator*(float)const;
    friend Fraction operator*(float ,const Fraction&);

    Fraction operator/(const Fraction&) const;
    Fraction operator/(float)const;
    friend Fraction operator/(float ,const Fraction&);

    bool operator==(const Fraction&) const;
    bool operator==(float)const;
    friend bool operator==(float ,const Fraction&);

    bool operator>(const Fraction&) const;
    bool operator>(float)const;
    friend bool operator>(float ,const Fraction&);

    bool operator<(const Fraction&) const;
    bool operator<(float)const;
    friend bool operator<(float ,const Fraction&);

    bool operator>=(const Fraction&) const;
    bool operator>=(float)const;
    friend bool operator>=(float ,const Fraction&);

    bool operator<=(const Fraction&) const;
    bool operator<=(float)const;
    friend bool operator<=(float ,const Fraction&);

    Fraction operator++(int);
    Fraction operator++();
    Fraction operator--(int);
    Fraction operator--();


    friend ostream& operator<< (ostream& , const Fraction& );
    friend istream& operator>>(istream& , Fraction& );








};


#endif //SP_Y2S2M3_FRACTION_H