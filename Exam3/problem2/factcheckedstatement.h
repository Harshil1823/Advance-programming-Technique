#ifndef FACTCHECKEDSTATEMENT_H
#define FACTCHECKEDSTATEMENT_H
#include"sentence.h"
#include <iomanip>
#include <sstream>
#include<string>
// Define the FactCheckedStatement class as a child of the Sentence class

namespace Project3Problem2 {
class FactCheckedStatement : public Sentence {
 public:
  // Add a constructor that takes a string parameter for the statement and
  // and a double parameter for the verified truth of the statement (a value
  // between 0 and 1, inclusive).
  // Provide a default argument of 0 for the double parameter.
  // If the string argument is not a valid statement (doesn't start with an
  // uppercase alphabetic character or doesn't end with a period), the statement
  // should default to "This is an unverified statement." 
  FactCheckedStatement(std::string text = "This is an unverified statement.",
   double truth = 0) : Sentence(text) , truth_(truth) {
    // Verify that the statement starts with an uppercase letter and ends with a period
    if (isupper(text[0]) && text.back() == '.') {
      Sentence::operator=(text);
    } else {
      Sentence::operator=("This is an unverified statement.");
    }
    // Ensure that the truth value is between 0 and 1 (inclusive)
    if (truth >= 0 && truth <= 1) {
      truth_ = truth;
    } else {
      truth_ = 0;
    }
  }

  // Overload the assignment operator.
  // If the string (the right operand) begins with an uppercase alphabetic
  // character and ends with a period, the FactCheckedStatement should be
  // set to that string and the data member holding the truth of the statement
  // should be set to 0.
  // If the right operand does not start with an uppercase alphabetic character
  // or it does not end with a period, the FactCheckedStatement object should
  // remain unchanged by the operation.
  FactCheckedStatement& operator=(const std::string& text) {
    if (!text.empty() && std::isupper(text[0]) && text.back() == '.') {
      Sentence::operator=(text);
      truth_ = 0.0;
    }
    return *this;
  }
  

  // Add an accessor function for the double data member holding the truth
  // of the statement.
  double GetTruth() const { return truth_;}

  // Add a mutator function for the double data member holding the truth of
  // the statement that takes a double parameter. 
  // If the argument sent to the function is a value between 0 and 1, inclusive,
  // the data member should be set to the argument's value.
  // If the argument sent to the function is not between 0 and 1, the data
  // member should remain unchanged by the function call.
  void SetTruth(double truth) {
    if (truth >= 0.0 && truth <= 1.0) {
      truth_ = truth;
    }
  }


  // Overload the stream insertion operator to output a FactCheckedStatement
  // object. The output should be the statement string followed by percent
  // truth in parenthesis.
  // For example, if the FactCheckedStatement x is 
  // "The third exam/project for CSCE240 is due by 11:59pm on May 2." with a
  // truth value of 1, then cout << x should print
  // "The third exam/project for CSCE240 is due by 11:59pm on May 2. (100% true)"
  // to the standard output device. 
  // See testoutput.cc and correctoutput.txt for additional examples of the
  // expected output for example FactCheckedStatement objects.
  friend std::ostream& operator<<(std::ostream& os, const FactCheckedStatement& statement) {
    std::ostringstream out;
    double tvalue = statement.GetTruth() < 0.0 ? 0.0 : statement.GetTruth();
    out << std::fixed << std::setprecision(0) << (tvalue * 100.0);
    std::string tru_perce = out.str() + "% true";
    os << statement.c_str() << " (" << tru_perce << ")";
    return os;
  }
 private:
  double truth_;
};  // end of class

}  // end of namespace

#endif