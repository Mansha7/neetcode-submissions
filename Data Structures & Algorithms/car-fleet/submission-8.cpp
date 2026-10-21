class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        int ans=0;
        int n = position.size();
        vector<pair<int,int>>arr;
        for(int i=0; i<n; i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(), arr.end());
        for(int i=arr.size()-1; i>=0; i--){
            double t= (double)(target-(arr[i].first))/arr[i].second;
            if(st.empty()) {
                st.push(t);
                continue;
            }
            if(st.top()<t){
                st.push(t);
            }
        }
        return st.size();
    }
};
