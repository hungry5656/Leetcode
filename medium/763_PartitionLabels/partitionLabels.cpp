class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i]] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_occurrence[s[i]]);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};

/** original solution
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> letterRange(26, {-1, -1});
        vector<int> retVec;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (letterRange[idx].first == -1) {
                letterRange[idx].first = i;  
            }
            letterRange[idx].second = i;
        }
        
        for (auto it = letterRange.begin(); it != letterRange.end(); ) {
            if (*it == std::make_pair(-1, -1)) {
                it = letterRange.erase(it);
            } else {
                ++it;
            }
        }

        sort(letterRange.begin(), letterRange.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b){ return a.first < b.first; });
        // for (int i = 0; i < letterRange.size(); ++i) {
        //     cout << letterRange[i].first << " " << letterRange[i].second << "\n";
        // }
        int currMax = letterRange[0].second, currMin = letterRange[0].first;
        for (int i = 1; i < letterRange.size(); ++i) {
            auto range = letterRange[i];
            if (range.first > currMax) {
                retVec.push_back(currMax - currMin + 1);
                currMin = range.first;
                currMax = range.second;
                continue;
            }
            currMin = min(range.first, currMin);
            currMax = max(range.second, currMax);
        }
        retVec.push_back(currMax - currMin + 1);
        return retVec;
    }
};
**/