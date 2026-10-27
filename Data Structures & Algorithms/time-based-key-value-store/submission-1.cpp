class TimeMap {
public:
//problem: need to have key to get the vlaue -> timestamp should be precomputed
//{key,timestamps} -> value?
//vector<timestamp>
    unordered_map<string,vector<pair<string,int>>>hash;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(hash.find(key)==hash.end()){
            // hash[key]=vector<pair<string,int>>;
            hash[key]={};
        }
        hash[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(hash.find(key)==hash.end()){
            return "";
        }
        auto& res = hash[key]; //vector in sorted inc order
        string ans = "";
        int l=0, h= res.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(res[mid].second>timestamp){
                h=mid-1;
            }else {
                ans=res[mid].first;
                l=mid+1;
            }
        }
        return ans;
    }
};
