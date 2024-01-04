#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &num:nums)
        {
            mp[num]++;
        }
        int result=0;
        for(auto &it:mp)
        {
            if(it.second==1)
            {
                return -1;
            }
            result+=ceil((double)it.second/3);
        }
        return result;
    }
};
int main()
{   Solution ob;
vector<int> x={1,2,3,4,1,3,2,3,4,1,2};
cout<<ob.minOperations(x);
}