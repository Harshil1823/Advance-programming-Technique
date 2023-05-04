#ifndef PROBLEM_H
#define PROBLEM_H
namespace Project3Problem1 {
  template <typename T>
  T Median (const T* array, int size) {
    // copy array so originizal is not modified 
    // hence it's constant 
    T* copy = new T[size];
    for (int i = 0; i < size; i++) {
      copy[i] = array[i];
    }
    // Sort the copy array from least to greatest
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
          if (copy[j] < copy[i]) {
            T temp = copy[i];
            copy[i] = copy[j];
            copy[j] = temp;
          }
        }
    }
    // now let's get the median
    T median = size % 2 == 0 ? (copy[size/2 - 1] + copy[size/2]) / 2 : copy[size/2];
    delete[] copy;
    return median;
  }
}  // end of namespace
#endif