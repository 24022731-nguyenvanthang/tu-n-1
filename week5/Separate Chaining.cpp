#include <iostream>
#define HASH_SIZE 11
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* hash_table[HASH_SIZE]; // mảng con trỏ

for (int i = 0; i < HASH_SIZE; i++)
    hash_table[i] = NULL;

int hash_function(int data) {
    return data % HASH_SIZE; // ánh xạ key -> index
}

void insert(int data) {
    int index = hash_function(data);
    Node* temp = new Node;// cấp phát vùng nhớ động mới , tạo node temp độc lập có giá trị = data,
    temp->value = data;
    temp->next = NULL;

    if (hash_table[index] == NULL) { // nếu ô đang trống thì gán luôn con trỏ hash đến temp
        hash_table[index] = temp;
        return;
    } else {
    	temp->next = hash_table[index];// nếu ô đó có ptu khác thì xảy ra va chạm
    	hash_table[index] = temp; // thì con trỏ mới trở đến node cũ đã có phần tử và node mới ở đầu danh sách
	}
   
}
int find(int data)
{
    int index = hash_function(data);    // Tính chỉ số băm
    Node* current = hash_table[index];  // Lấy node đầu danh sách tại vị trí đó

    while (current != NULL) {           // Duyệt từng node trong danh sách
        if (current->value == data)     // Nếu trùng giá trị
            return 1;                   // Tìm thấy
        current = current->next;        // Chuyển sang node kế tiếp
    }

    return 0; // Không tìm thấy trong danh sách
}

