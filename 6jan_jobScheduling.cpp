#include<bits/stdc++.h>
using namespace std;
//dp[i]--
//i-->maximum profit i can make if i start from position i


//base case: i==n(reached end) return 0;
//answer is going to be stored in dp[0]

//sorting startTime array
//becomes knapsack problem-- take,notake current job
//taking job -- puts constraint on next chosable job while giving profit
//If you choose a job that ends at time X you will be able to start another job that starts at time X.
//nottake=dp[i+1]
//take =profit[i]+dp[p]; //p=first min start time for current ith end time
//  int helper(i)
//  {
//     if(i==n)
//     return 0
//     if(dp[i]!=-1)
//     return dp[i]
//     int take,notake
//     notake=helper(i+1)
//     int p=binarySearch(i)
//     take=profit[i]+helper(p)
//     return dp[i]=max(take,notake)
//  }
class job{
    public:
        int start, end, profit;
    
    job(int a, int b, int c){
        start = a;
        end = b;
        profit = c;
    }
};
/*
Problem : Maximum Profit in Job Scheduling
Difficulty : Hard
Problem Link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
Video Solution : https://youtu.be/IBSv87Sk-rw

*/


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        
        vector<job> jobs;
        
        for(int i = 0; i < n; i++){
            job newJob(startTime[i], endTime[i], profit[i]);
            jobs.emplace_back(newJob);
        }
        
        sort(jobs.begin(), jobs.end(), [](job &a, job &b){
            return a.start < b.start;    
        });
            
        vector<int> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            int take, notake;
            
            notake = dp[i + 1];
            
            int low = i; // low is always false
            int high = n; // high is always true
            
            while(low < high - 1){
                int mid = low + (high - low) / 2;
                
                if(jobs[mid].start >= jobs[i].end)
                    high = mid;
                else
                    low = mid;
            }
            
            take = jobs[i].profit + dp[high];
            
            dp[i] = max(take, notake);
        }
        
        return dp[0];
    }
};



int main()
{
    vector<int> startTime,endTime,profit;
     startTime = {1,2,3,4,6}; endTime = {3,5,10,6,9}, profit = {20,20,100,70,60};
    Solution ob;
    cout<<ob.jobScheduling(startTime,endTime,profit);
    return 0;
}