#pragma once

#include "ThuVien.h"
#include "mylib.h"

using namespace std;

void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void Highlight() {
	SetColor(8);
	SetBGColor(7);
}
void Red_Highlight() {
	SetColor(7);
	SetBGColor(12);
}
void Green_Highlight() {
	SetColor(7);
	SetBGColor(10);
}

void fullScreen()
{
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void khungGiaoDien() {
	for (int i = 0; i < WIDTH; i++) {
		gotoxy(i + 2, 0);
		cout << char(NGANG);
	}
	gotoxy(2, 0);
	cout << char(UPLEFT);
	for (int i = 0; i < HEIGHT; i++) {
		gotoxy(2, i + 1);
		cout << char(DOC);
	}
	gotoxy(WIDTH + 1, 0);
	cout << char(UPRIGHT);
	for (int i = 0; i < HEIGHT; i++) {
		gotoxy(WIDTH + 1, i + 1);
		cout << char(DOC);
	}
	for (int i = 0; i < WIDTH; i++) {
		gotoxy(i + 2, HEIGHT + 1);
		cout << char(NGANG);
	}
	gotoxy(2, HEIGHT + 1);
	cout << char(DOWNLEFT);
	gotoxy(WIDTH + 1, HEIGHT + 1);
	cout << char(DOWNRIGHT);

	gotoxy(2, 10);
	cout << char(BELEFT);
	for (int i = 0; i < MIDDLE_DOC; i++) {
		gotoxy(i + 3, 10);
		cout << char(NGANG);
	}
	gotoxy(MIDDLE_DOC + 3, 0);
	cout << char(BEUP);
	gotoxy(MIDDLE_DOC + 3, MIDDLE_NGANG + 3);
	cout << char(BERIGHT);
	for (int i = 0; i <= MIDDLE_NGANG + 1; i++) {
		gotoxy(MIDDLE_DOC + 3, i + 1);
		cout << char(DOC);
	}
	for (int i = 0; i < (HEIGHT - MIDDLE_NGANG) - 2; i++) {
		gotoxy(MIDDLE_DOC + 3, i + MIDDLE_NGANG + 4);
		cout << char(DOC);
	}
	gotoxy(MIDDLE_DOC + 3, HEIGHT + 1);
	cout << char(BEDOWN);
	khungThongBao();
}
void veKhungNhap(int dai, int rong, int posx, int posy, string source)
{
	int len = source.length();
	if (dai == 0)
		dai = len + 2;
	for (int i = 0; i < dai; i++) // top
	{
		gotoxy(posx + i, posy);
		cout << char(196);
	}
	gotoxy(posx, posy);
	cout << char(218); // top-left
	gotoxy(posx + dai, posy);
	cout << char(191); // top-right
	for (int i = 1; i <= rong; i++) // right
	{
		gotoxy(posx + dai, posy + i);
		cout << char(179);
	}
	for (int i = 0; i < dai; i++) // bot
	{
		gotoxy(posx + i, posy + rong);
		cout << char(196);
	}
	gotoxy(posx + dai, posy + rong);
	cout << char(217);	// bot-right	
	for (int i = 1; i <= rong; i++) // left
	{
		gotoxy(posx, posy + i);
		cout << char(179);
	}
	gotoxy(posx, posy + rong);
	cout << char(192); // bot-left
	gotoxy(posx - len / 2 + dai / 2, posy + round(rong / 2));
	cout << source;
}

void khungThongBao() {
	gotoxy(COT, DONGDS_D - 2);
	cout << "Thong bao";
	veKhungNhap(DAIKHUNG, RONGKHUNG + 2, COT, DONGDS_D - 1, "");
}

void hienThongBao(string notif, string notif2, string notif3, string NoiDen) {
	gotoxy(COT + 1, DONGDS_D);
	cout << notif;

	if (notif2 != "") {
		gotoxy(COT + 1, DONGDS_D + 1);
		cout << notif2;
	}
	if (NoiDen != "") {
		gotoxy(COT + 1, DONGDS_D + 2);
		cout << NoiDen;
	}
	if (notif3 != "") {
		gotoxy(COT + 10, DONGDS_D + 2);
		cout << notif3;
	}
	Sleep(1500);
	Normal();
	gotoxy(COT + 1, DONGDS_D);
	cout << "                                                           ";
	gotoxy(COT + 1, DONGDS_D + 1);
	cout << "                                                           ";
	gotoxy(COT + 1, DONGDS_D + 2);
	cout << "                                                           ";
}

int menuDong_Prim(char td[soItem_MenuChinh][100]) {
	Normal();
	//system("cls");
	khungGiaoDien();
	int chon = 0;
	int i;
	for (int i = 0; i < soItem_MenuChinh; i++) {
		gotoxy(COT, DONG + i + 1);
		cout << td[i];
	}
	Highlight();
	gotoxy(COT, DONG + chon + 1);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == -32)
			kytu = _getch();
		switch (kytu) {
		case UP:
			if (chon > 0) {
				Normal();
				gotoxy(COT, DONG + chon + 1); cout << td[chon];
				chon--;
				Highlight();
				gotoxy(COT, DONG + chon + 1); 	cout << td[chon];
			}
			break;
		case DOWN:
			if (chon + 1 < soItem_MenuChinh) {
				Normal();
				gotoxy(COT, DONG + chon + 1);	cout << td[chon];
				chon++;
				Highlight();
				gotoxy(COT, DONG + chon +1); 	cout << td[chon];
			}
			break;
		case ENTER:
			return chon + 1;
		case ESC:
			return 0;
		}
	} while (TRUE);
}



