#include <stdio.h>
#include <string.h>
#include <iostream>
#include <wchar.h>
struct SinhVien
{
	wchar_t email[30];
	wchar_t HoTen[30];
	char MSSV[10];
	wchar_t	Khoa[30];
	int NamHoc;
	char NgaySinh[10]; //	dd/mm/yyyy (10 char)
	char Anh[14];	//	(mssv).img	(14 char)
	wchar_t BanThan[1000];
	wchar_t SoThich[1000];
};
typedef SinhVien SV;

int readSV(int &flagVitri)
{
	SV SV;
	FILE *FileSV;
	FileSV = _wfopen(L"ThongTin.csv", L"w,ccs=UTF-16LE");
	wchar_t bufwchar;
	char bufchar;
	if (!FileSV) // check file
	{
		printf("File could not be opened.\n");
		system("pause");
		return 0;
	}
	
	//Doc MSSV
	fwscanf(FileSV,L"%[^,],",SV.MSSV);
	flagVitri = ftell(FileSV)+strlen(SV.MSSV)+1;
	fseek(FileSV, flagVitri, SEEK_CUR);

	//Doc Ho ten
	fwscanf(FileSV, L"%[^,],", SV.HoTen);
	flagVitri = ftell(FileSV) + wcslen(SV.HoTen) + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);
	
	//Doc email
	fwscanf(FileSV, L"%[^,],", SV.email);
	flagVitri = ftell(FileSV) + wcslen(SV.email) + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);

	//Doc Khoa
	fwscanf(FileSV, L"%[^,],", SV.Khoa);
	flagVitri = ftell(FileSV) + wcslen(SV.Khoa) + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);

	//Doc Nam Hoc
	fwscanf(FileSV, L"%[^,],", SV.NamHoc);
	flagVitri = ftell(FileSV) + 4 + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);
	
	//Doc Ngay Sinh
	fwscanf(FileSV, L"%[^,],", SV.NgaySinh);
	flagVitri = ftell(FileSV) + strlen(SV.NgaySinh) + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);
	
	//Doc Anh
	fwscanf(FileSV, L"%[^,],", SV.Anh);
	flagVitri = ftell(FileSV) + strlen(SV.Anh) + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);
	
	//Doc Ban Than
	fwscanf(FileSV, L"%[^,],", SV.BanThan);
	flagVitri = ftell(FileSV) + wcslen(SV.BanThan) + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);
	
	//Doc SoThich
	fwscanf(FileSV, L"%[^\n]\n", SV.SoThich);
	flagVitri = ftell(FileSV) + wcslen(SV.SoThich) + 1;
	fseek(FileSV, flagVitri, SEEK_CUR);

	fclose(FileSV);
		if (SV.MSSV != 0)
		printf("MSSV: %s\n", SV.MSSV);
		printf("Ho ten: %s\n", SV.HoTen);
		printf("Khoa: %s\n", SV.Khoa);
		printf("Email: %s\n", SV.email);
		printf("Khoa' hoc: %d\n", SV.NamHoc);
		printf("Ngay sinh: %s\n", SV.NgaySinh);
		printf("So thich: %s\n", SV.SoThich);
}

void main()
{
	int flagVitri;
	readSV(flagVitri);
	system("pause");
}