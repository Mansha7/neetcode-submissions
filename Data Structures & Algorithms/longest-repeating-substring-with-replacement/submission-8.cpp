class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0;
        char maxc='#';
        int i=0, j=0;
        unordered_map<char,int>hash;
        int ans = 0;
        while(i<=j && j<s.size()){
            hash[s[j]]++;
            maxf=max(maxf,hash[s[j]]);
            // if(hash[s[j]]>=maxf){
            //     maxf = hash[s[j]];
            //     maxc=s[j];
            // }
            int count = j-i+1-maxf;
            while((j-i+1-maxf)>k){
                hash[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        } 
        return ans;
    }
};
