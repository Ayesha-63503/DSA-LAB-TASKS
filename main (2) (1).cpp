#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    void insertAtPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Position should be >= 1.\n";
            return;
        }
        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;

        if (!temp) {
            cout << "Position out of bounds.\n";
            return;
        }

        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << pos << ".\n";
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted element " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (!head->next) {
            cout << "Deleted element " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;

        cout << "Deleted element " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos) {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (pos < 1) {
            cout << "Position should be >= 1.\n";
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;

        if (!temp || !temp->next) {
            cout << "Position out of bounds.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "Deleted element " << toDelete->data << " from position " << pos << ".\n";
        delete toDelete;
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Specific Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Specific Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> pos;
                list.insertAtPosition(value, pos);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
