#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        n=matrix.size();
        // vector<vector<int>> result(n,vector<int>(n,0));
        vector<int> prev(n,0);
        for(int i=0;i<n;i++)
            prev[i]=matrix[0][i];
            // result[0][i]=matrix[0][i];
        for(int row=1;row<n;row++)
        {   
            //extra
            vector<int> curr(n);
            
            for(int col=0;col<n;col++)
            {
                int a=INT_MAX;
                if(col-1>=0)
                a=prev[col-1];
                // a=result[row-1][col-1];
                int b=INT_MAX;
                if(col+1<n)
                b=prev[col+1];
                // b=result[row-1][col+1];
                // result[row][col]=matrix[row][col]+min({result[row-1][col],a,b});
               curr[col]=matrix[row][col]+min({prev[col],a,b});
                
            }
            prev=curr;
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            // res=min(res,result[n-1][i]);
            res=min(res,prev[i]);
        }
        return res;
    }
};
int main()
{   Solution ob1;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout<<ob1.minFallingPathSum(matrix); 
    return 0;
}