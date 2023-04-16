//
// Created by Nisim Atiya on 14/04/2023.
//

#include "Fraction.hpp"
#include <string>
using namespace std;



Fraction::Fraction(int up, int donw) {
    this->up_=up;
    this->down_=donw;
}
Fraction::Fraction() {
    this->up_=0;
    this->down_=1;
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

Fraction Fraction::operator-(const Fraction &other) const {
    int temp_up = this->up_*other.getDown()-other.getUp()* this->down_;
    int temp_down = this->down_*other.getDown();
    Fraction temp(temp_up,temp_down);
    temp.reduce();
    return temp;
}

Fraction Fraction::operator*(const Fraction &other) const {
    int temp_up = this->up_*other.getUp();
    int temp_down =  this->down_*other.getDown();
    Fraction temp(temp_up,temp_down);
    temp.reduce();
    return temp;
}

Fraction Fraction::operator/(const Fraction &other) const {
    int temp_up = this->up_*other.getDown();
    int temp_down = this->down_*other.up_;
    Fraction temp(temp_up,temp_down);
    temp.reduce();
    return temp;

}

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
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return ((temp1 == temp2) || (temp1>temp2));
}

bool Fraction::operator<=(const Fraction &other) const {
    int temp1 = this->up_*other.getDown();
    int temp2 = this->down_*other.up_;
    return ((temp1 == temp2) || (temp1<temp2));
}

Fraction Fraction::operator++() {
    return Fraction();
}

Fraction Fraction::operator--() {
    return Fraction();
}

string Fraction::toString() {
    return to_string(this->up_) + "/" + to_string(this->down_);
}
ostream& operator<< (ostream& , const Fraction& ){

}

