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

//========== Xu Ly Nhap ===========
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

void NhapCHUOI_SO(char var[], int len) {

	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;
	rewind(stdin);
	NhapChuoi nhap;

	nhap.n = 0;

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			if (!(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122)
				&& !((int)c >= 48 && (int)c <= 57) && c != ' ') && nhap.n < maxInput) {
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
