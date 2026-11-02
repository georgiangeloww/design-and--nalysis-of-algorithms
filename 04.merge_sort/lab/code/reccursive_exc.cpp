#include <iostream>
using namespace std;

int maxRange(int* a, int left, int right) {
    if (left == right) return a[left];          // single element

    int mid = (left + right) / 2;
    int l = maxRange(a, left, mid);             // line A
    int r = maxRange(a, mid + 1, right);        // line B
    return l > r ? l : r;                       // line C
}

int main() {
    int a[] = {3, 4, 2, 4, 5, 4, 1};
    cout << maxRange(a, 4, 6) << endl;          // prints 6
}