#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();

//         int dp[n + 1][m + 1];

//         for(int i = 0; i < m + 1; i++)
//             dp[n][i] = 0;
//         for(int i = 0; i < n + 1; i++)
//             dp[i][m] = 0;

//         for(int i = n - 1; i > -1; i--){
//             for(int j = m - 1; j > -1; j--){
//                 if(text1[i] == text2[j]){
//                     dp[i][j] = 1 + dp[i + 1][j + 1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };



/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=aJNu_DLyOxY
    Company Tags                : Microsoft, Amazon, FactSet, Hike, Citrix, MakeMyTrip, Paytm, VMWare
    Leetcode Link               : https://leetcode.com/problems/longest-common-subsequence/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
*/


/**************************************************************** C++ ****************************************************************/
//T.C : O(m*n)
//S.C : O(m*n)
//Approach-1 (Recursion + Memoization)
// class Solution {
// public:
//     int t[1001][1001];
//     int LCS(string& s1, string& s2, int m, int n) {
//         if(m == 0 || n == 0)
//             return t[m][n] = 0;
        
//         if(t[m][n] != -1)
//             return t[m][n];
        
//         if(s1[m-1] == s2[n-1])
//             return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
//         return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
        
//         memset(t, -1, sizeof(t));
        
//         return LCS(text1, text2, m, n);
//     }
// };


// //Approach-2 (Bottom Up)
// //T.C : O(m*n)
// //S.C : O(m*n)
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
        
//         vector<vector<int>> t(m+1, vector<int>(n+1));
        
//         for(int i = 0; i<m+1; i++) {
//             for(int j = 0; j<n+1; j++) {
//                 if(i == 0 || j == 0)
//                     t[i][j] = 0;
//                 else if(text1[i-1] == text2[j-1])
//                     t[i][j] = 1 + t[i-1][j-1];
//                 else
//                     t[i][j] = max(t[i][j-1], t[i-1][j]);
//             }
//         }
        
//         return t[m][n];
//     }
// };

//Approach-3 (Bottom Up space optmized)
/*
Since, in bottm up approach, we are using results of only two rows, t[i] and t[i-1]. So, we can take only two rows.
*/
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> t(2, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i%2][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    t[i%2][j] = 1 + t[(i+1)%2][j-1];
                else
                    t[i%2][j] = max(t[i%2][j-1], t[(i+1)%2][j]);
            }
        }
        
        return t[m%2][n];
    }
};
