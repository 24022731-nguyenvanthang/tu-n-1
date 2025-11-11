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
    Node* temp = new Node;
    temp->value = data;
    temp->next = NULL;

    if (hash_table[index] == NULL) { // nếu ô đang trống thì gán luôn con trỏ hash đến temp
        hash_table[index] = temp;
        return;
    } else {
    	temp->next = hash_table[index];
    	hash_table[index] = temp; // con trỏ mới trở đến node cũ đã có phần tử và node mới ở đầu danh sách
	}
   
}
int find(int data)
{
    int index = hash_function(data);  
    Node* current = hash_table[index]; 

    while (current != NULL) {          
        if (current->value == data)     
            return 1;                   
        current = current->next;   
    }

    return 0;
}


