class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int lSize = s.size();
        unordered_map<char, int> mpp;

        for (int r = 0; r < lSize; r++) {
            char c = s[r];
            while (mpp.find(c) != mpp.end()) {
                mpp.erase(s[l]);
                l++;
            }
            mpp[c]++;
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};