//=====================May bay================
/**
* kiem tra rong
**/
int checkEmptyMB(listMB list) {
	return list.n == 0;
}
/**
* kiem tra day danh sach may bay
**/
int checkFullMB(listMB list) {
	return list.n == MAXLIST;
}
/**
* tim kiem may bay theo ma may bay (kiem tra ton tai)
**/
int searchMB(listMB list, char maMB[]) {
	for (int i = 0; i < list.n; i++) {
		if (strcmp(list.MB[i]->soHieuMayBay, maMB)) return 1;
	}
	return 0;
}

mayBay getMB(listMB list, char ma[]) {
	mayBay maybay;

	for (int i = 0; i < list.n; i++) {
		if (_stricmp(list.MB[i]->soHieuMayBay, ma) == 0) {
			strcpy_s(maybay.soHieuMayBay, list.MB[i]->soHieuMayBay);
			strcpy_s(maybay.loaiMayBay, list.MB[i]->loaiMayBay);
			maybay.soCho = list.MB[i]->soCho;
			maybay.soLuotThucHien = list.MB[i]->soLuotThucHien;
			return maybay;
		}
	}
	maybay.soHieuMayBay[0] = '\0';
	return maybay;
}

/**
* insert vao mang con tro
**/
int insertMB(listMB& list, mayBay mb) {
	if (checkFullMB(list)) return 0;
	nodeMayBay p = new mayBay;
	p = &mb;
	list.MB[list.n++] = p;
	return 1;
}

mayBay themMB(listMB &list){
	//khungNhapThongTin(THEM_MB, "THEM MAY BAY", "So hieu may bay:", "Loai may bay:", "So day:", "So dong:");
	mayBay mb;
	do {
		strcpy_s(mb.soHieuMayBay, CheckInputStr(true, DONGNHAP1));
		// kiem tra so hieu may bay da co chua
		int tontai = searchMB(list, mb.soHieuMayBay);
		if (tontai == 1) {
			Red_Highlight();
			hienThongBao("So hieu may bay da ton tai, nhap lai!");
		}
		else {
			if (mb.soHieuMayBay[0] == ESC) {
				return mb;
			}
			else break;
		}
	} while (true);

	do {
		strcpy_s(mb.loaiMayBay, CheckInputStr(false, DONGNHAP2));

		if (mb.loaiMayBay[0] == ESC) {
			mb.soHieuMayBay[0] = ESC;
			return mb;
		}
		else break;
	} while (true);

	do
	{
		mb.soCho = CheckInputNum(DONGNHAP3);
		if (mb.soCho == -1) {
			mb.soHieuMayBay[0] = ESC;
			return mb;
		}
		else if (mb.soCho > MAXLIST) {
			Red_Highlight();
			hienThongBao("So cho phai <=300 !!!");
		}
		else break;
	} while (true);
	mb.soLuotThucHien = 0;
	return mb;
}
/**
* xuat phan tu vua them
**/
void xuat(mayBay mb) {
	cout << mb.soHieuMayBay;
	cout << mb.loaiMayBay;
	cout << mb.soCho;
	cout << mb.soLuotThucHien;
}
/**
* show mot may bay voi vi tri can tim
**/
void showMotMB(listMB list, int chon, bool type, int dem) {
	gotoxy(COTDS_L + 1, DONGDS_U + 3 + dem);
	cout << "                                                                                                                 ";
	gotoxy(COTDS_L + 1, DONGDS_U + 3 + dem);
	cout << chon + 1;

	gotoxy(COTDS_L + 6, DONGDS_U + 3 + dem);
	cout << list.MB[chon]->soHieuMayBay;
	gotoxy(COTDS_L + 5, DONGDS_U + 3 + dem);
	cout << char(DOC);

	gotoxy(COTDS_L + 26, DONGDS_U + 3 + dem);
	cout << list.MB[chon]->loaiMayBay;
	gotoxy(COTDS_L + 25, DONGDS_U + 3 + dem);
	cout << char(DOC);

	gotoxy(COTDS_L + 71, DONGDS_U + 3 + dem);
	cout << list.MB[chon]->soCho;
	gotoxy(COTDS_L + 70, DONGDS_U + 3 + dem);
	cout << char(DOC);

	gotoxy(COTDS_L + 94, DONGDS_U + 3 + dem);
	cout << list.MB[chon]->soLuotThucHien;
	gotoxy(COTDS_L + 93, DONGDS_U + 3 + dem);
	cout << char(DOC);

	Normal();
	if (type == true) {
		gotoxy(COT + 1, DONGNHAP1 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP1 + 2);
		cout << list.MB[chon]->soHieuMayBay;
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << list.MB[chon]->loaiMayBay;
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << list.MB[chon]->soCho;
		gotoxy(COT + 1, DONGNHAP4 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP4 + 2);
		cout << list.MB[chon]->soLuotThucHien;
	}

}


