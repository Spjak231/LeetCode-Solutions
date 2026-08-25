class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());

        for (int multiple = k; ; multiple += k) {
            if (st.find(multiple) == st.end()) {
                return multiple;
            }
        }
    }
};
