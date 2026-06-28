class Solution {
public:
    void build(string &word, int k){
        if(word.length() >= k){
            return;
        }

        string next = "";
        for(char ch: word){
            if(ch == 'z'){
                next += 'a';
            }else{
                next+= ch + 1;
            }
        }

        word+=next;
        build(word, k);
    }


    char kthCharacter(int k) {
        string word = "a";
        build(word, k);
        return word[k-1];
    }
};