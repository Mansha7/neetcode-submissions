class Solution {
public:
    bool areEqual(unordered_map<char,int>&hash1, unordered_map<char,int>&hash2){
        for(auto it: hash2){
            if(it.second != hash1[it.first]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>hash1;
        unordered_map<char,int>hash2;
        for(auto it: s1){
            hash1[it]++;
        }
        if(s2.size()<s1.size()) return false;
        int j=0;
        int i=0;
        while(j<s2.size()){
            hash2[s2[j]]++;
            if(j-i+1 ==  s1.size()){
                if(areEqual(hash1,hash2)) return true;
            }
            if(j-i+1< s1.size()) j++;
            else {
                hash2[s2[i]]--;
                i++;
                j++;
            }
        }
        return false;
    }
};
