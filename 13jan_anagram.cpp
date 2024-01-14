#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int minSteps(string s, string t) {
//         int n = s.length();
        
//         int mp_s[26] = {0};
//         int mp_t[26] = {0};
        
//         for(int i = 0; i<n; i++) {
//             mp_s[s[i] - 'a']++;
//             mp_t[t[i] - 'a']++;
//         }
        
//         int result = 0;
        
//         for(int i = 0; i < 26; i++) {
//             int freq_in_t = mp_t[i];
            
//             int freq_in_s = mp_s[i];
            
//             if(freq_in_t < freq_in_s) {
//                 result += freq_in_s - freq_in_t;
//             }
//         } 
        
//         return result;
//     }
// };
//Approach-2 (Using 1 counter)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            result += max(0, mp[i]);
        } 
        
        return result;
    }
};

int main()
{   Solution ob;
    string s;
    cin>>s;
    cout<<ob.minSteps(s,"aabac");
    return 0;
}
