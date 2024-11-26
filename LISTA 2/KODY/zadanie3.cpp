#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* prev;
    Node* next;
    Node(int value):key(value),prev(nullptr),next(nullptr){}
};

struct List{
    Node* head;
    List():head(nullptr){}
};

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
        int key = a->key;
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
int main(){
    List L;
    LIST_INSERT(L.head, new Node(5));
    LIST_INSERT(L.head, new Node(1));
    LIST_INSERT(L.head, new Node(4));
    LIST_INSERT(L.head, new Node(2));
    LIST_INSERT(L.head, new Node(8));
    LIST_INSERT(L.head, new Node(6));
    LIST_INSERT(L.head, new Node(3));
    LIST_INSERT(L.head, new Node(7));


    WYPISZ_LISTE(L);
    INSERTION_SORT_LISTY(L.head);
    WYPISZ_LISTE(L);
    return 0;
}
