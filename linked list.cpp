// linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    int data;    
    Node* next;  
};

struct LinkedList {
    Node* head; 
};

// Hàm khởi tạo linked list rỗng
void init(LinkedList& l) {
    l.head = nullptr;  
}


// thêm vào đầu ds
void insertHead(LinkedList& l, int x) {
    Node* p = new Node;   // cấp phát node mới
    p->data = x;          
    p->next = l.head;     
    l.head = p;           
}



// thêm vào cuối ds
void insertTail(LinkedList& l, int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;

    if (l.head == nullptr) {
        l.head = p;
    }
    else {
        Node* temp = l.head;
        while (temp->next != nullptr) {
            temp = temp->next;   
        }
        temp->next = p;  
    }
}

// duyệt xuôi
void traverseForward(const LinkedList& l) {
    Node* temp = l.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void deleteHead(LinkedList& l) {
    if (l.head == nullptr) return;  
    Node* temp = l.head;   
    l.head = l.head->next; 
    delete temp;           
}


void deleteTail(LinkedList& l) {
    if (l.head == nullptr) return;       
    if (l.head->next == nullptr) {     
        delete l.head;
        l.head = nullptr;
        return;
    }
    Node* temp = l.head;
    while (temp->next->next != nullptr) {
        temp = temp->next;  
    }
    delete temp->next;      
    temp->next = nullptr;
}

// xoá vtri i
void deleteAt(LinkedList& l, int i) {
    if (l.head == nullptr) return; 

    if (i == 0) {
        deleteHead(l);
        return;
    }

    Node* temp = l.head;
    for (int k = 0; k < i - 1 && temp->next != nullptr; k++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) return;

    Node* del = temp->next;        
    temp->next = del->next;        
    delete del;                    
}



void duyetnguoc(Node* head) {
    if (head == nullptr) return;
    duyetnguoc(head->next);
    cout << head->data << " ";
}

int main()
{
   
}

