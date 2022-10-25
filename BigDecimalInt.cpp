

#include "BigDecimalInt.h"

// an empty constructor to declare an object from the BigDecimalInt class without the need for initialization
BigDecimalInt::BigDecimalInt() {}

// Eng Mohamed work

// a constructor that initialize objects from class BigDecimalInt by taking a string as a parameter
// and rejecting bad input using a loop that prevents creating the object until it's initialized with a correct input
BigDecimalInt::BigDecimalInt(string str_integer)
{

    //   loop to reject bad input
    while (true)
    {
        try
        {
            if (str_integer.find_first_not_of("0123456789-+") == string::npos and str_integer.find("+-") == string::npos and str_integer.find("-+") == string::npos and
                str_integer.find("--") == string::npos and str_integer.find("++") == string::npos)
            {
                bigDecimalIint = str_integer;
                sgn = str_integer[0];
                break;
            }
            throw "Invalid input.";
        }
        catch (...)
        {
            cout << "Invalid input.\n"
                 << "please Enter a big decimal integer:-";
            cin >> str_integer;
        }
    }
}

// a constructor that initialize objects from class BigDecimalInt by taking an integer as a parameter
// and rejecting bad input using a loop that prevents creating the object until it's initialized with a correct input
BigDecimalInt::BigDecimalInt(long long int int_integer)
{

    //    converting the integer input into a string to use the same methods made to the strings
    string str_integer = to_string(int_integer);

    //    loop to reject bad input
    while (true)
    {
        try
        {
            if (str_integer.find_first_not_of("0123456789-+") == string::npos and str_integer.find("+-") == string::npos and str_integer.find("-+") == string::npos and
                str_integer.find("--") == string::npos and str_integer.find("++") == string::npos)
            {
                bigDecimalIint = str_integer;
                sgn = str_integer[0];
                break;
            }
            throw "Invalid input.";
        }
        catch (...)
        {
            cout << "Invalid input.\n"
                 << "please Enter a big decimal integer:-";
            cin >> str_integer;
        }
    }
}

// + operator that uses the sum() function to get the sum of two big decimal numbers
// it covers all the different cases of addition numbers with the different signs
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{

    BigDecimalInt B1("0000"), B2("00000");

    string result, b1, b2;

    // to cover the case of the sum between two positive numbers written with no + sign
    if (isdigit(this->sgn) and isdigit(anotherDec.sgn))
    {
        b1 = bigDecimalIint;
        b2 = anotherDec.bigDecimalIint;

        result = sum(b1, b2);
    }

    // to cover the case of the sum between two positive numbers written with  + sign
    else if (this->sgn == '+' and anotherDec.sgn == '+')
    {
        b1 = bigDecimalIint.substr(1, bigDecimalIint.length() - 1);
        b2 = anotherDec.bigDecimalIint.substr(1, anotherDec.bigDecimalIint.length() - 1);

        result = sum(b1, b2);
    }

    // to cover the case of the sum between two negative numbers
    else if (this->sign() == '-' and anotherDec.sign() == '-')
    {
        b1 = bigDecimalIint.substr(1, bigDecimalIint.length() - 1);
        b2 = anotherDec.bigDecimalIint.substr(1, anotherDec.bigDecimalIint.length() - 1);

        result = sum(b1, b2);
        result.insert(0, 1, '-');
    }

    // to cover the case of the sum between one negative number and another positive number written with no + sign
    else if (this->sign() == '-' and isdigit(anotherDec.sgn))
    {

        B1.bigDecimalIint = this->bigDecimalIint.substr(1, this->size());
        B2.bigDecimalIint = anotherDec.bigDecimalIint;

        b1 = B1.bigDecimalIint;
        b2 = B2.bigDecimalIint;

        //        to decide which sign to put according to the comparsion between the two numbers without a sign
        if (B1 > B2)
        {
            result = difference(b1, b2);
            result.insert(0, 1, '-');
        }
        else
        {
            result = difference(b1, b2);
            result = result.substr(1, result.length() - 1);
        }
    }

    // to cover the case of the sum between a negative number and a positive number with  + sign
    else if (this->sign() == '-' and anotherDec.sgn == '+')
    {
        B1.bigDecimalIint = this->bigDecimalIint.substr(1, this->size());
        B2.bigDecimalIint = anotherDec.bigDecimalIint.substr(1, anotherDec.size());

        b1 = B1.bigDecimalIint;
        b2 = B2.bigDecimalIint;

        //        to decide which sign to put according to the comparsion between the two numbers without a sign
        if (B1 > B2)
        {
            result = difference(b1, b2);
            result.insert(0, 1, '-');
        }
        else
        {
            result = difference(b1, b2);
            result = result.substr(1, result.length() - 1);
        }
    }

    // to cover the case of the sum between a positive number with no + sign and a negative number
    else if (isdigit(this->sgn) and anotherDec.sign() == '-')
    {
        B1.bigDecimalIint = this->bigDecimalIint;
        B2.bigDecimalIint = anotherDec.bigDecimalIint.substr(1, anotherDec.size());

        b1 = B1.bigDecimalIint;
        b2 = B2.bigDecimalIint;

        //        to decide which sign to put according to the comparsion between the two numbers without a sign
        if (B2 > B1)
        {
            result = difference(b1, b2);
        }
        else
        {
            result = difference(b1, b2);
        }
    }

    // to cover the case of the sum between a positive number with + sign and a negative number
    else if (this->sgn == '+' and anotherDec.sign() == '-')
    {
        B1.bigDecimalIint = this->bigDecimalIint.substr(1, this->size());
        B2.bigDecimalIint = anotherDec.bigDecimalIint.substr(1, anotherDec.size());

        b1 = B1.bigDecimalIint;
        b2 = B2.bigDecimalIint;

        //        to decide which sign to put according to the comparsion between the two numbers without a sign
        if (B2 > B1)
        {
            result = difference(b1, b2);
        }
        else
        {
            result = difference(b1, b2);
        }
    }

    BigDecimalInt sum(result);
    return sum;
}

