#include <iostream>
#include <climits>
using namespace std;

int LCS_REK(const string &X, const string &Y, int m, int n, int **b){
    if(m==0 || n==0) return 0;
    if(b[m][n] != -1) return b[m][n]; //juz wpisane
    if(X[m-1] == Y[n-1]) return b[m][n] = 1 + LCS_REK(X,Y,m-1,n-1,b);//sprawdz ostatni
    return b[m][n] = max(LCS_REK(X,Y,m,n-1,b),LCS_REK(X,Y,m-1,n,b));//wynik    
}

void LCS_REK_SOLUTION(const string &X, const string &Y){
    int m = X.length();
    int n = Y.length();

    int **b = new int*[m+1];
    for(int i = 0; i<=m; i++){
        b[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            b[i][j] = -1;
        }
    }

    int k = LCS_REK(X,Y,m,n,b);

    string p = "";
    int i = m;
    int j = n;
    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
            p = X[i-1]+p;
            i--;
            j--;
        }else if(b[i-1][j] > b[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    cout << "dlugosc podciagu: " << k << endl;
    cout << "podciag: " << p << endl;

    delete[] b;

}
//oznaczenia strzałek: g - w gore, l - w lewo, s - na skos
char** LCS_ITEROWANE(string& X, string& Y, int& d){
    int m = X.length();
    int n = Y.length();

    char** b = new char*[m+1];
    int** c = new int*[m+1];

    for(int i = 0; i <= m; i++){
        b[i] = new char[n+1];
        c[i] = new int[n+1];
    }

    for(int j = 0; j<=m; j++){
        c[j][0] = 0;
    }
    for(int j = 0; j<=n; j++){
        c[0][j] = 0;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 's';
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'g';
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'l';
            }
        }
    }
    d = c[m][n];
    return b;
}

void PRINT_SOLUTION(char** b, string& X, int i, int j){
    if(i>0 && j>0){
        if(b[i][j] == 's'){
            PRINT_SOLUTION(b,X,i-1,j-1);
            cout << X[i - 1];
        }else if(b[i][j] == 'g'){
            PRINT_SOLUTION(b,X,i-1,j);
        }else{
            PRINT_SOLUTION(b,X,i,j-1);
        }

    }
}


int main(){
    string n1 = "WAWVBUECQUOLAQGYC";
    string n2  = "QWZSCRFVTGBUNJIO";
    LCS_REK_SOLUTION(n1,n2);

    int d;
    char** b = LCS_ITEROWANE(n1,n2,d);
    cout << "dlugosc " << d << endl;

    PRINT_SOLUTION(b,n1,n1.length(),n2.length());
    cout<<endl;
    return 0;
}