/**
* xuat list may bay
**/
void showListMB(listMB list) {
	//khungXuatDS(XUAT_MB, DONGDS_D - DONGDS_U, COTDS_R - COTDS_L, 5, 25, 70, 93);

	for (int i = 0; i < MAX_PAGE; i++) {
		//5, 25, 70, 93
		gotoxy(COTDS_L + 1, DONGDS_U + 3 + i);
		cout << i + 1;
		gotoxy(COTDS_L + 6, DONGDS_U + 3 + i);
		cout << list.MB[i]->soHieuMayBay;
		gotoxy(COTDS_L + 26, DONGDS_U + 3 + i);
		cout << list.MB[i]->loaiMayBay;
		gotoxy(COTDS_L + 71, DONGDS_U + 3 + i);
		cout << list.MB[i]->soCho;
		gotoxy(COTDS_L + 94, DONGDS_U + 3 + i);
		cout << list.MB[i]->soLuotThucHien;

	}
	
}
/**
* kiem tra may bay da bay chua
**/
int checkMB_DaBay(mayBay mb, PTRChuyenBay lstCB) {
	for (PTRChuyenBay p = lstCB; p != NULL; p = p->next) {
		if (_stricmp(mb.soHieuMayBay, p->data.soHieuMayBay) == 0) {
			return 1;
		}
	}
}

int checkTime_LapCB(CHUYENBAY cb, PTRChuyenBay lstCB) {
	for (PTRChuyenBay p = lstCB; p != NULL; p = p->next) {
		if (_stricmp(p->data.soHieuMayBay, cb.soHieuMayBay) == 0) {
			if (!checkKC_5Gio(cb.tgKhoiHanh, p->data.tgKhoiHanh)) {
				return 1;
			}
		}
	}
	return 0;
}

int toTime(THOI_GIAN tg) {
	int sumyear = 0;
	int summonth = 0;
	for (int i = 1999; i < tg.nam; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			sumyear = sumyear + 366;
		}
		else
		{
			sumyear = sumyear + 365;
		}
	}
	for (int j = 1; j < tg.thang; j++)
	{
		if (j == 2)
		{
			if ((tg.nam % 4 == 0 && tg.nam % 100 != 0) || tg.nam % 400 == 0)
			{
				summonth = summonth + 29;
			}
			else
			{
				summonth = summonth + 28;
			}
		}
		if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
		{
			summonth = summonth + 31;
		}
		if (j == 4 || j == 6 || j == 9 || j == 11)
		{
			summonth = summonth + 30;
		}
	}
	return sumyear + summonth + tg.ngay;
}

int checkKC_5Gio(THOI_GIAN tg1, THOI_GIAN tg2) {
	// truong hop trong cung 1 ngay
	if (toTime(tg1) - toTime(tg2) == 0) {
		if (abs(tg1.gio - tg2.gio) >= KC_GIO) {
			if (abs(tg1.gio - tg2.gio) == KC_GIO) {
				if (tg1.phut - tg2.phut >= 0)
					return 1;
				else
					return 0;
			}
			return 1;
		}
		return 0;
	}

	// truong hop cach nhau 1 ngay (0h==24h)
	if (abs(toTime(tg1) - toTime(tg2)) == 1) {

		// truong hop chuyen bay cach nhau giua moc 0h
		if (0 + tg1.gio <= KC_GIO && 24 - tg2.gio <= KC_GIO) {
			if (abs(tg1.gio - tg2.gio) <= KC_GIOAM) {
				if (abs(tg1.gio - tg2.gio) == KC_GIOAM) {
					if (tg1.phut - tg2.phut >= 0)
						return 1;
					else
						return 0;
				}
				return 1;
			}
			return 0;
		}
		if (24 - tg1.gio <= KC_GIO && 0 + tg2.gio <= KC_GIO) {
			if (abs(tg1.gio - tg2.gio) >= KC_GIO) {
				if (abs(tg1.gio - tg2.gio) == KC_GIO) {
					if (tg1.phut - tg2.phut >= 0)
						return 1;
					else
						return 0;
				}
				return 1;
			}
			return 0;
		}
		return 1;
	}
	// truong hop cach nhau nhieu ngay
	if (abs(toTime(tg1) - toTime(tg2)) > 1) {

		return 1;
	}

	return 0;
}

