#include "hash_table.hpp"
#include <algorithm>
#include <fmt/core.h>
#include <iostream>
#include <string>

using std::cin, std::endl, std::string, fmt::print;

int main() {
    ht_hash_table hash_table;
    hash_table.insert("hello", "world");
    hash_table.insert("hi", "Rishabh");
    print("{}\n", hash_table.search("hi"));
    return 0;
}
