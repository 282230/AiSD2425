#include <iostream>
#include <climits>
using namespace std;

int CUT_ROD(int p[], int n){
    if(n==0) return 0;

    int q = INT_MIN;
    for(int i = 1; i <= n; i++){
        q = max(q,p[i]+CUT_ROD(p,n-i));
    }
    return q;
}

int MEMORIZED_CUT_ROD(int p[], int r[], int s[], int n){
    if(r[n] >= 0) return r[n];
    int q;
    if(n==0){
        q = 0;
    }else{
        q = INT_MIN;
        for(int i = 1; i <= n; i++){
            int t = p[i] + MEMORIZED_CUT_ROD(p,r,s,n-i);
            if(q < t){
                q = t;
                s[n] = i;
            }
        }
        
    }
    r[n] = q;
    return q;
}

void PRINT_SOLUTION_MEMORIZED(int p[], int n) {
    int r[n + 1];
    int s[n + 1];
    for (int i = 0; i <= n; ++i) r[i] = -1;
    int zysk_max = MEMORIZED_CUT_ROD(p, r, s, n);

    cout << "max zysk memorized: " << zysk_max << endl;

    while (n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;
}

void EXT_BOT_UP_CUT_ROD(int p[], int n, int r[], int s[]){
    r[0] = 0;

    for(int j = 1; j <= n; j++){
        int q = INT_MIN;
        for(int i = 1; i <= j; i++){
            if(q < p[i]+r[j-i]){
                q = p[i]+r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

void PRINT_SOLUTION_EXT(int p[], int n){
    int r[n+1];
    int s[n+1];

    EXT_BOT_UP_CUT_ROD(p,n,r,s);

    cout << "max zysk iteracyjny: " << r[n] << endl;

    while(n>0){
        cout << s[n] << " ";
        n -= s[n];
    }

}

int main(){
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; //tablica cen
    int n = 4; //dlugosc
    cout << "Maksymalny zysk: " << CUT_ROD(p, n) << endl;

    PRINT_SOLUTION_MEMORIZED(p,n);
    
    PRINT_SOLUTION_EXT(p,n);
    return 0;
}