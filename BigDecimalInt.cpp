

#include "BigDecimalInt.h"

// an empty constructor to declare an object from the BigDecimalInt class without the need for initialization
BigDecimalInt::BigDecimalInt() {}




//Eng Mohamed work














//Eng Hadeer work










//Eng Mostafa Work

// member function that gives the size of an BigDecimalInt object (big number)
// (returns the number of digits forming this number without counting the sign as a digit)
int BigDecimalInt::size() {
    if(isdigit(sgn)){
        return bigDecimalIint.length();
    }
    else{
        return (bigDecimalIint.length()-1);
    }
}



// a friend member function that overrides << operator to be able to print the class BigDecimalInt objects
ostream& operator << (ostream& out, BigDecimalInt b){

    for (int i=0;i <b.bigDecimalIint.length();i++){
        out<<b.bigDecimalIint[i];
    }
    return out;
};



//a member function that overrides ==  operator to be able to compare two objects from the class BigDecimalInt
// returns true if the two objects are equal, false otherwise
bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {
    if (bigDecimalIint == anotherDec.bigDecimalIint){
        return true;
    }
    else{
        return false;
    }
}

// a member function that overrides =  operator to be able to assign the value of an object from the class BigDecimalInt to another one
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {
    bigDecimalIint = anotherDec.bigDecimalIint;
    sgn = anotherDec.sgn;
    return *this;
}


// operator > to compare between two big decimal numbers and  return a true value if the first number was greater than the second number
// and return false otherwise
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {

    //    compare between the two numbers using the sign
    if ((anotherDec.sign()=='-' and this->sign()=='+')){
        return  true;
    }

    //    compare between the two numbers using the sign
    if ((anotherDec.sign()=='+' and this->sign()=='-')){
        return  false;
    }

        //    compare between the two numbers using the length if the numbers had the same sign
    else if(bigDecimalIint.length() > anotherDec.bigDecimalIint.length()){
        return true;
    }

        //   compare between  the two numbers using the value of them if the length and the sign are the same
    else if(bigDecimalIint.length()==anotherDec.bigDecimalIint.length()){


        if(bigDecimalIint.length()<10){
            if(stoi(bigDecimalIint) > stoi(anotherDec.bigDecimalIint) )
                return true;
        }

        // comparing using the string to int conversion for every 9 digits of the string if the number was formed from more than 10 digits
        // until reaching the end of the string
        int start=0, len= 9,end=bigDecimalIint.length()/9,check=0;
        string p1 = bigDecimalIint ,p2 = anotherDec.bigDecimalIint;
        while(true){
            if(stoi(p1.substr(start, len))>stoi(p2.substr(start,len))){
                return true;
            }
            if( p1.length()-start>9){
                start+=9;
            }else{
                len = p1.length()-start;
            }

            check+=1;
            if(check>end){
                return false;
            }
        }
    }
    else {
        return false;
    }
}

// operator < to compare between two big decimal numbers and  return a true value if the first number was smaller than the second number
// and return false otherwise
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {

//    compare between the two numbers using the sign
    if ((anotherDec.sign()=='-' and this->sign()=='+')){
        return  false;
    }

//    compare between the two numbers using the sign
    if ((anotherDec.sign()=='+' and this->sign()=='-')){
        return  true;
    }

//    compare between the two numbers using the length if the numbers had the same sign
    else if(bigDecimalIint.length() > anotherDec.bigDecimalIint.length()){
        return false;
    }

//   compare between  the two numbers using the value of them if the length and the sign are the same
    else if(bigDecimalIint.length()==anotherDec.bigDecimalIint.length()){

//        comparing using the string to int conversion for the whole string if the number was formed from less than 10 digits
        if(bigDecimalIint.length()<10){
            if(stoi(bigDecimalIint) > stoi(anotherDec.bigDecimalIint) )
                return true;
        }


// comparing using the string to int conversion for every 9 digits of the string if the number was formed from more than 10 digits
// until reaching the end of the string
        int start=0, len= 9,end=bigDecimalIint.length()/9,check=0;
        string p1 = bigDecimalIint ,p2 = anotherDec.bigDecimalIint;
        while(true){
            if(stoi(p1.substr(start, len))>stoi(p2.substr(start,len))){
                return false;
            }
            if( p1.length()-start>9){
                start+=9;
            }else{
                len = p1.length()-start;
            }

            check+=1;
            if(check>end){
                return true;
            }
        }
    }
    else {
        return true;
    }
}




