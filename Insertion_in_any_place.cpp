#include<bits/stdc++.h>
using namespace std;
class Node {
  public :
    int data;
    Node* next;

    Node(int data1,Node* next1 = nullptr) {

        data = data1;
        next = next1;

    }

};

Node* convertarr2ll(vector<int> &ar) {

    if(ar.empty()) return nullptr;

    Node* head = new Node (ar[0]);
    Node* mover = head;
    for(int i=1; i<ar.size(); i++) {
        Node* temp = new Node (ar[i]);
        mover->next = temp;
        mover= temp;


    }
    return head;


}
Node* insert_before_head(Node* head,int value) {

    Node* temp = new Node(value);
    temp->next = head;

    return temp;


}
Node* insert_in_the_last(Node* head,int value) {
    if(head == NULL) {
        return new Node(value);


    }
    Node* temp = head;
    while(temp->next!= NULL) {

        temp = temp->next;

    }
    Node* newnode = new Node(value,NULL);
    temp ->next = newnode;
    return head;




}

Node* insert_at_any_pos(Node* head, int val, int k) {
    if (head == NULL) {
        return new Node(val);
    }
    if (k == 1) {
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }

    Node* temp = head;
    int cnt = 1;

    while (temp != NULL) {
        if (cnt == k - 1) {
            Node* newnode = new Node(val);
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
        cnt++;
    }

    return head;
}
void print(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;

    }


}


int main() {

    vector<int> ar= { 1,3,5,4,7};
    Node y(ar[0]);
    Node* head= convertarr2ll(ar);
    print(head);
    // cout<<endl<<"enter value to insert :";
    cout<<endl<<"enter value and  position to inset value :";
    int n,k;
    cin>>n>>k;

    //head = inser_before_head(head,n);
    //head = insert_in_the_last(head,n);
    head = insert_at_any_pos(head,n,k);
    print(head);

}

