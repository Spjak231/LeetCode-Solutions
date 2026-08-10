class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        // Frequency of s1
        for (char ch : s1) {
            mp1[ch]++;
        }

        int windowSize = s1.length();

        // First window
        for (int i = 0; i < windowSize; i++) {
            mp2[s2[i]]++;
        }

        if (mp1 == mp2)
            return true;

        // Sliding window
        for (int i = windowSize; i < s2.length(); i++) {

            // Add new character
            mp2[s2[i]]++;

            // Remove old character
            mp2[s2[i - windowSize]]--;

            // Remove character if frequency becomes 0
            if (mp2[s2[i - windowSize]] == 0) {
                mp2.erase(s2[i - windowSize]);
            }

            if (mp1 == mp2)
                return true;
        }

        return false;
    }
};