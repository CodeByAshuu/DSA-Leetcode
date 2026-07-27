class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        multiset<int> ms(nums1.begin(), nums1.end());
        for(int x : nums2){
            auto it = ms.find(x);
            if(it != ms.end()){
                result.push_back(x);
                ms.erase(it);
            }
        }

        return result;
    }
};