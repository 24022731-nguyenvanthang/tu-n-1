#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Cấu trúc cặp (key, value)
struct Entry {
    string key;
    string value;
};

// Lớp SymbolTable sử dụng vector thay cho mảng tĩnh
class SymbolTable {
private:
    vector<Entry> entries;

public:
    // Hàm thêm mới hoặc cập nhật
    void add(const string& key, const string& value) {
        for (auto& e : entries) {
            if (e.key == key) {
                e.value = value;
                cout << "Updated: " << key << endl;
                return;
            }
        }
        entries.push_back({key, value});
        cout << "Inserted: " << key << endl;
    }

    // Hàm tìm kiếm giá trị theo key
    string get(const string& key) const {
        for (const auto& e : entries) {
            if (e.key == key)
                return e.value;
        }
        return "[Not Found]";
    }

    // Hàm xóa một key khỏi bảng
    void erase(const string& key) {
        for (size_t i = 0; i < entries.size(); ++i) {
            if (entries[i].key == key) {
                entries.erase(entries.begin() + i);
                cout << "Removed: " << key << endl;
                return;
            }
        }
        cout << "Key not found: " << key << endl;
    }

    // In ra toàn bộ bảng
    void printAll() const {
        cout << "=== Symbol Table ===" << endl;
        for (const auto& e : entries) {
            cout << e.key << " -> " << e.value << endl;
        }
        cout << "====================" << endl;
    }

    // Trả về kích thước hiện tại
    int size() const {
        return static_cast<int>(entries.size());
    }
};

// Ví dụ sử dụng
int main() {
    SymbolTable sym;

    sym.add("x", "10");
    sym.add("y", "20");
    sym.add("x", "15");  // Cập nhật giá trị của x

    sym.printAll();

    cout << "Giá trị của y: " << sym.get("y") << endl;

    sym.erase("y");
    sym.printAll();

    cout << "Số lượng phần tử còn lại: " << sym.size() << endl;

    return 0;
}
