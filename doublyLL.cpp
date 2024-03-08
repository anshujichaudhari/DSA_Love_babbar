#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     Node* prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }    
};

//traverse a Linked list
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;
}


//gives length of linked list
int getLength(Node* head){
    int len =0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAthead(Node* &tail, Node* &head , int d){

    //empty list 
    if(head == NULL){
        Node* temp = new Node(d);
         head = temp;
         tail = temp;
    }
    else{
    Node* temp = new Node(d);
   
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
    
}

void insertAtTail(Node* &tail,Node* &head,int d){
    //empty list
    if(tail==NULL){
    Node* temp = new Node(d);
    tail = temp;
    head = temp;
    }
    else{
     //new node create
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
    
}

void insertAtPosition(Node* &tail , Node* &head , int position , int d){
    //inserting at first position
    if(position == 1){
    insertAthead(tail,head,d);
    return;
     }
 Node * temp = head;
    int count = 1;
     //inserting at last position
     if(temp->next == NULL){
      insertAtTail(tail,head,d);
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
 

int main(){
Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;

print(head);
//cout<<"length of doubly LL : "<<getLength(head) ;

insertAthead(tail,head,11);
print(head);

insertAthead(tail,head,13);
print(head);

insertAthead(tail,head,8);
print(head);

insertAtTail(tail,head,25);
print(head);

insertAtPosition(tail,head,2,100);
print(head);

insertAtPosition(tail,head,1,101);
print(head);

insertAtPosition(tail,head,8,102);
print(head);

cout<<"length of doubly LL : "<<getLength(head) ;
return 0;
}


