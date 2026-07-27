class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int longest = 0;
        for(int x : s){
            if(s.find(x-1) == s.end()){
                int current = x;
                int length = 1;


                while(s.find(current+1) != s.end()){
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};