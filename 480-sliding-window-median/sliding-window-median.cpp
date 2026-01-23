class Solution {
private:
    priority_queue<int> lo; // max heap
    priority_queue<int, vector<int>, greater<int>> hi; // min heap
    unordered_map<int, int> delayed;

    int k;
    int loSize = 0; // valid elements
    int hiSize = 0;

    // prune max heap
    void pruneLo() {
        while (!lo.empty()) {
            int num = lo.top();
            if (delayed.count(num)) {
                if (--delayed[num] == 0)
                    delayed.erase(num);
                lo.pop();
            } else break;
        }
    }

    // prune min heap
    void pruneHi() {
        while (!hi.empty()) {
            int num = hi.top();
            if (delayed.count(num)) {
                if (--delayed[num] == 0)
                    delayed.erase(num);
                hi.pop();
            } else break;
        }
    }

    // balance using LOGICAL sizes
    void balance() {
        if (loSize > hiSize + 1) {
            hi.push(lo.top());
            lo.pop();
            loSize--;
            hiSize++;
            pruneLo();
        }
        else if (loSize < hiSize) {
            lo.push(hi.top());
            hi.pop();
            hiSize--;
            loSize++;
            pruneHi();
        }
    }

    void add(int num) {
        if (lo.empty() || num <= lo.top()) {
            lo.push(num);
            loSize++;
        } else {
            hi.push(num);
            hiSize++;
        }
        balance();
    }

    void remove(int num) {
        delayed[num]++;

        if (num <= lo.top()) {
            loSize--;
            if (num == lo.top())
                pruneLo();
        } else {
            hiSize--;
            if (!hi.empty() && num == hi.top())
                pruneHi();
        }
        balance();
    }

    double getMedian() {
        if (k % 2 == 1)
            return lo.top();
        return ((double)lo.top() + hi.top()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        this->k = k;
        vector<double> res;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
            if (i >= k - 1) {
                res.push_back(getMedian());
                remove(nums[i - k + 1]);
            }
        }
        return res;
    }
};
