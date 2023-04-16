//
// Created by Nisim Atiya on 14/04/2023.
//

#include "Fraction.hpp"
#include <string>
#include <ostream>
using namespace std;



Fraction::Fraction(int up, int donw) {
    if (donw == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    this->up_=up;
    this->down_=donw;
}
Fraction::Fraction() {
    this->up_=0;
    this->down_=1;
}

Fraction::Fraction(float num) {
    int up = int(num)*1000+(int)(num * 1000) % 1000;
    this->up_=up;
    this->down_=1000;
}

int Fraction::getUp() const {
    return this->up_;
}
int Fraction::getDown() const {
    return this->down_;
}

void Fraction::reduce() {
    int gcd = findGCD(this->up_, this->down_);
    this->up_ = this->up_ / gcd;
    this->down_= this->down_ / gcd;
}

int Fraction::findGCD(int up, int down) {
    int min = up;
    if(down>up){
        min = down;
    }
    int temp=1;
    for(int i = 2; i <= min; ++i) {
        if( (up % i == 0) && (down % i == 0) ){
            temp = i;
        }
    }
    return temp;
}
//----------------------------------------------------------------------------------------------------------------------

Fraction Fraction::operator+(const Fraction &other) const {
    int temp_up = this->up_*other.getDown()+other.getUp()* this->down_;
    int temp_down = this->down_*other.getDown();
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
    int temp_up = this->up_*other.getDown()-other.getUp()* this->down_;
    int temp_down = this->down_*other.getDown();
    Fraction temp(temp_up,temp_down);
    temp.reduce();
    return temp;
}
Fraction Fraction::operator-(float other) const {
    Fraction fother(other);
    return this->operator-(fother);

}

Fraction operator-(float fother, const Fraction & other) {
    return other.operator-(fother);
}
//----------------------------------------------------------------------------------------------------------------------

Fraction Fraction::operator*(const Fraction &other) const {
    int temp_up = this->up_*other.getUp();
    int temp_down =  this->down_*other.getDown();
    Fraction temp(temp_up,temp_down);
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
    if (other.getUp() == 0) {
        throw invalid_argument("Division by zero!!");
    }
    int temp_up = this->up_*other.getDown();
    int temp_down = this->down_*other.up_;
    Fraction temp(temp_up,temp_down);
    temp.reduce();
    return temp;
}
Fraction Fraction::operator/(float other) const {
    Fraction fother(other);
    return this->operator/(fother);

}

Fraction operator/(float fother, const Fraction & other) {
    return other.operator/(fother);
}
//----------------------------------------------------------------------------------------------------------------------
bool Fraction::operator==(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return temp1 == temp2;
}
bool Fraction::operator>(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return temp1 > temp2;
}
bool Fraction::operator<(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return temp1 < temp2;
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
Fraction Fraction::operator++(int tenp) {

    return 3;
}

Fraction Fraction::operator--(int temp) {
    return 3;
}

string Fraction::toString() {
    return to_string(this->up_) + "/" + to_string(this->down_);
}
ostream& operator<<(ostream& output, const Fraction& other) {
    output << other.getUp() << "/" << other.getDown();
    return output;
}


