//
// Created by Nisim Atiya on 14/04/2023.
//

#include "Fraction.hpp"
#include <string>
#include <ostream>
using namespace std;



Fraction::Fraction(int up, int donw) {
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

Fraction Fraction::operator/(const Fraction &other) const {
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

bool Fraction::operator==(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return temp1 == temp2;
}
bool Fraction::operator==(float other) const {
    int num = int(other)*1000+(int)(other * 1000) % 1000;
    int temp1 = this->up_*1000;
    int temp2 =  num* this->down_;
    return temp1 == temp2;
}

bool operator==(float fother, const Fraction &other) {
    return other==fother;
}

bool Fraction::operator>(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return temp1 > temp2;
}
bool Fraction::operator>(float other) const {
    int num = int(other)*1000+(int)(other * 1000) % 1000;
    int temp1 = this->up_*1000;
    int temp2 =  num* this->down_;
    return temp1 > temp2;
}

bool operator>(float fother, const Fraction &other) {
    return other>fother;
}

bool Fraction::operator<(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return temp1 < temp2;
}
bool Fraction::operator<(float other) const {
    int num = int(other)*1000+(int)(other * 1000) % 1000;
    int temp1 = this->up_*1000;
    int temp2 =  num* this->down_;
    return temp1 < temp2;
}

bool operator<(float fother, const Fraction &other) {
    return other<fother;
}

bool Fraction::operator>=(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return ((temp1 == temp2) || (temp1>temp2));
}
bool operator>=(float fother, const Fraction &other) {
    return ((fother>other) || (fother==other));
}

bool Fraction::operator>=(float other) const {
    return other>=Fraction(this->up_, this->down_);
}

bool Fraction::operator<=(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return ((temp1 == temp2) || (temp1<temp2));
}
bool operator<=(float fother, const Fraction &other) {
    return ((fother>other) || (fother==other));
}

bool Fraction::operator<=(float other) const {
    return other>=Fraction(this->up_, this->down_);
}

Fraction Fraction::operator++(int tenp) {
    return Fraction();
}

Fraction Fraction::operator--(int temp) {
    return Fraction();
}

string Fraction::toString() {
    return to_string(this->up_) + "/" + to_string(this->down_);
}
ostream& operator<<(ostream& output, const Fraction& other) {
    output << other.getUp() << "/" << other.getDown();
    return output;
}

