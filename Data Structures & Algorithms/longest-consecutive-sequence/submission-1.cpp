class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(auto it: nums){
            hash[it]++;
            // if(hash.find(it+1)!=hash.end())
        }
        int ans = 0;
        for(auto it: nums){
            int cur = it+1;
            int temp=1;
            if(hash.find(it-1)!=hash.end()) continue;
            while(hash.find(cur)!=hash.end() && hash[cur]>0){
                temp++;
                hash[cur]--;
                cur+=1;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};
