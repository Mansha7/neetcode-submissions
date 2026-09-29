class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>arr1(n,0);
        vector<int>arr2(n,0);
        arr1[0]=height[0];
        arr2[n-1]=height[n-1];
        for(int i=1; i<n; i++){
            arr1[i]=max(height[i],arr1[i-1]);
        }
        for(int j=n-2; j>=0; j--){
            arr2[j]=max(height[j],arr2[j+1]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int sum = abs(min(arr1[i],arr2[i])-height[i]);
            ans+=sum;
        }
        return ans;
    }
};
