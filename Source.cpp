#include<iostream>
#include <cstring>
#include<string>
using namespace std;
void upper(char* s) {// thường thành hoa
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = char(s[i] - 32);
		}
	}
}

void lower(char* a) {// Hoa thành thường
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			a[i] = char(a[i] + 32);
		}
	}
}

void removeX(char* s, int idx) {
	if (idx < 0 || idx >= strlen(s)) {
		throw "index incorrect";
	}
	for (int i = idx; i < strlen(s); i++) {
		s[i] = s[i + 1];
	}
	s[strlen(s)] = '\0';
}
void trimleft(char* s) {// xóa dấu '+' trong chuỗi
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '+') {
			removeX(s, i);
			i--;
		}
	}
}
void trimMid(char* s) {// loại bỏ kí tự giống nhau liên tiếp
	for (int i = 0; i < strlen(s)-1; i++) {
		for (int j = i + 1; j < strlen(s); j++) {
			if (s[i] == s[j] && s[j] == '*') {// kí tự sao giống nhau thì xóa
				removeX(s, j);
				j--;
			}
		}
	}
}
int findX(char* s, char h) {// hàm trả về vị trí tìm thấy kí tự
	int i = 0;
	while (i < strlen(s) && s[i] != h) {
		i++;
		if (i < strlen(s) && s[i] == h) {
			return i;
		}
	}
	return -1;
}

void upperList(char* s) {
	//viết hoa kí tự đầu vào sau các kí tự *
	for (int i = 0; i < strlen(s); i++) 
		if (s[i] == '*') 
			s[i + 1] = char(s[i + 1] - 32);
		else 
			continue;
			s[0] = char(s[0] - 32);
}
//void insert0(char* s, int idx, char ch) {
//	if (idx<0 || idx>strlen(s)) {
//		throw"index incorect";
//	}
//	for (int i = strlen(s); i > idx; i--) {
//		s[i] = s[i - 1];
//	}
//		s[idx] = ch;
//		s[strlen(s) + 1] = '/0';
//}


void insert(char* s, int idx, char ch) {
	if (idx < 0 || idx > strlen(s)) {
		throw "index incorrect";
	}
	int length = strlen(s);
	char* temp = new char[length + 2];// +2 vì 1 cho ch 1 cho '/0' 
	// Tạo một mảng tạm để chứa chuỗi mới
	for (int i = 0; i < idx; i++) {
		temp[i] = s[i];
	}
	temp[idx] = ch; // Chèn ký tự ch vào vị trí idx
	for (int i = idx; i < length; i++) {
		temp[i + 1] = s[i];
	}
	temp[length + 1] = '\0'; // Kết thúc chuỗi
	// Sao chép từng ký tự từ mảng tạm temp vào mảng s
	for (int i = 0; i <= length + 1; i++) {
		s[i] = temp[i];
	}
	delete[] temp; // Xóa bộ nhớ đã cấp phát cho mảng tạm
}
void removeExits(char* s) {
	for (int i = 0; i < strlen(s) - 1; i++) {
		for (int j = i + 1; j < strlen(s); i++) {
			if (s[i] == s[j]) {
				removeX(s, i);
			}
			j--;
		}
	}
}
void swap(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
	void reverse(char* s) {
		int l = 0, r = strlen(s) - 1;
		while (l < r) {
			swap(s[l],s[r]);
		}
	}
int main() {
	int* a;
	a = new int[100];
	char* s;
	s = new char[101];
	cout << "Nhap chuoi: ";
	cin.getline(s, 101);
	//lower(s);
	//removeX(s,3);
	//trimMid(s);
	//cout << "x la: " << findX(s,'h');
	//upperList(s);
	insert(s, 4, 's');
	cout << "\n chuoi vua nhap la: " << s;
	delete[] a; //Giải phóng bộ nhớ động của mảng a
	delete[] s; //Giải phóng bộ nhớ động của mảng s
	return 0;
}