//=====================Doc ghi file MB============
int loadMB(listMB& list) {
	fstream inFile;
	inFile.open("C:/Users/anhse/source/repos/MayBay/DATA/MayBay.txt", ios::in);
	string temp;
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			list.MB[list.n] = new mayBay;
			getline(inFile, temp);
			inFile.getline(list.MB[list.n]->soHieuMayBay, 20);
			inFile.getline(list.MB[list.n]->loaiMayBay, 45);
			inFile >> list.MB[list.n]->soCho;
			inFile >> list.MB[list.n ]->soLuotThucHien;
			list.n++;
		}
	}
	else {
		return 0;
	}
	inFile.close();
	return 1;
}
int saveMB(listMB list) {
	fstream outFile;
	outFile.open("C:/Users/anhse/source/repos/MayBay/DATA/MayBay.txt", ios::out);
	int i = 0;
	if (outFile.is_open()) {
		while (i < list.n) {
			outFile << endl << list.MB[i]->soHieuMayBay;
			outFile << endl << list.MB[i]->loaiMayBay;
			outFile << endl << list.MB[i]->soCho;
			outFile << endl << list.MB[i]->soLuotThucHien;
			i++;
		}
	}
	else {
		return 0;
	}
	outFile.close();
	return 1;
}
/**
* Load file ChuyenBay.txt
**/
int loadCB(PTRChuyenBay& lstCB, listMB list) {

	fstream inFile;
	inFile.open("C:/Users/anhse/source/repos/MayBay/DATA/ChuyenBay.txt", ios::in);
	string temp;
	string temp1 = "";
	string ve;
	int slCB;
	if (inFile.is_open()) {
		while (!inFile.eof()) {


			getline(inFile, temp);
			if (temp == "") {
				CHUYENBAY cb;
				inFile.getline(cb.maChuyenBay, 20);
				inFile.getline(cb.soHieuMayBay, 20);
				inFile.getline(cb.sanBayDen, 50);
				inFile >> cb.tgKhoiHanh.ngay;
				inFile >> cb.tgKhoiHanh.thang;
				inFile >> cb.tgKhoiHanh.nam;
				inFile >> cb.tgKhoiHanh.gio;
				inFile >> cb.tgKhoiHanh.phut;
				inFile >> cb.trangThai;
				inFile >> cb.slVe;
				mayBay mb = getMB(list, cb.soHieuMayBay);
				cb.dsVe = new string[cb.slVe];

				getline(inFile, temp1);
				//getline(inFile, temp1);
				while (temp1 != "") {

					int vitri = 0;
					char cmnd[12] = "";


					catChuoi(temp1, '-', vitri, cmnd);
					cb.dsVe[vitri] = cmnd;

					getline(inFile, temp1);
				}

				insertNodeCB(lstCB, cb);
			}
		}
	}
	else {
		return 0;
	}

	inFile.close();
	return 1;
}
//======================Chuyen bay===============
/**
* khoi tao chuyen bay
**/
void initCB(PTRChuyenBay& lstCB) {
	lstCB = NULL;
}
/**
* kiem tra rong
**/
int empty_CB(PTRChuyenBay lstCB) {
	return (lstCB == NULL);
}
/**
* tim kiem CB, tra ve list
**/
PTRChuyenBay searchMaCB(PTRChuyenBay lstCB, char ma[]) {
	PTRChuyenBay p;
	for (p = lstCB; p != NULL; p = p->next) {
		if (_stricmp(p->data.maChuyenBay, ma) == 0)
			return p;
	}
	return NULL;
}

int insertNodeCB(PTRChuyenBay& lstCB, CHUYENBAY cb) {
	PTRChuyenBay p = new NodeChuyenBay;
	p->data = cb;
	p->next = NULL;
	if (lstCB == NULL)
		lstCB = p;
	else {
		PTRChuyenBay last;
		for (last = lstCB; last->next != NULL; last = last->next);
		last->next = p;
	}
	return 1;
}

