#include "HashString.h"
int hashString(const std::string& str) {
    int hash = 0;
    for (char c : str) {
        hash = (hash * 31) + c;
    }
    return hash;
}