// Copyright 2023 bhipp
// tests LastDayOfMonth function
#include<iostream>
using std::cout;
using std::endl;
#include "program2functions.h"

int main() {
  if ( LastDayOfMonth(3) == 31 )
    cout << "Passed last day of March test" << endl;
  else
    cout << "Failed last day of March test" << endl;

  if ( LastDayOfMonth(6) == 30 )
    cout << "Passed last day of June test" << endl;
  else
    cout << "Failed last day of June test" << endl;

  if ( LastDayOfMonth(7) == 31 )
    cout << "Passed last day of July test" << endl;
  else
    cout << "Failed last day of July test" << endl;

  if ( LastDayOfMonth(8) == 31 )
    cout << "Passed last day of August test" << endl;
  else
    cout << "Failed last day of August test" << endl;

  if ( LastDayOfMonth(0) == 0  )
    cout << "Passed bad month test" << endl;
  else
    cout << "Failed bad month test" << endl;

  if ( LastDayOfMonth(2, 2032) == 29  )
    cout << "Passed last day of February leap year test" << endl;
  else
    cout << "Failed last day of February leap year test" << endl;

  if ( LastDayOfMonth(2, 2030) == 28  )
    cout << "Passed last day of February non-leap year test" << endl;
  else
    cout << "Failed last day of February non-leap year test" << endl;

  if ( LastDayOfMonth(2) == 0  )
    cout << "Passed last day of February missing year test" << endl;
  else
    cout << "Failed last day of February missing year test" << endl;

  return 0;
}
