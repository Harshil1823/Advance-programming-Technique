// Copyright 2023 Harshil
#ifndef _PROGRAM3FUNCTIONS_H_
#define _PROGRAM3FUNCTIONS_H_
// prints the alhabets in most frequent to list frequnet
void printInOrder(char *fileName);
// prints the alphabets that has zero freq
void printZeros(int freq[]);
// sorts the array and then calls print in order
void arrayWithFrequency(char* fileName);
// findMaxChars and how many time they appeared
void findMaxChars(char* fileName);
// find min charas and how many time the appeared
void findMinChars(char* fileName);
// prints the bar graph of how many time each character appeared
void printBarChart(char* fileName);

#endif