// Copyright 2023 Harshil
#include<iostream>
#include"question.h"
#include"shortanswerquestion.h"
using std::cout;
using std::endl;

namespace csce240_program5 {

ShortAnswerQuestion::ShortAnswerQuestion(string q, string a) :
                                    Question(q), answer_("") {
  SetAnswer(a);
}

void ShortAnswerQuestion::SetAnswer(string answer) {
  answer_ = answer;
}

void ShortAnswerQuestion::Print(bool showAns) const {
  cout << "Question: " << GetQuestion() << endl;
  if (showAns) {
    cout << "Correct Answer: " << answer_ << endl;
  }
}

}  // namespace csce240_program5
