#include <iostream>
using namespace std ;


struct Node
{
  Node * prev ;
  int info ;
  Node * next ;
};

struct DoublyLinkedList
{
  Node * head ;
  Node * tail ;
  
  DoublyLinkedList() : head(NULL) {}

  void display(){
    if (head  == NULL){
      cout << "No values to display " << endl ;
      return ;
    }
    Node * temp = head ;
    while (temp != NULL)
    {
      cout << temp->info << " ";
      temp = temp->next ;
    }
    cout << endl ;
  }

  void  insertion_head(int val ){
    Node * newNode = new Node () ;
    newNode->info = val ;
    newNode->prev = NULL ;
    newNode->next = head ;
    head = newNode;
  }

  void insertion_tail(int val){
    Node * newNode = new Node() ;
    newNode->prev = tail ;
    newNode->info = val ;
    newNode->next = NULL ;
    tail = newNode ;
  }

  void insertion_atPos(int pos , int val){
    if (pos == 0){
      insertion_head(val);
      return ;
    }
    int count = 0 ;
    Node * temp = head ;
    while (temp != NULL && count < pos-1){
      temp = temp->next ;
      count++ ;
    }
    if (temp == NULL){
      cout << "Position out of bounds"<<endl ;
      return ;
    }
    Node * newNode = new Node();
    newNode->info = val ;
    newNode->next = temp->next ;
    newNode->prev = temp ;
    if (newNode->next != NULL) {
      newNode->next->prev = newNode ;
    }
    temp->next = newNode ;
  }

  void deletion_head(){
    if (head == NULL)  return ;
    Node* temp = head ;
    head = head->next ;
    if (head != NULL) {
      head->prev = NULL ; 
    }
    delete temp ; 
  }

  void deletion_tail(){
    if (head==NULL) return ;
    if (head -> next == NULL){
      delete head ;
      head = NULL;
      return ;
    }
    Node * temp = tail ;
    tail = tail->prev ;
    tail->next = NULL ;
    delete temp ;
  }

  void deletion_atPos(int pos){
    if (head == NULL) return ;
    if (pos == 0){
      deletion_head();
      return ;
    }
    Node * temp = head ;
    int count = 0 ;
    while (temp != NULL && count < pos-1 ){
      temp = temp->next;
      count ++ ;
    }
    if(temp == NULL || temp->next == NULL){
      cout << "Postion out of bounds"<< endl ;
      return ;
    }
    temp->prev->next = temp->next ;
    temp->next->prev = temp->prev ;
    delete temp ;
  }
};

int main() {
    DoublyLinkedList list;
    int pos, val;

    cout << "Inserting 10 at start" << endl;
    list.insertion_head(10);
    list.display(); // Corrected call: `arr.display()`

    cout << "Inserting 20 at end" << endl;
    list.insertion_tail(20);
    list.display(); // Corrected call: `arr.display()`

    cout << "Inserting 15 at position 1" << endl;
    list.insertion_atPos(1, 15);
    list.display();

    cout << "Deleting at head" << endl;
    list.deletion_head();
    list.display();

    cout << "Deleting at end" << endl;
    list.deletion_tail();
    list.display();

    // Re-insert some values for demonstration
    list.insertion_head(5);
    list.insertion_tail(25);
    list.display();

    cout << "Deleting at a specific index (position 1)" << endl;
    list.deletion_atPos(1);
    list.display();

    return 0;

}
