#include <iostream>
#define SIZE 5
using namespace std;

class Deque {
	int buffer[SIZE];
	int end = -1;
	int start = -1;
	int size = SIZE;

public:
	Deque() = default;

	bool IsEmpty() const {
		return (end == start && end == -1);
	}

	bool IsFull() const {
		return ((end + 1) % size == start);
	}

	bool push_front(int value) {
		if (IsFull()) return false;
		if (IsEmpty()) {
			start = end = 0;
		}
		else {
			start = (start - 1 + size) % size;
		}
		buffer[start] = value;
		return true;
	}

	bool push_back(int value) {
		if (IsFull()) return false;
		if (IsEmpty()) {
			start = end = 0;
		}
		else {
			end = (end + 1) % size;
		}
		buffer[end] = value;
		return true;
	}

	bool pop_front() {
		if (IsEmpty()) return false;
		if (end == start) {
			start = end = -1;
		}
		else {
			start = (start + 1) % size;
		}
		return true;
	}

	bool pop_back() {
		if (IsEmpty()) return false;
		if (start == end) {
			start = end = -1;
		}
		else {
			end = (end - 1 + size) % size;
		}
		return true;
	}

	int get_front() const {
		if (IsEmpty()) { cout << "The Queue is empty : \n"; exit(1); }
		return buffer[start];
	}

	int get_back() const {
		if (IsEmpty()) { cout << "The Queue is empty : \n"; exit(1); }
		return buffer[end];
	}

	void print() {
		if (IsEmpty()) {
			std::cout << "Deque empty\n";
			return;
		}
		for (size_t i = start; i != end; ) {
			cout << buffer[i] << " ";
			i = (i + 1) % size;
		}
		cout << buffer[end];
		cout << "\n";
	}

	int GetSize() const {
		if (IsEmpty()) { return 0; }
		if (IsFull()) { return size; }
		else {
			if (start <= end) {
				return end - start + 1;
			}
			else {
				return size - (start - end - 1);
			}
		}
	}

};

int main() {
	Deque data;
	cout << data.IsEmpty() << "\n";	//true
	cout << data.IsFull() << "\n";	//false
	std::cout << data.GetSize() << "\n";
	data.print();

	data.push_front(14);
	data.push_back(15);
	cout << data.IsEmpty() << "\n";	//false
	cout << data.IsFull() << "\n";	//false

	data.push_back(92);
	data.push_back(65);
	data.push_front(3);	//14, 15, 92, 65, 3 (start 4, end 3);
	cout << data.GetSize() << "\n";	//5
	data.print();
	cout << data.IsEmpty() << "\n";	//false
	cout << data.IsFull() << "\n";	//true

	cout << data.get_front() << "\n";	//3
	cout << data.get_back() << "\n";	//65

	data.pop_back();
	data.pop_front();
	data.print();	//14, 15, 92
	cout << data.GetSize() << "\n";	//3;
	return 0;
}

