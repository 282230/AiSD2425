#include <iostream>
using namespace std;

void WYPISZ_TABLICE(int A[], int n){
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

int MAX(int A[], int n){
    int max = A[0];
    for(int i = 1; i < n; i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}

int MIN(int A[], int n){
    int min = A[0];
    for(int i = 1; i < n; i++){
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}

void COUNTING_SORT0(int A[], int B[], int k, int n){
    int C[k+1] = {0};
    for(int j = 0; j < n; j++){
        C[A[j]]++;
    }
    for(int i = 1; i <= k; i++){
        C[i] += C[i-1];
    }
    for(int j = n-1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void COUNTING_SORT(int A[], int B[], int n, int k, int d){
    int C[d] = {0};

    for(int j = 0; j < n; j++){
        C[(A[j]/k)%d]++;
    }

    for(int i = 1; i < d; i++){
        C[i] += C[i-1];
    }

    for(int j = n-1; j >= 0; j--){
        B[C[(A[j]/k) % d] -1] = A[j];
        C[(A[j]/k) % d]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

}

void RADIX_SORT(int A[], int n, int d){
    int max = MAX(A,n);
    int B[n];
    for(int k = 1; max/k > 0; k *= 10){
        COUNTING_SORT(A,B,n,k,d);
    }
}

//modyfikacja
void RADIX_SORT_ZMOD(int A[], int n, int d){
    int min = MIN(A,n);
    if(min>=0){
        int max = MAX(A,n);
        int B[n];
        for(int k = 1; max/k > 0; k*=10){
            COUNTING_SORT(A,B,n,k,d);
        }
    }else{
        for(int i = 0; i < n; i++){
            A[i] = A[i] - min;
        }
        int max = MAX(A,n);
        int B[n];
        for(int k = 1; max/k > 0; k*=10){
            COUNTING_SORT(A,B,n,k,d);
        }
        for(int i = 0; i < n; i++){
            A[i] = A[i] + min;
        }

    }

}

int main(){
    int A[] = {5, 1, 4, 2, 8, 6, 3, 7,};
    int n = sizeof(A)/sizeof(A[0]);
    int B[n];
    int d = 10;//system liczbowy - tutaj w systemie dziesiatkowym
    RADIX_SORT_ZMOD(A,n,d);
    WYPISZ_TABLICE(A,n);

    return 0;
}
