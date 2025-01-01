#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate the distance between the circle's center and this closest point
        int distanceX = xCenter - closestX;
        int distanceY = yCenter - closestY;

        // Check if this distance is within the circle's radius
        return (distanceX * distanceX + distanceY * distanceY) <= (radius * radius);
    }
};

int main() {
    Solution solution;

    // Input parameters
    int radius = 2;
    int xCenter = 1, yCenter = 1;
    int x1 = 0, y1 = 0, x2 = 4, y2 = 4;

    // Function call
    bool result = solution.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);

    // Output the result
    if (result) {
        cout << "The circle overlaps with the rectangle." << endl;
    } else {
        cout << "The circle does not overlap with the rectangle." << endl;
    }

    return 0;
}
