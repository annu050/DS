#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        // Construct the modified string with special characters
        string p = "@";
        for (int i = 0; i < n; i++) {
            p += '#';
            p += s[i];
        }
        p += "#$";

        // Initialize variables
        int maxLen = 0;
        int centerIndex = 0;
        int c = 0; // center of the longest palindrome found so far
        int r = 0; // right boundary of the longest palindrome found so far

        // Vector to store the length of the palindrome centered at each position
        vector<int> ans(p.length());

        // Manacher's Algorithm
        for (int i = 1; i < p.length() - 1; i++) {
            // Mirror index of 'i' with respect to center 'c'
            int mirror = 2 * c - i;

            // Check if 'i' is within the current palindrome boundary
            if (i < r) {
                ans[i] = min(r - i, ans[mirror]);
            }

            // Expand around center 'i' to find the length of palindrome centered at 'i'
            while (p[i + 1 + ans[i]] == p[i - 1 - ans[i]]) {
                ans[i]++;
            }

            // Update the center and right boundary if the palindrome centered at 'i' expands beyond 'r'
            if (i + ans[i] > r) {
                c = i;
                r = i + ans[i];
            }

            // Update the maximum length and center index if the current palindrome is longer
            if (ans[i] > maxLen) {
                maxLen = ans[i];
                centerIndex = i;
            }
        }

        // Extract the longest palindrome substring from the original string 's'
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
}
int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s);
    return 0;
}