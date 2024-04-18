#include <iostream>
#include <fstream>
using namespace std;

int  multiply5(int n, ofstream& oop) {
    for (int i = 0; i < n; ++i) {
        cout << "Enter a number between 1000 and 5000: " << endl;
        int b;
        cin >> b;

        while (b < 1000 || b > 5000) {
            cout << "Please enter a value between 1000 and 5000" << endl;
            cin >> b;
        }
        b *= 5;
        oop.write((char*)&b, sizeof(b));
    }
    return 5;
}

float abcd(float n, ofstream& oop) {
    float c = -0.5;
    for (int i = 0; i < n; ++i) {
        float c2;
        c2 = c * c;
        c += 0.5;
        oop.write((char*)&c2, sizeof(c2));
    }
    return 6;
}

int main() {
    ofstream oop;
    oop.open("mybin.dat", ios::binary | ios::out);
    if (!oop) {
        cout << "Can't open mybin.dat\n";
        return 666;
    }

    int a = 1234;
    oop.write((char*)&a, sizeof(a));

    multiply5(5,oop);
    abcd(3,oop);

    oop.close();
    return 0;
}
