#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <openssl/sha.h>

using namespace std;

std::string sha256(const std::string str);

int main()
{
    std::string stringForHash = "string";
    int difficulty = 3;


    std::string target = "";
    for (unsigned i = 0; i < difficulty; i++)
    {
        target += std::to_string(0);
    }
    for (int i = 0;; i++)
    {
        std::string stringHash = sha256(stringForHash + std::to_string(i));
        std::cout << "Mining..." << stringHash << "\r";
        if (stringHash.substr(0, difficulty) == target)
        {
            std::cout << std::endl;
            std::cout << sha256(stringForHash) << " with nonce: " << i << std::endl;
            break;
        }
    }

    return 0;
}

std::string sha256(const std::string str)
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
