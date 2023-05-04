// Copyright 2023 Harshil
#include<iostream>
#include"multiplechoicequestion.h"
#include"question.h"
using std::cout;
using std::endl;

namespace csce240_program5 {

// Constructor
MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int n,
                                     string *a, bool *c)
    : Question(q), num_choices_(n), answer_choices_(nullptr),
      correct_answers_(nullptr) {
  if (n > 0) {
    answer_choices_ = new string[n];
    correct_answers_ = new bool[n];
    for (int i = 0; i < n; i++) {
      answer_choices_[i] = "";
      correct_answers_[i] = true;
    }
    if (a != nullptr) {
      for (int i = 0; i < n; i++) {
        answer_choices_[i] = a[i];
      }
    }
    if (c != nullptr) {
      for (int i = 0; i < n; i++) {
          correct_answers_[i] = c[i];
      }
    }
  }
}

// destructor
MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  delete [] answer_choices_;
  delete [] correct_answers_;
}

// print function
void MultipleChoiceQuestion::Print(bool show_answers) const {
  cout << "Question: " << GetQuestion() << endl;
  cout << "Answer Choices:" << endl;
  for (int i = 0; i < num_choices_; i++) {
    cout << answer_choices_[i];
    if (show_answers) {
      if (correct_answers_[i]) {
        cout << " - correct" << endl;
      } else {
        cout << " - incorrect" << endl;
      }
    } else {
      cout << endl;
    }
  }
}

// set answer choices
void MultipleChoiceQuestion::SetAnswerChoices(int numChoices,
                        string* choices, bool* answers) {
  if (numChoices > 0) {
    // delete any prev allocated memory
    delete [] answer_choices_;
    delete [] correct_answers_;
    // Allocate new memory
    answer_choices_ = new string[numChoices];
    correct_answers_ = new bool[numChoices];
    for (int i = 0; i < numChoices; i++) {
      answer_choices_[i] = choices[i];
      correct_answers_[i] = answers[i];
    }
    // at the end set the num_choices_ to what is was
    // asked to set it too
    num_choices_ = numChoices;
  }
}
// copy constructor
MultipleChoiceQuestion::MultipleChoiceQuestion
              (const MultipleChoiceQuestion& other)
    : Question(other.GetQuestion()), num_choices_(other.GetNumChoices()),
      answer_choices_(nullptr), correct_answers_(nullptr) {
    if (num_choices_ > 0) {
        answer_choices_ = new string[num_choices_];
        correct_answers_ = new bool[num_choices_];
        for (int i = 0; i < num_choices_; i++) {
            answer_choices_[i] = other.answer_choices_[i];
            correct_answers_[i] = other.correct_answers_[i];
        }
    }
}

// overload the = operator
MultipleChoiceQuestion& MultipleChoiceQuestion::operator=
                    (const MultipleChoiceQuestion& other) {
  // check if this other objectis the same
  // if it is then return this and if not then perform
  // the following
  if (this != &other) {
    // Call the base class assignment operator to copy the question string
    Question::operator=(other);
    // Copy the answer choices and correct/incorrect values
    delete[] answer_choices_;
    delete[] correct_answers_;
    num_choices_ = other.num_choices_;
    answer_choices_ = new string[num_choices_];
    correct_answers_ = new bool[num_choices_];
    for (int i = 0; i < num_choices_; i++) {
      answer_choices_[i] = other.answer_choices_[i];
      correct_answers_[i] = other.correct_answers_[i];
    }
  }
  return *this;
}

void MultipleChoiceQuestion::SetNumChoices(int num) {
  if (num > 0) {
    num_choices_ = num;
  }
}

void MultipleChoiceQuestion::SetAnswerChoices(string *choices) {
  answer_choices_ = choices;
}

void MultipleChoiceQuestion::SetCorrectAnswers(bool *correct) {
  correct_answers_ = correct;
}
}  // namespace csce240_program5
