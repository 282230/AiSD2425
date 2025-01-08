#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void RECURSIVE_ACTIVITY_SELECTOR(int s[], int f[], int k, int n, int wyniki[], int& ilosc){
    int m = k+1;
    while(m<=n && s[m] < f[k]){
        m++;
    }

    if(m<=n){
        wyniki[ilosc++] = m;//dodajemy do zajęć
        RECURSIVE_ACTIVITY_SELECTOR(s,f,m,n,wyniki,ilosc);
    }
}

void PRINT_RAS(int s[], int f[], int n){
    int* wyniki = new int[n];
    int ilosc = 0;

    RECURSIVE_ACTIVITY_SELECTOR(s,f,0,n,wyniki,ilosc);
    cout << "rekurencja:" <<endl;
    for(int i = 0; i < ilosc; i++){
        cout << wyniki[i] << " ";
        
    }
    cout<<endl;

    
}

void ACTIVITY_SELECTOR(int s[], int f[], int n, int wyniki[], int& ilosc){
    int k = 1;//poczatek
    wyniki[ilosc++] = 1;//pierwsze zajecia

    for(int m = 2; m <= n; m++){
        if(s[m] >= f[k]){
            wyniki[ilosc++] = m;
            k = m;
        }
    }

}

void PRINT_AS(int s[], int f[], int n){
    int wyniki[n];
    int ilosc = 0;

    ACTIVITY_SELECTOR(s,f,n,wyniki,ilosc);

    cout << "iteracyjna:"<<endl;
    for(int i = 0; i<ilosc; i++){
        cout << wyniki[i] << " ";
        
    }
    cout << endl;
}

int main(){
    int s[] = {0,1,2,3,4,5,6};//pierwszy element jest sztuczny
    int f[] = {INT_MIN,3,5,9,5,6,8};//pierwszy ustawiony na '−∞'
    int n = sizeof(s)/sizeof(s[0]) - 1;

    PRINT_AS(s,f,n);
    PRINT_RAS(s,f,n);

    return 0;
}