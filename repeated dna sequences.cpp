#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mpp; // Map to store substrings and their frequencies
        vector<string> res; // Result vector to store substrings that appear more than once

        // Iterate through the string, extracting all 10-character-long substrings
        for (int i = 0; i + 10 <= s.size(); i++) {
            mpp[s.substr(i, 10)]++;
        }

        // Check the map for substrings that appear more than once
        for (auto& [key, value] : mpp) {
            if (value > 1) {
                res.push_back(key);
            }
        }

        return res; // Return the result
    }
};

int main() {
    Solution solution;

    // Example input
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    // Call the function and get the result
    vector<string> result = solution.findRepeatedDnaSequences(s);

    // Print the result
    cout << "Repeated DNA sequences: " << endl;
    for (const string& seq : result) {
        cout << seq << endl;
    }

    return 0;
}
