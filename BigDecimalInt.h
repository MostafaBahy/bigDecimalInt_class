#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

#ifndef BIGDICMALINT_CLASS_BIGDIECIMALINT_H
#define BIGDICMALINT_CLASS_BIGDIECIMALINT_H



class BigDecimalInt {
private:
    string bigDecimalIint;
    char sgn;
    int sz;
    map<char,int>char_int_map
    { {'0',0}, {'1',1}, {'2',2}
    ,{'3',3}, {'4',4}, {'5',5}
    ,{'6',6}, {'7',7}, {'8',8}
    ,{'9',9} };

public:
    BigDecimalInt();
    BigDecimalInt(string str_integer);
    BigDecimalInt(long long int int_integer);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    char sign();
    int size();
    friend ostream& operator << (ostream& out, BigDecimalInt b);
    string sum(string b1,string b2);
    string difference(string  b1, string b2);

};
;


#endif //BIGDICMALINT_CLASS_BIGDIECIMALINT_H
