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
    Node(int data1,Node* next1){
        data = data1;
        next=next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* deletehead(Node* head){
    if(head==NULL){
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);                //or delete temp;
    return head;
}
Node* deletelast(Node* head){
    if(head->next==NULL || head==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next= nullptr;
    return head;
}
Node* convert(vector<int>&w){
    if(w.size()==0){
        return NULL;
    }
    Node* head = new Node(w[0]);
    Node* mover = head;
    for(int i=1;i<w.size();i++){
        Node* temp = new Node(w[i]);
        mover->next= temp;
        mover=temp;
    }
    return head;
}

//removing kth element
Node* deletekthelement(Node* head,int k){
    int counter = 0;
    if(head == NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* previous = NULL;
    while(temp!=NULL){
        counter++;
        if(counter==k){
            previous->next = previous->next->next;
            free(temp);
            break;
        }
        previous=temp;
        temp = temp->next;
    }
    return head;
}
//Inserting a element at the begining
Node* Inserthead(Node* head,int element){
    Node* newnode = new Node(element);
    newnode->next = head;
    return newnode;
}
Node* Insertatlast(Node* head,int val){
    Node* newnode= new Node(val); 
    if(head==NULL) return newnode;
    if(head->next==NULL){
        head->next=newnode;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    return head;
}
Node* Insertatkthpos(Node* head,int k,int element){
    if(head == NULL){
        return new Node(element);
    }
    if(k==1){
        return Inserthead(head,element);
    }
    int count=0;
    Node* newnode = new Node(element);
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next = newnode;
            newnode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next; 
    }
    return head;
}
int main(){ 
    vector<int>w={100,3,54,12,6,7};
    Node* head = convert(w);
    head = Insertatkthpos(head,12,200);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}