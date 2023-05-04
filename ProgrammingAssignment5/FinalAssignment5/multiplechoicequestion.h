// Copyright 2023 Harshil
#ifndef _MULTIPLECHOICEQUESTION_H_
#define _MULTIPLECHOICEQUESTION_H_
#include<string>
#include"question.h"
using std::string;
// MultipleChoiceQuestion should be a child of the Question class

namespace csce240_program5 {

class MultipleChoiceQuestion : public Question {
 public:
  // The class should have a private integer data member that holds the number
  // of answer choices for the question. Add an accessor and mutator function
  // for this data member
  int GetNumChoices() const { return num_choices_;}
  void SetNumChoices(int num);
  // The class should have a private string pointer data member that holds the
  // answer choices for the question.
  string* GetAnswerChoices() const {return answer_choices_;}
  void SetAnswerChoices(string *choices);
  // The class should have a private bool pointer data member that holds whether
  // each of the answer choices for the question is correct or not.
  bool* GetCorrectAnswer() const {return correct_answers_;}
  void SetCorrectAnswers(bool *correct);

  // Create an explicit constructor that allows the question, the number of
  // choices, the answer choices, and the answer correct/incorrect values to be
  // initialized when the object is instantiated. The parameters should have
  // default argments of "?", 0, nullptr, and nullptr, respectively.
  // If all but the last two arguments are provided, make all of the answer
  // choices the empty string "", and all of the correct/incorrect values true.
  // If all but the last argument is provided, default all correct/incorrect
  // values to true.
  // The prototype is provided below
  explicit MultipleChoiceQuestion(string = "?", int = 0, string *a = nullptr,
                                  bool *c = nullptr);

  // Create a copy constructor
  MultipleChoiceQuestion(const MultipleChoiceQuestion& other);
  // Overload the assignment operator
  MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion& other);
  // Create a destructor that frees up all dynamically allocated memory
  ~MultipleChoiceQuestion();
  // Add a SetAnswerChoices function that sets the number of choices, the values
  // of the answer choices, and the answer correct/incorrect values.
  // This function
  // will dynamically allocate and deallocate memory for the data members, as
  // necessary. The prototype is provided below
  void SetAnswerChoices(int numChoices, string* choices, bool* answers);

  // Add a Print function that takes a bool parameter: void Print(bool) const;
  // This fuction should send output to the standard output device, using cout.
  // The first line of output should be "Question: " followed by the value of
  // the question data member.
  // The next line of output should be "Answer Choices:"
  // The following lines should print each answer a separate line.
  // If the Print function's argument is true, each answer choice should be
  // followed by " - correct" or " - incorrect"
  void Print(bool show_answers) const;

 private:
  int num_choices_;
  string *answer_choices_;
  bool *correct_answers_;
};
}  // namespace csce240_program5
#endif  // _ACCT_HASHAH_DESKTOP_CSCE240_ASSIGNMENT5_MULTIPLECHOICEQUESTION_H_
