#include <iostream>
using namespace std;

class Complex {
private:
	double re;
	double im;

public:
	Complex() { re = 0.0; im = 0.0; }
	Complex(double re, double im) {
		this->re = re;
		this->im = im;
	}

	void print() {
		cout << "Действительная часть: " << re << "\nМнимая часть: " << im << "\n\n";
	}

	Complex add(const Complex& b) const {
		double temp_re = this->re + b.re;
		double temp_im = this->im + b.im;
		return Complex(temp_re, temp_im);
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	Complex X;				//re = 0, im = 0
	Complex Y(1.2, 4.3);	//re = 1.2, im = 4.3
	X.print();
	Y.print();
	Complex Z = Y.add(Complex(-2.1, 5.6));	//re = -0.9, im = 9.9
	Z.print();
	Complex XX = Z.add(Y);	//re = 0.3, im = 14.2
	XX.print();
	return 0;
}
