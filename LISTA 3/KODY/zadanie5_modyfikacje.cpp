#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Zajecia {
    int poczatek;  
    int koniec; 
    int index;  
};

void RAS_MOD(Zajecia lista_zajec[], int k, int n, int wyniki[], int& ilosc) {
    int m = k + 1;
    while (m <= n && lista_zajec[m].poczatek < lista_zajec[k].koniec){
        m++;
    }

    if (m <= n){
        wyniki[ilosc++] = lista_zajec[m].index; 
        RAS_MOD(lista_zajec, m, n, wyniki, ilosc); 
    }
}

void PRINT_RAS_MOD(Zajecia lista_zajec[], int n){
    int wyniki[n];
    int ilosc = 0;

    RAS_MOD(lista_zajec, 0, n, wyniki, ilosc);
    cout << "rekurencja modyfikacja:" <<endl;
    for(int i = 0; i < ilosc; i++){
        cout << wyniki[i] << " ";
        
    }
    cout<<endl;    
}

void AS_MOD(Zajecia lista_zajec[], int n, int wyniki[], int& ilosc){
    wyniki[ilosc++] = lista_zajec[1].index;
    int k = 1;

    for(int m = 2; m<=n; m++){
        if(lista_zajec[m].poczatek >= lista_zajec[k].koniec){
            wyniki[ilosc++] = lista_zajec[m].index;
            k = m;
        }
    }
}

void PRINT_AS_MOD(Zajecia lista_zajec[], int n){
    int wyniki[n];
    int ilosc = 0;

    AS_MOD(lista_zajec,n,wyniki,ilosc);

    cout << "iteracja modyfikacja:" <<endl;
    for(int i = 0; i < ilosc; i++){
        cout << wyniki[i] << " ";
        
    }
    cout<<endl; 
}

int main(){
    int s[] = {0,1,2,3,4,5,6};//pierwszy element jest sztuczny
    int f[] = {INT_MIN,3,5,9,5,6,8};//pierwszy ustawiony na '−∞'
    int n = sizeof(s)/sizeof(s[0]) - 1;



    Zajecia lista_zajec[n+1];
    for(int i = 0; i <= n; i++){
        lista_zajec[i] = {s[i], f[i], i};
    }
    sort(lista_zajec, lista_zajec + n, [](const Zajecia& a, const Zajecia& b) {
        return a.koniec < b.koniec;
    });

    PRINT_RAS_MOD(lista_zajec,n);
    PRINT_AS_MOD(lista_zajec,n);
    return 0;
}