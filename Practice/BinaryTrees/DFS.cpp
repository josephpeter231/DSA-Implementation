#include <bits/stdc++.h>
#define pb push_back
// #define min *min_element
// #define max *max_element
#define ll long long
using namespace std;
/*
3 ways for
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