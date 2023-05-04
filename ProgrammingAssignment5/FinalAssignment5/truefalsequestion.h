// Copyright 2023 Harshil
#ifndef _TRUEFLASEQUESTION_H_
#define _TRUEFLASEQUESTION_H_
#include<string>
#include"question.h"
using std::string;

namespace csce240_program5 {
// TrueFalseQuestion should be a child of the Question class
class TrueFalseQuestion : public Question {
 public:
  // Create an explicit constructor that allows the question and answer to be
  // initialized when an object is instantiated. The question and answer
  // parameters should have default arguments of "?" and true, respectively.
  explicit TrueFalseQuestion(string q = "?", bool a = true);
  // The class should have a private bool data member that holds whether the
  // answer to the question is true or false. Add an accessor and mutator
  // function for this data member
  bool GetAnswer() const {return answer_;}
  void SetAnswer(bool answer);
  // Add a Print function that takes a bool parameter: void Print(bool) const;
  // This fuction should create 1 or 2 lines of output to the standard output
  // device, using cout.
  // The first line of output should be "Question: " followed by the value of
  // the question data member.
  // If the Print function's argument is true, it should output a second line
  // that is "Correct Answer: " followed by "true" or "false" depending on the
  // value of the private data member.
  void Print(bool showAns) const;
 private:
  bool answer_;
};  // end of the class
}  // namespace csce240_program5
#endif  // _ACCT_HASHAH_DESKTOP_CSCE240_ASSIGNMENT5_TRUEFALSEQUESTION_H_
