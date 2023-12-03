#include <bits/stdc++.h>
#define pb push_back
// #define min *min_element
// #define max *max_element
#define ll long long
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data,Node* next1,Node* back1){
        data = data;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertarrtodll(vector<int>&w){
    Node* head = new Node(w[0]);
    Node* prev = head;
    for(int i=1;i<w.size();i++){
        Node* temp = new Node(w[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;

}
Node* deletehead(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next=nullptr;
    free(temp);
    return head;
}
Node* deletetail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
        
    }
    temp->back= nullptr;
    prev->next= nullptr;
    delete temp;
    return head;

}
Node* removeKthElement(Node* head, int k){
    
    if(head==NULL){
        return NULL;
    }
    int count = 0;
    Node* kNode = head;
    while(kNode!=NULL){
        count++;
        if(count==k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;
    
    if(prev==NULL && front == NULL){
        delete kNode;
        return NULL;
    }
    // else if (prev==NULL){
    //     return deletehead(head);
    // }
    // else if(front == NULL){
    //     return deletetail(head);
    // }
    prev->next = front;
    front->back = prev;
    
    kNode->next = NULL;
    kNode->back = NULL;
    
    delete kNode;
    return head;
    
    
}

int main(){ 
    vector<int>w={100,3,54,12,56,7};
    Node* head = convertarrtodll(w);
    // head = deletetail(head);
    // head = Insertatkthpos(head,12,200);
    head = removeKthElement(head,1);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}