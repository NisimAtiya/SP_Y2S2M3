// //
// // Created by Nisim Atiya on 14/04/2023.
// //


#include "Fraction.hpp"
#include <string>
#include <ostream>
#include <math.h>

#include <istream>

using namespace std;



Fraction::Fraction(int up, int donw) {
    if (donw == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    // if( (up>0) && (donw<0) ){
    //     up*=-1;
    //     donw*=-1;
    // }
    if( donw<0 ){
        up = -up;
        donw = -donw;
    }
    this->up_=up;
    this->down_=donw;
    this->reduce();
}
Fraction::Fraction() {
    this->up_=0;
    this->down_=1;

}

Fraction::Fraction(float num) {
    int up = num*1000;
    this->up_=up;
    this->down_=1000;
}
//getUp
int Fraction::getNumerator() const {
    return this->up_;
}
//getDown
int Fraction::getDenominator() const {
    return this->down_;
}

void Fraction::reduce() {
    int gcd = findGCD(this->up_, this->down_);
    this->up_ = this->up_ / gcd;
    this->down_= this->down_ / gcd;
}

int Fraction::findGCD(int up, int down) {
    if(down == 0) return up;
    return findGCD(down, up % down);
}
//----------------------------------------------------------------------------------------------------------------------

Fraction Fraction::operator+(const Fraction &other) const {
    if ((this->up_ > 0 && other.getNumerator() > std::numeric_limits<int>::max() - this->up_) ||
        (this->up_ < 0 && other.getNumerator() < std::numeric_limits<int>::min() - this->up_)) {
        throw std::overflow_error("Overflow detected in addition");
    }

    int temp_up = this->up_*other.getDenominator()+other.getNumerator()* this->down_;
    int temp_down = this->down_*other.getDenominator();
    Fraction temp(temp_up,temp_down);
    temp.reduce();
    return temp;
}

Fraction Fraction::operator+(float other) const {
    Fraction fother(other);
    return this->operator+(fother);

}

Fraction operator+(float fother, const Fraction & other) {
    return other.operator+(fother);
}
//----------------------------------------------------------------------------------------------------------------------

Fraction Fraction::operator-(const Fraction &other) const {

    long long num = static_cast<long long>(this->up_) * other.getDenominator() -
                    static_cast<long long>(other.getNumerator()) * this->down_;
    if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
        throw std::overflow_error("Overflow detected in subtraction");
    }

    int temp_up = this->up_*other.getDenominator()-other.getNumerator()* this->down_;
    int temp_down = this->down_*other.getDenominator();
    Fraction temp(temp_up,temp_down);
    temp.reduce();
    return temp;
}
Fraction Fraction::operator-(float other) const {
    Fraction fother(other);
    return this->operator-(fother);

}

Fraction operator-(float fother, const Fraction & other) {
    return -1*other.operator-(fother);
}
//----------------------------------------------------------------------------------------------------------------------

Fraction Fraction::operator*(const Fraction &other) const {

    int temp_up, temp_down;
    if (__builtin_mul_overflow(this->up_, other.getNumerator(), &temp_up) ||
        __builtin_mul_overflow(this->down_, other.getDenominator(), &temp_down)) {
        throw std::overflow_error("Overflow detected in multiplication");
    }
    Fraction temp(temp_up, temp_down);
    temp.reduce();
    return temp;
}
Fraction Fraction::operator*(float other) const {
    Fraction fother(other);
    return this->operator*(fother);

}

Fraction operator*(float fother, const Fraction & other) {
    return other.operator*(fother);
}

//----------------------------------------------------------------------------------------------------------------------

Fraction Fraction::operator/(const Fraction &other) const {
    if (other.getNumerator() == 0) {
        throw std::runtime_error("Division by zero");
    }
    int temp_up, temp_down;
    if (__builtin_mul_overflow(this->up_, other.getDenominator(), &temp_up) ||
        __builtin_mul_overflow(this->down_, other.getNumerator(), &temp_down)) {
        throw std::overflow_error("Overflow detected in division");
    }
    Fraction temp(temp_up, temp_down);

    temp.reduce();
    return temp;
}

