#include <iostream>
using std::cout;

void merge(int* a, int* tmp, int left, int mid, int right) {
    int i = left;        
    int j = mid + 1;     
    int k = left;       

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else              tmp[k++] = a[j++];
    }
    while (i <= mid)   tmp[k++] = a[i++];  
    while (j <= right) tmp[k++] = a[j++];  

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
    int a[] = {1, 2, 4, 2, 4, 8, 0, 5, 4, 1};
    int tmp[10];
    mergeSort(a, tmp, 0, 9);

    for (int i = 0; i < 10; i++) cout << a[i] << ' ';
    cout << std::endl;
}