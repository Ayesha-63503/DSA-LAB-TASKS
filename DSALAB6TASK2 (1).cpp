#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = NULL;

void addEmployee(string empName) {
    Node* newNode = new Node();
    newNode->name = empName;
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
    cout << empName << " added successfully.\n";
}

void deleteEmployee(string empName) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* current = head;
    Node* prev = NULL;
    if (head->name == empName) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        if (head->next == head)
            head = NULL;
        else {
            temp->next = head->next;
            head = head->next;
        }
        delete current;
        cout << empName << " deleted successfully.\n";
        return;
    }
    do {
        prev = current;
        current = current->next;
        if (current->name == empName) {
            prev->next = current->next;
            delete current;
            cout << empName << " deleted successfully.\n";
            return;
        }
    } while (current != head);
    cout << empName << " not found.\n";
}

void searchEmployee(string empName) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        if (temp->name == empName) {
            cout << empName << " found successfully.\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << empName << " not found.\n";
}

void display() {
    if (head == NULL) {
        cout << "No employees.\n";
        return;
    }
    Node* temp = head;
    cout << "Employee List:\n";
    do {
        cout << temp->name << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    addEmployee("Ali");
    addEmployee("Sara");
    addEmployee("Ahmed");
    display();
    searchEmployee("Sara");
    deleteEmployee("Ali");
    display();
}

