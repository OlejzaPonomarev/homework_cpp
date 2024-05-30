#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
	int re;
	int im;

public:
	Complex() { re = 0; im = 0; }
	Complex(int re, int im) { this->re = re; this->im = im; }
	~Complex() {}

	friend Complex operator + (double temp, const Complex& other);

	void Print() {
		cout << "Действительная часть объекта " << this << " : " << re << "\n";
		cout << "Мнимая часть объекта " << this << " : " << im << "\n\n";
	}

	int GetRe() {
		return re;
	}

	const Complex& operator ++ () { //Префиксная перегрузка
		this->re++;
		this->im++;
		return *this;
	}

	const Complex& operator ++ (int) {//Постфиксная перегрузка
		Complex temp = *this;
		this->re++;
		this->im++;
		return temp;
	}

	const Complex& operator = (const Complex temp) {
		this->re = temp.re;
		this->im = temp.im;
		return *this;
	}

	Complex& operator () (const Complex& temp1, const Complex& temp2) {
		this->re += (temp1.re + temp2.re);
		this->im += (temp1.im + temp2.im);
		return *this;
	}
};

Complex operator + (double temp, const Complex& other) {
	int temp_re = int(temp);
	string t = to_string(temp - int(temp));
	t.erase(0, 2);	//Избавляется от "0." в начале строки 
	int temp_im = stoi(t);
	while (temp_im % 10 == 0) {
		temp_im /= 10;
	}
	return Complex(temp_re + other.re, temp_im + other.im);
}

int main() {
	setlocale(LC_ALL, "rus");
	Complex X(10, 11);
	Complex Y(12, 13);
	X.Print();
	Y.Print();

	cout << "\nПроверяем работу префиксоного и постфиксного инкремента\n";
	cout << "++X; Y++;\n";
	++X;
	Y++;
	X.Print();
	Y.Print();

	cout << "\nПроверяем приоритет работы префиксоного и постфиксного инкремента с помощью перегруженного оператора =\n";
	cout << "X = ++Y;\n";
	X = ++Y;
	X.Print();
	Y.Print();
	cout << "X = Y++;\n";
	X = Y++;
	X.Print();
	Y.Print();

	cout << "\nПроверка перегрузки оператора +\n";
	X.Print();
	Complex Z = 10.14 + X;
	Z.Print();

	cout << "\nПроверка перегрузки оператора ()\n";
	Complex XX(7, 8);
	XX.Print();
	X.Print();
	Z.Print();
	cout << "XX(X, Z);\n";
	XX(X, Z);
	XX.Print();
	return 0;
}
