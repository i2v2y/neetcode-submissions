class KthLargest {
   private:
    int k;
    priority_queue<int, vector<int>, greater<int>> mh;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            mh.push(n);
            if (mh.size() > k) mh.pop();
        }
    }

    int add(int val) {
        mh.push(val);
        if (mh.size() > k) mh.pop();
        return mh.top();
    }
};
