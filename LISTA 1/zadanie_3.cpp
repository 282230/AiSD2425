#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

void WYPISZ_TABLICE(int A[], int n){
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int LEFT(int i) {
    return 2 * i + 1;
}

int RIGHT(int i) {
    return 2 * i + 2;
}

void HEAPIFY(int A[], int i, int n) {
    int l = LEFT(i); 
    int r = RIGHT(i);
    int largest = i;

    if (l < n && A[l] > A[i]) {
        largest = l;
    }

    if (r < n && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        HEAPIFY(A, largest, n);
    }
}

void BUILD_HEAP(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        HEAPIFY(A, i, n);
    }
}

void HEAP_SORT(int A[], int n) {
    BUILD_HEAP(A, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        n--;
        HEAPIFY(A, 0, n);  
    }
}

//modyfikacja
int LEFT_ZMOD(int i) {
    return 3 * i + 1;
}

int MID_ZMOD(int i) {
    return 3 * i + 2;
}

int RIGHT_ZMOD(int i) {
    return 3 * i + 3;
}

void HEAPIFY_ZMOD(int A[], int i, int n) {
    int l = LEFT_ZMOD(i);
    int s = MID_ZMOD(i);
    int p = RIGHT_ZMOD(i);
    int largest = i;

    if (l < n && A[l] > A[i]) {
        largest = l;
    }

    if (s < n && A[s] > A[largest]) {
        largest = s;
    }

    if (p < n && A[p] > A[largest]) {
        largest = p;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        HEAPIFY_ZMOD(A, largest, n);
    }
}

void BUILD_HEAP_ZMOD(int A[], int n) {
    for (int i = n / 3 - 1; i >= 0; i--) {
        HEAPIFY_ZMOD(A, i, n);
    }
}

void HEAP_SORT_ZMOD(int A[], int n) {
    BUILD_HEAP_ZMOD(A, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        n--;
        HEAPIFY_ZMOD(A, 0, n);
    }
}


int main(){
    int A[] = {3, 2, 5, 1, 7, 4, 6};
    int n = sizeof(A)/sizeof(A[0]);

    HEAP_SORT_ZMOD(A,n-1);
    WYPISZ_TABLICE(A,n);

    return 0;
}
