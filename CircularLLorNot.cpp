#include<iostream>
#include<map>
using namespace std;
class Node{
 public:
  int data;
  Node* next;
  
  Node(int d){
    this->data = d;
    this->next = NULL;
  }
  ~Node(){
    int val = this->data;
    if(this->next != NULL){
        delete next;
        next = NULL;
    }
    cout<< "Memory is free for node with data : "<<val<<endl;
  }
};
void insertNode(Node* &tail,int element,int d){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail=newNode;
        newNode->next= newNode;
     }
     else{
        //non-empty
        //assuming that the element is present in the list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr -> next;
        }
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp->next = curr -> next;
        curr->next = temp;
    }

    
}

void print(Node* tail){
     Node* temp = tail;
     
      //empty list
      if(tail == NULL){
        cout<<"List is Empty "<<endl;
        return;
      }
     do{
       cout<< tail->data << " ";
       tail = tail->next;
     }while(tail != temp);
     cout << endl;
}

void deleteNode(Node* &tail , int value){
  //empty list
  if(tail == NULL){
    cout<<"List is Empty "<<endl;
    return;
  }else{
    Node* prev = tail;
    Node* curr = prev -> next;
    while(curr->data != value){
      prev = curr;
      curr = curr -> next;
    }

    prev->next = curr -> next;
    // 1 Node Linked List
    if(curr = prev){
      tail = NULL;
    }

    // >=2 Node Linked list
    else if(tail == curr){
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}

bool isCircularList(Node* head){
  if(head == NULL){
    return true;
  }
  Node* temp = head->next;
  if(temp == NULL){
    return false;
  }
  while(temp!=NULL && temp!=head){
    temp = temp ->next;
  }
  if(temp == head){
    return true ;
  }
  return false;

}

bool detectLoop(Node* head){
  if(head == NULL){
    return false;
  }

  map<Node* , bool> visited;
  Node* temp = head;
  while(temp != NULL){
    //cycle is present
    if(visited[temp] == true)
    return true;

    visited[temp] = true;
    temp=temp->next;
  }
  return false;
}

int main(){
    Node* tail = NULL;
    Node* head = NULL;
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);
   
   if(isCircularList(head)){
    cout<< "Linked List is circular in nature" << endl;
   }
   else{
    cout<< "Linked List is not circular in nature" << endl;
   }

    return 0;
}


 
