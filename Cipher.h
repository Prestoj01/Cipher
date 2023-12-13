#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include "Queue.h"

class Cipher {
public:
    Cipher();
    Cipher(int size, char* key);
    void setCipher(int size, char* key);
    char* getCipher();
    std::string encodeMessage(std::string in);
    std::string decodeMessage(std::string in);
    static char letterShift(char l1, char l2, bool reverse);

private:
    Queue keyQueue;
    int keySize;
};

#endif
