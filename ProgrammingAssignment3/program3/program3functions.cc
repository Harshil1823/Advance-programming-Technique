// Copyright 2023 Harshil
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include"program3functions.h"
using std::endl;
using std::cout;
using std::cin;


const int MAX_CHAR = 26;

void findMaxChars(char* fileName) {
    int freq[MAX_CHAR] = {0};  // Initialize frequency array to 0
    char ch;

    std::ifstream inFile(fileName);  // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }
    while (inFile >> ch) {  // Read file character by character
        if (isalpha(ch)) {  // Check if character is alphabetic
            freq[tolower(ch) - 'a']++;
            // Increment frequency of corresponding character
        }
    }
    // Find the maximum frequency
    int maxFreq = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }
    // Count the number of characters with the maximum frequency
    // this is used so I can print characters or character
    int maxCount1 = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == maxFreq) {
            maxCount1++;
        }
    }
    if (maxCount1 == 1) {
        cout << "Highest frequency character (appeared " <<
            maxFreq << " times in the file): ";
    } else {
        cout << "Highest frequency characters (appeared " <<
             maxFreq << " times in the file): ";
    }
    int maxCount2 = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
    if (freq[i] == maxFreq) {
        maxCount2++;
        if (maxCount2 == 1) {
            // cout << (char)('a' + i);
            cout << static_cast<char>(i + 'a');
        } else if (maxCount2 < maxCount1) {
            // cout << ", " << (char)('a' + i);
            cout << ", " << static_cast<char>(i + 'a');
        } else {
            // cout << " and " << (char)('a' + i);
            cout << " and " << static_cast<char>(i + 'a');
        }
        }
    }
}

void findMinChars(char* fileName) {
    int freq[MAX_CHAR] = {0};  // Initialize frequency array to 0
    char ch;
    int minFreq = 1000000;
    // Keep track of the number of characters with minimum frequency
    int numCharsWithMinFreq = 0;
    // Keep track of the number of characters printed so far
    int numCharsPrinted = 0;
    std::ifstream inFile(fileName);  // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }
    while (inFile >> ch) {  // Read file character by character
        if (isalpha(ch)) {  // Check if character is alphabetic
        // Increment frequency of corresponding character
            freq[tolower(ch) - 'a']++;
        }
    }
    inFile.close();  // Close input file

    // Find the minimum frequency of all characters
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] < minFreq) {
            minFreq = freq[i];
            numCharsWithMinFreq = 1;  // reset count
        } else if (freq[i] == minFreq) {
            numCharsWithMinFreq++;
        }
    }

    if (minFreq == 1) {
        cout << "Lowest frequency characters (appeared "
        << minFreq << " time in the file): ";
    } else if (minFreq == 0) {
        cout << "Lowest frequency characters (appeared "
        << minFreq << " times in the file): ";
    }
    // Keep track of whether any characters have been printed yet
    bool printedChar = false;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == minFreq) {
            std::cout << static_cast<char>(i + 'a');
            numCharsPrinted++;
            printedChar = true;
            if (numCharsPrinted < numCharsWithMinFreq - 1) {
                std::cout << ", ";
            } else if (numCharsPrinted == numCharsWithMinFreq - 1) {
                std::cout << ", and ";
            }
        }
    }
    if (!printedChar) {  // If no characters were printed, print "None"
        std::cout << "None";
    }
    std::cout << std::endl;
}

// this method increments the frequency of corresponing character
// calls printZeros to print them
void arrayWithFrequency(char* fileName) {
  int freq[MAX_CHAR] = {0};  // Initialize frequency array to 0
    char ch;

    std::ifstream inFile(fileName);  // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }

    while (inFile >> ch) {  // Read file character by character
        if (isalpha(ch)) {  // Check if character is alphabetic
            // Increment frequency of corresponding character
            freq[tolower(ch) - 'a']++;
        }
    }
    inFile.close();  // Close input file
    printZeros(freq);
}

void printInOrder(char* fileName) {
    int freq[MAX_CHAR] = {0};  // Initialize frequency array to 0
    char ch;

    std::ifstream inFile(fileName);  // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }

    while (inFile >> ch) {  // Read file character by character
        if (isalpha(ch)) {  // Check if character is alphabetic
            // Increment frequency of corresponding character
            freq[tolower(ch) - 'a']++;
        }
    }
    inFile.close();  // Close input file

    // Output sorted list of characters and their frequencies
    // cout << "Sorted list of characters and their frequencies:" << endl;
    cout << endl;
    for (int i = 0; i < MAX_CHAR; i++) {
        int maxFreq = -1, maxIndex = -1;
        for (int j = 0; j < MAX_CHAR; j++) {
            if (freq[j] > maxFreq) {
                maxFreq = freq[j];
                maxIndex = j;
            }
        }
        if (maxFreq == 0) {  // If all frequencies are 0, exit loop
            break;
        }
        char c = maxIndex + 'a';
        cout << c << ": " << maxFreq << endl;
        freq[maxIndex] = 0;  // Reset frequency of character
        for (int j = maxIndex+1; j < MAX_CHAR; j++) {
            if (freq[j] == maxFreq) {
                char c = j + 'a';
                cout << c << ": " << maxFreq << endl;
                freq[j] = 0;  // Reset frequency of character
            }
        }
    }
}

void printZeros(int freq[]) {
  bool zerosFound = false;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == 0) {
            if (!zerosFound) {
               // cout << "Characters that did not appear in the file:" << endl;
                zerosFound = true;
            }
            char c = i + 'a';
            cout << c << ": " << freq[i] << endl;
        }
    }
}

void printBarChart(char* fileName) {
    const int alphabetSize = 26;
    int freq[alphabetSize] = {0};
    char ch;

    std::ifstream inFile(fileName);  // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << std::endl;
        return;
    }

    while (inFile >> ch) {  // Read file character by character
        if (isalpha(ch)) {  // Check if character is alphabetic
        // Increment frequency of corresponding character
            freq[tolower(ch) - 'a']++;
        }
    }
    // Find maximum frequency to scale bars
    int maxFreq = 0;
    for (int i = 0; i < alphabetSize; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    // Print bars and axis labels
    for (int i = maxFreq; i > 0; i--) {
        // std::cout << i << " ";
        if (maxFreq > 9) {
            std::cout << std::setw(2) << i << " ";
        } else {
            std::cout << i << " ";
        }

        for (int j = 0; j < alphabetSize; j++) {
            if (freq[j] >= i) {
                std::cout << "* ";
            } else {
                std::cout << "  ";
            }
        }
        cout << std::endl;
    }

    if (maxFreq > 9) {
        // Print horizontal axis labels
        std::cout << "   ";
        for (int i = 0; i < alphabetSize; i++) {
            std::cout << static_cast<char>('a' + i) << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "  ";
        for (int i = 0; i < alphabetSize; i++) {
            std::cout << static_cast<char>('a' + i) << " ";
        }
        std::cout << std::endl;
    }
}
