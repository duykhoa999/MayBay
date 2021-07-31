#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define MAX_INPUT 255
#define MAXLIST 300
#define MAX_PAGE 35
#define HUYCHUYEN 0
#define CONVE 1
#define HETVE 2
#define HOANTAT 3
using namespace std; 
const int MAX_NAM = 9999;
const int MIN_NAM = 1800;
const int MAX_DAY = 10;
const int MAX_DONG = 20;
const int KC_GIO = 5;
const int KC_GIOAM = 19;
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

//======Ham Ve Khung Giao Dien======
void khungGiaoDien();
void fullScreen();
void khungThongBao();
void veKhungNhap(int dai, int rong, int posx, int posy, string source);
void hienThongBao(string notif, string notif2 = "", string notif3 = "", string NoiDen = "");

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
//==========Cac ham kiem tra==========
int checkMB_DaBay(mayBay mb, PTRChuyenBay lstCB);
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
int checkStatus_CB(CHUYENBAY cb);
int checkTimeHienTai(THOI_GIAN tg);
//=================DOc ghi file==============
int loadMB(listMB& list);
int saveMB(listMB list);
int loadCB(PTRChuyenBay& lstCB, listMB list);
//=============Xu li chuoi===========
void NhapMA(char var[], int len);
void NhapCHUOI(char var[], int len);
void Nhap_SO(int& var, int len);
void NhapNGAY(int& var, int len);
void NhapTHANG(int& var, int len);
void NhapNAM(int& var, int len);
void NhapGIO(int& var, int len);
void NhapPHUT(int& var, int len);
char* CheckInputStr(bool nhapMa, int DongInfo);
int CheckInputNum(int DongInfo);
THOI_GIAN CheckInputDate(THOI_GIAN& tg, int DongInfo);
THOI_GIAN CheckInputTime(THOI_GIAN& tg, int DongInfo);
int rangBuocThoiGian(THOI_GIAN tg);
int rangBuocGio(THOI_GIAN h);
void catChuoi(string chuoi, char splitChar, int& vtri, char cmnd[]);

//=============Xu li chuc nang danh sach============
int confirm(string chose1, string chose2, bool huyCB);


//======================Giao dien menu==========
mayBay ChonMB_LapCB(listMB list);
