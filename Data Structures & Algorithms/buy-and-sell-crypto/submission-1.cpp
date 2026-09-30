class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN, ans=0;
        int i=0, j=i+1;
        while(i<j && j<prices.size()){
            int buy = prices[i];
            if(prices[j]>buy){
                profit=(prices[j]-buy);
                ans=max(ans,profit);
                j++;
                // continue;
            }else{
                i=j;
                j=i+1;
            }
        }
        return ans;
    }
};
