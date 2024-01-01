#ifndef HASH_TABLE
#define HASH_TABLE

#include <string>
#include <vector>

class ht_item {
  public:
    std::string key;
    std::string value;

  public:
    ht_item(const std::string& k, const std::string& v) : key(k), value(v) {}
};

class ht_hash_table {
  public:
    int size = 53;
    int count = 0;
    std::vector<ht_item*> hash_table;

  public:
    explicit ht_hash_table(int size = 53);
    ht_hash_table(const ht_hash_table&) = default;
    ht_hash_table(ht_hash_table&&) = delete;
    ht_hash_table& operator=(const ht_hash_table&) = default;
    ht_hash_table& operator=(ht_hash_table&&) = delete;
    explicit ht_hash_table(std::vector<ht_item*> hash_table)
        : hash_table(std::move(hash_table)) {}
    virtual ~ht_hash_table();

    // Hash table API
    void insert(const std::string& k, const std::string& v);
    std::string search(const std::string& key);
    void remove(const std::string& key);

  private:
    std::vector<ht_item*> getHashTable() const;
    constexpr int hash(const std::string& s, const int a, const int b) const;
    constexpr int ht_get_hash(const std::string& s, const int num_buckets,
                              const int attempts) const;
};

#endif
