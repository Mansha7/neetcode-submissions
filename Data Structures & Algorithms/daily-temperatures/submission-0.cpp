class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans(temp.size(),0);
        stack<pair<int,int>>st; //{ele,ind}
        int i=0;
        while(i<temp.size()){
            // int j=i;
            while(!st.empty() && st.top().first< temp[i]){
                ans[st.top().second]=i-st.top().second;
                st.pop();
                // j++;
            }
            st.push({temp[i],i});
            i++;
        }
        return ans;
    }
};
