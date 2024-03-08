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

    //destructor
        ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
        delete next;
        this->next = NULL;

        }
        cout<<"Memory is free for node with data " << value <<endl;
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


 //deletion

 void deleteNode(int position , Node* &head){
     //deleting first node
     if(position == 1){
      Node* temp = head;
      head = head->next;
      //memory free for first node
      temp->next = NULL;
      delete temp;
      
     }
     else{
        //deleting any middle or last element from LL
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev =curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next=NULL;
        delete curr ;
     }
 }

int main(){
    //created a new node 
Node* node1 = new Node(10);

//head pointed to node1
Node* head = node1;
Node* tail = node1; 


// insertAtHead(head,12);
// print(head);
// insertAtHead(head,15);
// print(head);


insertAtTail(tail,12);
print(head);
insertAtTail(tail,15);
print(head);



insertAtPosition(tail,head,4,22);
print(head);

cout<<"head = "<<head->data<<endl;
cout<<"tail = "<<tail->data<<endl;

 
deleteNode(2,head);
print(head);

return 0;
} 