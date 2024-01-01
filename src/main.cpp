#include "hash_table.hpp"
#include <fmt/core.h>

int main() {
    ht_hash_table hash_table;
    hash_table.insert("Hi", "Mushashi");
    hash_table.insert("Hi", "Mob");
    hash_table.remove("Hi");
    hash_table.insert("Hello", "World");
    fmt::print("{}\n", hash_table.search("Hi"));
    return 0;
}
