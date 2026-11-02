#include <iostream>
using std::cout;

int cnt = 0;

void merge(int* a, int* tmp, int left, int mid, int right) {
    int i = left;        
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        cnt = cnt + 1;
        if (a[i] <= a[j]) {
            tmp[k] = a[i];
            i = i + 1;
        }
        else {
            tmp[k] = a[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= mid)   
        tmp[k++] = a[i++];  
    while (j <= right) 
        tmp[k++] = a[j++];  

    for (int t = left; t <= right; t++)     
        a[t] = tmp[t];
}

void mergeSort(int* a, int* tmp, int left, int right) {
    if (left >= right) return;              

    int mid = (left + right) / 2;
    mergeSort(a, tmp, left, mid);          
    mergeSort(a, tmp, mid + 1, right);     
    merge(a, tmp, left, mid, right);      
}

int main() {
    int a[] = {1, 3, 2, 4, 8, 5, 7, 6};
    int tmp[8];
    mergeSort(a, tmp, 0, 7);

    cout << cnt << '\n';
    for (int i = 0; i < 8; i++) cout << a[i] << ' ';
    cout << std::endl;
}