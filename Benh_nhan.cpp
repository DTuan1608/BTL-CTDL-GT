//Nguyễn Nhật Hoàng Anh
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//Dữ liệu về bác sĩ
struct Bac_si{
	string Ho_tenBS;
	string Chuc_vu;
	long Gia_kham;
};
struct NODEBS{
	Bac_si BS;
	NODEBS* nextBS; 
}; 
typedef NODEBS* BSNODE; 
typedef NODEBS* DSBS; 

//Dữ liệu về dịch vụ
struct Dich_vu{
    string Ten_DV;
    long Gia_DV;
};
struct NODEDV{
    Dich_vu DV;
    NODEDV *nextDV;
};
typedef NODEDV* DVNODE;
typedef NODEDV* DSDV;

//Dữ liệu về thuốc
typedef struct THUOC{
    string Ten_thuoc;
    int Ma_thuoc;
    long Gia_thuoc;
    int so_luong;
}THUOC;
struct NODET{
    THUOC T;
    NODET *nextT;
};
typedef NODET* NodeT;
typedef NODET* DSThuoc;

//Dữ liệu về bệnh nhân
struct Benh_nhan{
    string Ho_tenBN;
    long Tuoi;
    string Gioi_tinh;
    string Que;
    string CCCD;
    string SDT;
	int DK, MK, YK; // Ngày bệnh nhân đi khám
    DSDV DV;
    DSThuoc T;
    int Bao_hiem; 
};
struct NODEBN{
	Benh_nhan BN;
	NODEBN* nextBN;
};
typedef NODEBN* BNNODE;
typedef NODEBN* DSBN;

//Danh sách viện phí
struct Vienphi{
    Benh_nhan BN;
    int DK, MK, YK; // Ngày bệnh nhân đi khám
    DSDV DV;
    DSThuoc T;
    long Tong_VP;
};
struct NODEVP{
    Vienphi VP;
    NODEVP* nextVP;
};
typedef NODEVP* VPNODE;
typedef NODEVP* DSVP;

void InitBN(DSBN dsbn){
	dsbn = NULL;
}
int IsEmpty(DSBN dsbn){
	return(dsbn == NULL);
}
//In 1 phan tu
void PrintfBN(Benh_nhan benh_nhan){
	cout<<"Ho va ten:"<<benh_nhan.Ho_tenBN<<endl;
	cout<<"Tuoi:";
	cout<<benh_nhan.Tuoi<<endl;
	cout<<"Gioi tinh:";
	cout<<benh_nhan.Gioi_tinh<<endl;
	cout<<"Que quan: ";
	cout<<benh_nhan.Que<<endl;
	cout<<"So CCCD: "; 
	cout<<benh_nhan.CCCD<<endl;
	cout<<"BHYT:"<<(benh_nhan.Bao_hiem == 1 ? "Co" : "Khong") << endl;
	
}
//In DS
void Printf(DSBN dsbn){
	BNNODE R = dsbn;
	cout<<"\t"<<"***"<<"DANH SACH BENH NHAN"<<"***"<<endl;
	while(R != NULL){
		PrintfBN(R->BN);
		R = R->nextBN;
	}
	return;
}
//Tao ra 1 NODE moi bang cach nhap tu ban phim vao
Benh_nhan Create()
{
	Benh_nhan A;
	cout<<"Ho va ten:";
	getline(cin,A.Ho_tenBN);
	cout<<"Tuoi:";
	cin>>A.Tuoi;
	cout<<"Gioi tinh:";
	cin>>A.Gioi_tinh;
	cin.ignore();
	cout<<"Que quan: ";
	getline(cin,A.Que);
	cout<<"So CCCD: "; 
	cin>>A.CCCD;
	cout<<"BHYT (1. Co, 0. Khong):"<<endl;
	cin>>A.Bao_hiem;
	cin.ignore();
	A.DV = NULL;
	A.T = NULL;
	return A;
}
//Nhap benh nhan tu vao DS 
void InsertBN(DSBN& dsbn){
	BNNODE P = new NODEBN;
    P->BN = Create();
    P->nextBN = dsbn;
    dsbn = P;
}
//Tim benh nhan voi so cccd cho truoc 
BNNODE FindBN(DSBN dsbn,string cccd){
	BNNODE R = dsbn;
	while( R != NULL){
		if(R->BN.CCCD == cccd) return R;
		R = R->nextBN;
	}
	cout <<"Khong tim thay BN"<<endl;
	return NULL;
}
//Tim BN o truoc benh nhan voi so cccd cho truoc 
BNNODE FindBNBefore(DSBN dsbn,string cccd){
	BNNODE R = dsbn;
	while( R != NULL){
		if(R->nextBN->BN.CCCD == cccd) return R;
		R = R->nextBN;
	}
	cout <<"Khong tim thay BN"<<endl;
	return NULL;
}
// Xoa 1 BN voi so cccd cho truoc 
void DeleteBN(DSBN& dsbn, string cccd){
	BNNODE P = FindBNBefore(dsbn,cccd);
	BNNODE Q = FindBN(dsbn,cccd);
	if(P == NULL)return;
	if(dsbn == Q)dsbn = dsbn->nextBN;
	P = P->nextBN;
	delete Q;
}
//Sua thong tin benh nhan 
void fixBN(DSBN& dsbn, string cccd) {
    BNNODE P = FindBN(dsbn, cccd);
    
    if (P != NULL) {
        cout << "Nhap thong tin moi cho benh nhan:" << endl;
        cout << "Ho va ten: ";
        getline(cin, P->BN.Ho_tenBN);
        cout << "Tuoi: ";
        cin >> P->BN.Tuoi;
        cout << "Gioi tinh: ";
        cin >> P->BN.Gioi_tinh;
        cin.ignore(); 
        cout << "Que: ";
        getline(cin, P->BN.Que);
        cout << "CCCD: ";
        cin >> P->BN.CCCD;
        cout << "BHYT (1. Co, 0. Khong): ";
        cin >> P->BN.Bao_hiem;
        cout << "Thong tin thay doi thanh cong!" << endl;
        cin.ignore();
    } else {
        return; 
    }
}
// sap xep BN 
void ArrangeBN(DSBN& dsbn) {
    if (dsbn == NULL) return; // Danh s ch r?ng, kh ng c?n s?p x?p
    
    int check;
    do{
        check = 0;
        BNNODE mid = dsbn;
        BNNODE last = NULL;
        BNNODE next = dsbn->nextBN;

        while (next != NULL) {
            if (mid->BN.Ho_tenBN > next->BN.Ho_tenBN) {
                if (last == NULL) { 
                    dsbn = next;
                }
				else {
                    last->nextBN = next;
                }
                mid->nextBN = next->nextBN;
                next->nextBN = mid;
                // Cap nhap gia tri 
				check = 0;
                mid = next;
                next = mid->nextBN;
            } 
			else {
                last = mid;
                mid = next;
                next = next->nextBN;
            }
        }
    } while (check);
}
int main(){
	DSBN dsbn;
	InitBN(dsbn);
	InsertBN(dsbn);
	InsertBN(dsbn);
	InsertBN(dsbn);
	Printf(dsbn); 
}

