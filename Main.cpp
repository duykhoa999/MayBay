#pragma once
#include <iostream>
#include <conio.h>
#include "ThuVien.h"

using namespace std;

char tdChinh[soItem_MenuChinh][100] = { "1. Quan ly may bay                                     ",
										 "2. Quan ly chuyen bay                                 ",
										 "3. Dat ve/Huy ve                                      ",
										 "4. Danh sach hanh khach thuoc 1 chuyen bay            " ,
										 "5. Danh sach cac chuyen bay khoi hanh trong dd/mm/yyyy",
										 "6. Danh sach ve con trong cua chuyen bay X            ",
										 "7. Thong ke so luot thuc hien chuyen bay"
};

using namespace std;

int main(int argc, char** argv) {
	int chon;
	fullScreen();
	int exit = 1;
	while (exit) {
		Normal();
		system("cls");
		char str[7];
		chon = menuDong_Prim(tdChinh);
		switch (chon) {
		case 1:
		{
			NhapMA(str, 5);
			cout << str;
			hienThongBao("Chon 1", "Chon 2", "Chon 3", "Chon 4");
			break;
			/*QLMB(lstMB, lstCB);
			break;*/
		}
		case 2:
		{
			/*int check = checkHoanTat_CB(lstCB);
			QLCB(lstCB, lstMB);
			int save = saveCB(lstCB);
			break;*/
		}
		case 3:
		{
			/*DatHuyVe(lstCB, lstMB, lstHK);
			break;*/
		}
		case 4:
		{
			/*dsHK_1_CB(lstCB, lstHK, lstMB);
			break;*/
		}
		case 5:
		{
			/*locCB_CoNoiDen(lstCB, lstMB);
			break;*/
		}
		case 6:
		{
			/*dsVeTrong_1_CB(lstCB, lstMB);
			break;*/
		}
		case 7:
		{
			/*thongKeCB(lstCB, lstMB);
			break;*/

		}
		case 0:
			return 0;
		}
	}
	_getch();
	return 0;
}