// function that calculates the sum of two big decimal numbers
string BigDecimalInt::sum(string b1, string b2)
{

    string result;

    int carry = 0, int_result, n_itr = b1.length() - 1, diff_len = 0;

    //    check if the length of the first string is larger than the second and make them equal by filling with zeros on the left
    if (b1.length() > b2.length())
    {
        n_itr = b1.length() - 1;
        diff_len = b1.length() - b2.length();
        b2.insert(0, diff_len, '0');
    }

    //    check if the length of the second string is larger than the first and make them equal by filling with zeros on the left
    else if (b2.length() > b1.length())
    {
        n_itr = b2.length() - 1;
        diff_len = b2.length() - b1.length();
        b1.insert(0, diff_len, '0');
    }

    //    sum algorithm
    for (int i = n_itr; i >= 0; i--)
    {

        int_result = char_int_map[b1[i]] + char_int_map[b2[i]] + carry;
        if (carry > 10 and i != 0)
        {
            carry = 1;
            int_result = int_result % 10;
        }
        else if (int_result == 10 and i != 0)
        {
            carry = 1;
            int_result = 0;
        }

        else
        {
            carry = 0;
        }
        result += to_string(int_result);
    }

    reverse(result.begin(), result.end());

    return result;
}

// Eng Hadeer work

// function that calculates the difference of two big decimal numbers
string BigDecimalInt::difference(string b1, string b2)
{

    string result;

    int reminder = 0, int_result, n_itr = b1.length() - 1, diff_len = 0;

    //    check if the length of the first string is larger than the second and make them equal by filling with zeros on the left
    if (b1.length() > b2.length())
    {
        n_itr = b1.length() - 1;
        diff_len = b1.length() - b2.length();
        b2.insert(0, diff_len, '0');
    }

    //    check if the length of the second string is larger than the first and make them equal by filling with zeros on the left
    else if (b2.length() > b1.length())
    {
        n_itr = b2.length() - 1;
        diff_len = b2.length() - b1.length();
        b1.insert(0, diff_len, '0');
    }

    // checking if the first number is greater the second
    if (b1 > b2)
    {

        //        subtracting algorithm
        for (int i = n_itr; i >= 0; i--)
        {

            int_result = char_int_map[b1[i]] - char_int_map[b2[i]] - reminder;
            if (int_result < 0)
            {
                int_result += 10;
                reminder = 1;
            }
            else
            {
                reminder = 0;
            }
            result += to_string(int_result)[to_string(int_result).length() - 1];
        }
    }

    // checking if the second number is greater the first to add a - sign to the result of subtracting
    else if (b2 > b1)
    {

        //        subtracting algorithm
        for (int i = n_itr; i >= 0; i--)
        {

            int_result = char_int_map[b2[i]] - char_int_map[b1[i]] - reminder;
            if (int_result < 0)
            {
                int_result += 10;
                reminder = 1;
            }
            else
            {
                reminder = 0;
            }
            result += to_string(int_result);
        }
        result.resize(result.length() + 1, '-');
    }
    else
    {
        result = '0';
    }

    reverse(result.begin(), result.end());

    return result;
}

