class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        int left = 0;
        int ones = 0;

        map<int, vector<string>> mp;

        for (int right = 0; right < n; right++) {

            // Add s[right]
            if (s[right] == '1') {
                ones++;
            }

            // If we have more than k ones,
            // move left until we have at most k ones
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Now if exactly k ones,
            // make the window as small as possible
            if (ones == k) {

                while (s[left] == '0') {
                    left++;
                }

                string cur = s.substr(left, right - left + 1);

                mp[cur.length()].push_back(cur);
            }
        }

        // No beautiful substring
        if (mp.empty()) {
            return "";
        }

        // map keeps lengths sorted
        int shortestLength = mp.begin()->first;

        // Lexicographically smallest among shortest
        return *min_element(
            mp[shortestLength].begin(),
            mp[shortestLength].end()
        );
    }
};