#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <string>

#include <openssl\sha.h>
#include <openssl\md5.h>

std::string getStrSha256(const std::string str);
std::string getFileSha256(char* filePath);
std::string getFileMD5(char* filePath);