/**
* tao chuyen bay
**/
CHUYENBAY createCB(PTRChuyenBay lstCB, listMB list) {
	//khungNhapThongTin(GDTHEM_CB, "THEM CHUYEN BAY", "Ma chuyen bay:", "So hieu may bay:", "San bay den:", "Ngay khoi hanh:", "Gio khoi hanh:");
	CHUYENBAY cb;
	PTRChuyenBay p;

	do
	{
		strcpy_s(cb.maChuyenBay, CheckInputStr(true, DONGNHAP1));
		p = searchMaCB(lstCB, cb.maChuyenBay);
		if (p != NULL) {
			Red_Highlight();
			hienThongBao("Ma chuyen bay da ton tai!");
		}
		else {
			if (cb.maChuyenBay[0] == ESC) {
				return cb;
			}
			else break;
		}
	} while (true);

ChonMayBay:
	mayBay chonMB;
	do
	{
		// chon may bay tren giao dien
		chonMB = ChonMB_LapCB(list);
		strcpy_s(cb.soHieuMayBay, chonMB.soHieuMayBay);
		// tim may bay bang cach nhap
		if (chonMB.soHieuMayBay[0] == '\0') {
			strcpy_s(cb.soHieuMayBay, CheckInputStr(true, DONGNHAP2));
			if (cb.soHieuMayBay[0] == ESC) {
				cb.maChuyenBay[0] = ESC;
				return cb;
			}
			int tontai = searchMB(list, cb.soHieuMayBay);
			if (tontai == -1) {
				Red_Highlight();
				hienThongBao("Khong co may bay nao mang so hieu nay!");
				continue;
			}
			else
				break;

		}
		else {
			gotoxy(COT + 1, DONGNHAP2 + 2);
			cout << cb.soHieuMayBay;
			break;
		}

	} while (true);

	do
	{
		strcpy_s(cb.sanBayDen, CheckInputStr(false, DONGNHAP3));
		if (cb.sanBayDen[0] == ESC) {
			cb.maChuyenBay[0] = ESC;
			return cb;
		}
		else
			break;
	} while (true);

	do
	{

		cb.tgKhoiHanh = CheckInputDate(cb.tgKhoiHanh, DONGNHAP4);

		if (cb.tgKhoiHanh.ngay == -1 || cb.tgKhoiHanh.thang == -1 || cb.tgKhoiHanh.nam == -1) {
			cb.maChuyenBay[0] = ESC;
			return cb;
		}
		if (rangBuocThoiGian(cb.tgKhoiHanh) == -1)
		{
			break;
		}
		else
		{
			gotoxy(COT + 1, DONGNHAP4 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
			cout << "    ";
		}
	} while (true);

	do
	{
		cb.tgKhoiHanh = CheckInputTime(cb.tgKhoiHanh, DONGNHAP5);
		if (cb.tgKhoiHanh.gio == -1 || cb.tgKhoiHanh.phut == -1) {
			cb.maChuyenBay[0] = ESC;
			return cb;
		}
		if (rangBuocGio(cb.tgKhoiHanh) == -1)
		{
			break;
		}
		else
		{
			gotoxy(COT + 1, DONGNHAP5 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
			cout << "  ";
		}
	} while (true);
	// xet gio lap chuyen bay 
	if (checkTime_LapCB(cb, lstCB)) {
		Red_Highlight();
		hienThongBao("May bay nay phai cat canh sau 5h nua! Hay chon may bay khac");
		goto ChonMayBay;
	}
	cb.slVe = chonMB.soCho;
	cb.dsVe = new string[cb.slVe];
	cb.trangThai = CONVE;

	return cb;
}

/**
* huy chuyen bay
**/
int huy_CB(PTRChuyenBay& lstCB, PTRChuyenBay p) {

	if (empty_CB(lstCB))
		return 0;
	else {
		if (p->data.trangThai == HOANTAT
			|| p->data.trangThai == HUYCHUYEN) {
			return 0;
		}
		else {
			p->data.trangThai = HUYCHUYEN;
			return 1;
		}
	}
}
/**
* kiem tra tinh trang chuyen bay
**/
int checkStatus_CB(CHUYENBAY cb) {
	if (cb.trangThai == HOANTAT) {
		Red_Highlight();
		hienThongBao("Chuyen bay da hoan tat khong the thao tac!");
		return 1;
	}
	if (cb.trangThai == HUYCHUYEN) {
		Red_Highlight();
		hienThongBao("Chuyen bay da bi huy khong the thao tac!");
		return 1;
	}
	if (cb.trangThai == HETVE) {
		Red_Highlight();
		hienThongBao("Chuyen bay da het ve!");
		return 1;
	}
	return 0;
}

int checkTimeHienTai(THOI_GIAN tg) {
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	THOI_GIAN t;
	t.ngay = ltm->tm_mday;
	t.thang = ltm->tm_mon + 1;
	t.nam = ltm->tm_year + 1900;
	t.gio = ltm->tm_hour;
	t.phut = ltm->tm_min;

	if (toTime(tg) - toTime(t) == 0)
		return 1;
	return 0;
}

//======================Quan li ve============


//==================Xu li chuoi=============================
void NhapMA(char var[], int len) {
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;
	rewind(stdin);
	NhapChuoi nhap;

	nhap.n = 0;

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (!(!((int)c >= A && (int)c <= Z) && !((int)c >= a && (int)c <= z)
				&& !((int)c >= So0 && (int)c <= So9)) && nhap.n < maxInput) {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ' && c == ' ')
					continue;
				if (!(nhap.n == 0 && (int)c >= So0 && (int)c <= So9)) {
					c = toupper(c);
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var[0] = ESC;
				return;
			}
		}
	}
	for (int i = 0; i < nhap.n; i++) {
		var[i] = *nhap.data[i];
	}
	var[nhap.n] = '\0';
}

void NhapCHUOI(char var[], int len) {
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;
	rewind(stdin);
	NhapChuoi nhap;

	nhap.n = 0;

	while (true) {
		if (_kbhit()) {
			char c = _getch();

			if (!(!((int)c >= A && (int)c <= Z) && !((int)c >= a && (int)c <= z)
				&& c != ' ') && nhap.n < maxInput) {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ' && c == ' ')
					continue;
				if (!(nhap.n == 0 && c == ' ')) {
					if (nhap.n == 0)
						c = toupper(c);
					else {
						if (*nhap.data[nhap.n - 1] == ' ')
							c = toupper(c);
						else
							c = tolower(c);
					}
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var[0] = ESC;
				return;
			}
		}
	}
	for (int i = 0; i < nhap.n; i++) {
		var[i] = *nhap.data[i];
	}
	var[nhap.n] = '\0';
}

void Nhap_SO(int& var, int len) {
	char num[12] = { '\0' };
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;

	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(num);

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (nhap.n < 11) {
				if ((int)c >= So0 && (int)c <= So9 && nhap.n < maxInput) {

					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var = -1;
				return;
			}

		}
	}
	for (int i = 0; i < nhap.n; i++) {
		num[i] = *nhap.data[i];
	}
	num[nhap.n] = '\0';
	var = atoi(num);
}
/**
* xu li nhap ngay
**/
void NhapNGAY(int& var, int len) {
	char num[12] = { '\0' };
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;

	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(num);

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (nhap.n < 2) {
				if ((int)c >= So0 && (int)c <= So9 && nhap.n < maxInput) {
					if ((nhap.n > 0 && (int)*nhap.data[nhap.n - 1] == So3 && (int)c >= So2)
						|| (nhap.n > 0 && (int)*nhap.data[nhap.n - 1] >= 52 && c >= So0)
						|| (nhap.n == 0 && (int)c == So0)) {
						continue;
					}
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var = -1;
				return;
			}

		}
	}
	for (int i = 0; i < nhap.n; i++) {
		num[i] = *nhap.data[i];
	}
	num[nhap.n] = '\0';
	var = atoi(num);
}

