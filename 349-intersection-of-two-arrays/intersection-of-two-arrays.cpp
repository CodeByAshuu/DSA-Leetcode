class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> mp;
        for(int x : nums1){
            mp[x]++;
        }

        for(int num : nums2){
            if(mp.count(num)){
                result.push_back(num);
                mp.erase(num);
            }
        }

        return result;
    }
};