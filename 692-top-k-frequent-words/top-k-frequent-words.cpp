class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for(string word : words){
            freq[word]++;
        }

        multimap<int, string, greater<int>> mp;
        for(auto it : freq){
            mp.insert({it.second, it.first});
        }

        vector<string> ans;
        for(auto it = mp.begin(); it != mp.end() && k > 0; ++it){
            ans.push_back(it->second);
            k--;
        }

        return ans;
    }
};