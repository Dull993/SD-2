#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    if (top < MAX - 1) {
        top++;
        stack[top] = value;
    }
}

char pop() {
    if (top >= 0) {
        char value = stack[top];
        top--;
        return value;
    }
    return '\0';
}

int main() {
    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    for (int i = 0; i < (int)kata.length(); i++) {
        push(kata[i]);
    }

        while (top >= 0) {
        cout << pop();
    }

    cout << endl;

    return 0;
}