// Copyright 2023 Harshil
// Define the set Template class
#ifndef _SET_H_
#define _SET_H_
#include<iostream>
using std::cout;
using std::endl;
// set - unordered (order doesn't matter) collection of distinct (no dups)
//       objects
namespace csce240_set {

template<class TheType>
class Set {
 public:
  ~Set(){
    if (values_ != nullptr) {
        delete [] values_;
    }
  }

  // copy constructor
  Set(const Set& to_copy);
  //assignment operator
  Set operator = (const Set& to_copy);

  Set() {
    size_ = 0;
    values_ = nullptr;
  }
  void SetValues(int new_size, const TheType * new_values);
  void Print() const {
    cout << "{";
    for ( int i = 0; i < size_; ++i )
      cout << values_[i] << (i < size_ - 1 ? ", " : "");
    cout << "}"  << endl;
  }
 private:
  int size_;  // cardinality / cardinal number
  TheType * values_;  // points to block of memory with the values
                      // that are in the set
};  // class set

}  // namespace csce240_set
#endif