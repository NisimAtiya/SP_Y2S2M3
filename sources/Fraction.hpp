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
    int getUp() const;
    int getDown() const;
    Fraction operator+(const Fraction&) const;
    Fraction operator-(const Fraction&) const;
    Fraction operator*(const Fraction&) const;
    Fraction operator/(const Fraction&) const;
    bool operator==(const Fraction&) const;
    bool operator>(const Fraction&) const;
    bool operator<(const Fraction&) const;
    bool operator>=(const Fraction&) const;
    bool operator<=(const Fraction&) const;
    Fraction operator++(int) ;
    Fraction operator--(int) ;
    friend ostream& operator<< (ostream& output, const Fraction& other);
    string toString();


};


#endif //SP_Y2S2M3_FRACTION_H