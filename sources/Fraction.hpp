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
    Fraction();
    void reduce();


public:
    Fraction(int,int);
    Fraction(float);
    int getUp() const;
    int getDown() const;
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

    Fraction operator++(int) ;
    Fraction operator--(int) ;

    friend ostream& operator<< (ostream& output, const Fraction& other);








};


#endif //SP_Y2S2M3_FRACTION_H