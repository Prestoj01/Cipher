/*Preston Johnson
CPSC 1071: 05
Team Number 2 CTRL+C CTRL+V
Date: 11/11/2023*/

#include "Queue.h"
#include "Cipher.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*Purpose of this code is to create a ceaser cipher that uses a queue to hold its key. The code takes in a key and then can encode and decode
any input based on that said key. This project serves as a basic encryption and decription tool using a ceasar cipher.*/

int main() {
    //initialize varibables
    char* key;
    char choice;
    string input;

    //get input
    cout << "Type in the word to use as the key: ";
    cin >> input;
    
    //create key array based on input
    char keyArray[input.length() + 1];
    int arraySize = sizeof(keyArray);

    for (int i = 0; i < arraySize; i++) {
        keyArray[i] = input[i];
    }
    
    //pointer to keyArray
    key = keyArray;

    cout << "\nKey: " << key << endl;

    //creates cipher using length of input and key array
    Cipher cipher(input.length(), key);

    //while loop to determine when to stop program
    while (choice != 'q') {
        cout << "[e] encode with that key" << endl;
        cout << "[d] decode with that key" << endl;
        cout << "[q] quit" << endl;

        cin >> choice;

        //choices given to user
        if (choice == 'e') {
            string encodePrompt;

            cout << "Enter what to encode: ";
            cin >> encodePrompt;

            cout << "result: " << cipher.encodeMessage(encodePrompt) << "\n" << endl;
        }
        else if (choice == 'd') {
            string decodePrompt;

            cout << "Enter what to decode: ";
            cin >> decodePrompt;

            cout << "result: " << cipher.decodeMessage(decodePrompt) << "\n" << endl;
        }
        else if (choice != 'q') {
            cout << "Ivalid entry, please try again" << endl;
        }
    }
}