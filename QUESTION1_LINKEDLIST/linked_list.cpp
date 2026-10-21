
#include <iostream>
using namespace std;

// Node structure for the singly linked list
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a node at a specified position (0-based)
    void insertPosition(int value, int position) {
        if (position < 0) {
            cout << "Error: Invalid position.\n";
            return;
        }

        if (position == 0) {
            insertBeginning(value);
            return;
        }

        Node* current = head;

        for (int i = 0; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Error: Position out of range.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Insert a node at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Delete a node by its 0-based position
    void deletePosition(int position) {
        if (head == nullptr) {
            cout << "Error: Cannot delete from an empty list.\n";
            return;
        }

        if (position < 0) {
            cout << "Error: Invalid position.\n";
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        for (int i = 0; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Error: Position out of range.\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Delete the first node containing the specified value
    void deleteValue(int value) {
        if (head == nullptr) {
            cout << "Error: Cannot delete from an empty list.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Error: Value not found.\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Display every node in the list
    void display() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }

        cout << " -> NULL\n";
    }

    // Release all dynamically allocated nodes
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Test the list with three different data sets
int main() {
    cout << "QUESTION 1: SINGLY LINKED LIST\n\n";

    cout << "TEST 1: Basic operations\n";
    LinkedList list1;
    list1.insertBeginning(20);
    list1.insertBeginning(10);
    list1.insertEnd(40);
    list1.insertPosition(30, 2);
    cout << "After insertions: ";
    list1.display();

    list1.deletePosition(2);
    cout << "After deleting position 2: ";
    list1.display();

    list1.deleteValue(10);
    cout << "After deleting value 10: ";
    list1.display();

    list1.deleteValue(999);

    cout << "\nTEST 2: Different values\n";
    LinkedList list2;
    list2.insertEnd(5);
    list2.insertEnd(15);
    list2.insertEnd(25);
    list2.insertPosition(20, 2);
    cout << "After insertions: ";
    list2.display();

    list2.deletePosition(0);
    cout << "After deleting position 0: ";
    list2.display();

    cout << "\nTEST 3: Empty list and edge cases\n";
    LinkedList list3;
    list3.display();
    list3.deletePosition(0);
    list3.deleteValue(7);

    list3.insertBeginning(100);
    list3.insertEnd(200);
    list3.insertPosition(150, 1);
    cout << "After insertions: ";
    list3.display();

    list3.deleteValue(150);
    cout << "After deleting value 150: ";
    list3.display();

    return 0;
}
