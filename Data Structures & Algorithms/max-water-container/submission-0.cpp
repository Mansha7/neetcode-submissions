class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j = heights.size()-1;
        int n = heights.size()-1;
        int ans = 0;
        while(i<j){
            ans=max(ans,(n*(min(heights[i],heights[j]))));
            if(heights[i]==min(heights[i],heights[j])){
                i++;
            }else{
                j--;
            }
            n--;
        }
        return ans;
    }
};
