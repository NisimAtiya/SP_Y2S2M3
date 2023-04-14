//
// Created by Nisim Atiya on 14/04/2023.
//

#include "Fraction.hpp"

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

void Fraction::reduce(Fraction) {
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
    for(int i = 2; i < min; ++i) {
        if( (up % i == 0) && (down % i == 0) ){
            temp = i;
        }
    }
    return temp;
}
