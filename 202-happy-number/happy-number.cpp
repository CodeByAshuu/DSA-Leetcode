class Solution {
public:
    int nextNum(int n){
        int sum = 0;
        while(n > 0){
            int digit = n%10;
            sum += digit*digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        set<int> s;
        while(n!=1){
            if(s.find(n) != s.end()){
                return false;
            }

            s.insert(n);
            n = nextNum(n);
        }

        return true;
    }
};