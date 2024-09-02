class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapM[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mapM.find(key) == mapM.end())
            return "";
        vector<pair<string, int>> &vec = mapM[key];
        int start = 0, end = vec.size() - 1;
        int maxAvailable = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (vec[mid].second == timestamp) {
                return vec[mid].first;
            } else if (vec[mid].second < timestamp) {
                maxAvailable = max(maxAvailable, mid);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (maxAvailable == -1)
            return "";
        return vec[maxAvailable].first;
    }

private:

    unordered_map<string, vector<pair<string, int>>> mapM;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */