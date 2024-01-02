#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // unordered_map<int,int> mp;
        int n=nums.size();
        vector<int> mp(n+1,0);
        vector<vector<int>> result;
        for(int &num:nums)
        {
            int freq=mp[num];
            if(freq==result.size())
                result.push_back({});
            result[freq].push_back(num);
            mp[num]++;
        }
        return result;
    }
};
int main()
{   Solution ob;
vector<int> x={1,2,3,4,1,3,2,3,5};
    vector<vector<int>> y=ob.findMatrix(x);
    for(int i=0;i<y.size();i++)
    {
        for(int j=0;j<y[i].size();j++)
        cout<<y[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}