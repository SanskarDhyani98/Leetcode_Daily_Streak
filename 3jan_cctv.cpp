#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result=0;
        int prev=0;int n=bank.size();
        for(int i=0;i<n;i++)
        {
            int curr=0;
            for(char &ch:bank[i])
            {
                if(ch=='1')
                    curr++;
            }
            result+=prev*curr;
            if(curr!=0)
                prev=curr;
        }
        return result;
    }
};
int main()
{   Solution ob;
vector<string> x={"011001","000000","010100","001000"};
    int y=ob.numberOfBeams(x);
    cout<<y;
}