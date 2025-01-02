#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> Prefix(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; 

        // Build the prefix sum array
        for (int i = 0; i < n; i++) {
            Prefix[i + 1] = Prefix[i];
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                Prefix[i + 1]++;
            }
        }

        // Process the queries
        vector<int> ANS; 
        for (auto& query : queries) {
            int L = query[0], R = query[1];  
            ANS.push_back(Prefix[R + 1] - Prefix[L]);  
        }

        return ANS; 
    }
};

int main() {
    Solution solution;

    // Example input
    vector<string> words = {"apple", "orange", "idea", "umbrella", "elephant"};
    vector<vector<int>> queries = {{0, 2}, {1, 3}, {0, 4}};

    // Compute the results for the queries
    vector<int> results = solution.vowelStrings(words, queries);

    // Output the results
    cout << "Results for the queries:" << endl;
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