// - operator that uses the difference() function to get the difference of two big decimal numbers
// it covers all the different cases of subtraction numbers with the different signs
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{

    BigDecimalInt B1("0000"), B2("00000");
    string result, b1, b2;

    // to cover the case of the difference between two positive numbers written with no + sign
    if (isdigit(this->sgn) and isdigit(anotherDec.sgn))
    {
        b1 = bigDecimalIint;
        b2 = anotherDec.bigDecimalIint;

        result = difference(b1, b2);
    }

    // to cover the case of the difference between two positive numbers written with  + sign
    else if (this->sgn == '+' and anotherDec.sgn == '+')
    {
        b1 = bigDecimalIint.substr(1, bigDecimalIint.length() - 1);
        b2 = anotherDec.bigDecimalIint.substr(1, anotherDec.bigDecimalIint.length() - 1);

        result = difference(b1, b2);
    }

    // to cover the case of the difference between one negative number and one positive number written with no + sign
    else if (this->sign() == '-' and isdigit(anotherDec.sgn))
    {

        b1 = this->bigDecimalIint.substr(1, this->size());
        b2 = anotherDec.bigDecimalIint;
        result = sum(b1, b2);
        result.insert(0, 1, '-');
    }

    // to cover the case of the difference between one negative number and one positive number written with + sign
    else if (this->sign() == '-' and anotherDec.sgn == '+')
    {
        b1 = this->bigDecimalIint.substr(1, this->size());
        b2 = anotherDec.bigDecimalIint.substr(1, anotherDec.size());
        result = sum(b1, b2);
        result.insert(0, 1, '-');
    }

    // to cover the case of the difference between one positive number written with no + sign and another positive number written with + sign
    else if (isdigit(this->sgn) and anotherDec.sgn == '+')
    {
        b1 = this->bigDecimalIint;
        b2 = anotherDec.bigDecimalIint.substr(1, anotherDec.size());
        result = difference(b1, b2);
    }

    // to cover the case of the difference between one positive number written with sign and another positive number written with no + sign
    else if (this->sgn == '+' and isdigit(anotherDec.sgn))
    {
        b1 = this->bigDecimalIint.substr(1, this->size());
        b2 = anotherDec.bigDecimalIint;
        result = difference(b1, b2);
    }

    // to cover the case of the difference between two negative numbers written with - sign
    else if (this->sign() == '-' and anotherDec.sign() == '-')
    {
        B1.bigDecimalIint = this->bigDecimalIint.substr(1, this->size());
        B2.bigDecimalIint = anotherDec.bigDecimalIint.substr(1, anotherDec.size());

        b1 = B1.bigDecimalIint;
        b2 = B2.bigDecimalIint;

        //        to decide which sign to put according to the comparsion between the two numbers without a sign
        if (B1 > B2)
        {
            result = difference(b1, b2);
            result.insert(0, 1, '-');
        }
        if (B2 > B1)
        {
            result = difference(b1, b2);
            result = result.substr(1, result.length() - 1);
        }
    }

    // to cover the case of the difference between one positive number written with no + sign and  one negative number written with - sign
    else if (isdigit(this->sgn) and anotherDec.sign() == '-')
    {
        b1 = bigDecimalIint;
        b2 = anotherDec.bigDecimalIint.substr(1, anotherDec.bigDecimalIint.length() - 1);

        result = sum(b1, b2);
    }

    // to cover the case of the difference between one positive number written with  + sign and  one negative number written with - sign
    else if (this->sgn == '+' and anotherDec.sign() == '-')
    {
        b1 = bigDecimalIint.substr(1, anotherDec.bigDecimalIint.length() - 1);
        b2 = anotherDec.bigDecimalIint.substr(1, anotherDec.bigDecimalIint.length() - 1);

        result = sum(b1, b2);
    }

    BigDecimalInt difference(result);
    return difference;
}

