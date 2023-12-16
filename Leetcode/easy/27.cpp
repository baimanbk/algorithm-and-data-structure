class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(auto &x: nums) {
            if(x == val) {
                n--;
                x = INT_MAX;
            }
        }
        sort(nums.begin(), nums.end());
        return n;
    }
};