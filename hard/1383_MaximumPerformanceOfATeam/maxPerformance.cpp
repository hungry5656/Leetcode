class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;
        long long int maxP = 0, currSpeed = 0;
        vector<pair<int, int>> people(n);
        for (int i = 0; i < n; ++i) {
            people[i] = {efficiency[i], speed[i]};
        }
        sort(people.rbegin(), people.rend());
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (auto& [effi, speed]: people) {
            pq.push(speed);
            currSpeed += speed;
            if (pq.size() > k) {
                int speedRemoved = pq.top();
                pq.pop();
                currSpeed -= speedRemoved;
            }
            maxP = max(maxP, currSpeed * effi);
        }
        return maxP % MOD;
    }
};