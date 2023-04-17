#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("constructor check"){
    CHECK_NOTHROW(Fraction a(1,2));
    CHECK_NOTHROW(Fraction b(0.5));
}

TEST_CASE("Checking the correctness of fraction versus fraction functions"){
    Fraction a(1,2);
    Fraction b(0.5);
    CHECK(a==b);
    CHECK(a+b==1);
    CHECK(a-b==0);
    CHECK(a*b==0.25);
    CHECK(a/b==1);
}
TEST_CASE("Checking the correctness of a fraction against a float"){
    Fraction a(1,2);
    CHECK(a==0.5);
    CHECK(a+0.5==1);
    CHECK(a-0.5==0);
    CHECK(a*0.5==0.25);
    CHECK(a/0.5==1);
}
TEST_CASE("Checking the correctness of a fraction float against a fraction"){
    Fraction a(1,2);
    CHECK(0.5==a);
    CHECK(0.5+a==1);
    CHECK(0.5-a==0);
    CHECK(0.5*a==0.25);
    CHECK(0.5/a==1);
}
TEST_CASE("Equality and inequality testing of fracture and fracture"){
    Fraction a(1,2);
    Fraction b(2,3);
    CHECK(a<b);
    CHECK(!(a>b));
    CHECK(a<=b);
    CHECK(!(a>=b));
}
TEST_CASE("Equality and inequality testing of fracture and a float"){
    Fraction a(1,2);
    CHECK(a<0.66);
    CHECK(!(a>0.66));
    CHECK(a<=0.66);
    CHECK(!(a>=0.66));
}
TEST_CASE("Equality and inequality testing of  and float a fracture"){
    Fraction a(1,2);
    CHECK(0.66>a);
    CHECK(!(0.66<a));
    CHECK(0.66>=a);
    CHECK(!(0.66<=a));
}
TEST_CASE("Checking the operator ++ and -- before and after"){
    Fraction a(1,2);
    CHECK(a++==1.5);
    CHECK(++a==1.5);
    CHECK(a--==0.5);
    CHECK(--a==0.5);

}
TEST_CASE("Reduced fracture reconstruction test"){
    Fraction a(44,88);
    CHECK(a==0.5);
    CHECK(0.5==a);
    CHECK(a-0==0.5);
    CHECK(a*0.5==0.25);
    CHECK(a/0.5==1);
}
