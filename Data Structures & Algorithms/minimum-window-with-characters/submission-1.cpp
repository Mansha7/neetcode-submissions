class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        unordered_map<char, int> window;

        int required = need.size();
        int formed = 0;

        int i = 0;
        int bestStart = 0;
        int minLen = INT_MAX;

        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            while (formed == required) {
                int len = j - i + 1;

                if (len < minLen) {
                    minLen = len;
                    bestStart = i;
                }

                char left = s[i];
                window[left]--;

                if (need.count(left) &&
                    window[left] < need[left]) {
                    formed--;
                }

                i++;
            }
        }

        return minLen == INT_MAX
                   ? ""
                   : s.substr(bestStart, minLen);
    }
};