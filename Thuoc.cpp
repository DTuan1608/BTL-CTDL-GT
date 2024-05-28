//Hà Hữu An
#include <iostream>
#include <string>
using namespace std;

typedef struct THUOC{
    string Ten_thuoc;
    int Ma_thuoc;
    long Gia_thuoc;
    int so_luong;
} THUOC;

struct NODET{
    THUOC T;
    NODET *nextT;
};
typedef NODET* NodeT;
typedef NODET* DSThuoc;

bool emptyT(DSThuoc S){
    return S == NULL;
}

NodeT makenodeT(THUOC T1){
    NodeT node = new NODET;
    node->T = T1;
    node->nextT = NULL;
    return node;
}

NodeT FindT(DSThuoc &S, int Ma_thuoc){
    NodeT p = S;
    while (p != NULL && p->T.Ma_thuoc != Ma_thuoc){
        p = p->nextT;
    }
    if(p == NULL){
        cout << "Khong co thuoc voi ma thuoc: " << Ma_thuoc << " trong danh sach" << endl;
        return NULL;
    } else {
        return p;
    }
}

void DeleteT(DSThuoc &S, int Ma_thuoc){
    if(emptyT(S)){
        cout << "Danh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT P = FindT(S, Ma_thuoc);
    if(P == NULL) return;

    if(S == P){
        S = S->nextT;
        delete P;
    } else {
        NodeT R = S;
        while(R->nextT != P) R = R->nextT;
        R->nextT = P->nextT;
        delete P;
    }
}

void FixT(DSThuoc S, int Ma_thuoc){
    if(emptyT(S)){
        cout << "Danh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT p = FindT(S, Ma_thuoc);
    if(p == NULL) return;
    
    long x;
    cout << "Nhap gia thay doi: ";
    cin >> x;
    p->T.Gia_thuoc = x;
    cout << "Da thay doi gia thuoc" << endl;
}

void ArrangeT(DSThuoc &S, THUOC T1){
    NodeT P = makenodeT(T1);
    if(emptyT(S)){
        S = P;
    } else {
        if(P->T.Ten_thuoc[0] <= 'A'){
            P->nextT = S;
            S = P;
        } else {
            NodeT R = S;
            while(R->nextT != NULL && R->nextT->T.Ten_thuoc[0] < P->T.Ten_thuoc[0]) 
                R = R->nextT;
                P->nextT = R->nextT;
                R->nextT = P;
        }
    }
}

void NhapT(DSThuoc &S){
    cout << "------------nhap thuoc-------------\n";
    int x = 1;
    while(x == 1){
        THUOC T1;
        cout << "Ten thuoc: "; cin >> T1.Ten_thuoc;
        cout << "Ma thuoc: "; cin >> T1.Ma_thuoc;
        cout << "Don gia: ";  cin >> T1.Gia_thuoc;
        cout << "So luong: "; cin >> T1.so_luong;
        ArrangeT(S, T1);
        cout << "----------------------\n" << "0.thoat\n" << "1.nhap tiep\n";
        cin >> x;
        if(x != 0 && x != 1){
            cout << "Nhap lai: "; cin >> x;
        }
    }
}

void printfT(DSThuoc S){
    NodeT P = S;
    while(P != NULL){
        cout << P->T.Ten_thuoc << " " << P->T.Ma_thuoc << " " << P->T.Gia_thuoc << " " << P->T.so_luong << endl;
        P = P->nextT;
    }
}

int main(){
    DSThuoc S = NULL;
    NhapT(S);
    printfT(S);
    return 0;
}
