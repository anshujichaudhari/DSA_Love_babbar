#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};



void insertAtHead(Node* &head, int d){
    //new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

}
 

 void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node* &tail,int d){
    //new node create
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

 void insertAtPosition(Node* &tail , Node* &head , int position , int d){
    //inserting at first position
     if(position == 1){
        insertAtHead(head,d);
        return;
     }
      

      Node * temp = head;
    int count = 1;
     //inserting at last position
     if(temp->next == NULL){
      insertAtTail(tail,d);
      return;
     }

     while(count < position-1){
        temp = temp ->next;
        count++;
    }
    //creating a node for d(data)
    Node* nodeToInsert = new Node(d);
     nodeToInsert->next = temp ->next;
     temp ->next = nodeToInsert;

 }


 Node* removeDuplicateFromASortedLL(Node* head){
    if(head == NULL)
    return NULL;

    Node* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr->data == curr->next->data ){
          Node* next_next = curr->next->next;
          Node* nodeTODelete = curr->next;
          delete(nodeTODelete);
          curr->next = next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
 }


int main(){
//created a new node 
Node* node1 = new Node(1);

//head pointed to node1
Node* head = node1;
Node* tail = node1; 

insertAtTail(tail,2);
print(head);
insertAtTail(tail,2);
print(head);
insertAtTail(tail,3);
print(head);

removeDuplicateFromASortedLL(head);
   cout<<"After removing duplicates nodes  "<<endl;
   print(head);


    return 0;
}