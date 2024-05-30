#include <iostream>
#define SIZE 10	//Размер стека
using namespace std;

class Stack {
private:
	int arr[SIZE];
	int total = 0;
public:
	Stack() {}
	Stack(int elem) { arr[0] = elem; total = 1; }

	// Список методов
	int countElem() { //Метод, который выводит текущее кол-во элементов в стеке
		cout << "В стеке: " << total << " элементов" << endl;
		return total;
	}

	bool isEmpty() { //  Метод, проверяющий пуст ли стек
		return (total == 0) ? true : false;
	}

	bool isFull() { //  Метод проверки полон ли стек
		return (total == SIZE) ? true : false;
	}

	void push(int elem) { // Положить элемент в стек
		if (total < SIZE) {
			arr[total] = elem;
			total++;
		}
		else {
			cout << "В стеке нет свободного места" << endl;
		}
	}

	void pop() { // Удалить элемент из стека
		if (isEmpty()) {
			cout << "Нельзя удалить элемент из пустого стека" << endl;
		}
		else {
			total--;
		}
	}

	int get_top() const {
		if (total == 0) {
			cout << "Стек пуск" << endl;
			return 0;
		}
		else {
			return arr[total - 1];
		}
	}

	void print() {
		for (int i = total - 1; i != -1; i--) {
			cout << arr[i] << " ";
		}
	}

};




int main() {
	setlocale(LC_ALL, "rus");
	Stack s1, s2(1);
	s1.countElem();
	s2.countElem();
	cout << (int)s1.isEmpty() << endl;
	cout << (int)s2.isEmpty() << endl;
	cout << (int)s1.isFull() << endl;
	cout << (int)s2.isFull() << endl;
	s1.pop();
	s2.pop();

	int i = 0;
	for (i; i <= 12; i++) {
		s1.push(i);
		s2.push(i + 123);
	}

	cout << (int)s1.isFull() << endl;
	cout << (int)s2.isFull() << endl;
	s1.print();
	s2.print();
	cout << endl << s1.get_top() << endl;
	cout << s2.get_top() << endl;

	s1.pop();
	s1.print();
	s1.countElem();
	cout << (int)s1.isFull() << endl;
	cout << (int)s2.isFull() << endl;
	return 0;
}
