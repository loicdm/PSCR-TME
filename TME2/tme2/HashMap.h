//
// Created by loic on 27/09/23.
//

#ifndef TME2_HASHMAP_H
#define TME2_HASHMAP_H

#include <forward_list>
#include <vector>
#include <cstring>

namespace pr {
    template <typename K, typename V>
    class HashMap {
    public:
        class Entry {
        public:
            const K key;
            V val;
            Entry(const K& k, const V&v) : key(k), val(v) {}
        };
    private:
        typedef std::vector<std::forward_list<Entry>> buckets_t;
        buckets_t buckets;
        size_t sz;
    public:
        HashMap(size_t size) : sz(0), buckets(size) {}
        V * get(const K & key) {
            size_t h = std::hash<K>()(key);
            size_t target = h % buckets.size();
            for (Entry &e : buckets[target]) {
                if (e.key==key) {
                    return &e.val;
                }
            }
            return nullptr;
        }
        bool put(const K& key, const V& val) {
            size_t h = std::hash<K>()(key);
            size_t target = h % buckets.size();
            for (Entry &e : buckets[target]) {
                if (e.key==key) {
                    e.val = val;
                    return true;
                }
            }
            sz++;
            buckets[target].emplace_front(key,val);
            return false;
        }
        size_t size() const {
            return sz;
        }
    };


}




#endif //TME2_HASHMAP_H
