// Copyright 2023 Harshil Shah
#include<iostream>
using std:: cout;
using std:: endl;
using std:: cin; // object for accepting input from the standard keyboard

int main(){
    char choice;
    cout << "(E)nglish, (S)panish";
    cin >> choice;
    switch (choice)
    {
    case 'E':
    case 'e':
        cout << "What's up?";
        break;
    case 'S':
        cout << "Hola?";
        break;
    default:
        cout << "invalud";
        break;
    }
/*
    double grade;
    cout << "enter your numeric grade";
    cin >> grade;
    if(grade > 59.5)
        cout << "You pass buddy\n";
    else
        cout << "you didn't, work harder\n";

    // ?: condtional operator
    //logical expression ? true side: false side
    return 0;
`*/

/*
    int x, y;
    double z;
    cout << "Enter two integer values";
    cin >> x >> y; // equivalent to cin >> x; cin >> y;
    cout << "x / y = " << x / y << endl;
    cout << "x % y = " << x % y << endl;
    z = x / static_cast<double>(y);
    cout << "z = " << z << endl;
    int num1 = 3, num2 = 3;
    cout << "++num1 = " << ++num1;
    cout << "\nafter the statement num1 = " << num1;
    cout << "num2++ = " << num2++;
    cout << "\nafter the statement num2 = " << num2;
    return 0;
*/
}