Fraction Fraction::operator/(float other) const {
    Fraction fother(other);
    return this->operator/(fother);

}

Fraction operator/(float fother, const Fraction & other) {
    Fraction ff(fother);
    return ff.operator/(other);

}
//----------------------------------------------------------------------------------------------------------------------
bool Fraction::operator==(const Fraction &other) const {
    float temp1 = float(this->getNumerator())/ this->getDenominator();
    float temp2 = float(other.getNumerator())/ other.getDenominator();
    int tenp11 = temp1*1000;
    int temp22 = temp2*1000;
    return tenp11==temp22;
}
bool Fraction::operator>(const Fraction &other) const {
    float temp1 = float(this->getNumerator())/ this->getDenominator();
    float temp2 = float(other.getNumerator())/ other.getDenominator();
    int tenp11 = temp1*1000;
    int temp22 = temp2*1000;
    return tenp11>temp22;
}
bool Fraction::operator<(const Fraction &other) const {
    float temp1 = float(this->getNumerator())/ this->getDenominator();
    float temp2 = float(other.getNumerator())/ other.getDenominator();
    int tenp11 = temp1*1000;
    int temp22 = temp2*1000;
    return tenp11<temp22;
}
bool Fraction::operator>=(const Fraction &other) const {
    return ( (this->operator>(other)) || (this->operator==(other)) );
}
bool Fraction::operator<=(const Fraction &other) const {
    return ( (this->operator<(other)) || (this->operator==(other)) );
}
//----------------------------------------------------------------------------------------------------------------------
bool Fraction::operator==(float other) const {
    Fraction fother(other);
    return this->operator==(fother);
}
bool Fraction::operator>(float other) const {
    Fraction fother(other);
    return this->operator>(fother);
}
bool Fraction::operator<(float other) const {
    Fraction fother(other);
    return this->operator<(fother);
}
bool Fraction::operator>=(float other) const {
    Fraction fother(other);
    return this->operator>=(fother);
}
bool Fraction::operator<=(float other) const {
    Fraction fother(other);
    return this->operator<=(fother);
}
//----------------------------------------------------------------------------------------------------------------------
bool operator==(float fother, const Fraction &other) {
    return other.operator==(fother);
}
bool operator>(float fother, const Fraction &other) {
    return other.operator<(fother);

}
bool operator<(float fother, const Fraction &other) {
    return other.operator>(fother);
}
bool operator>=(float fother, const Fraction &other) {
    return other.operator<=(fother);

}

bool operator<=(float fother, const Fraction &other) {
    return other.operator>=(fother);

}

//----------------------------------------------------------------------------------------------------------------------
Fraction Fraction::operator++(int temp) {
    Fraction copy(this->getNumerator(), this->getDenominator());
    this->up_= this->up_+ this->down_;
    return copy;
}
Fraction Fraction::operator++() {
    this->up_= this->up_+ this->down_;
    return Fraction(this->up_, this->down_);
}

Fraction Fraction::operator--(int temp) {
    Fraction copy(this->getNumerator(), this->getDenominator());
    this->up_= this->up_- this->down_;
    return copy;
}
Fraction Fraction::operator--() {
    this->up_= this->up_- this->down_;
    return Fraction(this->up_, this->down_);
}
//----------------------------------------------------------------------------------------------------------------------



string Fraction::toString() {

    return to_string(this->up_) + "/" + to_string(this->down_);
}
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    int num = f.up_;
    int den = f.down_;
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
    os << num << "/" << den;
    return os;
}


istream &operator>>(istream& is, Fraction& f) {
    int up;
    int down=0;
    is >> up;
    is >> down;
    if(down==0) throw runtime_error("Invalid input");
    f=Fraction(up,down);
    return is;
}