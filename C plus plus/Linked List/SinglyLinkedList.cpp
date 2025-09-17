#include <iostream>

using namespace std;

// The Node struct can be defined separately or nested
struct Node {
    int info;
    Node* next;
};

// The SinglyLinkedList struct with member functions
struct SinglyLinkedList {
    Node* head;

    // Constructor to initialize head
    SinglyLinkedList() : head(NULL) {}

    // Display:
    void display() {
        if (head == NULL) {
            cout << "No values to display" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insertion at the beginning
    void insertion_at_Begin(int val) {
        Node* newNode = new Node();
        newNode->info = val;
        newNode->next = head;
        head = newNode;
    }

    // Insertion at the end
    void insertion_at_end(int val) {
        Node* newNode = new Node();
        newNode->info = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insertion at a specific position
    void insertion_pos(int pos, int val) {
        if (pos == 0) {
            insertion_at_Begin(val);
            return;
        }
        int count = 0;
        Node* temp = head;
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->info = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Deletion at the beginning
    void delete_head() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Deletion at the end
    void delete_tail() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Deletion at a specific position
    void delete_atPos(int pos) {
        if (head == NULL) return;
        if (pos == 0) {
            delete_head();
            return;
        }
        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
};

int main() {
    SinglyLinkedList list;
    int pos, val;

    cout << "Inserting 10 at start" << endl;
    list.insertion_at_Begin(10);
    list.display(); // Corrected call: `arr.display()`

    cout << "Inserting 20 at end" << endl;
    list.insertion_at_end(20);
    list.display(); // Corrected call: `arr.display()`

    cout << "Inserting 15 at position 1" << endl;
    list.insertion_pos(1, 15);
    list.display();

    cout << "Deleting at head" << endl;
    list.delete_head();
    list.display();

    cout << "Deleting at end" << endl;
    list.delete_tail();
    list.display();

    // Re-insert some values for demonstration
    list.insertion_at_Begin(5);
    list.insertion_at_end(25);
    list.display();

    cout << "Deleting at a specific index (position 1)" << endl;
    list.delete_atPos(1);
    list.display();

    return 0;
}