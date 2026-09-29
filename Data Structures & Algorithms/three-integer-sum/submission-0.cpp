class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0, k=nums.size()-1;
        int target =0;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        while(i<k && i<(int)nums.size()-2){
            if (i > 0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }
            int j=i+1;
            k=nums.size()-1;
            while(j<k){
                if((nums[i]+nums[j]+nums[k])>target){
                    k--;
                }
                else if((nums[i]+nums[j]+nums[k])<target){
                    j++;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
            i++;

        }
        return ans;
    }
};
