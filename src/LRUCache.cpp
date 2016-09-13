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

class LRUCache {
private:
    int mCapacity;
    unordered_map<int, list<pair<int, int>>::iterator> mCache;
    list<pair<int, int>> mList;

    void update(int key, int value) {
        auto it = mCache[key];
        mList.erase(it);
        mList.push_front(make_pair(key, value));
        mCache[key] = mList.begin();
    }
public:
    LRUCache(int capacity) : mCapacity(capacity) {

    }

    int get(int key) {
        if (mCache.count(key)) {
            update(key, mCache[key]->second);
            return mCache[key]->second;
        } else {
            return -1;
        }
    }

    void set(int key, int value) {
        if (mCache.count(key)) {
            update(key, value);
        } else {
            mList.push_front(make_pair(key, value));
            mCache[key] = mList.begin();
            if (mCache.size() > mCapacity) {
                pair<int, int> last = mList.back();
                mCache.erase(last.first);
                mList.pop_back();
            }
        }
    }
};

