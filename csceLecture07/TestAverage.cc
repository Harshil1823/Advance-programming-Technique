// Copyright 2023 Harshil Shah
// test the overloaded Average functions
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"mynumericfunctions.h"

int main() {
    int x;
    cout << "which fibonacci number do you want? ";
    cin >> x;
    int start = clock();
    cout << Fibonacci(x) << "\ntook " << (clock() - start)
         << " milliseconds " << endl;
    /*
    cout << "Avergae (2.3, 5.6, 6.1) = " << Average(2.3, 5.7, 6.1)
        << endl;
    cout << "Avergae (2.3, 5.6,) = " << Average(2.3, 5.7)
        << endl;   
    cout << "Average (a, c) = " << Average ('a', 'c') << endl;

    cout << "Average (1.2, 1.3, 1.9, 3.7, 8.6) = " <<
         Average(1.2, 1.3, 1.9, 3.7, 8.6)
         << endl;
    */
    return 0;
}