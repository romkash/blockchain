#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace Utils {

    std::string SHA256(const std::string str);
    std::string MD5(const std::string str);
    std::string RIPEMD160(const std::string str);
}

#endif // UTILS_HPP
