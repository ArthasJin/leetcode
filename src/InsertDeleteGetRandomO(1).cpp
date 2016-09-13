class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> elements;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            cout << elements.size() << endl;
            return false;
        } else {
            elements.push_back(val);
            m[val] = elements.size() - 1;
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) != m.end()) {
            int index = m[val];
            elements[index] = elements.back();
            m[elements.back()] = index;
            elements.pop_back();
            m.erase(val);
            return true;
        } else {
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (elements.empty()) {
            return -1;
        }
        return elements[rand() % elements.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
