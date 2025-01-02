#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                int total_sum = 0;
                int count = 0;

                for (int l = max(0, i-1); l < min(rows, i+2); ++l) 
                {
                    for (int k = max(0, j-1); k < min(cols, j+2); ++k) 
                    {
                        total_sum += img[l][k];
                        count += 1;
                    }
                }

                result[i][j] = total_sum / count;
            }
        }

        return result;
    }
};

int main() {
    // Example input
    vector<vector<int>> img = {
        {100, 200, 100},
        {200, 50, 200},
        {100, 200, 100}
    };

    // Creating an instance of the solution class
    Solution sol;

    // Applying the image smoother
    vector<vector<int>> result = sol.imageSmoother(img);

    // Printing the result
    cout << "Smoothed Image:" << endl;
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
