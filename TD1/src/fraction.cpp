#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// void Fraction::display() {
//     std::cout << numerator << "/" << denominator;
// }

std::ostream& operator<<(std::ostream& os, Fraction const& p) {
    return os << '(' << p.numerator << "/" << p.denominator << ')';
}

Fraction operator+(Fraction f1, Fraction const& f2) {
    // return simplify({
    //     f1.numerator * f2.denominator + f2.numerator * f1.denominator,
    //     f1.denominator * f2.denominator
    // });
    f1 += f2;
    return simplify(f1);
}


Fraction operator-(Fraction f1, Fraction const& f2) {
    // return simplify({
    //     f1.numerator * f2.denominator - f2.numerator * f1.denominator,
    //     f1.denominator * f2.denominator
    // });
    f1 -= f2;
    return simplify(f1);
}

Fraction operator*(Fraction f1, Fraction const& f2) {
    // return simplify({
    //     f1.numerator * f2.numerator,
    //     f1.denominator * f2.denominator
    // });
    f1 *= f2;
    return simplify(f1);
}

Fraction operator/(Fraction f1, Fraction const& f2) {
    // return simplify({
    //     f1.numerator * f2.denominator,
    //     f1.denominator * f2.numerator
    // });
    f1 /= f2;
    return simplify(f1);
}

bool operator==(Fraction const& f1, Fraction const& f2){
    // if(f1.numerator!=f2.numerator){
    //     return false;
    // }
    // else if(f1.denominator!=f2.denominator){
    //     return false;
    // }
    // else {
    //     return true;
    // }
    Fraction frac1 {simplify(f1)};
    Fraction frac2 {simplify(f2)};
    bool egal {frac1.numerator==frac2.numerator && frac1.denominator==frac2.denominator};
    return egal;
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    // if(f1==f2){
    //     return false;
    // }
    // else {
    //     return true;
    // }
    return !(f1==f2);
}

bool operator<(Fraction const& f1, Fraction const& f2){
    
    if(static_cast<float>(f2.numerator)/static_cast<float>(f2.denominator) > static_cast<float>(f1.numerator)/static_cast<float>(f1.denominator)){
        return true;
    }
    else {
        return false;
    }
}

bool operator>(Fraction const& f1, Fraction const& f2){
    if(f1<f2){
        return false;
    }
    else if(f1==f2){
        return false;
    }
    else {
        return true;
    }
}

bool operator<=(Fraction const& f1, Fraction const& f2){
    if(f1==f2){
        return true;
    }
    else if(f1<f2){
        return true;
    }
    else {
        return false;
    }
}

bool operator>=(Fraction const& f1, Fraction const& f2){
    if(f1==f2){
        return true;
    }
    else if(f1>f2){
        return true;
    }
    else {
        return false;
    }
}

//EXO 6 :
float Fraction::to_float() const{
    return static_cast<float>(numerator)/static_cast<float>(denominator);
}

Fraction::operator float() const{
    return to_float();
}