class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();
        nth_element(nums.begin() , nums.begin() + n/2 , nums.end());
        int mid = *(nums.begin() + n/2);
        
        #define arr(i) nums[(1+2 * (i)) % (n|1)]
        
        int i=0; 
        int j=0;
        int k=n-1;
        
        while(j <= k){
            
            if(arr(j) > mid){
                swap(arr(i++),arr(j++));
            }
            else if(arr(j) < mid){
                swap(arr(j) , arr(k--));
            }
            else{
                j++;
            }
        }
    }
};