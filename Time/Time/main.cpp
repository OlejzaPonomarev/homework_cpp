#include <iostream>
using namespace std;

class Time {
private:
	int hours = 0, minutes = 0, seconds = 0;

public:
	Time() = default; //����������� �� ���������
	Time(int h, int m, int s) {
		//��������� ������ �������, ���� � ������
		m += s / 60;
		s %= 60;
		if (s < 0) {//���� ������������ ������ ������������� �����, �� �� ��� ���������
			m -= 1;
			s += 60;
		}

		h += m / 60;
		m %= 60;
		if (m < 0) {
			h -= 1;
			m += 60;
		}

		h %= 24;
		if (h < 0) {
			h += 24;
		}

		hours = h;
		minutes = m;
		seconds = s;

	}
	Time(int s) : Time(0, 0, s) {//������������ ������������
	};
	Time(int m, int s) : Time(0, m, s) {};

	//�������
	int getHours() const { return hours; }
	int getMinutes() const { return minutes; }
	int getSeconds() const { return seconds; }

	void addSeconds(int s) {
		seconds += s;
		minutes += seconds / 60;
		seconds %= 60;
		minutes += seconds / 60;
		seconds %= 60;
		if (seconds < 0) {//���� ������������ ������ ������������� �����, �� �� ��� ���������
			minutes -= 1;
			seconds += 60;
		}

		hours += minutes / 60;
		minutes %= 60;
		if (minutes < 0) {
			hours -= 1;
			minutes += 60;
		}

		hours %= 24;
		if (hours < 0) {
			hours += 24;
		}
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	Time t1;
	cout << "������� ������ t1 ��� �������� ��� ����������" << endl;
	cout << t1.getHours() << " " << t1.getMinutes() << " " << t1.getSeconds() << endl;
	cout << "�������� � ����� ������� 100 ������ (1 ������ 40 ���)" << endl;
	t1.addSeconds(100);
	cout << t1.getHours() << " " << t1.getMinutes() << " " << t1.getSeconds() << endl;
	t1.addSeconds(-200);
	cout << "����� �� ����� ������� 200 ������ (3 ������ 20 ������)" << endl;
	cout << t1.getHours() << " " << t1.getMinutes() << " " << t1.getSeconds() << endl;

	//������ ��������
	Time t2(100), t3(1, 20), t4(25, 1, 16);
	cout << t2.getHours() << " " << t2.getMinutes() << " " << t2.getSeconds() << endl;
	cout << t3.getHours() << " " << t3.getMinutes() << " " << t3.getSeconds() << endl;
	cout << t4.getHours() << " " << t4.getMinutes() << " " << t4.getSeconds() << endl;
	return 0;
}
