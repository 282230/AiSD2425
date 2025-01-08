#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void AS_DYNAM(int s[], int f[], int n){
    int max_zajec[n];  
    int poprzedni[n];  

    for (int i = 0; i < n; i++){
        max_zajec[i] = 1;
        poprzedni[i] = -1;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (f[j] <= s[i]){
                if (max_zajec[j] + 1 > max_zajec[i]){//sprawdzenie czy wiecej zajec
                    max_zajec[i] = max_zajec[j] + 1;
                    poprzedni[i] = j;
                }
            }
        }
    }


    int index_max = 0;
    for (int i = 1; i < n; i++){
        if (max_zajec[i] > max_zajec[index_max]){//wybor maksymalnego zestawu
            index_max = i;
        }
    }


    int wynik[n];
    int ilosc = 0;

    while (index_max != -1){
        wynik[ilosc++] = index_max + 1;
        index_max = poprzedni[index_max];
    }


    cout << "prog. dynamiczne: ";
    for (int i = ilosc - 1; i >= 0; i--){
        cout << wynik[i] << " ";
    }
    cout << endl;
}

int main(){

    int s[] = {1,2,3,4,5,6};
    int f[] = {3,5,9,5,6,8};

    int n = sizeof(s) / sizeof(s[0]);

    AS_DYNAM(s, f, n);

    return 0;
}
