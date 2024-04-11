class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas = 0, netGas = 0, startingPoint = 0;
        for (int i = 0; i < gas.size(); ++i) {
            int currNet = gas[i] - cost[i];
            currGas += currNet;
            netGas += currNet;
            if (currGas < 0) {
                currGas = 0;
                startingPoint = i + 1;
            }
        }
        if (netGas < 0) {
            return -1;
        }
        return startingPoint;
    }
};