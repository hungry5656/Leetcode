class Solution {
public:
    // floyd cycle detection algo
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
    
};

/* original solution: index bucket: O(n) time O(1) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            nums[idx] *= -1;
            if (nums[idx] > 0)
                return abs(nums[i]);
        }
        return -1;
    }
};
*/