void NhapTHANG(int& var, int len) {
	char num[12] = { '\0' };
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;

	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(num);

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (nhap.n < 2) {
				if ((int)c >= So0 && (int)c <= So9 && nhap.n < maxInput) {
					if ((nhap.n > 0 && (int)*nhap.data[nhap.n - 1] == So1 && (int)c >= So3)
						|| (nhap.n > 0 && (int)*nhap.data[nhap.n - 1] >= So2 && c >= So0)
						|| (nhap.n == 0 && (int)c == So0)) {
						continue;
					}
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var = -1;
				return;
			}

		}
	}
	for (int i = 0; i < nhap.n; i++) {
		num[i] = *nhap.data[i];
	}
	num[nhap.n] = '\0';
	var = atoi(num);
}

void NhapNAM(int& var, int len) {
	char num[12] = { '\0' };
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;

	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(num);

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (nhap.n < 4) {
				if ((int)c >= So0 && (int)c <= So9 && nhap.n < maxInput) {
					if ((nhap.n == 0 && (int)c == So0)) {
						continue;
					}
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var = -1;
				return;
			}
		}
	}
	for (int i = 0; i < nhap.n; i++) {
		num[i] = *nhap.data[i];
	}
	num[nhap.n] = '\0';
	var = atoi(num);

}

void NhapGIO(int& var, int len) {
	char num[12] = { '\0' };
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;

	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(num);

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (nhap.n < 2) {
				if ((int)c >= So0 && (int)c <= So9 && nhap.n < maxInput) {
					if ((nhap.n > 0 && (int)*nhap.data[nhap.n - 1] >= So2 && (int)c >= So4)) {
						continue;
					}
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var = -1;
				return;
			}

		}
	}
	for (int i = 0; i < nhap.n; i++) {
		num[i] = *nhap.data[i];
	}
	num[nhap.n] = '\0';
	var = atoi(num);
}

void NhapPHUT(int& var, int len) {
	char num[12] = { '\0' };
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;

	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(num);

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (nhap.n < 2) {
				if ((int)c >= So0 && (int)c <= So9 && nhap.n < maxInput) {
					if ((nhap.n > 0 && (int)*nhap.data[nhap.n - 1] >= So6 && (int)c >= So0)) {
						continue;
					}
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}

				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
			if (c == ESC) {
				var = -1;
				return;
			}

		}
	}
	for (int i = 0; i < nhap.n; i++) {
		num[i] = *nhap.data[i];
	}
	num[nhap.n] = '\0';
	var = atoi(num);
}

char* CheckInputStr(bool nhapMa, int DongInfo) {
	char info[50] = { '\0' };
	do
	{
		rewind(stdin);
		gotoxy(COT + 1, DongInfo + 2);
		cout << "                                ";
		gotoxy(COT + 1, DongInfo + 2);
		if (nhapMa == true)
			NhapMA(info, 50);
		else
			NhapCHUOI(info, 50);
		if (info[0] == '\0') {
			Red_Highlight();
			hienThongBao("Chua nhap thong tin!");
		}
		// kiem tra nguoi nhap co nhan phim ESC de huy hay khong
		else if (info[0] == ESC) {
			int exit = confirm("HUY", "NHAP TIEP", false);
			if (exit == YES) {
				return info;
			}
			else
				continue;
		}
		else {
			return info;
		}

	} while (true);
}

int CheckInputNum(int DongInfo) {
	int var;
	do
	{
		rewind(stdin);
		gotoxy(COT + 1, DongInfo + 2);
		cout << "                                ";
		gotoxy(COT + 1, DongInfo + 2);
		Nhap_SO(var, 50);
		if (var == 0) {
			Red_Highlight();
			hienThongBao("Chua nhap thong tin!");
		}
		else if (var == -1) {
			int exit = confirm("HUY", "NHAP TIEP", false);
			if (exit == YES) {
				return var;
			}
			else
				continue;
		}
		else {
			return var;
		}

	} while (true);
}


