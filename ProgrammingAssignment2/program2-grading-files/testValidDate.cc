// Copyright 2023 bhipp
// runs sample tests for ValidDate function
#include<iostream>
using std::cout;
using std::endl;
#include "program2functions.h"

int main() {
  if ( ValidDate(2, 29, 2008) )
    cout << "Passed 2/29/2008 test" << endl;
  else
    cout << "Failed 2/29/2008 test" << endl;

  if ( !ValidDate(2, 29, 2007) )
    cout << "Passed 2/29/2007 test" << endl;
  else
    cout << "Failed 2/29/2007 test" << endl;

  if ( !ValidDate(2, 29, 3000)  )
    cout << "Passed 2/29/3000 test" << endl;
  else
    cout << "Failed 2/29/3000 test" << endl;

  if ( ValidDate(2, 29, 4000)  )
    cout << "Passed 2/29/4000 test" << endl;
  else
    cout << "Failed 2/29/4000 test" << endl;

  if ( !ValidDate(-3, 6, 2023) )
    cout << "Passed -3/6/2023 test" << endl;
  else
    cout << "Failed -3/6/2023 test" << endl;

  if ( ValidDate(3, 31, 2023) )
    cout << "Passed 3/31/2023 test" << endl;
  else
    cout << "Failed 3/31/2023 test" << endl;

  if ( !ValidDate(9, 31, 2023) )
    cout << "Passed 9/31/2023 test" << endl;
  else
    cout << "Failed 9/31/2023 test" << endl;

  if ( ValidDate(10, 31, 2023) )
    cout << "Passed 10/31/2023 test" << endl;
  else
    cout << "Failed 10/31/2023 test" << endl;

  return 0;
}
