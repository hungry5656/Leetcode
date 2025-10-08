

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> retVec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                long int nTarget = (long int)target - nums[i] - nums[j];
                int low = j + 1, high = n - 1;
                while (low < high) {
                    if(nums[low] + nums[high] < nTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > nTarget){
                        high--;
                    }
                    else{
                        retVec.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return retVec;
    }
};

/* original solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> retVec;
        set<vector<int>> resSet;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long int sumN = (long int)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sumN == target){
                        resSet.insert({nums[i] , nums[j] , nums[k] , nums[l]});
                        k++;
                        l--;
                    } else if (sumN < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        for (auto cVec: resSet) {
            retVec.push_back(cVec);
        }
        return retVec;
    }
};
*/