class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // row -> bitmask of reserved seats
        unordered_map<int, int> mp;

        // Store reserved seats using bits
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Masks for the three possible groups
        int left = 0;    // seats 2,3,4,5
        int middle = 0; // seats 4,5,6,7
        int right = 0;  // seats 6,7,8,9

        for (int i = 2; i <= 5; i++) {
            left |= (1 << i);
        }

        for (int i = 4; i <= 7; i++) {
            middle |= (1 << i);
        }

        for (int i = 6; i <= 9; i++) {
            right |= (1 << i);
        }

        int ans = 0;

        // Rows with reservations
        for (auto &[row, mask] : mp) {

            bool canLeft = ((mask & left) == 0);
            bool canMiddle = ((mask & middle) == 0);
            bool canRight = ((mask & right) == 0);

            // If both outer blocks are available,
            // we can place 2 groups.
            if (canLeft && canRight) {
                ans += 2;
            }
            // Otherwise, if any one block is available,
            // we can place 1 group.
            else if (canLeft || canMiddle || canRight) {
                ans += 1;
            }
        }

        // Rows without any reserved seats can always
        // accommodate 2 groups.
        int emptyRows = n - mp.size();

        ans += emptyRows * 2;

        return ans;
    }
};