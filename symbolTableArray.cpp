#include <iostream>
#include <string>
using namespace std;

struct Entry {
    string key;
    string value;
};

class SymbolTableArray {
private:
    static const int MAX_SIZE = 100;
    Entry table[MAX_SIZE];
    int count;

public:
    SymbolTableArray() : count(0) {}

    void insert(const string& key, const string& value) {
        for (int i = 0; i < count; ++i) {
            if (table[i].key == key) {
                table[i].value = value;
                cout << "Updated: " << key << endl;
                return;
            }
        }
        if (count < MAX_SIZE) {
            table[count].key = key;
            table[count].value = value;
            count++;
            cout << "Inserted: " << key << endl;
        } else {
            cout << "Symbol Table is full!" << endl;
        }
    }

    string lookup(const string& key) const {
        for (int i = 0; i < count; ++i) {
            if (table[i].key == key)
                return table[i].value;
        }
        return "[Not Found]";
    }

    void remove(const string& key) {
        for (int i = 0; i < count; ++i) {
            if (table[i].key == key) {
                for (int j = i; j < count - 1; ++j) {
                    table[j] = table[j + 1];
                }
                count--;
                cout << "Removed: " << key << endl;
                return;
            }
        }
        cout << "Key not found: " << key << endl;
    }


    int size() const {
        return count;
    }
};


