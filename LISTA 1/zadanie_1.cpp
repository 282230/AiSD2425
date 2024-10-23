#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

void TABLICA(int A[], int n){
    for(int i = 0; i < n; i++){
        A[i] = rand() % 101;
    }
}

void WYPISZ_TABLICE(int A[], int n){
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

void INSERTION_SORT(int A[], int n){
    for (int i = 1; i < n; i++){
        int key = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j = j-1;
        A[j+1] = key;
        }
    }
}

void INSERTION_SORT_ZMOD(int A[], int n) {
    for (int i = 1; i < n; i += 2) {
        int key1 = A[i - 1];
        int key2 = A[i];
        if (key1 > key2) {
            swap(key1, key2);
        }
        int j = i - 2;

        while (j >= 0 && A[j] > key2) {
            A[j + 2] = A[j];
            j--;
        }

        A[j + 2] = key2;

        while (j >= 0 && A[j] > key1) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key1;
    }

    if (n % 2 != 0) {
        int key = A[n-1];
        int j = n - 2;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j = j-1;
        
        }
        A[j+1] = key;
    }
    
}
int main(){
    int A[] = {3, 2, 5, 1, 7, 4, 6};
    int n = sizeof(A)/sizeof(A[0]);

    INSERTION_SORT_ZMOD(A,n);
    WYPISZ_TABLICE(A,n);

    return 0;
}