#include "hash_table.hpp"
#define HT_PRIME_1 151
#define HT_PRIME_2 173

#include <cmath>
#include <vector>

ht_hash_table::ht_hash_table(int size) : size(size) {
    hash_table.reserve(size);
}
ht_hash_table::~ht_hash_table() {
    for (std::vector<ht_item*>::size_type i = 0; i < hash_table.size(); i++) {
        delete hash_table[i];
    }
}

void ht_hash_table::insert(const std::string& key, const std::string& value) {
    ht_item* new_item = new ht_item(key, value);
    int index = ht_get_hash(new_item->key, this->size, 0);
    ht_item* curr_item = hash_table[index];
    if (curr_item == NULL) {
        hash_table[index] = new_item;
        this->count++;
    } else {
        int i = 1;
        while (curr_item != NULL) {
            if (curr_item->key == key) {
                delete curr_item;
                hash_table[index] = new_item;
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
    while (item != NULL) {
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
    while (item != NULL) {
        if (item->key == key) {
            delete hash_table[index];
        }
        index = ht_get_hash(key, this->size, i);
        item = hash_table[index];
        i++;
    }
    this->count--;
}

std::vector<ht_item*> ht_hash_table::getHashTable() const { return hash_table; }

int ht_hash_table::hash(const std::string& s, const int a, const int m) {
    long hash = 0;
    const int len_s = s.size();
    for (int i = 0; i < len_s; i++) {
        hash += (long)std::pow(a, len_s - (i + 1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

int ht_hash_table::ht_get_hash(const std::string& s, const int num_buckets,
                               const int attempts) {
    const int hash_a = hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempts * (hash_b + 1))) % num_buckets;
}
