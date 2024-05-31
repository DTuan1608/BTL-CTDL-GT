//Dương Đức Tuấn
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

//Dữ liệu về bác sĩ
struct Bac_si{
	string Ho_tenBS;
    string Ma_so;
	string Chuc_vu;
	long Gia_kham;
};
struct NODEBS{
	Bac_si BS;
	NODEBS* nextBS; 
}; 
typedef NODEBS* BSNODE; 
typedef NODEBS* DSBS; 

//Dương Đức Tuấn - 20224188
void InitBS(DSBS &H){
    H = NULL;
}
//Them bác sĩ để tạo danh sách
void InsertBSS(DSBS &H, Bac_si K) {
    BSNODE Q = new NODEBS;
    Q->BS = K;
    Q->nextBS = NULL;
    if (H == NULL || H->BS.Ho_tenBS >= Q->BS.Ho_tenBS) {
        Q->nextBS = H;
        H = Q;
    } else {
        BSNODE P = H;
        while (P->nextBS != NULL && P->nextBS->BS.Ho_tenBS < Q->BS.Ho_tenBS) {
            P = P->nextBS;
        }
        Q->nextBS = P->nextBS;
        P->nextBS = Q;
    }
}
//InsertBS(....) & ArrangeBS()
void InsertBS(DSBS &H) {
    Bac_si k;
    cout << "Nhap thong tin bac si can them nhu sau:" << endl;
    cout << "Ho ten BS:";
    getline(cin, k.Ho_tenBS);
    cout << "Ma so: ";
    getline(cin, k.Ma_so);
    cout << "Chuc vu:";
    getline(cin, k.Chuc_vu);
    cout << "Gia kham:";
    cin >> k.Gia_kham;
    cin.ignore();
    BSNODE Q = new NODEBS;
    Q->BS = k;
    Q->nextBS = NULL;

    if (H == NULL || H->BS.Ho_tenBS >= Q->BS.Ho_tenBS) {
        Q->nextBS = H;
        H = Q;
    } else {
        BSNODE P = H;
        while (P->nextBS != NULL && P->nextBS->BS.Ho_tenBS < Q->BS.Ho_tenBS) {
            P = P->nextBS;
        }
        Q->nextBS = P->nextBS;
        P->nextBS = Q;
    }
}
//DeleteBS(....)
void DeleteBS(DSBS &H, string hotenBS){
    cout << "Nhap ten Bac si can xoa: " << endl;
    cin.ignore();
    getline(cin, hotenBS);
    if(H == NULL){
        cout << "Khong co gi de xoa:" << endl;
        return;
    }
    else if (H->BS.Ho_tenBS == hotenBS) {
        BSNODE temp = H;
        H = H->nextBS;
        delete temp;
        return;
    }
    else{
        BSNODE Q = H;
        while (Q->nextBS != NULL && Q->nextBS->BS.Ho_tenBS != hotenBS) {
            Q = Q->nextBS;
        }
        if (Q->nextBS != NULL) {
            BSNODE temp = Q->nextBS;
            Q->nextBS = temp->nextBS;
            delete temp;
        }
    }
}
//FindBS(......)
BSNODE FINDBS(DSBS &H, string MS){
    cout << "Nhap ma so Bac si can tim: ";
    cin >> MS;
    BSNODE Q = H;
    while(Q->nextBS != NULL){
        if(Q->BS.Ma_so == MS){
            return Q;
        }
        Q = Q->nextBS;
    }
    return NULL;
}
void FixBS(DSBS& H, string MS) {
    BSNODE P = FINDBS(H, MS);
    
    if (P != NULL) {
        cout << "Nhap thong tin moi cho BS:" << endl;
        cout << "Ho va ten: ";
        getline(cin, P->BS.Ho_tenBS);
        cout << "Ma so: ";
        cin >> P->BS.Ma_so;
        cin.ignore();
        cout << "Chuc vu: ";
        getline(cin, P->BS.Chuc_vu);
        cin.ignore(); 
        cout << "Gia kham: ";
        cin >> P->BS.Gia_kham;
        cin.ignore();
    } else {
        return; 
    }
}

void PrintBS(DSBS &H) {
    if(H == NULL) cout << "Khong co gi de in ra man hinh" << endl;
    else{
        BSNODE Q = H;
        while (Q != NULL) {
            cout << "Ho ten BS: " << Q->BS.Ho_tenBS << endl;
            cout << "Chuc vu: " << Q->BS.Chuc_vu << endl;
            cout << "Gia kham: " << Q->BS.Gia_kham << endl;
            Q = Q->nextBS;
        }
    }
}
int main(){
    DSBS BSS;
    InitBS(BSS);
    
    Bac_si BS1 = {"Nguyen Van A", "MS01", "Bac si tim mach", 500000};
    Bac_si BS2 = {"Nguyen Van B", "MS02", "Bac si tai mui hong", 800000};
    Bac_si BS3 = {"Nguyen Van C", "MS03", "Bac si da lieu", 400000};
    Bac_si BS4 = {"Nguyen Van D", "MS04", "Y ta", 100000};
    Bac_si BS5 = {"Nguyen Van E", "MS05", "Dieu duong", 50000};

    InsertBSS(BSS, BS2);
    InsertBSS(BSS, BS3);
    InsertBSS(BSS, BS4);
    InsertBSS(BSS, BS5);
    PrintBS(BSS);
    cout << endl;
    //InsertBS(BSS);
    //InsertBS(BSS);
    //PrintBS(BSS);
}
