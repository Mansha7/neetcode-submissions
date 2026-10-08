class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            while (hash.find(s[j]) != hash.end()) {
                hash.erase(s[i]);
                i++;
            }
            hash.insert(s[j]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
