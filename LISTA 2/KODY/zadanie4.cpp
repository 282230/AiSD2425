#include <iostream>
using namespace std;

struct Node{
    double key;
    Node* prev;
    Node* next;
    Node(double value):key(value),prev(nullptr),next(nullptr){}
};

struct List{
    Node* head;
    List():head(nullptr){}
};
void WYPISZ_TABLICE(double A[], int n){
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

double MAX(double A[], int n){
    double max = A[0];
    for(int i = 1; i < n; i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}
double MIN(double A[], int n){
    double min = A[0];
    for(int i = 1; i < n; i++){
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}

void WYPISZ_LISTE(const List& L) {
    Node* a = L.head;
    while (a != nullptr) {
        cout << a->key << " ";
        a = a->next;
    }
    cout << endl;
}

void LIST_INSERT(Node*& head, Node* x){
    x->next = head;
    x->prev = nullptr;
    if(head != nullptr){
        head->prev = x;
    }
    head = x;
}

void LIST_DELETE(Node*& head, Node* x){
    if(x->prev != nullptr){
        x->prev->next = x->next;
    }else{
        head = x->next;
    }
    if(x->next != nullptr){
        x->next->prev = x->prev;
    }
    delete x;
}

Node* LIST_SEARCH(Node*& head, int k){
    Node* x = head;
    while(x != nullptr && x->key != k){
        x = x->next;
    }
    return x;
}

void INSERTION_SORT_LISTY(Node*& head){//I_S na listach
    if(!head || !head->next) return;
    Node* a = head->next;
    while(a != nullptr){
        Node* next = a->next;
        double key = a->key;
        LIST_DELETE(head,a);//usuwamy element ze starego miejsca

        Node* posortowana = head;//szukamy miejsca w posortowanej czesci
        while(posortowana != nullptr && posortowana->key < key){//gdzie wstawic
            posortowana = posortowana->next;
        }

        Node* Nowy = new Node(key);

        if(posortowana == nullptr){//wstawianie na koniec
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = Nowy;
            Nowy->prev = tail;
        }else if(posortowana == head){//wstawianie na poczatek
            LIST_INSERT(head, Nowy);
        }else{//w srodku
            Nowy->next = posortowana;
            Nowy->prev = posortowana->prev;
            if(posortowana->prev != nullptr){
                posortowana->prev->next = Nowy;
            }
            posortowana->prev = Nowy;
        }
        a = next;
    }


}

void BUCKET_SORT(double A[], int n){
    List* B = new List[n];
    for(int i = 0; i < n; i++){
        B[i].head = nullptr;
    }

    for(int i = 0; i < n; i++){
        int indeksB = min(static_cast<int>(n*A[i]),n-1);
        LIST_INSERT(B[indeksB].head, new Node(A[i]));
    }
    for(int j = 0; j < n; j++){
        INSERTION_SORT_LISTY(B[j].head);
    }
    //przypisanie z B[i] do tablicy A
    int k = 0;//indeksy z tablicy A
    for(int i = 0; i < n; i++){
        Node* a = B[i].head;
        while(a != nullptr){
            A[k] = a->key;
            a = a->next;
            k++;
        }
    }
}

//modyfikacja
void BUCKET_SORT_ZMOD(double A[], int n){
    double max = MAX(A,n);
    double min = MIN(A,n);
    if(max == min){//wszystkie wartosci takie same - unikanie dzielenia przez 0
        return;
    }else if(0<min && max<=1){//czy wszystkie wartości są z (0,1]
        BUCKET_SORT(A,n); 
    }else{
        for(int i = 0; i < n; i++){
            //najpierw chcemy miec same dodatnie 
            //potem dzieląc przez najwiekszą dostaniemy wartości z (0,1]
            A[i] = (A[i]-min)/(max-min);
        }

        BUCKET_SORT(A,n);
        
        for(int i = 0; i < n; i++){//odwracamy zmiany
            A[i] = (A[i]*(max-min))+min;
        }
        
    }
}

int main(){
    double A[] = {0.5, -0.1, -4, 2, 0.8, 6, -0.3, 0.7};
    int n = sizeof(A)/sizeof(A[0]);

    BUCKET_SORT_ZMOD(A,n);
    WYPISZ_TABLICE(A,n);

    return 0;
}
