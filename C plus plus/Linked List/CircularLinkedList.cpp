#include <iostream>

using namespace std;

// Circular Linked List
// Similar as Linked List but the head and tail are connected

struct Node
{
  int info;
  Node *next;
};

struct CircularLinkedList
{
  Node *head;

  CircularLinkedList() : head(NULL) {}

  void display(){
    if (head == NULL){
      cout << "No values to display" << endl;
      return;
    }
    Node *temp = head;
    do {
      cout << temp->info << " ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;
  }

  void insertion_head(int val){
    Node* newNode = new Node();
    newNode->info = val ;
    if (head == NULL) {
      newNode->next = newNode;
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
  }

  void insertion_tail(int val){
    Node* newNode = new Node();
    newNode->info = val; 
    if (head == NULL){
      newNode->next = newNode;
      head = newNode ;
      return ;
    }
    Node* temp = head ; 
    while(temp->next != head){
      temp = temp->next ;
    }
    temp->next = newNode ;
    newNode->next = head;
  }

  void insertion_atPos(int pos,int val){
    if (pos == 0){
      insertion_head(val) ;
      return;
    }
    int count = 0 ;
    Node* temp = head ;
    while (temp->next != head && count < pos-1){
      temp = temp->next ;
      count++ ;
    }
    if(count < pos-1){
      cout << "Position out of bounds"<< endl ;
      return ;
    }
    Node* newNode = new Node();
    newNode->info = val; 
    newNode->next = temp->next;
    temp->next = newNode ;
  }

  void delete_head(){
    if (head == NULL) return ;
    if (head->next == head) {
      delete head;
      head = NULL;
      return;
    }
    Node* temp = head;
    Node* last = head;
    while (last->next != head) {
      last = last->next;
    }
    head = head->next;
    last->next = head;
    delete temp;
  }

  void delete_tail(){
    if (head == NULL) return ;
    if (head->next == head){
      delete head ;
      head = NULL ;
      return ;
    }
    Node* temp = head ;
    while (temp->next->next != head){
      temp = temp->next ;
    }
    Node* toDelete = temp->next;
    temp->next = head;
    delete toDelete;
  }

  void delete_atPos(int pos){
    if(head == NULL) return ;
    if (pos == 0){
      delete_head();
      return ;
    } 
    Node* temp = head ;
    int count = 0;
    while (temp->next != head && count < pos-1){
      temp = temp->next ;
      count++ ;
    }
    if(count < pos-1 || temp->next == head){
      cout << "Index out of bounds" << endl ;
      return ;
    }
    Node* toDelete = temp->next ;
    temp->next = toDelete->next ;
    delete toDelete ;
  }
};


int main() {
    CircularLinkedList list;
    int pos, val;

    cout << "Inserting 10 at start" << endl;
    list.insertion_head(10);
    list.display(); 

    cout << "Inserting 20 at end" << endl;
    list.insertion_tail(20);
    list.display(); 

    cout << "Inserting 15 at position 1" << endl;
    list.insertion_atPos(1, 15);
    list.display();

    cout << "Deleting at head" << endl;
    list.delete_head();
    list.display();

    cout << "Deleting at end" << endl;
    list.delete_tail();
    list.display();

    list.insertion_head(5);
    list.insertion_tail(25);
    list.display();

    cout << "Deleting at a specific index (position 1)" << endl;
    list.delete_atPos(1);
    list.display();

    return 0;
}