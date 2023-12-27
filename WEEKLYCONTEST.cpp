/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=M8WnAIhTjmQ
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-to-convert-string-i/
*/

/***************************************************************** C++ ******************************************************************************/
//Approach-1 (Using Simple Dijkstra's Algorithm)
//T.C : n * (time complexity of Dijkstra) = O(n * (V+E)logV) , where V = number of vertices and E = number of edges
//S.C : O(V+E) -> We create a graph, where V = number of vertices and E = number of edges
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dijkstra(char &source, unordered_map<char, vector<pair<char, int>>> &adj, vector<vector<long long>> &costMatrix) {

        //min-heap
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

        pq.push({0, source});

        while(!pq.empty()) {
            int d        = pq.top().first;
            char adjNode = pq.top().second;
            pq.pop();

            for(auto &it : adj[adjNode]) {
                char adjNode = it.first;
                int cost      = it.second;

                if(costMatrix[source - 'a'][adjNode - 'a'] > d + cost) {
                    costMatrix[source - 'a'][adjNode - 'a'] = d + cost;
                    pq.push({d + cost, adjNode});
                }
            }

        }
        return;
    }
    //V = # of vertices
    //E = # of edges
    //O(n * (V+E)log(V))
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;
        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> costMatrix(26, vector<long long>(26, INT_MAX));

        //Populate the costMatrix using Dijkstra's Algorithm
        for(int i = 0; i < source.length(); i++) { //n
            char ch = source[i];
            dijkstra(ch, adj, costMatrix);
        }

        long long ans = 0;

        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i]) {
                continue;
            }

            if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }

            ans += costMatrix[source[i] - 'a'][target[i] - 'a'];

        }

        return ans;
    }
};


//Approach-2 (Simply replace Dijkstra's with Floyd Warshall)
//Link (Inside my "Floyd Warshall" folder) - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Floyd%20Warshall/Minimum%20Cost%20to%20Convert%20String%20I.cpp

