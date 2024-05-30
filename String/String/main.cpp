#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996) // _CRT_SECURE_NO_WARNINGS
using namespace std;

class String {
private:
	int size = 0;
	char* data = nullptr;
public:
	//Конструкторы
	String() = default;
	String(const char* text) : size(strlen(text)) {
		data = new char[size + 1];
		strcpy(data, text);
	}
	String(const String& other) : size(other.size) {
		data = new char[size + 1];
		strcpy(data, other.data);

	}
	~String() { delete[] data; }

	//Перегрузка входного и выходного потоков
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String& sting_i);

	//перегрузка остальных операторов
	char operator[](int i) {
		if (0 <= i && i <= size && size != 0) {
			return data[i];
		}
		else {
			cout << "Empty string\n";
			exit(1);
		}
	}

	String& operator=(const String& other) {
		if (this == &other) {
			return *this;
		}
		else {
			delete[] data;
			size = other.size;
			data = new char[size + 1];
			strcpy(data, other.data);
			return *this;
		}
	}

	bool operator== (String& other) {
		if (this == &other) { return true; }
		if (size != other.size) { return false; }
		for (size_t i = 0; i < size; ++i) {
			if (data[i] != other.data[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!= (String& other) {
		if (*this == other) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator< (String& other) {
		if (this == &other) { return false; }
		size_t temp_size = min(size, other.size);
		for (size_t i = 0; i < temp_size; ++i) {
			if (int(data[i]) > int(other.data[i])) {
				return false;
			}
		}
		if (size == other.size || size > other.size) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator<= (String& other) {
		if (*this < other || *this == other) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator> (String& other) {
		if (*this <= other) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator >= (String& other) {
		if (*this > other || *this == other) {
			return true;
		}
		else {
			return false;
		}
	}

	String operator+ (const String& other) {
		size_t temp_size = this->size + other.size;
		char* temp_data = new char[temp_size];
		for (size_t i = 0; i < this->size; ++i) {
			temp_data[i] = this->data[i];
		}
		for (size_t i = 0; i < other.size; ++i) {
			temp_data[this->size + i] = other.data[i];
		}
		return String(temp_data);
	}

	String& operator+= (const String& other) {
		String temp = *this + other;
		return temp;

	}
};

ostream& operator<<(ostream& out, const String& string_out) {
	if (string_out.size != 0) {
		return out << string_out.data << endl;
	}
	else {
		return out << "Empty string\n";
	}
}

istream& operator>>(istream& in, String& string_i) {
	vector<char> input_data;
	char input_char;
	while (in.get(input_char) && input_char != '\n')
		input_data.push_back(input_char);
	delete[] string_i.data;
	string_i.size = input_data.size();
	string_i.data = new char[string_i.size + 1];
	for (size_t i = 0; i < input_data.size(); ++i) {
		string_i.data[i] = input_data[i];
	}
	return in;
}

int main() {
	String str1;
	String str2("Hello, World!");

	cout << str1;
	cout << str2;

	/*cout << str1[0];*/
	//Выводит "Empty string" и программа завершает работу
	cout << str2[0] << "\n";

	String str3;
	str3 = str2;
	cout << str3;

	String str4;
	cin >> str4;

	String str5("abcde");
	String str6("abcde");

	bool test;
	test = str5 >= str6;
	cout << test << "\n";

	String str7 = str6 + str5;
	cout << str7 << "\n";

	//не работает :c
	//String str8 = "Hello";
	//str8 += str5;
	return 0;
}