class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 1;
        for(int num : nums){
            if(num == target){
                target++;
            }else if(num > target){
                return target;
            }
        }   
        return target;
    }
};