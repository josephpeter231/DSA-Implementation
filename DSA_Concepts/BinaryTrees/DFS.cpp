#include <bits/stdc++.h>
#define pb push_back
// #define min *min_element
// #define max *max_element
#define ll long long
using namespace std;
/*
Three types of DFS Traversals

Inorder - Left->root->right
Preorder- root->left->right
PostOrder -left->right->root

BFS Traversal - goes level wise
*/
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
// void preordertraversal(Node* root){
//     if(Node==NULL) return;
//     cout<<Node->data<<" ";
//     preordertraversal(Node->left);
//     preordertraversal(Node->right);
// }

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    // preordertraversal(root);
}