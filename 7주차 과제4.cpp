#include <iostream>
#include <fstream>
using namespace std;
//정수 함수
int mult5(int* ii, int x) {
    if (x == 0) {
        ii[x] = 1234;
    }
    else {
        cout << " Enter number 1000~5000" << endl;
        cin >> ii[x];
        while (ii[x] < 1000 or ii[x] >5000) {
            cout << " Enter number between 1000 and 5000 again" << endl;
            cin >> ii[x];
        }
        ii[x] *= 5;
    }
    return ii[x];

}
int All(int* ii, int x) {

    return mult5(ii, x);
}
//실수 함수
float square(float* ii, int x) {
    ii[x] = (-0.5 + 0.5 * x) * (-0.5 + 0.5 * x);
    return ii[x];
}

float All(float* ii, int x) {

    return square(ii, x);
}
void main() {
    int a[6];
    float b[5];
    for (int i = 0; i < 6; i++) {
        a[i] = All(a, i);
    }
    for (int i = 0; i < 5; i++) {
        b[i] = All(b, i);
    }
    ofstream hw7;
    hw7.open("mybin.dat", ios::binary | ios::out);
    hw7.write((char*)&a, 24);
    hw7.write((char*)&b, 20);
    hw7.close();

    ifstream hw;
    hw.open("mybin.dat", ios::binary | ios::in);
    hw.read((char*)&a, 24);
    hw.read((char*)&b, 20);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << b[i] << endl;
    }
}