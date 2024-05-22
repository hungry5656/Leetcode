class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (idxMap.find(val) != idxMap.end()) return false;
        idxMap[val] = valVec.size();
        valVec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto itr = idxMap.find(val);
        if (itr == idxMap.end()) return false;
        // swap last element and delete the current val
        if (valVec.size() == 1) {
            valVec.clear();
            idxMap.clear();
            return true;
        }
        valVec[itr->second] = valVec.back();
        idxMap[valVec.back()] = itr->second;
        valVec.pop_back();
        idxMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return valVec[rand() % valVec.size()];
    }
private:
    vector<int> valVec;
    unordered_map<int, int> idxMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */