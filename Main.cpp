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
	listMB listMB;
	mayBay mb;
	int chon;
	TREEHanhKhach listHK;
	PTRChuyenBay listCB;
	CHUYENBAY cb;
	//init_HK(listHK);
	//initCB(listCB);

	//int loadhk = loadHK(listHK);
	//int checkLoad = loadCB(listCB, listMB);

	//int checkLoadFileCB = loadCB(listCB, list);
	//if (checkLoadFileCB == 1)
	//	hienThongBao("Doc file thanh cong");
	//else hienThongBao("Doc file that bai");

	//strcpy_s(mb.soHieuMayBay, "VN01");
	//strcpy_s(mb.loaiMayBay, "Boeing");
	//mb.soCho = 20;
	//mb.soLuotThucHien = 0;
	//insertMB(listMB, mb);

	//strcpy_s(mb.soHieuMayBay, "VN02");
	//strcpy_s(mb.loaiMayBay, "Airbus");
	//mb.soCho = 25;
	//mb.soLuotThucHien = 0;
	//insertMB(listMB, mb);

	//strcpy_s(mb.soHieuMayBay, "VN03");
	//strcpy_s(mb.loaiMayBay, "Airbus");
	//mb.soCho = 17;
	//mb.soLuotThucHien = 0;
	//insertMB(listMB, mb);


	/*strcpy_s(cb.maChuyenBay, "CB01");
	strcpy_s(cb.soHieuMayBay, listMB.MB[0]->soHieuMayBay);
	strcpy_s(cb.sanBayDen, "Ho Chi Minh");
	cb.tgKhoiHanh.ngay = 20;
	cb.tgKhoiHanh.thang = 1;
	cb.tgKhoiHanh.nam = 2020;
	cb.tgKhoiHanh.gio = 5;
	cb.tgKhoiHanh.phut = 30;
	cb.trangThai = 1;
	cb.slVe = listMB.MB[0]->soCho;
	cb.dsVe = new string[cb.slVe];
	for (int i = 0; i < cb.slVe; i++) {
		cb.dsVe[i] = "";
	}
	insertNodeCB(listCB, cb);

	strcpy_s(cb.maChuyenBay, "CB02");
	strcpy_s(cb.soHieuMayBay, listMB.MB[1]->soHieuMayBay);
	strcpy_s(cb.sanBayDen, "Da Nang");
	cb.tgKhoiHanh.ngay = 20;
	cb.tgKhoiHanh.thang = 1;
	cb.tgKhoiHanh.nam = 2020;
	cb.tgKhoiHanh.gio = 5;
	cb.tgKhoiHanh.phut = 30;
	cb.trangThai = 1;
	cb.slVe = listMB.MB[1]->soCho;
	cb.dsVe = new string[cb.slVe];
	for (int i = 0; i < cb.slVe; i++) {
		cb.dsVe[i] = "";
	}
	insertNodeCB(listCB, cb);*/



	fullScreen();
	int exit = 1;
	while (exit) {
		Normal();
		system("cls");
		chon = menuDong_Prim(tdChinh);
		switch (chon) {
		case 1:

		{
			//int checkLoad = loadCB(listCB, listMB);
			//if (checkLoad == 1) {
			//	hienThongBao(listCB->data.dsVe[2]);
			//	hienThongBao("load thanh cong");
			//}
			//else hienThongBao("load that bai");
			//break;
			//mayBay mb = themMB(listMB);
			//if (mb.soHieuMayBay[0] == ESC) {
			//	break;
			//}
			int checkInsert = insertMB(listMB, mb);
			if (checkInsert == 1) {
				hienThongBao("Them thanh cong !!");
				showListMB(listMB);
				int checkSave = saveMB(listMB);
				if (checkSave == 1) hienThongBao("Save file thanh cong");
				else hienThongBao("save file that bai");
			}
			else
				hienThongBao("Them that bai!!!");
				//hienThongBao("Chon 1", "Chon 2", "Chon 3", "Chon 4");
			/*QLMB(lstMB, lstCB);
			break;*/
		}
		case 2:
		{
			int checkLoad = loadMB(listMB);
			if (checkLoad == 1) {
				hienThongBao("load thanh cong");
				showListMB(listMB);
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
			//DatHuyVe(listCB, listMB, listHK);
			break;
		}
		case 4:
		{
			//dsHK_1_CB(listCB, listHK, listMB);
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
}