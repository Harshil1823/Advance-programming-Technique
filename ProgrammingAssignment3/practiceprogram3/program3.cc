#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using std::endl;
using std::cout;


void printInOrder(char *fileName);
void printZeros(int freq[]);
void arrayWithFrequency(char* fileName);
void findMaxChars(char* fileName);
void findMinChars(char* fileName);

const int MAX_CHAR = 26;

int main(int argc, char *argv[])
{
    findMaxChars(argv[1]);
    findMinChars(argv[1]);
    printInOrder(argv[1]);
    arrayWithFrequency(argv[1]);
    return 0;
}

void printInOrder(char* fileName)
{
    int freq[MAX_CHAR] = {0}; // Initialize frequency array to 0
    char ch;

    std::ifstream inFile(fileName); // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }

    while (inFile >> ch) { // Read file character by character
        if (isalpha(ch)) { // Check if character is alphabetic
            freq[tolower(ch) - 'a']++; // Increment frequency of corresponding character
        }
    }
    
    inFile.close(); // Close input file

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
        if (maxFreq == 0) { // If all frequencies are 0, exit loop
            break;
        }
        char c = maxIndex + 'a';
        cout << c << ": " << maxFreq << endl;
        freq[maxIndex] = 0; // Reset frequency of character
        for (int j = maxIndex+1; j < MAX_CHAR; j++) {
            if (freq[j] == maxFreq) {
                char c = j + 'a';
                cout << c << ": " << maxFreq << endl;
                freq[j] = 0; // Reset frequency of character
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

//this method increments the frequency of corresponing character
void arrayWithFrequency(char* fileName) {
  int freq[MAX_CHAR] = {0}; // Initialize frequency array to 0
    char ch;

    std::ifstream inFile(fileName); // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }

    while (inFile >> ch) { // Read file character by character
        if (isalpha(ch)) { // Check if character is alphabetic
            freq[tolower(ch) - 'a']++; // Increment frequency of corresponding character
        }
    }
    
    inFile.close(); // Close input file
    printZeros(freq);
}

void findMaxChars(char* fileName) {
    int freq[MAX_CHAR] = {0}; // Initialize frequency array to 0
    char ch;

    std::ifstream inFile(fileName); // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }
    while (inFile >> ch) { // Read file character by character
        if (isalpha(ch)) { // Check if character is alphabetic
            freq[tolower(ch) - 'a']++; // Increment frequency of corresponding character
        }
    }
    // Find the maximum frequency
    int maxFreq = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    cout << "Highest frequency characters (appeared " << maxFreq << " times in the file): ";
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == maxFreq) {
            if (count > 0) {
                if (count == maxCount - 1) {
                    cout << ", ";
                } else {
                    cout << " and ";
                }
            }
            cout << static_cast<char>('a' + i);
            count++;
            maxCount = count;
        }
    }
    cout << endl;
}

void findMinChars(char* fileName) {
    int freq[MAX_CHAR] = {0}; // Initialize frequency array to 0
    char ch;
    int minFreq = INT_MAX;

    std::ifstream inFile(fileName); // Open input file
    if (!inFile) {
        std::cerr << "Error: File could not be opened" << endl;
        return;
    }
    while (inFile >> ch) { // Read file character by character
        if (isalpha(ch)) { // Check if character is alphabetic
            freq[tolower(ch) - 'a']++; // Increment frequency of corresponding character
        }
    }
    inFile.close(); // Close input file

    // Find the minimum frequency of all characters
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] < minFreq) {
            minFreq = freq[i];
        }
    }

    cout << "Lowest frequency characters (appeared " << minFreq << " times in the file): ";
    bool first = true;
    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == minFreq) {
            if (!first) {
                if (count == 1) {
                    cout << " and ";
                }
                else {
                    cout << ", ";
                }
            }
            cout << (char)(i + 'a');
            first = false;
            count++;
        }
    }
    if (count > 2) {
        cout << " and ";
    }
    cout << "\n";
}
