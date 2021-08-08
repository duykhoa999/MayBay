#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define MAX_SOCHO 20
#define MAX_INPUT 255
#define MAXLIST 300
#define MAX_PAGE 35
#define HUYCHUYEN 0
#define CONVE 1
#define HETVE 2
#define HOANTAT 3
#define SODONG 6
using namespace std; 
const int MAX_NAM = 9999;
const int MIN_NAM = 1800;
const int MAX_DAY = 10;
const int MAX_DONG = 20;
const int KC_GIO = 5;
const int KC_GIOAM = 19;
#define MAX_INPUT 255
#define MAX_PAGE_SMALL 15
#define NAM 0
#define NU 1

using namespace std;

//struct may bay
struct maybay {
	char soHieuMayBay[20];
	char loaiMayBay[45];
	int soCho;

	//Chi so phu
	int soLuotThucHien = 0;

};
typedef struct maybay mayBay;
typedef struct maybay* nodeMayBay;

//struct ds may bay
struct ListMayBay {
	int n = 0;
	nodeMayBay MB[MAXLIST];
};
typedef struct ListMayBay listMB;

//struct thoi gian
struct ThoiGian
{
	int gio;
	int phut;

	int ngay;
	int thang;
	int nam;
};
typedef struct ThoiGian THOI_GIAN;

// struct chuyen bay
struct ChuyenBay {
	char maChuyenBay[20];
	THOI_GIAN tgKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
	string* dsVe;
	int slVe; //slVe = soCho;
};
typedef struct ChuyenBay CHUYENBAY;

typedef struct NodeChuyenBay {
	CHUYENBAY data;
	struct NodeChuyenBay* next;
};
typedef struct NodeChuyenBay* PTRChuyenBay;

//struct hanh khach
struct HanhKhach {
	char CMND[21];
	char ho[31];
	char ten[11];
	int phai;
};
typedef struct HanhKhach HANHKHACH;

struct nodeHanhKhach {
	HANHKHACH data;
	struct nodeHanhKhach* Left;
	struct nodeHanhKhach* Right;
};
typedef struct nodeHanhKhach NodeHanhKhach;
typedef struct nodeHanhKhach* TREEHanhKhach;
//struct cua cac ham xu li chuoi
struct NhapChuoi {
	int n = 0;
	char* data[MAX_INPUT];
};

//======Hang so GD======
const int soItem_MenuChinh = 7;
const int soItem_MenuMB = 4;
const int soItem_MenuCB = 5;
const int soItem_MenuDV = 3;

//=== To mau ====
void Normal();
void Highlight();
void Red_Highlight();
void Green_Highlight();

//======Ham Giao Dien======
void khungGiaoDien();
void fullScreen();
void khungThongBao();
void veKhungNhap(int dai, int rong, int posx, int posy, string source = "");
void hienThongBao(string notif, string notif2 = "", string notif3 = "", string NoiDen = "");
void xoaKhungDS();
void hienHuongDan(int type);
void khungNhapThongTin(int type, string title = "", string s1 = "", string s2 = "", string s3 = "", string s4 = "",
	string s5 = "", string s6 = "", string s7 = "", string s8 = "", string s9 = "");
void khungXuatDS(int type, int rong, int dai, int colump1 = 0, int colump2 = 0, int colump3 = 0, int colump4 = 0,
	int colump5 = 0, int posx = 0, int posy = 0);
void xoaThongTin(int type);
char* gdTimMa(int type, string title);

//======Menu Chon======
int menuDong_Prim(char td[soItem_MenuChinh][100]);

//===========May bay===========
int checkEmptyMB(listMB list);
int checkFullMB(listMB list);
int searchMB(listMB list, char maMB[]);
int insertMB(listMB& list, mayBay mb);
mayBay themMB(listMB &list);
void xuat(mayBay mb);
void showMotMB(listMB list, int chon, bool type, int dem);
void showListMB(listMB list);
int checkMB_DaBay(mayBay mb, PTRChuyenBay lstCB);
int delete_MB(listMB& listMB, int i, PTRChuyenBay lstCB);
int hieuChinh_MB(listMB& listMB, int i);
//==========Cac ham kiem tra==========
int checkTime_LapCB(CHUYENBAY cb, PTRChuyenBay lstCB);
int toTime(THOI_GIAN tg);
int checkKC_5Gio(THOI_GIAN tg1, THOI_GIAN tg2);

