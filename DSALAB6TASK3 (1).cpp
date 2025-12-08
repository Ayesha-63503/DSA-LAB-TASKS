#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;

public:
    Book() {}
    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }

    string getId() { return bookId; }
    string getName() { return bookName; }
    double getPrice() { return bookPrice; }
    string getAuthor() { return bookAuthor; }
    string getISBN() { return bookISBN; }

    void setBook(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }

    void display() {
        cout << "Book ID: " << bookId
             << " | Name: " << bookName
             << " | Price: " << bookPrice
             << " | Author: " << bookAuthor
             << " | ISBN: " << bookISBN << endl;
    }
};

class Node {
public:
    Book book;
    Node* next;
    Node() { next = NULL; }
    Node(Book b) {
        book = b;
        next = NULL;
    }
};

class BookList {
private:
    Node* head;

public:
    BookList() { head = NULL; }

    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Book added successfully.\n";
    }

    void removeBook(string id) {
        if (head == NULL) {
            cout << "No books in list.\n";
            return;
        }
        Node* current = head;
        Node* previous = NULL;
        if (head->book.getId() == id) {
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
            cout << "Book removed successfully.\n";
            return;
        }
        do {
            previous = current;
            current = current->next;
            if (current->book.getId() == id) {
                previous->next = current->next;
                delete current;
                cout << "Book removed successfully.\n";
                return;
            }
        } while (current != head);
        cout << "Book not found.\n";
    }

    void updateBook(string id, string name, double price, string author, string isbn) {
        if (head == NULL) {
            cout << "No books in list.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->book.getId() == id) {
                temp->book.setBook(id, name, price, author, isbn);
                cout << "Book updated successfully.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Book not found.\n";
    }

    void printBooks() {
        if (head == NULL) {
            cout << "No books to display.\n";
            return;
        }
        Node* temp = head;
        cout << "Book List:\n";
        do {
            temp->book.display();
            temp = temp->next;
        } while (temp != head);
    }

    void printBook(string id) {
        if (head == NULL) {
            cout << "No books in list.\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->book.getId() == id) {
                temp->book.display();
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Book not found.\n";
    }
};

int main() {
    BookList bl;
    for (int i = 1; i <= 10; i++) {
        bl.addBook("B" + to_string(i), "Book" + to_string(i), 100 + i, "Author" + to_string(i), "ISBN" + to_string(i));
    }
    bl.printBook("B5");
    bl.removeBook("B3");
    bl.removeBook("BX");
    bl.printBook("B5");
    bl.updateBook("B5", "Updated Book 5", 199.99, "Updated Author", "UpdatedISBN5");
    bl.printBook("B5");
}
