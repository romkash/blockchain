#include <iostream>
#include <string>
#include <algorithm>

#include "code/core/Utils.hpp"


int main(int args, char** argv)
{
    std::string stringForHash = "string";
    int difficulty = 7;

    std::string target = "";
    for (unsigned i = 0; i < difficulty; i++)
    {
        target += std::to_string(0);
    }
    for (int i = 0;; i++)
    {
        std::string stringHash = Utils::SHA256(stringForHash + std::to_string(i));
        //std::cout << "Mining..." << stringHash << "\r";
        if (stringHash.substr(0, difficulty) == target)
        {
            std::cout << std::endl;
            std::cout << Utils::SHA256(stringForHash) << " with nonce: " << i << std::endl;
            break;
        }
    }

    return 0;
}


