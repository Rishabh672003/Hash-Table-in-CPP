#include "hash_table.hpp"
#include <algorithm>
#include <fmt/core.h>
#include <iostream>
#include <string>

using std::string, fmt::print;

int main() {
    ht_hash_table hash_table;
    hash_table.insert("Hello", "World");
    hash_table.insert("Hi", "Mushashi");
    hash_table.insert("Hi", "Mob");
    hash_table.remove("Hi");
    print("{}\n", hash_table.search("Hi"));
    return 0;
}
