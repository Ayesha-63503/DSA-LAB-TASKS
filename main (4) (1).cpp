#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBefore(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    cout << "Node inserted at beginning successfully.\n";
}

void insertAfter(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Node inserted at end successfully.\n";
}

void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* current = head;
    Node* previous = NULL;
    if (head->data == value) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        if (head->next == head) {
            head = NULL;
        } else {
            temp->next = head->next;
            head = head->next;
        }
        delete current;
        cout << "Node deleted successfully.\n";
        return;
    }
    do {
        previous = current;
        current = current->next;
        if (current->data == value) {
            previous->next = current->next;
            delete current;
            cout << "Node deleted successfully.\n";
            return;
        }
    } while (current != head);
    cout << "Node not found.\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    insertBefore(10);
    insertAfter(20);
    insertAfter(30);
    display();
    deleteNode(10);
    display();
    deleteNode(30);
    display();
}
