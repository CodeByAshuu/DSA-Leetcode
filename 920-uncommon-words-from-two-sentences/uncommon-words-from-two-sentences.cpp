class Solution {
public:
    void countWords(string s, unordered_map<string, int>& freq){
        string word = "";

        for(char ch : s){
            if(ch == ' '){
                freq[word]++;
                word="";
            }else{
                word += ch;
            }
        }

        freq[word]++;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        countWords(s1, freq);
        countWords(s2, freq);

        vector<string> ans;
        for(auto it : freq){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};