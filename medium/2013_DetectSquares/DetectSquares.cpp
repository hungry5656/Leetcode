class DetectSquares {
public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        mapP[point[0]][point[1]]++;
        points.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int a = point[0], b = point[1];
        int retVal = 0;
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i].first, y = points[i].second;
            if ((a - x != 0) && abs(a - x) == abs(b - y)) {
                retVal += mapP[a][y] * mapP[x][b];
            }
        }
        return retVal;
    }
    int mapP[1001][1001] = {};
    vector<pair<int, int>> points;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */