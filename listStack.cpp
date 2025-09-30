#include <iostream>
using namespace std;

const int MAX = 100;

struct Stack {
    int data[MAX];
    int n;  // s? ph?n t? hi?n t?i

    Stack() {
        n = 0;
    }

    // ki?m tra r?ng
    bool isEmpty() {
        return n == 0;
    }

    // ch�n v�o cu?i
    void push(int item) {
        if (n >= MAX) {
            cout << "Stack day!" << endl;
            return;
        }
        data[n++] = item;
    }

    // x�a cu?i v� tr? v? ph?n t? ?�
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1; // gi� tr? b�o l?i
        }
        return data[--n];
    }

    // l?y k�ch th??c
    int size() {
        return n;
    }

    // xem ph?n t? cu?i
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return data[n - 1];
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
