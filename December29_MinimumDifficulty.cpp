#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int t[301][11];
    // int solve(vector<int>& jd, int n,int i,int d)
    // {
    //     if(d==1)
    //     {
    //         int maxD=jd[i];
    //         for(int x=i+1;x<n;x++)
    //             maxD=max(maxD,jd[x]);
    //         return maxD;
    //     }
    //     if(t[i][d]!=-1)
    //         return t[i][d];
    //     int maxD=jd[i];
    //     int finalResult=INT_MAX;
    //     for(int x=i;x<=n-d;x++)
    //     {
    //         maxD=max(maxD,jd[x]);
    //         int result=maxD+solve(jd,n,x+1,d-1);
    //         finalResult=min(finalResult,result);
    //     }
    //     return t[i][d]=finalResult;
    // }
    int minDifficulty(const vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n)
            return -1;
        // memset(t,-1,sizeof(t));
        // return solve(jobDifficulty,n,0,d);
        vector<vector<int>> t(n,vector<int>(d+1,-1));
        for(int i=0;i<n;i++)
        {
            t[i][1]=*max_element(jobDifficulty.begin()+i,jobDifficulty.end());
        }
        for(int days=2;days<=d;days++)
        {
            for(int i=0;i<=n-days;i++)
            {  int maxD=INT_MIN;
               int result=INT_MAX;
                for(int j=i;j<=n-days;j++)
                {
                    maxD=max(maxD,jobDifficulty[j]);
                    result=min(result,maxD+t[j+1][days-1]);
                }
             t[i][days]=result;
            }
        }
        return t[0][d];
    }
};
int main()
{
    Solution ob;
    cout<<ob.minDifficulty(vector<int>{6,5,4,3,2,1},2);
}