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
    virtual ~ht_hash_table();

    // Hash table API
    void insert(const std::string& k, const std::string& v);
    std::string search(const std::string& key);
    void remove(const std::string& key);

  private:
    std::vector<ht_item*> getHashTable() const;
    int hash(const std::string& s, const int a, const int b);
    int ht_get_hash(const std::string& s, const int num_buckets,
                    const int attempts);
};

#endif
