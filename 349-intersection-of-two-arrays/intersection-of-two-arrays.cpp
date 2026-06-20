class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(nums2[i] == nums1[j] && find(ans.begin(), ans.end(), nums2[i]) == ans.end()){
                    ans.push_back(nums2[i]);
                }
            }
        }

        return ans;
    }
};