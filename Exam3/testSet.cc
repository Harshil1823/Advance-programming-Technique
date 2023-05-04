#include <iostream>
#include <cassert>
#include "set.h"
using namespace Project3Problem3;
int main() {
    /*
    // Test case 1: sets with common elements
    Set<int> s1;
    int some_ints[6] = {1, 7, 22, 7, 22, 107};
    s1.SetValues(6, some_ints);
    Set<int> s2;
    int some_ints_again[5] = {1, 99, 101, 102, 104};
    s2.SetValues(6, some_ints_again);
    Set<int> intersection_set = s1.Intersection(s2);
    std::cout << "Test case 1: Expected output: {1}\n";
    std::cout << "Actual output: " << intersection_set.Print() << "\n";
    */
    
    Set<int> s1;
    int some_ints[6] = {1, 7, 22, 7, 22, 107};
    s1.SetValues(6, some_ints);

    Set<int> s2;
    int some_ints_again[5] = {1, 99, 101, 102, 104};
    s2.SetValues(5, some_ints_again);

    Set<int> intersection_set = s1.Intersection(s2);

    // check if the intersection_set contains only one element
    assert(intersection_set.GetCardinality() == 1);

    // check if the intersection_set contains the value 1
    assert(intersection_set.IsAnElementOf(1));

    // check if the intersection_set does not contain any other elements
    assert(!intersection_set.IsAnElementOf(7));
    assert(!intersection_set.IsAnElementOf(22));
    assert(!intersection_set.IsAnElementOf(99));
    assert(!intersection_set.IsAnElementOf(101));
    assert(!intersection_set.IsAnElementOf(102));
    assert(!intersection_set.IsAnElementOf(104));
    assert(!intersection_set.IsAnElementOf(107));
    return 0;
}

