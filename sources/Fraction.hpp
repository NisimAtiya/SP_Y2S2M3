//
// Created by Nisim Atiya on 14/04/2023.
//

#ifndef SP_Y2S2M3_FRACTION_H
#define SP_Y2S2M3_FRACTION_H

namespace ariel{}

class Fraction {
    private:
        int up_;
        int down_;
        void reduce(Fraction);
        int findGCD(int, int);
        


    public:
    Fraction();
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
    Fraction operator++() ;
    Fraction operator--() ;









};


#endif //SP_Y2S2M3_FRACTION_H
