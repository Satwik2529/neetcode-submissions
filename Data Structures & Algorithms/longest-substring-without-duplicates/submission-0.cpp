class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        int r = 0;
        int maxlen = 0;

        unordered_map<char, int> seen;

        while (r < s.size()) {

            if (seen.find(s[r]) == seen.end()) {

                seen[s[r]]++;

                int len = r - l + 1;
                maxlen = max(maxlen, len);

                r++;
            }
            else {

                seen.erase(s[l]);
                l++;
            }
        }

        return maxlen;
    }
};