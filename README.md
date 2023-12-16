# Hash-Table-in-CPP

A very simple hash table implementation in CPP,

## Very simple API

```cpp
ht_hash_table hash_table;
hash_table.insert("hello", "world");
hash_table.insert("hi", "Rishabh");
print("{}\n", hash_table.search("hi"));
```

## Credit

I wrote this while following [How to write a Hash Table](https://github.com/jamesroutley/write-a-hash-table).
it was written in C so for learning purpose I converted it to CPP, logic is same but i have changed the implementation
to an OOPS one, with classes and other modern CPP features like using standard string and others
