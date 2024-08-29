class MedianFinder {
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (size == 0) {
            medium = num;
            size++;
            return;
        }
        if (size % 2 == 0) {
            int left = leftpq.top(), right = rightpq.top();
            if (num > right) {
                medium = right;
                rightpq.pop();
                rightpq.push(num);
            } else if (num > left) {
                medium = num;
            } else {
                medium = left;
                leftpq.pop();
                leftpq.push(num);
            }
        } else {
            int mediumInt = int(medium);
            if (num > mediumInt) {
                leftpq.push(mediumInt);
                rightpq.push(num);
                int right = rightpq.top();
                medium = (medium + right) / 2.0;
            } else {
                leftpq.push(num);
                rightpq.push(mediumInt);
                int left = leftpq.top();
                medium = (medium + left) / 2.0;
            }
        }
        size++;
    }
    
    double findMedian() {
        return medium;
    }
private:
    priority_queue<int, vector<int>, greater<int>> rightpq;
    priority_queue<int> leftpq;
    double medium;
    int size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */