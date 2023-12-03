#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

const int MAX_LEN = 100;

void findAdditions(const char* s, int target, char* current, int index, int currentSum, int& found) {
    if (s[index] == '\0') {
        if (currentSum == target) {
            cout << current << "=" << target << endl;
            found++;
        }
        return;
    }
    int num = 0;
    size_t currentLength = strlen(current);

    for (int i = index; s[i] != '\0'; i++) {
        num = num * 10 + (s[i] - '0');

        if (index == 0) {
            sprintf_s(current + currentLength, MAX_LEN * 2 - currentLength, "%d", num);
        }
        else {
            sprintf_s(current + currentLength, MAX_LEN * 2 - currentLength, "+%d", num);
        }

        findAdditions(s, target, current, i + 1, index == 0 ? num : currentSum + num, found);
        current[currentLength] = '\0';
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char s[MAX_LEN];
    int a;
    cout << "Введіть число s: ";
    cin >> s;
    cout << "Введіть число a: ";
    cin >> a;
    char current[MAX_LEN * 2] = { 0 };
    int found = 0;
    findAdditions(s, a, current, 0, 0, found);
    if (found == 0) {
        cout << "Неможливо знайти рішення." << endl;
    }

    return 0;
}
