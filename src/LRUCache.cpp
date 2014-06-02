class LRUCache{
public:
    LRUCache(int capacity) {
        mCapacity = capacity;
    }

    int get(int key) {
        if (mCache.find(key) != mCache.end()) {
            update(key);
            return mCache[key]->value;
        }
        return -1;
    }

    void set(int key, int value) {
        if (mCache.find(key) != mCache.end()) {
            mCache[key]->value = value;
            update(key);
        } else {
            CacheEntry entry(key, value);
            if (mCache.size() == mCapacity) {
                CacheEntry lastEntry = mList.back();
                mCache.erase(lastEntry.key);
                mList.pop_back();
            }
            mList.push_front(entry);
            mCache[key] = mList.begin();
        }
    }
private:
    typedef struct CacheEntry {
        public:
        int key;
        int value;
        CacheEntry(int k, int v) :key(k), value(v) {}
    } CacheEntry;

    int mCapacity;
    unordered_map<int, list<CacheEntry>::iterator> mCache;
    list<CacheEntry> mList;

    void update(int key) {
        CacheEntry entry = *mCache[key];
        mList.erase(mCache[key]);
        mList.push_front(entry);
        mCache[key] = mList.begin();
    }
};

