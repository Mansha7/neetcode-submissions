class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0, j=0;
        int curmax = INT_MIN;
        priority_queue<pair<int,int>>pq; //max-heap, num-index
        while(j<nums.size()){
            pq.push({nums[j],j});
            if (j-i+1 == k){
                auto top = pq.top();
                ans.push_back(top.first);
                while(!pq.empty() && pq.top().second <=i){
                    pq.pop();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
