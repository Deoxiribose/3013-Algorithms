/*
Name: Jacob Bradley
Assignment: P1
Professor: Dr.Griffin
Date 5/6/24

*/




#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vector {
private:
    int* list;
    int size;
    int capacity;

public:
    // Constructors
    Vector() {
        size = 0;
        capacity = 10;
        list = new int[capacity];
    }

    Vector(int* A, int size) {
        this->size = size;
        capacity = size + 10;
        list = new int[capacity];
        for (int i = 0; i < size; i++) {
            list[i] = A[i];
        }
    }

    Vector(string FileName) {
        ifstream infile(FileName);
        size = 0;
        capacity = 10;
        list = new int[capacity];
        int val;
        while (infile >> val) {
            pushRear(val);
        }
        infile.close();
    }

    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        list = new int[capacity];
        for (int i = 0; i < size; i++) {
            list[i] = other.list[i];
        }
    }

    ~Vector() {
        delete[] list;
    }

    // Helper function to increase capacity
    void resize() {
        capacity *= 2;
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
    }

    // Adding items
    void pushFront(int val) {
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > 0; i--) {
            list[i] = list[i - 1];
        }
        list[0] = val;
        size++;
    }

    void pushFront(const Vector& other) {
        for (int i = other.size - 1; i >= 0; i--) {
            pushFront(other.list[i]);
        }
    }

    void pushRear(int val) {
        if (size == capacity) {
            resize();
        }
        list[size++] = val;
    }

    void pushRear(const Vector& other) {
        for (int i = 0; i < other.size; i++) {
            pushRear(other.list[i]);
        }
    }

    void inOrderPush(int val) {
        int i = size - 1;
        while (i >= 0 && list[i] > val) {
            list[i + 1] = list[i];
            i--;
        }
        list[i + 1] = val;
        size++;
    }

    // Removing items
    int popFront() {
        int val = list[0];
        for (int i = 0; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        return val;
    }

    int popRear() {
        int val = list[size - 1];
        size--;
        return val;
    }

    int popAt(int loc) {
        int val = list[loc];
        for (int i = loc; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        return val;
    }

    int find(int val) {
        for (int i = 0; i < size; i++) {
            if (list[i] == val) {
                return i;
            }
        }
        return -1;
    }

    // Printing
    void print() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << list[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    ofstream outfile("test.out");

    int x = 0;

    Vector v1;
    cout << "Enter elements for v1 (type -1 to stop): ";
    int val;
    while (cin >> val && val != -1) {
        v1.pushRear(val);
    }
    cout << "Jacob Bradley" << endl;
    cout << "5/6/2024" << endl;
    cout << "Spring 2024" << endl;
    cout << "" << endl;
    cout << "v1: ";
    v1.print();
    outfile << "Jacob Bradley" << endl;
    outfile << "5/6/2024" << endl;
    outfile << "Spring 2024" << endl;
    outfile << endl;
    outfile << "v1: ";
    v1.print();
    outfile << endl;

    int A[] = { 11,25,33,47,51 };
    Vector v2(A, 5);
    v2.print();
    outfile << "v2: ";
    v2.print();
    outfile << endl;

    v2.pushFront(9);
    v2.pushRear(63);
    v2.print();
    outfile << "v2 after adding front and rear: ";
    v2.print();
    outfile << endl;

    v1.pushRear(v2);
    v1.print();
    outfile << "v1 after pushing rear of v2: ";
    v1.print();
    outfile << endl;

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();
    outfile << "v1 after popping front three times: ";
    v1.print();
    outfile << x << endl;

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();
    outfile << "v1 after popping rear three times: ";
    v1.print();
    outfile << x << endl;

    x = v2.popAt(3);
    v2.print();
    outfile << "v2 after popping at index 3: ";
    v2.print();
    outfile << x << endl;

    x = v2.find(51);
    outfile << "Index of 51 in v2: " << x << endl;

    x = v2.find(99);
    outfile << "Index of 99 in v2: " << x << endl;

    Vector v3(v1);
    v3.print();
    outfile << "v3 copied from v1: ";
    v3.print();
    outfile << endl;

    v3.pushFront(v2);
    v3.print();
    outfile << "v3 after pushing front of v2: ";
    v3.print();
    outfile << endl;

    Vector v4("input.dat");
    v4.pushRear(v3);
    v4.print();
    outfile << "v4 after pushing rear of v3: ";
    v4.print();

    outfile.close();

    return 0;
}
