/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildBST(TreeNode* root, TreeNode* newNode){
        TreeNode* curr = root;;
        while(true){
            if(newNode-> val < curr->val){
                if(curr->left == NULL){
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
            }else{
                if(curr->right == NULL){
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
            }
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1; i < preorder.size(); i++){
            TreeNode* node = new TreeNode(preorder[i]);
            buildBST(root, node);
        }

        return root;
    }
};