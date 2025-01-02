#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rects;
    vector<int> prefixAreas;
    mt19937 rng{random_device{}()}; // Random number generator
    uniform_int_distribution<int> dist; // Distribution for rectangle selection

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int totalArea = 0;

        // Calculate prefix sum of areas
        for (const auto& rect : rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalArea += area;
            prefixAreas.push_back(totalArea);
        }

        dist = uniform_int_distribution<int>(1, totalArea); // Distribution for rectangle areas
    }

    vector<int> pick() {
        // Randomly pick a rectangle based on weighted areas
        int target = dist(rng);
        int rectIndex = lower_bound(prefixAreas.begin(), prefixAreas.end(), target) - prefixAreas.begin();

        // Randomly pick a point within the selected rectangle
        const auto& rect = rects[rectIndex];
        uniform_int_distribution<int> xDist(rect[0], rect[2]);
        uniform_int_distribution<int> yDist(rect[1], rect[3]);
        int x = xDist(rng);
        int y = yDist(rng);

        return {x, y};
    }
};

int main() {
    // Define a list of rectangles as [x1, y1, x2, y2]
    vector<vector<int>> rects = {
        {1, 1, 5, 5},
        {10, 10, 13, 13},
        {20, 20, 25, 25}
    };

    // Instantiate the Solution class
    Solution* obj = new Solution(rects);

    // Test the pick function
    cout << "Random points picked from the rectangles:" << endl;
    for (int i = 0; i < 10; ++i) {
        vector<int> point = obj->pick();
        cout << "(" << point[0] << ", " << point[1] << ")" << endl;
    }

    // Clean up
    delete obj;

    return 0;
}
