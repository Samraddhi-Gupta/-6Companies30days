#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        // Fill the circle with numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            circle.push_back(i);
        }
        int cur_ind = 0;

        // Simulate the elimination process
        while (circle.size() > 1) {
            int next_to_remove = (cur_ind + k - 1) % circle.size();
            circle.erase(circle.begin() + next_to_remove);
            cur_ind = next_to_remove;
        }

        // Return the last remaining friend
        return circle[0];
    }
};

int main() {
    Solution solution;

    // Example inputs
    int n = 5, k = 2;

    // Find the winner
    int winner = solution.findTheWinner(n, k);

    cout << "The winner is: " << winner << endl;

    return 0;
}
