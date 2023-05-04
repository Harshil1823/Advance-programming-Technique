// Copyright 2023 Harshil
#ifndef _SHORTANSWERQUESTION_H_
#define _SHORTANSWERQUESTION_H_
#include<string>
#include"question.h"
using std::string;

namespace csce240_program5 {

class ShortAnswerQuestion : public Question {
 public:
  // Create an explicit constructor that allows the question and answer to be
  // initialized when instantiated. The question and answer parameters should
  // have default arguments of "?" and "", respectively.
  explicit ShortAnswerQuestion(string q = "?", string a = "");
  // The class should have a private string data member that holds the correct
  // answer to the question. Add an accessor and mutator function for this data
  // member
  void SetAnswer(string answer);
  string GetAnswer() const {return answer_;}

  // Add a Print function that takes a bool parameter: void Print(bool) const;
  // This fuction should create 1 or 2 lines of output to the standard output
  // device, using cout.
  // The first line of output should be "Question: " followed by the value of
  // the question data member.
  // If the Print function's argument is true, it should output a second line
  // that is "Correct Answer: " followed by the value of the correct answer
  // private data member.
  void Print(bool showAns) const;
 private:
  string answer_;
};

}  // namespace csce240_program5
#endif  // _ACCT_HASHAH_DESKTOP_CSCE240_ASSIGNMENT5_SHORTANSWERQUESTION_H_
