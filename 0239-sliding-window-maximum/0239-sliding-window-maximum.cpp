class Solution {
public:
      struct Compare {
        bool operator()(const int& a, const int& b) const {
            return a > b; // Compare in descending order
        }
    };

    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::multiset<int, Compare> mySet;
        std::vector<int> res;

        // Insert the first k elements into the multiset
        for (int i = 0; i < k; i++) {
            mySet.insert(nums[i]);
        }
        res.push_back(*mySet.begin());

        int i = 1;
        int j = k;

        while (j < nums.size()) {
            // Erase the element that is no longer in the sliding window
            mySet.erase(mySet.find(nums[i - 1]));

            // Insert the new element coming into the sliding window
            mySet.insert(nums[j]);

            res.push_back(*mySet.begin());

            i++;
            j++;
        }

        return res;
    }
};