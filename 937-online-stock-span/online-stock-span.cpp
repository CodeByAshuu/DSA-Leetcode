class StockSpanner {
public:
    stack<pair<int, int>> st;
    int day;
    StockSpanner() {
        day = 0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int span;
        if(st.empty()){
            span = day+ 1;
        }else{
            span = day - st.top().second;
        }

        st.push({price, day});
        day++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */