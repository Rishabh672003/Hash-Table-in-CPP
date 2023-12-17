#include "hash_table.hpp"
#include <fmt/core.h>

using std::string, fmt::print;

int main() {
    ht_hash_table hash_table;
    hash_table.insert("Hi", "Mushashi");
    hash_table.insert("Hi", "Mob");
    hash_table.remove("Hi");
    hash_table.insert("Hello", "World");
    print("{}\n", hash_table.search("Hi"));
    return 0;
}
