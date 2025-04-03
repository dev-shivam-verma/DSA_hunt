class StockSpanner {
public:
    vector<int> prices;
    stack<int> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int n = prices.size();

        while (!stk.empty() && prices[stk.top()] <= price){
            stk.pop();
        }

        int lastBig = stk.empty()? -1: stk.top();
        int ans = (n - 1) - lastBig;

        stk.push(n - 1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */