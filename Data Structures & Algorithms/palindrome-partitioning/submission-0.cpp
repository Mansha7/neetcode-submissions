class Solution {
public:
    // bool isPalindrome()
    bool canPlace(int start,int ind, string s){
        while(start<=ind){
            if(s[start]!=s[ind]) return false;
            start++; ind--;
        }
        return true;
    }
    void recur(int i, int j, string s, vector<string>&temp, vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        if(j>=s.size()) return;
        //take
        if (canPlace(i,j,s)){
            cout<<"calling"<<endl;
            temp.push_back(s.substr(i,j-i+1));
            recur(j+1,j+1,s,temp,ans);
            cout<<"removed"<<endl;
            temp.pop_back();
            // return;
        }
        //notake
        recur(i,j+1,s,temp,ans);
        return;
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        recur(0,0,s,temp,ans);
        return ans;
    }
};
