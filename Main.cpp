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
	listMB list;
	int chon;
	TREEHanhKhach lstHK;
	PTRChuyenBay listCB;
	CHUYENBAY cb;
	init_HK(lstHK);
	initCB(listCB);

	//int checkLoadFileCB = loadCB(listCB, list);
	//if (checkLoadFileCB == 1)
	//	hienThongBao("Doc file thanh cong");
	//else hienThongBao("Doc file that bai");

	strcpy_s(cb.maChuyenBay, "CB01");
	strcpy_s(cb.soHieuMayBay, "VN01");
	strcpy_s(cb.sanBayDen, "Ho Chi Minh");
	cb.tgKhoiHanh.ngay = 20;
	cb.tgKhoiHanh.thang = 1;
	cb.tgKhoiHanh.nam = 2020;
	cb.tgKhoiHanh.gio = 5;
	cb.tgKhoiHanh.phut = 30;
	cb.trangThai = 1;
	cb.slVe = 20;
	cb.dsVe = new string[cb.slVe];
	for (int i = 0; i < cb.slVe; i++) {
		cb.dsVe[i] = "";
	}
	insertNodeCB(listCB, cb);

	strcpy_s(cb.maChuyenBay, "CB02");
	strcpy_s(cb.soHieuMayBay, "VN02");
	strcpy_s(cb.sanBayDen, "Da Nang");
	cb.tgKhoiHanh.ngay = 20;
	cb.tgKhoiHanh.thang = 1;
	cb.tgKhoiHanh.nam = 2020;
	cb.tgKhoiHanh.gio = 5;
	cb.tgKhoiHanh.phut = 30;
	cb.trangThai = 1;
	cb.slVe = 26;
	cb.dsVe = new string[cb.slVe];
	for (int i = 0; i < cb.slVe; i++) {
		cb.dsVe[i] = "";
	}
	insertNodeCB(listCB, cb);



	fullScreen();
	int exit = 1;
	while (exit) {
		Normal();
		system("cls");
		chon = menuDong_Prim(tdChinh);
		switch (chon) {
			case 1:

			{
				/*mayBay mb = themMB(list);
				if (mb.soHieuMayBay[0] == ESC) {
					break;
				}
				int checkInsert = insertMB(list, mb);
				if (checkInsert == 1) {
					hienThongBao("Them thanh cong !!");
					showListMB(list);
					int checkSave = saveMB(list);
					if (checkSave == 1) hienThongBao("Save file thanh cong");
					else hienThongBao("save file that bai");
				}
				else
					hienThongBao("Them that bai!!!");*/
					//hienThongBao("Chon 1", "Chon 2", "Chon 3", "Chon 4");
				break;
				/*QLMB(lstMB, lstCB);
				break;*/
			}
			case 2:
			{
				int checkLoad = loadMB(list);
				if (checkLoad == 1) {
					hienThongBao("load thanh cong");
					showListMB(list);
				}
				else hienThongBao("load that bai");
				break;
				/*int check = checkHoanTat_CB(lstCB);
				QLCB(lstCB, lstMB);
				int save = saveCB(lstCB);
				break;*/
			}
			case 3:
			{
				DatHuyVe(listCB, list, lstHK);
				break;
			}
			case 4:
			{
				dsHK_1_CB(listCB, lstHK, list);
				break;
			}
			case 0:
			{
				return 0;
			}
		}
	}
}