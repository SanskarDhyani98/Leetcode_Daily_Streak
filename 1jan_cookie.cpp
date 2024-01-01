#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int findContentChildren( vector<int> g, vector<int> s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<g.size()&&j<s.size())
        {
            if(g[i]<=s[j])
                i++;
            j++;
        }
        return i;
    }
};
int main()
{
    Solution ob;
    cout<<ob.findContentChildren(vector<int>{1,2,3},vector<int>{1,2,3});
}