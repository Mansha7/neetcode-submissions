class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>beg(nums.size()); //storing product of all elements before 
        vector<int>end(nums.size()); // storing prod of all elements after
        beg[0]=1;
        end[nums.size()-1]=1;
        for(int i=1; i<nums.size(); i++){
            beg[i]=beg[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2; i>=0; i--){
            end[i]=end[i+1]*nums[i+1];
        }
        vector<int>ans(nums.size());
        ans[0]=end[0];
        ans[nums.size()-1]=beg[nums.size()-1];
        for(int i=1; i<nums.size()-1; i++){
            ans[i]=beg[i]*end[i];
        }
        return ans;
    }
};
