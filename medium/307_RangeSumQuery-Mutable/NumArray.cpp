class NumArray {
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        seg.resize(2 * size + 1);
        for (int i = 0; i < nums.size(); ++i) {
            seg[size + i] = nums[i];
        }
        for (int i = size - 1; i > 0; --i) {
            seg[i] = seg[2 * i] + seg[2 * i + 1];
        }
    }
    
    void update(int index, int val) {
        index += size;
        seg[index] = val;
        while (index > 1) {
            index /= 2;
            seg[index] = seg[2 * index] + seg[2 * index + 1];
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        left += size;
        right += size;
        while (left <= right) {
            if (left & 1) {
                sum += seg[left];
                left++;
            }
            if (!(right & 1)) {
                sum += seg[right];
                right--;
            }

            left = left >> 1;
            right = right >> 1;
        }
        return sum;
    }
private:
    vector<int> seg;
    int size;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */