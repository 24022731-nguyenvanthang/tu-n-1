#include <iostream>
#define HASH_SIZE 11
using namespace std;

int hash_table[HASH_SIZE];
bool used[HASH_SIZE];

// Khởi tạo bảng
void init() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hash_table[i] = 0;
        used[i] = false;
    }
}

// Hàm băm
int hash_function(int data) {
    return data % HASH_SIZE;
}


void insert(int data) {
    int index = hash_function(data);

    while (used[index]) {
        index = (index + 1) % HASH_SIZE;
    }
    hash_table[index] = data;
    used[index] = true;
}

int find(int data) {
    int index = hash_function(data);
    int start = index;

    while (used[index]) {
        if (hash_table[index] == data)
            return 1;

        index = (index + 1) % HASH_SIZE;

        if (index == start)
            break;
    }
    return 0;
}
