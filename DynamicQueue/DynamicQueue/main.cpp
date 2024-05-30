#include <iostream>
#define SIZE 3
using namespace std;

class DynamicQueue {
private:
	int* buffer = nullptr;
	int size = SIZE;
	int start = -1;
	int end = -1;
public:
	//Конструкторы
	DynamicQueue() {
		buffer = new int[size];
	}
	DynamicQueue(const DynamicQueue& other) {
		size = other.GetSize();
		start = 0;
		end = size - 1;
		int* tempBuffer = buffer;
		buffer = new int[size];
		for (int i = 0, j = other.start; j != other.end;) {
			buffer[i] = other.buffer[j];
			i += 1;
			j = (j + 1) % other.size;
		}
		buffer[end] = other.buffer[other.end];
		delete[] tempBuffer;
	}
	~DynamicQueue() {
		delete[] buffer;
	}

	//Методы
	bool IsEmpty() const {
		return (start == end && start == -1);
	}

	bool IsFull() const {
		return ((end + 1) % size == start);
	}

	void push_front(int value) {
		if (this->IsEmpty()) {
			*buffer = value;
			start = end = 0;
		}
		else if (this->IsFull()) {
			int* tempBuffer = buffer;
			buffer = new int[size + 1];
			*buffer = value;
			for (int i = 1, j = start; j != end;) {
				buffer[i] = tempBuffer[j];
				j = (j + 1) % size;
				i += 1;
			}
			buffer[size] = tempBuffer[end];	//копируем последний элемент
			delete[] tempBuffer;
			size += 1;
			start = 0;
			end = size - 1;
		}
		else {
			start = (start - 1 + size) % size;
			buffer[start] = value;
		}
	}

	void push_back(int value) {
		if (this->IsEmpty()) {
			*buffer = value;
			start = end = 0;
		}
		else if (this->IsFull()) {
			int* tempBuffer = buffer;
			buffer = new int[size + 1];
			for (int i = 0, j = start; j != end;) {
				buffer[i] = tempBuffer[j];
				j = (j + 1) % size;
				i += 1;
			}
			buffer[size - 1] = tempBuffer[end];
			buffer[size] = value;
			delete[] tempBuffer;
			size += 1;
			start = 0;
			end = size - 1;
		}
		else {
			end = (end + 1) % size;
			buffer[end] = value;
		}
	}

	void pop_front() {
		if (this->IsEmpty()) {
			cout << "Queue is empty\n";
		}
		else if (end == start) {
			end = start = -1;
		}
		else {
			start = (start + 1) % size;
		}
	}

	void pop_back() {
		if (this->IsEmpty()) {
			cout << "Queue is empty\n";
		}
		else if (end == start) {
			end = start = -1;
		}
		else {
			end = (end - 1 + size) % size;
		}
	}

	int get_front() const {
		if (this->IsEmpty()) {
			cout << "not get_front... Queue is empty\n";
			exit(1);
		}
		else {
			return buffer[start];
		}
	}

	int get_back() const {
		if (this->IsEmpty()) {
			cout << "not get_back... Queue is empty\n";
			exit(1);
		}
		else {
			return buffer[end];
		}
	}

	int GetSize() const {
		if (this->IsEmpty()) {
			return 0;
		}
		else if (this->IsFull()) {
			return size;
		}
		else {
			if (start <= end) {
				return end - start + 1;
			}
			else {
				return size - (start - end - 1);
			}
		}
	}

	void print() const {
		if (this->IsEmpty()) {
			cout << "Queue is empty\n";
			return;
		}

		for (int i = start; i != end; ) {
			cout << buffer[i] << " ";
			i = (i + 1) % size;
		}
		cout << buffer[end];
		cout << "\n";
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	DynamicQueue dq1;
	dq1.print();	//Queue is empty
	dq1.pop_back();	//Queue is empty
	dq1.pop_front();	//Queue is empty
	//dq1.get_back() так же как и при dq1.get_front() выводит сообщение "not get_back... Queue is empty"
	//и программа завершает работу
	cout << dq1.GetSize() << "\n";	// 0

	dq1.push_back(4);
	dq1.push_front(7);
	dq1.push_back(9);
	dq1.push_front(1);	//1, 7, 4, 9
	dq1.print();

	dq1.pop_back();
	dq1.pop_front();
	cout << dq1.GetSize() << "\n";	// 2
	dq1.print();	//7, 4

	DynamicQueue dq2(dq1);
	dq2.push_front(0);
	dq2.print();	//0, 7, 4
	cout << dq2.GetSize() << "\n";	//3
	dq1.print();	//7, 4 - не поменялся
	return 0;
}