//================Chuyen bay=============
void initCB(PTRChuyenBay& lstCB);
int empty_CB(PTRChuyenBay lstCB);
PTRChuyenBay searchMaCB(PTRChuyenBay lstCB, char ma[]);
int insertNodeCB(PTRChuyenBay& lstCB, CHUYENBAY cb);
CHUYENBAY createCB(PTRChuyenBay lstCB, listMB list);
int huy_CB(PTRChuyenBay& lstCB, PTRChuyenBay p);
int xoa_CB(PTRChuyenBay& lstCB, char ma[]);
int checkSoCho(mayBay mbCu, mayBay mbMoi);
int checkBooked(string listVe[], int slVe);
int hieuChinh_CB(PTRChuyenBay& lstCB, PTRChuyenBay p, listMB lstMB);
int checkStatus_CB(CHUYENBAY cb);
int checkTimeHienTai(THOI_GIAN tg);
void show_1_CB(CHUYENBAY* cb, int chon);
PTRChuyenBay searchBin_CB(PTRChuyenBay lstCB, char ma[]);

//=================Doc ghi file==============
int loadMB(listMB& list);
int saveMB(listMB list);
int loadCB(PTRChuyenBay& lstCB, listMB list);
int saveCB(PTRChuyenBay lstCB);
int loadHK(TREEHanhKhach& lstHK);

//=============Xu li chuoi===========
void NhapMA(char var[], int len);
void NhapCHUOI(char var[], int len);

//======Ham Nhap======
void NhapMA(char var[], int len);
void NhapCHUOI(char var[], int len);
void NhapCHUOI_SO(char var[], int len);

void Nhap_SO(int& var, int len);
void NhapNGAY(int& var, int len);
void NhapTHANG(int& var, int len);
void NhapNAM(int& var, int len);
void NhapGIO(int& var, int len);

void NhapPHUT(int& var, int len);
char* CheckInputStr(bool nhapMa, int DongInfo);
int CheckInputNum(int DongInfo);
char* CheckInputCMND(int DongInfo);
THOI_GIAN CheckInputDate(THOI_GIAN& tg, int DongInfo);
THOI_GIAN CheckInputTime(THOI_GIAN& tg, int DongInfo);
int rangBuocThoiGian(THOI_GIAN tg);
int rangBuocGio(THOI_GIAN h);
void catChuoi(string chuoi, char splitChar, int& vtri, char cmnd[]);

//=============Xu li chuc nang danh sach============
int confirm(string chose1, string chose2, bool huyCB);


//======================Giao dien menu==========
mayBay ChonMB_LapCB(listMB list);

//======================Dat Huy Ve================
PTRChuyenBay ChonCB_DatVe_HuyVe(PTRChuyenBay lstCB, int& chonCB, listMB lstMB);
void DatHuyVe(PTRChuyenBay& lstCB, listMB lstMB, TREEHanhKhach& lstHK);
void showCB_DatVe(PTRChuyenBay lstCB);
void show_1_CB_DatVe(CHUYENBAY* cb, int chon);
void chuyenMang(PTRChuyenBay lstCB, CHUYENBAY* cb[], int& n, listMB lstMB, int trangThai);
int createDsVe(mayBay mb, string* lstVe);
int demSoVe(string dsVe[], int slVe);
void insertVe(string dsVe[], int vitri, char cmnd[]);
int checkVeCung_CB(PTRChuyenBay p, HANHKHACH hk);
PTRChuyenBay checkVeCungTime(PTRChuyenBay lstCB, PTRChuyenBay p, HANHKHACH hk);
int checkHK_HuyVe(PTRChuyenBay p, HANHKHACH& hk);

//=======================Hanh Khach==================
void init_HK(TREEHanhKhach& lstHK);
int empty_HK(TREEHanhKhach lstHK);
HANHKHACH create_HK(TREEHanhKhach& lstHK, PTRChuyenBay& lstCB);
TREEHanhKhach timKiem_HK(TREEHanhKhach lstHK, char cmnd[]);
void showHK(TREEHanhKhach lstHK);
int hieuChinh_HK(TREEHanhKhach& lstHK, TREEHanhKhach t, PTRChuyenBay& lstCB);
int timTrung_HK(TREEHanhKhach lstHK, char soCMND[]);
void insertNode_HK(TREEHanhKhach& lstHK, HANHKHACH p);

//========================Thong ke====================
PTRChuyenBay ChonCB_Xuat_DSHK(PTRChuyenBay lstCB, int& chonCB, listMB lstMB, TREEHanhKhach lstHK);
void xuatHK_1_CB(CHUYENBAY* cb, TREEHanhKhach lstHK, int page);
void dsHK_1_CB(PTRChuyenBay lstCB, TREEHanhKhach lstHK, listMB lstMB);
void xuatALL_HK_1_CB(CHUYENBAY* cb, TREEHanhKhach lstHK);
void dsVeTrong_1_CB(PTRChuyenBay lstCB, listMB lstMB);
PTRChuyenBay ChonCB_XemVeTrong(PTRChuyenBay lstCB, listMB lstMB, int& chonCB);
void show_VeTrong(PTRChuyenBay p);