
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int j = 0;
        for(int i = 0 ; i < nums.size(); i++){
            for(j = i + 1; j < nums.size(); j++){
                if(nums[j]+ nums[i] == target){
                    return {j,i};
            }      
        }
        }

        return {};
    }
};