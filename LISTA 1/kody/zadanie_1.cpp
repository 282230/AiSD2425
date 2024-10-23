#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

int przypisania = 0;
int porownania = 0;


void WYPISZ_TABLICE(int A[], int n){
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

void INSERTION_SORT(int A[], int n){
    for (int i = 1; i < n; i++){
        int key = A[i];
        przypisania++;
        int j = i - 1;
        while(j >= 0 && A[j] > key){
            porownania++;
            A[j+1] = A[j];
            przypisania++;
            j = j-1;
        A[j+1] = key;
        przypisania++;
        }
    }
}
//modyfikacja
void INSERTION_SORT_ZMOD(int A[], int n) {
    for (int i = 1; i < n; i += 2) {
        int key1 = A[i - 1];
        przypisania++;
        int key2 = A[i];
        przypisania++;
        if (key1 > key2) {
            swap(key1, key2);
            przypisania +=2;
        }
        
        int j = i - 2;

        while (j >= 0 && A[j] > key2) {
            porownania++;
            A[j + 2] = A[j];
            przypisania++;
            j--;
        }

        A[j + 2] = key2;
        przypisania++;

        while (j >= 0 && A[j] > key1) {
            porownania++;
            A[j + 1] = A[j];
            przypisania++;
            j--;
        }
        A[j + 1] = key1;
        przypisania++;
    }

    if (n % 2 != 0) {
        int key = A[n-1];
        przypisania++;
        int j = n - 2;
        while(j >= 0 && A[j] > key){
            porownania++;
            A[j+1] = A[j];
            przypisania++;
            j = j-1;
        
        }
        A[j+1] = key;
        przypisania++;
        porownania++;
    }
    
}
int main(){
    przypisania = 0;
    porownania = 0;

    int A[] = {5, 1, 4, 2, 8, 6, 3, 7};
    int n = sizeof(A)/sizeof(A[0]);

    INSERTION_SORT(A,n);
    //INSERTION_SORT_ZMOD(A,n);
    WYPISZ_TABLICE(A,n);

    cout<<"przypisania:"<<przypisania<<endl;
    cout<<"porównania:"<<porownania<<endl;

    return 0;
}