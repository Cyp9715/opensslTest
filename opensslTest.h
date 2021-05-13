#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include <openssl/sha.h>
#include <openssl/md5.h>

std::string getMD5FileHash(char* filePath);
std::string getSha256FileHash(char* filePath);
std::string getSha256(std::string str);