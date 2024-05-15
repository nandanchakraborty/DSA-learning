#include<bits/stdc++.h>
using namespace std;
class Node {
  public :
    int data;
    Node* next;


    Node(int data1,Node* next1 = nullptr) {
        data= data1;
        next = next1;

    }



};

Node* convertarr2ll(vector<int> & ar) {
    if(ar.empty()) return nullptr;

    Node* head =  new Node (ar[0]);
    Node* mover = head;
    for(int i=1; i<ar.size(); i++) {
        Node* temp = new Node(ar[i]);
        mover ->next = temp;
        mover = temp;

    }
    return head;



}


Node* deletenode(Node* head) {

    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;



}
Node* deletetail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    else {
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp= temp->next;


        }
        free(temp->next);
        temp->next=nullptr;


    }
    return head;



}

void print(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp -> data<<" ";
        temp = temp-> next;


    }


}

int main() {
    vector<int> ar= {1,3,5,4,6};
    Node  y(ar[0]);
    Node* head = convertarr2ll(ar);

   // print(head);
    //cout<<endl<<"after deleting first node :";
   // head =deletenode(head);
   // print(head);
    head = deletetail(head);
    cout<<endl<<"after deleting tail :";
    print(head);






}
