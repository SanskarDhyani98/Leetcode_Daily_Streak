#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool makeEqual(const vector<string>& words) {
        int n=words.size();
        // unordered_map<char,int> mp;
        // vector<int> arr(26,0);
        int arr[26]={0};
        for(string str:words)
        {
            for(char &ch:str)
            {
               // mp[ch]++; 
                arr[ch-'a']++;
            }
        }
      //   METHOD1
        // for(auto &it:mp)
        // {
        //     int x=it.second;
        //     if(x%n!=0)
        //         return false;
        // }
         // return true;
        //METHOD2
        // for(int x:arr)
        // {
        //     if(x%n!=0)
        //         return false;
        // }
        // return true;
        //METHOD3
        auto lambda=[&](int freq)
        {
            return freq%n == 0;
        };
        return all_of(begin(arr),end(arr),lambda);
        // return all_of(begin(arr),end(arr),[&](int freq)
        // {
        //     return freq%n == 0;
        // });
    }
};
int main()
{
    Solution ob;
    cout<<ob.makeEqual(vector<string>{"Jam","Jamm","Ja"});
}