THOI_GIAN CheckInputDate(THOI_GIAN& tg, int DongInfo) {

	do
	{
	Ngay:
		gotoxy(COT + 1, DongInfo + 2);
		cout << "    ";
		gotoxy(COT + 1, DongInfo + 2);
		NhapNGAY(tg.ngay, 3);
		if (tg.ngay == 0 || tg.ngay == -1)
			goto Check;
	Thang:
		gotoxy(COT + DAIKHUNGNHO + 1, DongInfo + 2);
		cout << "   ";
		gotoxy(COT + DAIKHUNGNHO + 1, DongInfo + 2);
		NhapTHANG(tg.thang, 3);
		if (tg.thang == 0 || tg.thang == -1)
			goto Check;
	Nam:
		gotoxy(COT + DAIKHUNGNHO * 2 + 1, DongInfo + 2);
		cout << "    ";
		gotoxy(COT + DAIKHUNGNHO * 2 + 1, DongInfo + 2);
		NhapNAM(tg.nam, 5);
		if (tg.nam == 0 || tg.nam == -1)
			goto Check;

	Check:
		if (tg.ngay == 0 || tg.thang == 0 || tg.nam == 0) {
			Red_Highlight();
			hienThongBao("Chua nhap thong tin!");
			if (tg.ngay == 0)
				goto Ngay;
			if (tg.thang == 0)
				goto Thang;
			if (tg.nam == 0)
				goto Nam;
		}
		if (tg.ngay == -1 || tg.thang == -1 || tg.nam == -1) {
			int exit = confirm("HUY", "NHAP TIEP", false);
			if (exit == YES) {
				return tg;
			}
			else {
				if (tg.ngay == -1)
					goto Ngay;
				if (tg.thang == -1)
					goto Thang;
				if (tg.nam == -1)
					goto Nam;
			}
		}
		return tg;
	} while (true);
}

THOI_GIAN CheckInputTime(THOI_GIAN& tg, int DongInfo) {

	do
	{
	Gio:
		gotoxy(COT + 1, DongInfo + 2);
		cout << "    ";
		gotoxy(COT + 1, DongInfo + 2);
		NhapGIO(tg.gio, 3);
		if (tg.gio == -1)
			goto Check;
	Phut:
		gotoxy(COT + DAIKHUNGNHO + 1, DongInfo + 2);
		cout << "   ";
		gotoxy(COT + DAIKHUNGNHO + 1, DongInfo + 2);
		NhapPHUT(tg.phut, 3);
		if (tg.phut == -1)
			goto Check;

	Check:
		if (tg.gio == -1 || tg.phut == -1) {
			int exit = confirm("HUY", "NHAP TIEP", false);
			if (exit == YES) {
				return tg;
			}
			else {
				if (tg.gio == -1)
					goto Gio;
				if (tg.phut == -1)
					goto Phut;
			}

		}
		return tg;

	} while (true);
}

int rangBuocThoiGian(THOI_GIAN tg) {

	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	if (tg.ngay < ltm->tm_mday || tg.thang < 1 + ltm->tm_mon || tg.nam < 1900 + ltm->tm_year)
	{
		if (tg.thang <= 1 + ltm->tm_mon || tg.nam < 1900 + ltm->tm_year)
		{
			if (tg.nam <= 1900 + ltm->tm_year)
			{
				char nam[5];
				_itoa_s(1900 + ltm->tm_year, nam, 10);
				char thang[3];
				_itoa_s(ltm->tm_mon + 1, thang, 10);
				char ngay[50];
				_itoa_s(ltm->tm_mday, ngay, 10);
				char thongbao[70] = "Hom nay la ";
				strcat_s(ngay, "/");
				strcat_s(ngay, thang);
				strcat_s(ngay, "/");
				strcat_s(ngay, nam);
				strcat_s(ngay, ". Lap chuyen bay sau ngay hien tai!");
				strcat_s(thongbao, ngay);
				Red_Highlight();
				hienThongBao(thongbao);
				return 1;
			}
		}
	}
	if (tg.ngay == 31 && (tg.thang == 4 || tg.thang == 6 || tg.thang == 9 || tg.thang == 11))
	{

		char month[50];
		_itoa_s(tg.thang, month, 10);
		char thongbao[50] = "Thang ";
		strcat_s(month, " chi co 30 ngay!");
		strcat_s(thongbao, month);
		Red_Highlight();
		hienThongBao(thongbao);
		return 1;
	}
	if ((tg.ngay == 30 || tg.ngay == 31) && tg.thang == 2)
	{

		char month[50];
		_itoa_s(tg.thang, month, 10);
		char thongbao[50] = "Thang ";
		strcat_s(month, " chi co 29 ngay!");
		strcat_s(thongbao, month);
		Red_Highlight();
		hienThongBao(thongbao);
		return 1;
	}
	if (!((tg.nam % 4 == 0 && tg.nam % 100 != 0) || tg.nam % 400 == 0) && tg.ngay == 29 && tg.thang == 2) // kiem tra nam nhuan
	{
		char year[100];
		_itoa_s(tg.nam, year, 10);
		strcat_s(year, " la nam khong nhuan nen thang 2 chi co 28 ngay!");
		Red_Highlight();
		hienThongBao(year);

		return 1;
	}

	return -1;
}

