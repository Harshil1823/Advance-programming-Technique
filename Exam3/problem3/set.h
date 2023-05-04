// Copyright 2023 CSCE240 (bhipp)
// Harshil Shah

// Define our Set template class
// set - unordered (the order of the values doesn't matter) collection of
//       distinct objects (since the objects can be of any type - we'll make
//       this a template class
#ifndef _SET_H_
#define _SET_H_

#include<iostream>
#include<algorithm>
#include <set>
using std::cout;
using std::endl;

namespace Project3Problem3 {

template<class TheType>
class Set {
 public:
  // default constructor
  explicit Set(int size = 0, const TheType * values = nullptr) {
    size_ = 0;
    values_ = nullptr;
    SetValues(size, values);
  }

  // copy constructor
  Set(const Set& to_copy) {
    size_ = 0;
    values_ = nullptr;
    SetValues(to_copy.size_, to_copy.values_);
  }

  // destructor
  ~Set() {
    if ( values_ != nullptr )
      delete [] values_;
  }

  // assignment operator
  Set& operator = (const Set& to_copy) {
    SetValues(to_copy.size_, to_copy.values_);
    return *this;  // return the newly updated object the operator
                  // was called on
  }

  // SetValues function
  // pre-conditions the second argument points to a block of at least
  //                new_size TheTypes (currently not checking for
  //                duplicates)
  void SetValues(int new_size, const TheType * new_values) {
    if ( new_size < 0 )
      return;
    if ( new_size != size_ ) {
      if ( size_ != 0 )
        delete [] values_;
      if ( new_size == 0 )
        values_ = nullptr;
      else
       values_ = new TheType[new_size];
    }
    size_ = new_size;
    int position = 0;
    for ( int i = 0; i < size_; ++i ) {
      bool already_in_there = false;
      for ( int j = 0; j < position && !already_in_there; ++j )
         already_in_there = values_[j] == new_values[i];
      if ( !already_in_there )
        values_[position++] = new_values[i];
     }
     size_ = position;
  }

  // Print function to display values at the standard output device
  void Print() const {
    cout << "{";
    for ( int i = 0; i < size_; ++i )
      cout << values_[i] << (i < size_ - 1 ? ", " : "");
    cout << "}" << endl;
  }

  // Is a Subset of
  bool IsASubset(const Set& possible_subset) const {
    bool answer = true;
    int i = 0;
    while ( answer && i < possible_subset.size_ ) {
      answer = false;
      for ( int j = 0; j < size_ && !answer; ++j ) {
        answer = values_[j] == possible_subset.values_[i];
      }
      ++i;
    }
    return answer;
  }

  // is an element of
  bool IsAnElementOf(const TheType& the_value) const {
    bool found = false;
    int i = 0;
    while ( i < size_ && !found )
      found = values_[i++] == the_value;
    return found;
  }

  int GetCardinality() const { return size_; }

  // Implement the Intersection function whose prototype is given below.
  // The function should return the intersection of the two sets. Recall, the
  // intersection of two sets is the set of all elements the two sets have in
  // common.
  // For example, if set1 is the set { 1, 8, 2, 6, 3 } and
  //                 set2 is the set { 6, 4, 1 } then
  //                 set1.Intersection(set2) should return the set { 1, 6 }
  // For example, if set1 is the set { 'a', 'c' } and
  //                 set2 is the set { 'r, 'm', 'l', 't' } then
  //                 set1.Intersection(set2) should return the set {}
  // For example, if set1 is the set { 9.8, 2.7 } and
  //                 set2 is the set { 2.7, 4.16, 9.8 } then
  //                 set1.Intersection(set2) should return the set { 9.8, 2.7 }
  // function prototype: Set Intersection(const Set& right) const;
  Set Intersection(const Set& right) const {
    Set intersection;
    const int maxValues = 100000; // maximum number of elements we can store in tempValues
    TheType tempValues[maxValues];
    int count = 0;
    for (int i = 0; i < size_; ++i) {
     if (right.IsAnElementOf(values_[i])) {
       tempValues[count] = values_[i];
       ++count;
     }
    }
    intersection.SetValues(count, tempValues);
    return intersection;
  }
  // The == operator should return true if the set on the left on the left
  // and the set on the right contain exactly the same elements (values) and
  // false otherwise.
  // For example, if set1 is the set {1, 2, 3} and
  //                 set2 is the set {2, 1, 3}
  //                 set1 == set2 should return true
  // For example, if set1 is the set {'a', 'b', 'x'} and
  //                 set2 is the set {'x', 'b'}
  //                 set1 == set2 should return false
  // prototype: bool operator == (const Set& right) const;
  bool operator==(const Set& right) const {
    if (size_ != right.size_) {
      return false;
    }
    for (int i = 0; i < size_; ++i) {
      if (!right.IsAnElementOf(values_[i])) {
        return false;
      }
    }
    for (int i = 0; i < right.size_; ++i) {
      if (!IsAnElementOf(right.values_[i])) {
        return false;
      }
    }
    return true;
  }
 private:
  int size_;  // cardinality / cardinal number
  TheType * values_;
};  // class Set

}  // namespace Project3Problem3

#endif  // _SET_H







/*
  Set Intersection(const Set& right) const {
    Set intersection_set;
    TheType *intersection_values = new TheType[size_ + right.size_];
    TheType *end_ptr = std::set_intersection(values_, values_ + size_, right.values_, 
                                    right.values_ + right.size_, intersection_values);
    for (TheType *ptr = intersection_values; ptr != end_ptr; ++ptr) {
        intersection_set.Insert(*ptr);
    }
    delete[] intersection_values;
    return intersection_set;
  }
  void Insert(const TheType& value) {
    // First, check if the value is already in the set
    if (std::binary_search(values_, values_ + size_, value)) {
      return;
    }
    // If not, insert it at the correct position
    TheType* new_values = new TheType[size_ + 1];
    std::copy(values_, values_ + size_, new_values);
    new_values[size_] = value;
    std::sort(new_values, new_values + size_ + 1);
    delete[] values_;
    values_ = new_values;
    ++size_;
  }
*/