// Copyright 2023 Harhsil
#include"set.h"

namespace csce240_set {


// copy constructor
template<class TheType>
Set<TheType>::Set(const Set& to_copy) {
  size_ = 0;
  values_ = nullptr;
  SetValues(to_copy.size_, to_copy.values_);
}

//assignment operator
template<class TheType>
Set<TheType>Set<TheType>::operator = (const Set& to_copy) {
  SetValues(to_copy.size_, to_copy.values_);
  return *this;
}


// preconditions: values points to a block of memory with at least
//                size values
template<class TheType>
void Set<TheType>::SetValues(int new_size, const TheType * new_values) {
  if ( new_size < 0 )
        return;
  if ( new_size != size_ ) {
    if ( size_ != 0 )  // if (values_ != nullptr)
    delete [] values_;
    if ( new_size == 0 )
    values_ = nullptr;
    else
    values_ = new TheType[new_size];
  }
  size_ = new_size;
  int next_position = 0;
  // note: the new_values pointer may point to the values 
  // that duplicates, we're adding code to ensure that we don't 
  // include duplicate values in the set
  bool already_in_the_set = false;
  // outer loop moves through the values that we're looking to insert in the
  // set
  for ( int i = 0; i < size_; ++i ) {
    already_in_the_set = false;
    // linear search of values already in the set to ensure that there are 
    // no duplicates inserted
    for (int j = 0; j < i && !already_in_the_set; ++j) {
      already_in_the_set = new_values[i]== values_[j];
    }
    // if the new_value is new, we place it in the set
    if ( !already_in_the_set ) {
      values_[next_position++] = new_values[i];
    }
  }
  size_ = next_position;
}

}  // end of namespace