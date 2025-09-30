#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct Stack {
    Node* head; // ??nh stack
    int n;      // s? ph?n t?

    Stack() {
        head = nullptr;
        n = 0;
    }

    // ki?m tra r?ng
    bool isEmpty() {
        return head == nullptr;
    }

    // thêm vào ??u (push)
    void push(int item) {
        Node* node = new Node(item);
        node->next = head;
        head = node;
        n++;
    }

    // xóa ??u và tr? v? giá tr? (pop)
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1; // giá tr? báo l?i
        }
        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
        return val;
    }

    // tr? v? kích th??c
    int size() {
        return n;
    }

    // xem ph?n t? ??u (top)
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return head->data;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;   // 30
    cout << "Size: " << st.size() << endl; // 3

    cout << "Pop: " << st.pop() << endl;   // 30
    cout << "Pop: " << st.pop() << endl;   // 20

    cout << "Top: " << st.top() << endl;   // 10
    cout << "Size: " << st.size() << endl; // 1

    return 0;
}
