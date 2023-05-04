// Copyright 2023 Harshil
#include<string>
#include<iostream>
#include"truefalsequestion.h"
#include"question.h"
using std::cout;
using std::endl;
using std::string;

namespace csce240_program5 {
TrueFalseQuestion::TrueFalseQuestion(string q, bool a) :
                          Question(q), answer_(true) {
  SetAnswer(a);
}
void TrueFalseQuestion::SetAnswer(bool answer) {
  answer_ = answer;
}
void TrueFalseQuestion::Print(bool showAns) const {
  cout << "Question: " << GetQuestion() << endl;
  if (showAns) {
    cout << "Correct Answer: " << (answer_ ? "true" : "false") << endl;
  }
}
}  // namespace csce240_program5
