class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Store {position, speed}
        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position from closest to target to farthest
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double previousTime = 0;

        for (int i = 0; i < n; i++) {
            int pos = cars[i].first;
            int spd = cars[i].second;

            // Time needed to reach target
            double currentTime = (double)(target - pos) / spd;

            // Current car cannot catch the fleet ahead
            if (currentTime > previousTime) {
                fleets++;
                previousTime = currentTime;
            }
        }

        return fleets;
    }
};