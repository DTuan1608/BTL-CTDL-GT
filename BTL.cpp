#include <iostream>
#include <string.h>
using namespace std;

typedef struct InfoBN{
    string hoten;
    long db, mb, yb;
    string gioitinh;
    string Que;
    string CCCD;
    string Sdt;
    int Baohiem;
} infoBN;
struct Doctor{
	string name;
	string duty;
}; 
struct Point2{
	Doctor A;
	Point2* next; 
}; 
typedef Point2* Node2; 
typedef Point2* DSBS; 
typedef struct Service{
    string tenS;
    long dongiaS;
}Service;
struct DSKham{
    Service K;
    DSKham *nextK;
    DSBS D;
};
typedef struct THUOC{
    string tent;
    int Identify;
    long dongiaT;
}THUOC;
struct NODET{
    THUOC T;
    DSThuoc *nextT;
};
typedef NODET* NodeT;
typedef NODET* DSThuoc;
typedef struct Namvien{
    int days;
    long value;
    int VIP;
}NamV;
struct food{
	string name;
	int value;
	int food;
};
struct Point3{
	food A;
	Point3* nextf;
}; 
typedef Point3* Node3;
typedef Point3* DSDA;
struct Vienphi{
    infoBN BN;
    DSKham* K;  
    DSThuoc* T;
    NamV H;
    DSDA D;
    Vienphi *nextV;
};
typedef DSKham* ListService;
typedef DSKham* ENode;
void Init(ListService& S)
{
	S == NULL;
}
ENode Create(Service K)
{
	ENode P = new(DSKham);
	P->K = K;
	P->D = NULL;
	P->nextK = NULL;
	return P;
}
int isEmpty(ListService S)
{
	return(S == NULL);
}
void Insert(ListService& S,Service K)
{
	ENode P = Create(K);
	if(isEmpty(S)){
		S = P;
		return;
	}
	P->nextK = S;
	S = P;
}
ENode Search (ListService S,Service K)
{
	ENode P = S;
	while(P != NULL)
	{
		if(P->K.tenS == K.tenS)return P;
		P = P->nextK;
	}
	return NULL;
}

void Insert (ListService& S,Service K,Doctor A){
	ENode P = Search(S,K);
	ENode1 B ;
	B->A = A; 
	if(P == NULL){
		cout<<"Khong co Dich vu nay"<<endl;
		return ;
	}
	if(P->D == NULL)
	{
		P->D = B;
		B->next = NULL;
		return; 
	}
	B->next = P->D;
	P->D = B;
}
long TinhTien(ListService S){
	long T = 0;
	ENode P = S;
	while(P != NULL){
		T += P->K.dongiaS;
		P = P->nextK ;
	}
	return T;
} 
int main(){

}
//Viet cho BTL CTDL&GT
// 6 ham can lam
// ham nhapten1(Rieng BN,)
// ham nhapten2(Thuoc, Dich vu)
// tim kiem bang ten Search----
// sap xep(them vao Insert)
// ham nhap Insert-----
// Tinh tong
// thuoc Tuan
// doan Can
// dichvu HA
// bacsi Han
