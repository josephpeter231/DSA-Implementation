#include <bits/stdc++.h>
#define pb push_back
// #define min *min_element
// #define max *max_element
#define ll long long
using namespace std;

//Types of binary tree
/*Full      - has 0 or 2 Childrens
  Complete  - each level is completely filled or 
              except last level
            - and last level every node is left
  Perfect   - All leaf nodes are at same level
  Balanced  - height of the tree is not max of log(n)
  Degenerate- skew tree either left or right
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
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    cout<<root->right->data;
}