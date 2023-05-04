#include<iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

int NumDigits(int num);
bool findAndReplace1(int &x, int find, int replace);
int replaceDig( int num, int oldDigit, int newDigit);

int main () {
    int x = -1785;
    // findAndReplace1(x, 78, 96);
    x = replaceDig(x, 78, 96);
    if (x == -1965) {
        cout << "The number after replacing is " << x << endl;
    } else {
        cout << "The preconditions were not met" << endl;
    }
    return 0;
}

int NumDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

bool findAndReplace1(int &num, int find, int replace) {
    if (find < 0 || replace < 0 || replace >= pow(10, NumDigits(find))) {
        return false;
    }
    int res = 0, digit, multiplier = 1;
    while (num != 0) {
        digit = num % 10;
        if (digit == find) {
            digit = replace;
        }
        res = res + digit * multiplier;
        multiplier *= 10;
        num /= 10;
    }
    num = res;
    return true;
}

int replaceDig( int num, int oldDigit, int newDigit)
{
   int position = NumDigits(num);
    int remainder = num;
    int currentDigit;
    while (remainder >0)
    {
        currentDigit=(num/pow(10,position))%10;
        if(currentDigit==oldDigit)
        {
            num = num - oldDigit*pow(10,position);
            num = num + newDigit*pow(10,position);
        }
        remainder = remainder/10;
        position--;
    }
    return remainder;
}
