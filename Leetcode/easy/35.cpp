class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        if(target > nums[r-1]){
            return r;
        }
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                return m;
            }
            else if(nums[m] > target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return l;
        // if(nums.size() == 2){
        //     if(x == nums.size()-1){
        //         return x+1;
        //     }
        //     else{
        //         return x;
        //     }
        // }
    }

};