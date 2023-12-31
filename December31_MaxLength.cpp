#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         vector<vector<int>> f(26, {-1, -1});
//         int n = s.size();
//         for(int i = 0; i < n; i++){
//             f[s[i] - 'a'][1] = i;
//             f[s[n - i - 1] - 'a'][0] = n - i - 1;
//         }
//         int ans = -1;
//         for(int i = 0; i < 26; i++)
//             if(f[i][0] != -1)
//                 ans = max(ans, f[i][1] - f[i][0] - 1);
//         return ans;
//     }
// };
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kQLhWLVlzYo
    Company Tags                : Amazon, Google, Meta
    Leetcode Link               : https://leetcode.com/problems/largest-substring-between-two-equal-characters/
*/

/************************************************************************ C++ ************************************************************************/
//Approach-1 (Using Brute Force) - ACCEPTED
//T.C : O(n^2)
//S.C : O(1)
// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         int result = -1;
//         int n      = s.length();
        
//         for(int i = 0; i < n-1; i++) {
//             for(int j = i+1; j<n; j++) {
                
//                 if(s[i] == s[j]) {
//                     result = max(result, j-i-1);
//                 }
            
//             }
//         }
        
//         return result;
//     }
// };
//Approach-2 (Using Hashmap) - ACCEPTED
//T.C : O(n)
//S.C : O(n)
// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         int n = s.length();
//         unordered_map<char, int> mp;
        
//         int result = -1;
        
//         for(int i = 0 ; i < n;  i++) {
//             char ch = s[i];
            
//             if(mp.find(ch) == mp.end()) {
//                 mp[ch] = i;
//             } else {
//                 result = max(result, i - mp[ch] - 1);
//             }
//         }
        
//         return result;
//     }
// };
//Approach-3 (Using integer array instead of map)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        
        vector<int> count(26, -1);
        
        int result = -1;
        
        for(int i = 0 ; i < n;  i++) {
            char ch = s[i];
            
            if(count[ch-'a'] == -1) {
                count[ch-'a'] = i;
            } else {
                result = max(result, i - count[ch-'a'] - 1);
            }
        }
        
        return result;
    }
};
int main()
{
    Solution ob;
    cout<<ob.maxLengthBetweenEqualCharacters("jamabcdefmy");
}