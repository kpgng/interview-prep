// Design data structure w/ O(1) insert, delete, and get random

// Hash set (can't do random) -> hash map + vector (remove O(n)), swap w/ last + pop last (optimal)

// Time: O(1)
// Space: O(n)

class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        }
        v.push_back(val);
        m.insert({val, v.size() - 1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        
        int currValue = m[val];
        int lastValue = v.back();
        
        v[currValue] = lastValue;
        v.pop_back();
        
        m[lastValue] = currValue;
        m.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
