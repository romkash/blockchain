#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>

class Block {
private:
    uint64_t version = 0;
    int difficultyIndex = 0;
    std::string prevBlockHash;
    std::string merkleRootHash;
    std::string hash;
    std::string nonce;
    std::vector<std::string> timestamp;
    std::vector<std::string> transactions;

public:
    Block() = default;
    Block()
};

#endif // BLOCK_HPP
