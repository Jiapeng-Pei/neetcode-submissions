/*
I am able to calculate the ideal time (no fleet ahead) it takes for each car to reach the destination.
Then the actual time is the fleet ahead. Let do the following case:
[...100t, 99t], a smaller time comes after, we need to keep the smaller time
[...100t, 101t], a larger time comes after, we need to throws away the 100t, the larger one becomes the new fleet.
[...100t, 100t], a same number come, we should treat it as the same fleet. They catch up at the destination and it is considered as the same fleet.

The number of fleets at the very end is the size of the non-decreasing stack.

We also need to sort the positions array so the stack actually worked.
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> sortedPosition(n);
        for (int i = 0; i < n; i++) {
            sortedPosition[i] = {position[i], speed[i]};
        }
        sort(
            sortedPosition.begin(), 
            sortedPosition.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            }
        );

        vector<double> idealArrivalTime(n, 0);
        for (int i = 0; i < n; i++) {
            idealArrivalTime[i] = double(target - sortedPosition[i].first) / sortedPosition[i].second;
        }

        vector<double> fleetStack;
        for (double t : idealArrivalTime) {
            while (fleetStack.size() && t >= fleetStack.back()) {
                fleetStack.pop_back();
            }
            fleetStack.push_back(t);
        }

        return fleetStack.size();
    }
};
