//T.C : O(n)
//S.C : O(1) (Ignoging recursion stack space)
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        //Within Range
        if(root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        //When outside the range (Less than low) - Go right
        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        //When outside the range (Greater than high) - Go left
        return rangeSumBST(root->left, low, high);
    }
};
int main()
{
    Solution ob;
    TreeNode* root1=new TreeNode(6,new TreeNode(5),new TreeNode(7));
    TreeNode* root2=new TreeNode(2,new TreeNode(1),new TreeNode(3));
    TreeNode* root=new TreeNode(4,root2,root1);
    cout<<ob.rangeSumBST(root,3,6);
}