#include <iostream>
using namespace std;

void WYPISZ_TABLICE(int A[], int n){
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

int PARTITION(int A[], int p, int k){
    int x = A[k];
    int i = p - 1;
    for(int j = p; j < k; j++){
        if(A[j] <= x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[k],A[i+1]);
    return(i+1);
}


void QUICK_SORT(int A[],int p, int k){
    if(p<k){
        int s = PARTITION(A,p,k);
        QUICK_SORT(A,p,s-1);
        QUICK_SORT(A,s+1,k);
    }
}

//modyfikacja
void PARTITION_ZMOD(int A[], int p, int k, int& s1, int& s2){
    if(A[p]>A[k]){
        swap(A[p],A[k]);
    }

    int x1 = A[p];
    int x2 = A[k];
    int i1 = p + 1;
    int i2 = k - 1;

    for(int j = p+1; j <= i2; j++){
        if(A[j] < x1){
            swap(A[i1],A[j]);
            i1++;
        }else if(A[j] > x2){
            swap(A[j],A[i2]);
            i2--;
            j--;
        }
    }
    swap(A[p],A[i1-1]);
    swap(A[k],A[i2+1]);
    s1 = i1-1;
    s2 = i2+1;
}

void QUICK_SORT_ZMOD(int A[], int p, int k){
    if(p<k){
        int s1,s2;
        PARTITION_ZMOD(A,p,k,s1,s2);
        QUICK_SORT_ZMOD(A,p,s1-1);
        QUICK_SORT_ZMOD(A,s1+1,s2-1);
        QUICK_SORT_ZMOD(A,s2+1,k);
    }
}


int main(){
    int A[] = {5, 1, 4, 2, 8, 6, 3, 7};
    int n = sizeof(A)/sizeof(A[0]);

    QUICK_SORT_ZMOD(A,0,n-1);
    WYPISZ_TABLICE(A,n);

    return 0;
}
