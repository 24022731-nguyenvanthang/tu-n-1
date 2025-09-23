
#include <iostream>
using namespace std;

const int MAX = 100;
struct List{
	int a[MAX];
	int size;
};
void khoi_tao(List &l) {
	l.size = 0;// ds đag rỗng
}

int truy_cap(const List& l, int vtri) {
	if (vtri < 0 || vtri >= l.size) {
		return -1;
	}
	return l.a[vtri];
}
bool chen_cuoi(List& l, int x) {
	if (l.size >= MAX) {
		return false;
	}
	l.a[l.size++] = x; // đặt phần tử ở vị trí cuối cùng
	return true;
}
bool chen_dau(List& l, int x) {
	if (l.size >= MAX) {
		return false;
	}
	// Dời toàn bộ phần tử sang phải
	for (int i = l.size; i > 0; i--) {
		l.a[i] = l.a[i - 1];
	}

	l.a[0] = x;
	l.size++;
	return true;
}
bool xoaptcuoi(List& l) {
		if (l.size == 0) {
			return false;
		}
		l.size--; // bỏ qua phần tử cuối
		return true;
	}

bool xoaptdau(List& l) {
		if (l.size == 0) {
			return false;
		}
		for (int i = 0; i < l.size - 1; i++) {
			l.a[i] = l.a[i + 1];
		}
		l.size--;
		return true;
	}
bool xoavtri_i(List& l, int i) {
	if (l.size == 0) {
		return false;
	}
	if (i < 0 || i >= l.size) {
		return false;
	}

	// Dời các phần tử từ i+1 về i
	for (int j = i; j < l.size - 1; j++) {
		l.a[j] = l.a[j + 1];
	}

	l.size--;
	return true;

}
void duyetxuoi(const List& l) {
	for (int i = 0; i < l.size; i++) {
		cout << l.a[i] << " ";
	}
	cout << endl;
}

void duyetnguoc(const List& l) {
	for (int i = l.size - 1; i >= 0; i--) {
		cout << l.a[i] << " ";
	}
	cout << endl;
}







int main()
{

}

