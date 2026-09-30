class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN, ans=0;
        for(int i=0; i<prices.size()-1; i++){
            int buy = prices[i];
            for(int j=i+1; j<prices.size(); j++){
                int sell = prices[j];
                profit = (sell-buy);
                ans=max(ans,profit);
            }
        }
        return ans;
    }
};
