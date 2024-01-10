/******************************************************** C++ ********************************************************/
//T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here
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
    
    void inOrder(TreeNode* root, string& s) {
        if(root == NULL) return;
        
        //leaf node
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        
        inOrder(root->left, s);
        inOrder(root->right, s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        
        inOrder(root1, s1);
        inOrder(root2, s2);
        
        return s1==s2;
    }
};
int main()
{
    Solution ob;
    TreeNode* root1=new TreeNode(6,new TreeNode(5),new TreeNode(7));
    TreeNode* root2=new TreeNode(2,new TreeNode(1),new TreeNode(3));
    TreeNode* root=new TreeNode(4,root2,root1);
    cout<<ob.leafSimilar(root,root);
}

