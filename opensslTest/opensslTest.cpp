#include "opensslTest.h"

std::string getStrSha256(const std::string str)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str.c_str(), str.size());
	SHA256_Final(hash, &sha256);
	std::stringstream ss;
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	}
	return ss.str();
}

std::string getFileSha256(char* filePath)
{
	unsigned char c[SHA256_DIGEST_LENGTH];
	char *filename = filePath;
	int i;
	FILE *inFile;
	fopen_s(&inFile, filename, "rb");
	SHA256_CTX shaContext;
	int bytes;
	unsigned char data[1024];
	std::stringstream ss;

	if (inFile == NULL) {
		printf("%s can't be opened.\n", filename);
		return "ERROR";
	}

	SHA256_Init(&shaContext);
	while ((bytes = fread(data, 1, 1024, inFile)) != 0)
		SHA256_Update(&shaContext, data, bytes);
	SHA256_Final(c, &shaContext);
	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)c[i];
	}
	fclose(inFile);
	return ss.str();
}

std::string getFileMD5(char* filePath)
{
	unsigned char c[MD5_DIGEST_LENGTH];
	char *filename = filePath;
	int i;
	FILE *inFile;
	fopen_s(&inFile, filename, "rb");
	MD5_CTX mdContext;
	int bytes;
	unsigned char data[1024];
	std::stringstream ss;

	if (inFile == NULL) {
		printf("%s can't be opened.\n", filename);
		return "ERROR";
	}

	MD5_Init(&mdContext);
	while ((bytes = fread(data, 1, 1024, inFile)) != 0)
		MD5_Update(&mdContext, data, bytes);
	MD5_Final(c, &mdContext);
	for (i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)c[i];
	}
	fclose(inFile);
	return ss.str();
}


int main()
{
	std::string fileMD5 = getFileMD5("C:\\Users\\Cyp\\Desktop\\123.txt");
	std::string fileSHA256 = getFileSha256("C:\\Users\\Cyp\\Desktop\\123.txt");
	std::string strSHA256 = getStrSha256("Hello World");
}