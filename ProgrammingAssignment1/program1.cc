// Copyright 2023 Harshil Shah
#include <iostream>
#include <iomanip>
// using namespace std;
using std:: cout;
using std:: endl;
using std:: cin;

int main() {
  int num1, num2, num3, tempNum;
  char arithmeticOp, relationalOp, continue_or_quit;
  int correctExpression = 0;
  int totalExpression = 0;

  while ( true ) {
  cin >> num1 >> arithmeticOp >> num2 >> relationalOp >> num3;
  cin >> continue_or_quit;

  if (arithmeticOp == '+') {
    tempNum = num1 + num2;
    // create a temp number and store calclations in there
    if (relationalOp == '>') {
        if (tempNum > num3) {  // compare tempNumber calculation to num3
        cout << num1 << " " << arithmeticOp << " " << num2 << " " <<
        relationalOp << " " << num3 << " " << "-" << " " << "Correct"
        << endl;
        correctExpression++;
        totalExpression++;
    } else {
        cout << num1 << " " << arithmeticOp << " " << num2 << " "
        << relationalOp << " "<< num3 << " " << "-" << " " << "Incorrect"
        << endl;
        totalExpression++;
    }
    } else if (relationalOp == '<') {
    if (tempNum < num3) {
        cout << num1 << " " << arithmeticOp << " " << num2 << " "
        << relationalOp << " "<< num3 << " " << "-" << " " << "Correct"
        << endl;
        correctExpression++;
        totalExpression++;
    } else {
        cout << num1 << " " << arithmeticOp << " " << num2 << " "
        << relationalOp << " "<< num3 << " " << "-" << " " << "Incorrect"
        << endl;
        totalExpression++;
    }
  } else {
    cout << "Unrecognized relational operator " << relationalOp << endl;
  }
  } else if (arithmeticOp == '-') {
    tempNum = num1 - num2;

        if (relationalOp == '>') {
            if (tempNum > num3) {  // compare tempNumber calculation to num3
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " " << "Correct"
                << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Incorrect" << endl;
                totalExpression++;
            }
        } else if (relationalOp == '<') {
            if (tempNum < num3) {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " " << "Correct"
                << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Incorrect" << endl;
                totalExpression++;
            }
        } else {
                cout << "Unrecognized relational operator " << relationalOp
                << endl;
        }
} else if (arithmeticOp == '*') {
    tempNum = num1 * num2;
        if (relationalOp == '>') {
            if (tempNum > num3) {  // compare tempNumber calculation to num3
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " " << "Correct"
                << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " " <<
                "Incorrect" << endl;
                totalExpression++;
            }
        } else if (relationalOp == '<') {
            if (tempNum < num3) {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Correct" << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Incorrect" << endl;
                totalExpression++;
            }
        } else {
                cout << "Unrecognized relational operator "
                << relationalOp << endl;
        }
  } else if (arithmeticOp == '/') {
    tempNum = num1 / num2;
        if (relationalOp == '>') {
            if (tempNum > num3) {  // compare tempNumber calculation to num3
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Correct" << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Incorrect" << endl;
                totalExpression++;
            }
        } else if (relationalOp == '<') {
            if (tempNum < num3) {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Correct" << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Incorrect" << endl;
                totalExpression++;
            }
        } else {
                cout << "Unrecognized relational operator "
                << relationalOp << endl;
        }
} else if (arithmeticOp == '%') {
    tempNum %= num1 % num2;
        if (relationalOp == '>') {
            if (tempNum > num3) {  // compare tempNumber calculation to num3
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Correct" << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Incorrect" << endl;
                totalExpression++;
            }
        } else if (relationalOp == '<') {
            if (tempNum < num3) {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Correct" << endl;
                correctExpression++;
                totalExpression++;
            } else {
                cout << num1 << " " << arithmeticOp << " " << num2 << " "
                << relationalOp << " "<< num3 << " " << "-" << " "
                << "Incorrect" << endl;
                totalExpression++;
            }
        } else {
                cout << "Unrecognized relational operator "
                << relationalOp << endl;
        }
} else {
        cout << "Unrecognized arithmetic operator " << arithmeticOp << endl;
        if (relationalOp != '<' && relationalOp != '>') {
            cout << "Unrecognized relational operator " << relationalOp << endl;
        }
}

    if (continue_or_quit == 'q') {
        break;
    } else if (continue_or_quit != 'c') {
        cout <<
        "Not a valid input. Enter lowercase 'c' to continue or 'q' to quit"
        << endl;
    }
  }  // end of while loop
    double percentage;
    percentage = correctExpression / static_cast<double>(totalExpression) * 100;
    /*
    cout << correctExpression << " of " << totalExpression << 
    " = " << fixed << setprecision(2) << percentage << "%" << endl;
    */
    if (totalExpression == 0) {
        cout << correctExpression << " of " << totalExpression << " = "
        << std::setiosflags(std::ios::fixed | std::ios::showpoint)
        << std::setprecision(2) << 0.00 << "%" << endl;
    } else {
    cout << correctExpression << " of " << totalExpression << " = "
        << std::setiosflags(std::ios::fixed | std::ios::showpoint)
        << std::setprecision(2) << percentage << "%" << endl;
    }
    return 0;
}  // end main
