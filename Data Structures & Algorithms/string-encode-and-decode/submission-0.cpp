class Solution {
public:
    unordered_map<int,int>map; // store word_index -> length
    int length = 0;
    string encode(vector<string>& strs) {
        string comb = "";
        int len =0; int ind=0;
        for(auto it:strs){
            len = it.size();
            comb+=it;
            map[ind]=len;
            ind++;
        }
        length = strs.size();
        return comb;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int ind =0;
        int start = 0; int end = map[0];
        while(length--){
            string temp = s.substr(start,end);
            ans.push_back(temp);
            start=(start+end);
            ind++;
            end=map[ind];
        }
        return ans;
    }
};
