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

Node* sort_all_012(Node* head){
    int countOne = 0;
    int countZero=0;
    int countTwo =0;

    Node* temp =head;
    while(temp!= NULL){
        if(temp->data == 0){
            countZero++;
        }
       else if(temp->data == 1){
            countOne++;
        }
       else if(temp->data == 2){
            countTwo++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp!=NULL){
        if(countZero != 0){
            temp->data = 0;
            countZero--;
        }else if(countOne != 0){
            temp->data = 1;
            countOne--;
        }
        else if(countTwo != 0){
            temp->data = 2;
            countTwo--;
        }
        temp = temp->next;
    }
    
    return head;
}

int main(){
//created a new node 
Node* node1 = new Node(2);

//head pointed to node1
Node* head = node1;
Node* tail = node1; 

insertAtTail(tail,1);
print(head);
insertAtTail(tail,2);
print(head);
insertAtTail(tail,0);
print(head);
insertAtTail(tail,1);
print(head);
insertAtTail(tail,0);
print(head);
insertAtTail(tail,2);
print(head);

sort_all_012(head);
cout<<"After sorting ";
print(head);


    return 0;
}