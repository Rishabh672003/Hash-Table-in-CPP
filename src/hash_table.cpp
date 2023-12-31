#define HT_PRIME_1 65'537
#define HT_PRIME_2 14'657

#include "hash_table.hpp"

#include <cmath>
#include <vector>

ht_hash_table::ht_hash_table(int size) : size(size) {
    hash_table.reserve(size);
    std::fill(hash_table.begin(), hash_table.begin() + size, nullptr);
}
ht_hash_table::~ht_hash_table() {
    for (int i = 0; i < size; ++i) {
        ht_item* current = hash_table[i];
        while (current != nullptr) {
            ht_item* prev = current;
            current = hash_table[++i];
            delete prev;
        }
    }
}

void ht_hash_table::insert(const std::string& key, const std::string& value) {
    ht_item* new_item = new ht_item(key, value);
    int index = ht_get_hash(new_item->key, this->size, 0);
    ht_item* curr_item = hash_table[index];
    if (curr_item == nullptr) {
        hash_table[index] = new_item;
        new_item = nullptr;
        this->count++;
    } else {
        int i = 1;
        while (curr_item != nullptr) {
            if (curr_item->key == key) {
                delete curr_item;
                hash_table[index] = new_item;
                new_item = nullptr;
                return;
            }
            index = ht_get_hash(new_item->key, this->size, i);
            curr_item = hash_table[index];
            i++;
        }
        hash_table[index] = new_item;
        this->count++;
    }
}

std::string ht_hash_table::search(const std::string& key) {
    int index = ht_get_hash(key, this->size, 0);
    ht_item* item = hash_table[index];
    int i = 1;
    while (item != nullptr) {
        if (item->key == key) {
            return item->value;
        }
        index = ht_get_hash(key, this->size, i);
        item = hash_table[index];
        i++;
    }
    return "Key not found";
}

void ht_hash_table::remove(const std::string& key) {

    int index = ht_get_hash(key, this->size, 0);
    ht_item* item = hash_table[index];
    int i = 1;
    while (item != nullptr) {
        if (item->key == key) {
            delete hash_table[index];
            hash_table[index] = nullptr;
        }
        index = ht_get_hash(key, this->size, i);
        item = hash_table[index];
        i++;
    }
    this->count--;
}

std::vector<ht_item*> ht_hash_table::getHashTable() const { return hash_table; }

constexpr int ht_hash_table::hash(const std::string& s, const int a,
                                  const int m) const {
    long hash = 0;
    const int len_s = s.size();
    for (int i = 0; i < len_s; i++) {
        hash += (long)std::pow(a, len_s - (i + 1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

constexpr int ht_hash_table::ht_get_hash(const std::string& s,
                                         const int num_buckets,
                                         const int attempts) const {
    const int hash_a = hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempts * (hash_b + 1))) % num_buckets;
}
