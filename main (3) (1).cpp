#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
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

    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos == 1) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Delete from Beginning\n3. Delete from End\n4. Delete from Position\n5. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insert(value);
            break;
        case 2:
            list.deleteBeginning();
            break;
        case 3:
            list.deleteEnd();
            break;
        case 4:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 5:
            list.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
