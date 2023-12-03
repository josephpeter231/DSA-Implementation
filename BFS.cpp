#include <bits/stdc++.h>
#define pb push_back
// #define min *min_element
// #define max *max_element
#define ll long long
using namespace std;

/*
Each level values are traversed
queue is used
*/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>levels;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();;
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                levels.push_back(node->val);
            }
            ans.push_back(levels);
        }
        return ans;
        
    }

};