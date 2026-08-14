class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int>mpp;
        int j= 0;
        int maxL = 0;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            while(mpp[s[i]] > 2){
                mpp[s[j]]--;
                j++;
            }
            maxL = max(maxL, i-j+1);
        }

        return maxL;
    }
};