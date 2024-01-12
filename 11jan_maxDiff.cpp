#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    // int maxD;
    // void maxDiffUtil(TreeNode* root,TreeNode* child)
    // {
    //     if(root==NULL||child==NULL)
    //         return ;    
    //     maxD=max(maxD,abs(root->val-child->val));
    //     maxDiffUtil(root,child->left);
    //     maxDiffUtil(root,child->right);
    // }
    // void maxDiff(TreeNode* root)
    // {
    //      if(root==NULL)
    //         return ;
    //     maxDiffUtil(root,root->left);
    //     maxDiffUtil(root,root->right);
    //     maxDiff(root->left);
    //     maxDiff(root->right);
    // }
    // int maxAncestorDiff(TreeNode* root) {
    //     maxD=-1;
    //     maxDiff(root);
    //     return maxD;
    // }

    //2
//      int maxAncestorDiff(TreeNode* root) {
        
//        return maxDiffUtil(root,root->val,root->val);
        
//     }
//    int maxDiffUtil(TreeNode* root, int minv,int maxv)
//      {
//        if(root==NULL)
//            return abs(minv-maxv);
//        minv=min(minv,root->val);
//        maxv=max(maxv,root->val);
//        int l=maxDiffUtil(root->left,minv,maxv);
//        int r=maxDiffUtil(root->right,minv,maxv);
//        return max(l,r);
//    }
      int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        const int inf = 1e6;
        
        function<pair<int,int>(TreeNode *)> dfs = [&](TreeNode * node) -> pair<int,int> {
            if(!node)
                return {inf, -inf};
            
            pair<int,int> left = dfs(node -> left);
            pair<int,int> right = dfs(node -> right);
            
            int MIN = min(left.first, right.first);
            int MAX = max(left.second, right.second);
            
            if(node -> left or node -> right)
                ans = max({ans, abs(MIN - node -> val), abs(MAX - node -> val)});
            
            return {min(MIN, node -> val), max(MAX, node -> val)};
        };
        
        dfs(root);
        
        return ans;
    }
};
int main()
{
    Solution ob;
    TreeNode* root1=new TreeNode(6,new TreeNode(5),new TreeNode(7));
    TreeNode* root2=new TreeNode(2,new TreeNode(1),new TreeNode(3));
    TreeNode* root=new TreeNode(4,root2,root1);
    cout<<ob.maxAncestorDiff(root);
}