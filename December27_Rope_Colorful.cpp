#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, const vector<int>& neededTime) {
        //DP solution
        // int n = colors.size();
        // vector<vector<int>> dp(n + 1, vector<int> (27, 0));
        
        // for(int i = n - 1; i >=0; i--){
        //     for(int j = 0; j < 27; j++){
        //         int remove, noremove;

        //         remove = neededTime[i] + dp[i + 1][j];
        //         noremove = dp[i + 1][colors[i] - 'a' + 1];
                
        //         if(colors[i] - 'a' + 1 == j)
        //             dp[i][j] = remove;
        //         else
        //             dp[i][j] = min(remove, noremove);
        //     }
        // }
        
        // return dp[0][0];
        
        //Greedy Solution
         int n = colors.size();
        
        int time    = 0;
        int prevMax = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(i > 0 && colors[i] != colors[i-1]) {
                prevMax = 0;
            }
            int curr = neededTime[i];
            
            time += min(prevMax, curr); //greedily
            
            prevMax = max(prevMax, curr);
            
        }
        
        return time;
    }
};
int main()
{   Solution ob;
    cout<<ob.minCost("abaac",{1,2,3,4,5});
    return 0;
}