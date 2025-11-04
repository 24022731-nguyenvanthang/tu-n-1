#include <iostream>
#include <string>
using namespace std;

// Node trong danh sách liên kết
struct Node {
    string key;
    string value;
    Node* next;

    Node(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};

// Lớp Symbol Table dùng Linked List
class SymbolTableLinkedList {
private:
    Node* head;
    int count;

public:
    SymbolTableLinkedList() {
        head = nullptr;
        count = 0;
    }

    ~SymbolTableLinkedList() {
        clear();
    }

    // Thêm hoặc cập nhật
    void insert(const string& key, const string& value) {
        Node* current = head;

        // Kiểm tra nếu key đã tồn tại → cập nhật
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                cout << "Updated: " << key << endl;
                return;
            }
            current = current->next;
        }

        // Nếu chưa có, thêm node mới vào đầu danh sách
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        count++;
        cout << "Inserted: " << key << endl;
    }

    // Tìm giá trị theo key
    string lookup(const string& key) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        return "[Not Found]";
    }

    // Xóa một phần tử theo key
    void remove(const string& key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr)
                    head = current->next;  // Xóa phần tử đầu
                else
                    prev->next = current->next;

                delete current;
                count--;
                cout << "Removed: " << key << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Key not found: " << key << endl;
    }


    // Trả về số phần tử
    int size() const {
        return count;
    }

    // Xóa toàn bộ danh sách (dùng trong destructor)
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        count = 0;
    }
};

