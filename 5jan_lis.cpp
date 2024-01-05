#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 //dp[i]-->minimum last element of any subsequence of length i
    int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1,1e5);
//         dp[0]=-1e5;
//         for(int i=0;i<=n-1;i++)
//         {  int curr=nums[i];
//             for(int j=0;j<n;j++)
//             {
//                 if(dp[j]<curr)
//                     dp[j+1]=min(dp[j+1],curr);
//             }
//         }
//         for(int i=n;i>=0;i--)
//         {
//             if(dp[i]!=1e5)
//                 return i;
//         }
//         return n;
        //2nd approach
//           int n = nums.size();
//         vector<int> dp(n, 1e5);
        
//         for(int i = 0; i < n; i++){
//             int p = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            
//             if(p < n)
//                 dp[p] = min(dp[p], nums[i]);
//         }
        
//         for(int i = n - 1; i > -1; i--){
//             if(dp[i] < 1e5)
//                 return i + 1;
//         }
        
        
        //3rd approach
       
        int n=nums.size(); int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {   dp[i]=1;
            for(int j=0;j<i;j++)
            {   if(nums[j]<nums[i])
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
        return *max_element(dp,dp+n);
        
    }
};
int main()
{
    vector<int> nums={10,9,2,5,3,7,101,18};
    Solution ob;
    cout<<ob.lengthOfLIS(nums);
}