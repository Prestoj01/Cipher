#include "Cipher.h"
#include "Queue.h"
#include <iostream>

//default cipher constructor
Cipher::Cipher() : keySize(0) {
    char defaultKey[] = "cpsc";
    char* defaultPtr = defaultKey;
    setCipher(4, defaultPtr);
}

//overloaded cipher constructor
Cipher::Cipher(int size, char* key) : keySize(0) {
    setCipher(size, key);
}

//function to fill the keyQueue with the elements from the input string
void Cipher::setCipher(int size, char* key) {
    keySize = size;
    keyQueue.clear();

    for (int i = 0; i < size; ++i) {
        keyQueue.enqueue(key[i]);
    }
}

//returns the cipher as a pointer to array converted from the keyQueue
char* Cipher::getCipher() {
    char* cipher = new char[keySize + 1];

    QNode* current = keyQueue.front;
    int i = 0;
    while (current != nullptr && i < keySize) {
        cipher[i++] = current->data;
        current = current->next;
    }

    return cipher;
}

//functions that takes in a string and returns an encoded version based on the keyQueue
std::string Cipher::encodeMessage(std::string in) {
    std::string encodedMessage;
    char* cipher = getCipher();
    
    //for loop to iterate through all chars in the string and lettershift them
    for (char c : in) {
        if (isalpha(c)) {
            char shifted = letterShift(c, keyQueue.front->data, false);
            encodedMessage += shifted;
            keyQueue.enqueue(keyQueue.front->data);
            char temp;
            keyQueue.dequeue(temp);
        }
    }
    
    //resets the cipher to orginal
    setCipher(keySize, cipher);

    return encodedMessage;
}

//function that takes in string and returns a decoded version based on keyQueue
std::string Cipher::decodeMessage(std::string in) {
    std::string decodedMessage;
    char* cipher = getCipher();

    //for loop to iterate through all chars of the string and lettershift them
    for (char c : in) {
        if (isalpha(c)) {
            char shifted = letterShift(c, keyQueue.front->data, true);
            decodedMessage += shifted;
            keyQueue.enqueue(keyQueue.front->data);
            char temp;
            keyQueue.dequeue(temp);
           
        }
    }

    //resets the cipher
    setCipher(keySize, cipher);

    return decodedMessage;
}

//function to shift the first letter based on the second normally or in reverse
char Cipher::letterShift(char l1, char l2, bool reverse) {
    const int alphabetSize = 26;
    const char baseChar = 'a';

    //sets both letters to lowercase
    l1 = std::tolower(l1);
    l2 = std::tolower(l2);

    //sets shift value and checks if shift is reverse or not
    int shift = l2 - baseChar + 1;
    if (reverse) {
        shift = -shift;
    }

    //calculates how many letters after 'a' the result will be
    int newVal = l1 - baseChar;
    newVal = (newVal + shift + alphabetSize) % alphabetSize;

    char result = baseChar + newVal;

    return result;
}