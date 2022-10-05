#ifndef UTILS_CPP
#define UTILS_CPP

#include "Utils.hpp"
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/ripemd.h>
#include <iomanip>
#include <sstream>
#include <string>

namespace Utils {

    std::string SHA256(const std::string str)
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

    std::string MD5(const std::string str)
    {
        unsigned char hash[MD5_DIGEST_LENGTH];
        MD5_CTX md5;
        MD5_Init(&md5);
        MD5_Update(&md5, str.c_str(), str.size());
        MD5_Final(hash, &md5);

        std::stringstream ss;
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }

    std::string RIPEMD160(const std::string str)
    {
        unsigned char hash[RIPEMD160_DIGEST_LENGTH];
        RIPEMD160_CTX ripemd160;
        RIPEMD160_Init(&ripemd160);
        RIPEMD160_Update(&ripemd160, str.c_str(), str.size());
        RIPEMD160_Final(hash, &ripemd160);

        std::stringstream ss;
        for (int i = 0; i < RIPEMD160_DIGEST_LENGTH; i++)
        {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }
}

#endif // UTILS_CPP
