#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> Map;
        for (int itr = 0; itr < nums.size(); ++itr){
            Map.emplace(nums.at(itr), itr);
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i != j){
            int sum = nums[i] + nums[j];
            if (sum == target)
                return {Map[nums[i]], Map[nums[j]]};
            else if (sum > target)
                j--;
            else
                i++;
        }
        return {0, 0};
    }
};