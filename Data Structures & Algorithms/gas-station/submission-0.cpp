/*
画一个加油站位置与加油量的坐标图；
如果总的cost大于总的gas量 那么就肯定不行
如果不是 那么从gas剩余量最低的点，之后的点出发 肯定就可以
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0, minGas = INT_MAX, minIndex = -1;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if (minGas > total) {
                minGas = total;
                minIndex = i;
            }
        }

        if (total < 0) return -1;
        return (minIndex + 1) % n;
    }
};
