#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end()); // Sort the array to find the median
        int median = nums[n / 2]; // Median is the middle element after sorting
        for (int i = 0; i < n; i++) {
            steps += abs(nums[i] - median); // Add the absolute difference
        }
        return steps;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3};

    // Creating an instance of the solution class
    Solution sol;

    // Calling the minMoves2 function
    int result = sol.minMoves2(nums);

    // Printing the result
    cout << "Minimum number of moves to make all elements equal: " << result << endl;

    return 0;
}
