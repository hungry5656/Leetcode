class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        if(n < 2 || mini == maxi) return 0;

        vector<int> bucketLargest(n,INT_MIN);
        vector<int> bucketSmallest(n,INT_MAX);

        for (int i = 0; i < n; ++i) {
            int index = (((nums[i] - mini) * (n - 1)) / (maxi - mini));
            bucketLargest[index] = max(bucketLargest[index], nums[i]);
            bucketSmallest[index] = min(bucketSmallest[index], nums[i]);
        }

        int retVal = 0;
        int p = mini;
        for(int i = 0; i < n; ++i){
            if(bucketSmallest[i] == INT_MAX) continue;
            retVal = max(retVal,bucketSmallest[i] - p);
            p = bucketLargest[i];
        }

        return retVal;
    }
};

/* original solution: sort and greedy O(nlogn) time O(1) space
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int retGap = 0;
        for (int i = 1; i < nums.size(); ++i)
            retGap = max(retGap, nums[i] - nums[i - 1]);
        return retGap;
    }
};
*/