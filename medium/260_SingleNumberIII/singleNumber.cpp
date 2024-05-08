class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorb = 0;  // the result of a xor b;
        for (auto i : nums)
            aXorb ^= i;
        int lastBit;
        for (int i = 0; i < 32; ++i) {
            if (aXorb & (1 << i)) {
                lastBit = 1 << i;
                break;
            }
        }
        int intA = 0, intB = 0;
        for (auto i : nums) {
            if (i & lastBit)
                intA = intA ^ i;
        }
        intB = intA ^ aXorb;
        return vector<int>{intA, intB};  
    }
};