// class Solution {
// public:
//     vector<int> beautifulIndices(string s, string a, string b, int k) {
//         int n = s.length();
//         int m = a.length();
//         int l = b.length();
//         vector<int> result;

//         for (int i = 0; i <= n - m; ++i) {
//             bool found_a = true;
//             for (int j = 0; j < m; ++j) {
//                 if (s[i + j] != a[j]) { // Check if substring starting at index i matches pattern a
//                     found_a = false;
//                     break;
//                 }
//             }
//             if (found_a) {
//                 for (int j = 0; j <= n - l; ++j) {
//                     bool found_b = true;
//                     for (int t = 0; t < l; ++t) {
//                         if (s[j + t] != b[t]) { // Check if substring starting at index j matches pattern b
//                             found_b = false;
//                             break;
//                         }
//                     }
//                     if (found_b && abs(j - i) <= k) { // Check if |j - i| <= k
//                         result.push_back(i);
//                         break;
//                     }
//                 }
//             }
//         }

//         return result;
//     }
// };
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        int m = a.length();
        int l = b.length();
        vector<int> result;

        // Count occurrences of each character in string s
        unordered_map<char, vector<int>> charIndices;
        for (int i = 0; i < n; ++i) {
            charIndices[s[i]].push_back(i);
        }

        // Check for beautiful indices
        for (auto index : charIndices[a[0]]) {
            if (index + m > n) continue; // Avoid substrings exceeding string size
            if (s.substr(index, m) == a) {
                for (auto j : charIndices[b[0]]) {
                    if (j + l > n) continue; // Avoid substrings exceeding string size
                    if (abs(j - index) <= k && s[j] == b[0]) {
                        bool match = true;
                        for (int t = 1; t < l; ++t) {
                            if (s[j + t] != b[t]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            result.push_back(index);
                            break;
                        }
                    }
                }
            }
        }

        return result;
    }
};
