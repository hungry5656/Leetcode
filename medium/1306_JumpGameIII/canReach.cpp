class Solution {
public:
    bool canReachHelper(vector<int>& arr, int curr, vector<bool>& visited) {
        if (curr < 0 || curr >= arr.size())
            return false;
        if (visited[curr])
            return false;
        if (arr[curr] == 0)
            return true;
        visited[curr] = true;
        return canReachHelper(arr, curr + arr[curr], visited) || canReachHelper(arr, curr - arr[curr], visited);
        
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return canReachHelper(arr, start, visited);
    }
};