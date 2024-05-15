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

Node* delete_k_element(Node* head,int k) {
    Node* temp = head;
    int cnt=0;
    Node* prev = NULL;
    if(head == NULL) return head;

    if(k==1) {
        head = head->next;
        return head;
    }

    while(temp!=NULL) {
        cnt++;
        if(cnt==k) {
            prev->next= prev->next->next;
            free(temp);
            break;



        }
        prev=temp;
        temp=temp->next;



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
    //print(head);

    cout<<"enter the element number to delete :";
    int n;
    cin>>n;
    head = delete_k_element(head,n);
    cout<<"after deleting "<<n<<"th node :"<<endl;
    print(head);



}


