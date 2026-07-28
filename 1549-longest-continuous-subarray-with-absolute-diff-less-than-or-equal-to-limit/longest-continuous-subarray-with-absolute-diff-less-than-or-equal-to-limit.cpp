class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;

        int left = 0;
        int ans = 0;
        for(int right = 0; right < nums.size(); right++){
            ms.insert(nums[right]);

            while(*ms.rbegin() - *ms.begin() > limit){
                auto it = ms.find(nums[left]);
                ms.erase(it);

                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};