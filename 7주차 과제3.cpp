#include <iostream>
#include <fstream>
using namespace std;

// 정수 함수
int mult5(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter a number between 1000 and 5000: ";
        cin >> arr[i];
        while (arr[i] < 1000 || arr[i] > 5000) {
            cout << "Enter a number between 1000 and 5000 again: ";
            cin >> arr[i];
        }
        arr[i] *= 5;
    }
    return 12;
}

// 실수 함수
void square(float* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (i == 0)
            arr[i] = -0.5;
        else if (i == 1)
            arr[i] = 0.0;
        else if (i == 2)
            arr[i] = 0.5;
        arr[i] *= arr[i];
    }
}

int main() {
    int integers[5];
    float floats[5];

    const int intCount = 5;
    mult5(integers, intCount);

    const int floatCount = 3;
    square(floats, floatCount);

    ofstream outFile("mybin.dat", ios::binary | ios::out);
    if (outFile.is_open()) {
        int value = 1234;

        outFile.write((char*)&value, sizeof(value));
        outFile.write((char*)&integers, sizeof(integers));
        outFile.write((char*)&floats, sizeof(floats));
        outFile.close();

        cout << "Results saved to mybin.dat" << endl;
    }
    else {
        cout << "Error: Unable to open file for writing." << endl;
    }

    return 0;
}