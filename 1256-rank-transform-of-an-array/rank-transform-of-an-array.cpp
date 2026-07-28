class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        multiset<int> ms(arr.begin(), arr.end());
        
        unordered_map<int, int> rank;
        int r = 1;

        for(int x: ms){
            if(rank.find(x) == rank.end()){
                rank[x] = r;
                r++;
            }
        }

        vector<int> result;
        for(int x : arr){
            result.push_back(rank[x]);
        }

        return result;
    }
};