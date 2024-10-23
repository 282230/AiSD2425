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

void MERGE(int A[], int p, int s, int k) {
    int n1 = s - p + 1;
    int n2 = k - s;

    int L[n1 + 1];
    int P[n2 + 1];

    for (int i = 0; i <= n1; i++) {
        L[i] = A[i+p];
        przypisania++;
    }
    for (int j = 0 ; j <= n2; j++) {
        P[j] = A[s+1+j];
        przypisania++;
    }
    L[n1] = std::numeric_limits<int>::max();
    P[n2] = std::numeric_limits<int>::max();
    przypisania += 2;

    int i = 0;
    int j = 0;
    for (int l = p; l <= k; l++) {
        if (P[j] <= L[i]) {
            porownania++;
            A[l] = P[j];
            przypisania++;
            j++;
        } else {
            porownania++;
            A[l] = L[i];
            przypisania++;
            i++;
        }
    }
}
void MERGE_SORT(int A[], int p, int k){
    if (p < k){
        int s = ((p+k)/ 2);
        MERGE_SORT(A, p, s);
        MERGE_SORT(A, s + 1, k);
        MERGE(A, p, s, k);


    }
}

//modyfikacja
void MERGE_ZMOD(int A[], int p, int s1, int s2, int k) {
    int n1 = s1 - p + 1;
    int n2 = s2 - s1;
    int n3 = k - s2;

    int L[n1 + 1];
    int S[n2 + 1];
    int P[n3 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
        przypisania++;
    for (int j = 0; j < n2; j++)
        S[j] = A[s1 + 1 + j];
        przypisania++;
    for (int h = 0; h < n3; h++)
        P[h] = A[s2 + 1 + h];
        przypisania++;

    L[n1] = std::numeric_limits<int>::max();
    S[n2] = std::numeric_limits<int>::max();
    P[n3] = std::numeric_limits<int>::max();
    przypisania += 3;

    int i = 0;
    int j = 0;
    int h = 0;

    for (int l = p; l <= k; l++) {
        if (L[i] <= S[j] && L[i] <= P[h]) {
            porownania += 2;
            A[l] = L[i];
            przypisania++;
            i++;
        } else if (S[j] <= L[i] && S[j] <= P[h]) {
            porownania += 2;
            A[l] = S[j];
            przypisania++;
            j++;
        } else {
            porownania += 2;
            A[l] = P[h];
            przypisania++;
            h++;
        }
    }
}

void MERGE_SORT_ZMOD(int A[], int p, int k) {
    if (p < k) {
        int s1 = p + (k - p) / 3;
        int s2 = p + 2 * (k - p) / 3;

        MERGE_SORT_ZMOD(A, p, s1);
        MERGE_SORT_ZMOD(A, s1 + 1, s2);
        MERGE_SORT_ZMOD(A, s2 + 1, k);

        MERGE_ZMOD(A, p, s1, s2, k);
    }
}


int main(){

    przypisania = 0;
    porownania = 0;

    int A[] = {5, 1, 4, 2, 8, 6, 3, 7};
    int n = sizeof(A)/sizeof(A[0]);

    MERGE_SORT(A,0,n-1);
    //MERGE_SORT_ZMOD(A,0,n-1);
    WYPISZ_TABLICE(A,n);

    cout<<"przypisania:"<<przypisania<<endl;
    cout<<"porównania:"<<porownania<<endl;

    return 0;
}