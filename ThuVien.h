#pragma once
#include <iostream>
#include <string>

#define MAXLIST 300

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