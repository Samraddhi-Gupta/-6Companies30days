#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        unordered_map<char, int> mp;
        string ng = "";

        // Count bulls and prepare for counting cows
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                ng += guess[i];
                mp[secret[i]]++;
            }
        }

        // Count cows
        int cows = 0;
        for (char ch : ng) {
            if (mp.find(ch) != mp.end()) {
                cows++;
                mp[ch]--;
                if (mp[ch] == 0) {
                    mp.erase(ch);
                }
            }
        }

        // Build result string
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};

int main() {
    Solution solution;

    // Example inputs
    string secret = "1807";
    string guess = "7810";

    // Call the function and print the result
    string result = solution.getHint(secret, guess);
    cout << "Hint: " << result << endl;

    return 0;
}
