class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> result;
        set<int> s;
        for(int x: nums1){
            s.insert(x);
        }

        for(int i=0; i<nums2.size(); i++){
            if(s.find(nums2[i]) != s.end()){
                result.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }

        return result;
        
    }
};