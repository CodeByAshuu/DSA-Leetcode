class Solution {
public:

    int recur(int num){
        if(num == 0){
            return 0;
        }
        int product = 1;
        while(num > 0){
            product *= (num%10);
            num /= 10;
        }

        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(recur(n) % t == 0){
                return n;
            }

            n++;
        }
    }
};