int rangBuocGio(THOI_GIAN h)
{
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	THOI_GIAN t;
	t.ngay = ltm->tm_mday;
	t.thang = ltm->tm_mon + 1;
	t.nam = ltm->tm_year + 1900;
	t.gio = ltm->tm_hour;
	t.phut = ltm->tm_min;
	char thongbao[70] = "Bay gio la ";
	char gio[4];
	char phut[4];
	if (checkTimeHienTai(h) && h.gio < t.gio) {
		_itoa_s(t.gio, gio, 10);
		strcat_s(gio, ":");
		_itoa_s(t.phut, phut, 10);
		strcat_s(thongbao, gio);
		strcat_s(thongbao, phut);
		Red_Highlight();
		hienThongBao(thongbao);
		return 1;
	}
	if (checkTimeHienTai(h) && h.gio == t.gio) {
		if (h.phut < t.phut) {
			_itoa_s(t.gio, gio, 10);
			strcat_s(gio, ":");
			_itoa_s(t.phut, phut, 10);
			strcat_s(thongbao, gio);
			strcat_s(thongbao, phut);
			Red_Highlight();
			hienThongBao(thongbao);
			return 1;
		}
	}
	if (h.gio > 23 || h.gio < 0)
	{
		Red_Highlight();
		hienThongBao("Gio bat dau tu 0h den 23h. Vui long nhap gio hop le!");
		return 1;
	}
	if (h.phut > 59 || h.phut < 0)
	{
		Red_Highlight();
		hienThongBao("Phut bat dau tu 0 den 59 phut. Vui long nhap phut hop le!");
		return 1;
	}
	return -1;
}

void catChuoi(string chuoi, char splitChar, int& vtri, char cmnd[]) {
	int len = chuoi.length();
	int k = 0;
	for (int i = 0; i < len; i++) {
		if (chuoi.at(i) == splitChar) {
			vtri = atoi(chuoi.substr(4, i).c_str());
			for (int j = i + 1; j < len; j++) {
				cmnd[k] = chuoi[j];
				k++;
			}
			cmnd[k + 1] = '\0';
			break;
		}
	}
}
//============Xu li chuc nang danh sach

int confirm(string chose1, string chose2, bool huyCB) {
	char key;
	int chon = 3;

	Highlight();
	gotoxy(COT + 10, DONGNHAP7);
	cout << chose1;
	Normal();
	gotoxy(COT + DAIKHUNGNHO + 28, DONGNHAP7);
	cout << chose2;
	do
	{
		key = _getch();
		if (key == -32)
			key = _getch();
		switch (key)
		{
		case LEFT:
			Normal();
			gotoxy(COT + DAIKHUNGNHO + 28, DONGNHAP7);
			cout << chose2;
			Highlight();
			gotoxy(COT + 10, DONGNHAP7);
			cout << chose1;
			chon = YES;
			break;
		case RIGHT:
			Normal();
			gotoxy(COT + 10, DONGNHAP7);
			cout << chose1;
			Highlight();
			gotoxy(COT + DAIKHUNGNHO + 28, DONGNHAP7);
			cout << chose2;
			if (huyCB == true)
				chon = HUY_CB;
			else
				chon = NO;
			break;
		case ENTER:
			Normal();
			gotoxy(COT + 10, DONGNHAP7);
			cout << "                                       ";
			return chon;
		case ESC:
			Normal();
			gotoxy(COT + 10, DONGNHAP7);
			cout << "                                       ";
			return CANCEL;
		}

	} while (true);
}


//=============Giao dien menu=============
mayBay ChonMB_LapCB(listMB list) {
	//xoaKhungDS();
	mayBay tmp;
	Normal();
	int page = MAX_PAGE - 1;
	if (list.n < MAX_PAGE)
		page = list.n;
	int dem = 0;
	int chon = 0;
	int i;
	showListMB(list);
	Highlight();
	showMotMB(list, chon, false, dem);
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == -32)
			kytu = _getch();
		switch (kytu)
		{
			case UP:
				if (chon > 0 && dem > 0) {
					Normal();
					showMotMB(list, chon, false, dem);

					chon--;
					dem--;
					Highlight();
					showMotMB(list, chon, false, dem);
				}
				break;
			case DOWN:
				if (chon + 1 < list.n && dem + 1 < MAX_PAGE) {
					Normal();
					showMotMB(list, chon, false, dem);
					chon++;
					dem++;
					Highlight();
					showMotMB(list, chon, false, dem);
				}
				break;
			case LEFT:
				if (page > MAX_PAGE) {
					Normal();
					page -= MAX_PAGE * 2;
					chon = page;
					dem = 0;
					//xoaThongTin(XOA_MB);
					for (page; page < list.n; page++) {
						showMotMB(list, page, true, dem);
						if (dem == MAX_PAGE - 1) {
							break;
						}
						dem++;
					}
					dem = 0;
					Highlight();
					showMotMB(list, chon, true, dem);
				}

				break;
			case RIGHT:
				if (page < list.n) {
					Normal();
					//xoaThongTin(XOA_MB);
					page++;
					chon = page;
					dem = 0;
					for (page; page < list.n; page++) {
						showMotMB(list, page, true, dem);
						if (dem == MAX_PAGE - 1) {
							break;
						}
						dem++;
					}
					page += MAX_PAGE - dem;
					dem = 0;
					Highlight();
					showMotMB(list, chon, true, dem);
				}
				break;
			case ESC: {
				Normal();
				tmp.soHieuMayBay[0] = '\0';
				return tmp;
			}
			case ENTER:
			{
				Normal();
				mayBay maybay;
				strcpy_s(maybay.soHieuMayBay, list.MB[chon]->soHieuMayBay);
				strcpy_s(maybay.loaiMayBay, list.MB[chon]->loaiMayBay);
				maybay.soCho = list.MB[chon]->soCho;
				maybay.soLuotThucHien = list.MB[chon]->soLuotThucHien;

				return maybay;
			}
		}
	} while (true);
}