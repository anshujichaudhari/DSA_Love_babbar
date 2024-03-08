#include<iostream>
#include<map>
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

bool detectLoop(Node* head){
  if(head == NULL){
    return false;
  }

  map<Node*,bool> visited;
  Node* temp = head;
  while(temp != NULL){
    //cycle is present
    if(visited[temp] == true){
        cout<<"Present on element "<<temp->data<<endl;
        return true;
    }
    

    visited[temp] = true;
    temp=temp->next;
  }
  return false;
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
insertAtTail(tail,22);

print(head);
tail->next = head->next;

if(detectLoop(head) == 1){
    cout<<"Cycle is present"<<endl;
}else{
    cout<<"Cycle is not present"<<endl;
}



// insertAtPosition(tail,head,1,70);
// print(head);

// cout<<"head = "<<head->data<<endl;
// cout<<"tail = "<<tail->data<<endl;

    return 0;
}