// operator < to compare between two big decimal numbers and  return a true value if the first number was smaller than the second number
// and return false otherwise
bool BigDecimalInt::operator<(BigDecimalInt anotherDec)
{

    //    compare between the two numbers using the sign
    if ((anotherDec.sign() == '-' and this->sign() == '+'))
    {
        return false;
    }

    //    compare between the two numbers using the sign
    if ((anotherDec.sign() == '+' and this->sign() == '-'))
    {
        return true;
    }

    //    compare between the two numbers using the length if the numbers had the same sign
    else if (bigDecimalIint.length() > anotherDec.bigDecimalIint.length())
    {
        return false;
    }

    //   compare between  the two numbers using the value of them if the length and the sign are the same
    else if (bigDecimalIint.length() == anotherDec.bigDecimalIint.length())
    {

        //        comparing using the string to int conversion for the whole string if the number was formed from less than 10 digits
        if (bigDecimalIint.length() < 10)
        {
            if (stoi(bigDecimalIint) > stoi(anotherDec.bigDecimalIint))
                return true;
        }

        // comparing using the string to int conversion for every 9 digits of the string if the number was formed from more than 10 digits
        // until reaching the end of the string
        int start = 0, len = 9, end = bigDecimalIint.length() / 9, check = 0;
        string p1 = bigDecimalIint, p2 = anotherDec.bigDecimalIint;
        while (true)
        {
            if (stoi(p1.substr(start, len)) > stoi(p2.substr(start, len)))
            {
                return false;
            }
            if (p1.length() - start > 9)
            {
                start += 9;
            }
            else
            {
                len = p1.length() - start;
            }

            check += 1;
            if (check > end)
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
}

// Eng Mostafa Work

// member function that gives the size of an BigDecimalInt object (big number)
// (returns the number of digits forming this number without counting the sign as a digit)
int BigDecimalInt::size()
{
    if (isdigit(sgn))
    {
        return bigDecimalIint.length();
    }
    else
    {
        return (bigDecimalIint.length() - 1);
    }
}

// a friend member function that overrides << operator to be able to print the class BigDecimalInt objects
ostream &operator<<(ostream &out, BigDecimalInt b)
{

    for (int i = 0; i < b.bigDecimalIint.length(); i++)
    {
        out << b.bigDecimalIint[i];
    }
    return out;
};

// a member function that overrides ==  operator to be able to compare two objects from the class BigDecimalInt
//  returns true if the two objects are equal, false otherwise
bool BigDecimalInt::operator==(BigDecimalInt anotherDec)
{
    if (bigDecimalIint == anotherDec.bigDecimalIint)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// a member function that overrides =  operator to be able to assign the value of an object from the class BigDecimalInt to another one
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec)
{
    bigDecimalIint = anotherDec.bigDecimalIint;
    sgn = anotherDec.sgn;
    return *this;
}

// operator > to compare between two big decimal numbers and  return a true value if the first number was greater than the second number
// and return false otherwise
bool BigDecimalInt::operator>(BigDecimalInt anotherDec)
{

    //    compare between the two numbers using the sign
    if ((anotherDec.sign() == '-' and this->sign() == '+'))
    {
        return true;
    }

    //    compare between the two numbers using the sign
    if ((anotherDec.sign() == '+' and this->sign() == '-'))
    {
        return false;
    }

    //    compare between the two numbers using the length if the numbers had the same sign
    else if (bigDecimalIint.length() > anotherDec.bigDecimalIint.length())
    {
        return true;
    }

    //   compare between  the two numbers using the value of them if the length and the sign are the same
    else if (bigDecimalIint.length() == anotherDec.bigDecimalIint.length())
    {

        if (bigDecimalIint.length() < 10)
        {
            if (stoi(bigDecimalIint) > stoi(anotherDec.bigDecimalIint))
                return true;
        }

        // comparing using the string to int conversion for every 9 digits of the string if the number was formed from more than 10 digits
        // until reaching the end of the string
        int start = 0, len = 9, end = bigDecimalIint.length() / 9, check = 0;
        string p1 = bigDecimalIint, p2 = anotherDec.bigDecimalIint;
        while (true)
        {
            if (stoi(p1.substr(start, len)) > stoi(p2.substr(start, len)))
            {
                return true;
            }
            if (p1.length() - start > 9)
            {
                start += 9;
            }
            else
            {
                len = p1.length() - start;
            }

            check += 1;
            if (check > end)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

// operator < to compare between two big decimal numbers and  return a true value if the first number was smaller than the second number
// and return false otherwise
bool BigDecimalInt::operator<(BigDecimalInt anotherDec)
{

    //    compare between the two numbers using the sign
    if ((anotherDec.sign() == '-' and this->sign() == '+'))
    {
        return false;
    }

    //    compare between the two numbers using the sign
    if ((anotherDec.sign() == '+' and this->sign() == '-'))
    {
        return true;
    }

    //    compare between the two numbers using the length if the numbers had the same sign
    else if (bigDecimalIint.length() > anotherDec.bigDecimalIint.length())
    {
        return false;
    }

    //   compare between  the two numbers using the value of them if the length and the sign are the same
    else if (bigDecimalIint.length() == anotherDec.bigDecimalIint.length())
    {

        //        comparing using the string to int conversion for the whole string if the number was formed from less than 10 digits
        if (bigDecimalIint.length() < 10)
        {
            if (stoi(bigDecimalIint) > stoi(anotherDec.bigDecimalIint))
                return true;
        }

        // comparing using the string to int conversion for every 9 digits of the string if the number was formed from more than 10 digits
        // until reaching the end of the string
        int start = 0, len = 9, end = bigDecimalIint.length() / 9, check = 0;
        string p1 = bigDecimalIint, p2 = anotherDec.bigDecimalIint;
        while (true)
        {
            if (stoi(p1.substr(start, len)) > stoi(p2.substr(start, len)))
            {
                return false;
            }
            if (p1.length() - start > 9)
            {
                start += 9;
            }
            else
            {
                len = p1.length() - start;
            }

            check += 1;
            if (check > end)
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
}
