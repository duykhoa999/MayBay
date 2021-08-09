#pragma once
#include <iostream>
#include <conio.h>
#include "ThuVien.h"

using namespace std;

char tdChinh[soItem_MenuChinh][100] = { "1. Quan ly may bay                                     ",
										 "2. Quan ly chuyen bay                                 ",
										 "3. Dat ve/Huy ve                                      ",
										 "4. Danh sach hanh khach thuoc 1 chuyen bay            " ,
										 "5. Danh sach ve con trong cua chuyen bay X            ",
										 "6. Thong ke so luot thuc hien chuyen bay"
};

using namespace std;

int main(int argc, char** argv) {
	listMB listMB;
	mayBay mb;
	int chon;
	TREEHanhKhach listHK;
	PTRChuyenBay listCB;
	CHUYENBAY cb;
	init_HK(listHK);
	initCB(listCB);

	int loadmb = loadMB(listMB);
	int loadcb = loadCB(listCB, listMB);
	int loadhk = loadHK(listHK);

	fullScreen();
	int exit = 1;
	while (exit) {
		Normal();
		system("cls");
		chon = menuDong_Prim(tdChinh);
		switch (chon) {
		case 1:
		{
			QLMB(listMB, listCB);
			break;
		}
		case 2:
		{
			int check = checkHoanTat_CB(listCB);
			QLCB(listCB, listMB);
			int save = saveCB(listCB);
			break;
		}
		case 3:
		{
			DatHuyVe(listCB, listMB, listHK);
			break;
		}
		case 4:
		{
			dsHK_1_CB(listCB, listHK, listMB);
			break;
		}
		case 5:
		{
			dsVeTrong_1_CB(listCB, listMB);
			break;
		}
		case 6:
		{
			thongKeCB(listCB, listMB);
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
}