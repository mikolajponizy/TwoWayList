#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void Add(int new_element) {
        Node* new_node = new Node;
        new_node->data = new_element;
        new_node->next = NULL;
        if (head == NULL) {
            new_node->prev = NULL;
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void Push(int new_element) {
        Node* new_node = new Node;
        new_node->data = new_element;
        new_node->prev = NULL;
        if (head == NULL) {
            new_node->next = NULL;
            head = new_node;
            tail = new_node;
            return;
        }
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }

    void AddAt(int new_element, int position) {
        Node* new_node = new Node;
        new_node->data = new_element;
        if (position == 0) {
            new_node->prev = NULL;
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }

    int Get() {
        return tail->data;
    }

    int GetAt(int position) {
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    int Pop() {
        int value = head->data;
        head = head->next;
        head->prev = NULL;
        return value;
    }

    int RemoveAt(int position) {
        if (position == 0) {
            int value = head->data;
            head = head->next;
            head->prev = NULL;
            return value;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        int value = temp->next->data;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        return value;
    }

    void PrintList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //############ SECOND part functions ############//
    void Sort(bool reverse = false) {

    }

    void Display() {

    }

private:
    void MergeSort() {

    }

    void Merge() {

    }
};

//################ MAIN function ################//

int main() {
    DoubleLinkedList dll;
    dll.Add(10);
    dll.Add(20);
    dll.Add(30);
    dll.PrintList();
    dll.Push(40);
    dll.PrintList();
    dll.AddAt(50, 2);
    dll.PrintList();
    cout << dll.Get() << endl;
    cout << dll.GetAt(2) << endl;
    cout << dll.Pop() << endl;
    dll.PrintList();
}


