#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator):
    m_numerator(numerator), m_denominator(denominator)
{
    reduce(*this);
}

Fraction Fraction::operator+(const int other){
    Fraction temp(other, 1);
    return *this+temp;
}

Fraction Fraction::operator+(const Fraction& other){
    Fraction lhs=*this;
    Fraction temp=other;
    //Different Denominators
    if(lhs.Getdenominator()!=temp.Getdenominator()){
        int lcm;
        lcm=LCM(lhs.Getdenominator(),temp.Getdenominator());   //find lcm
        int factor1=lcm/lhs.Getdenominator();  //Divide lcm by denominators
        int factor2=lcm/temp.Getdenominator();
        //Fix numerators
        lhs.Setnumerator(lhs.Getnumerator()*factor1);
        temp.Setnumerator(temp.Getnumerator()*factor2);
        //Set denoms
        lhs.Setdenominator(lcm);
        temp.Setdenominator(lcm);
    }

    //Adding fractions with like denoms
    lhs.Setnumerator(lhs.Getnumerator()+temp.Getnumerator());
    reduce(lhs);
    return lhs;
}

Fraction Fraction::operator-(const int other){
    Fraction temp(other,1);
    return *this-temp;
}

Fraction Fraction::operator-(const Fraction& other){
    Fraction lhs=*this;
    Fraction temp=other;

    if(lhs.Getdenominator()!=temp.Getdenominator()){
        int lcm;
        lcm=LCM(lhs.Getdenominator(),temp.Getdenominator());   //find lcm
        int factor1=lcm/lhs.Getdenominator();  //Divide lcm by denominators
        int factor2=lcm/temp.Getdenominator();
        //Fix numerators
        lhs.Setnumerator(lhs.Getnumerator()*factor1);
        temp.Setnumerator(temp.Getnumerator()*factor2);
        //Set denoms
        lhs.Setdenominator(lcm);
        temp.Setdenominator(lcm);
    }

    lhs.Setnumerator(Getnumerator()-temp.Getnumerator());
    reduce(lhs);
    return lhs;
}


Fraction Fraction::operator*(const int other){
    Fraction temp(other,1);
    return *this*temp;
}


Fraction Fraction::operator*(const Fraction& other){
    Fraction lhs=*this;
    Fraction temp=other;

    lhs.Setnumerator(lhs.Getnumerator()*temp.Getnumerator());
    lhs.Setdenominator(lhs.Getdenominator()*temp.Getdenominator());

    reduce(lhs);
    return lhs;
}

Fraction Fraction::operator/(const int other){
    Fraction temp(other,1);
    return *this/temp;
}


Fraction Fraction::operator/(const Fraction & other){
    Fraction temp=reciprocal(other);
    return ((*this)*temp);
}

Fraction& Fraction::operator++(){
    *this=*this+1;
    return *this;
    }


Fraction Fraction::operator++(int){
    Fraction temp=*this;
    *this=*this+1;
    return temp;

}

Fraction& Fraction::operator--(){
    *this=*this-1;
    return *this;
}

Fraction Fraction::operator--(int){
    Fraction temp=*this;
    *this=*this-1;
    return temp;
}

void Fraction::operator<<(const Fraction& fraction){
    Fraction temp=fraction;
    std::stringstream ss;
    std::cout<<ss<<"F"<<temp.Getnumerator()<<"/"<<temp.Getdenominator();
}

bool Fraction::operator==(const Fraction& fraction){
    Fraction temp=fraction;
    if(m_numerator==temp.Getnumerator()&&m_denominator==temp.Getdenominator()){
        return true;
    }
    return false;
}

bool Fraction::operator!=(const Fraction& fraction){
    return !(*this==fraction);
}

bool Fraction::operator<(const Fraction& fraction){
    Fraction temp=fraction;
    if (double(*this)<double(temp)){
        return true;
    }
    return false;
}

Fraction::operator double(){
    return static_cast<double>(m_numerator)/m_denominator;
}

Fraction::operator int(){
    return m_numerator/m_denominator;
}

int Fraction::GCD(int x, int y){
    if (y==0){return x;}
    else{
        return GCD(y, x%y);
    }
}

int Fraction::LCM(int x, int y){
    return std::abs(x*y)/GCD(x, y);
}

void Fraction::reduce(Fraction& fraction){
    int gcd=GCD(m_numerator,m_denominator);
    fraction.Setnumerator(fraction.Getnumerator()/gcd);
    fraction.Setdenominator(fraction.Getdenominator()/gcd);
}

Fraction Fraction::reciprocal(const Fraction& fraction){
    Fraction temp=fraction;
    int hold=temp.Getnumerator();

    temp.Setnumerator(temp.Getdenominator());
    temp.Setdenominator(hold);

    return temp;
}
