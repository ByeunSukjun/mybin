#include <iostream> // cout cin
#include <fstream>  // ifstream ofstream
using namespace std;

int main() {
	ofstream oop;
	oop.open("mybin.dat", ios::binary | ios::out);
	if (!oop) {
		cout << " can't open mybin.dat\n";
		return 666;
	}

	int a = 1234;

	oop.write((char*)&a, sizeof(a));

	for (int i = 0; i < 5; ++i) {
		int b;
		cout << "Enter a number between 1000 and 5000: " << endl;
		cin >> b;

		while (b < 1000 || b > 5000) {
			cout << "Please enter a value between 1000 and 5000" << endl;
			cin >> b;
		}

		b *= 5;
		oop.write((char*)&b, sizeof(b));
	}
	float  c = -0.5;

	for (int i = 0; i < 3; ++i) {
		float c2;
		c2 = c * c;// 입력된 float을 자승하여 파일에 저장
		oop.write((char*)&c2, sizeof(c2));
		c += 0.5; // 0.5씩 증가
	}

	oop.close();
	return 0;
}