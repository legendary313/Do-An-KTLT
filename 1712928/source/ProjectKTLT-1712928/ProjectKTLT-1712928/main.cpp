#include <stdio.h>
#include <string.h>
#include <iostream>
#include <wchar.h>
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
struct SinhVien
{
	wchar_t *email;
	wchar_t *HoTen;
	wchar_t *MSSV;
	wchar_t	*Khoa;
	wchar_t *NamHoc;
	wchar_t *NgaySinh; 
	wchar_t *Anh;	
	wchar_t *BanThan;
	wchar_t *SoThich;
};
typedef SinhVien SV;

void XoaKep(wchar_t *a)
{
	if (a == NULL) { return; }
	else 
	{
		int x = wcslen(a);
		for (int i = 0; i < x; i++)
		{
			if (a[i] == '"')
			{
				for (int j = i; j < x; j++)
				{
					a[j] = a[j + 1];
				}
				a[x - 1] = '\0';
			}
		}
	}
}

void XoaPhay(wchar_t *a)
{
	if (a == NULL) { return; }
	else
	{
		int x = wcslen(a);
		for (int i = 0; i < x; i++)
		{
			if (a[i] == ',')
			{
				for (int j = i; j < x; j++)
				{
					a[j] = a[j + 1];
				}
				a[x - 1] = '\0';
				break;
			}
		}
	}
}
#pragma warning(disable: 4996)


void TaoFileTuThongTinSV(int &dem, SV SV[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);  //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE *FileSV;
	FileSV = _wfopen(L"ThongTin.csv", L"r,ccs=UTF-8");
	if (!FileSV) // check file
	{
		printf("File could not be opened.\n");
		system("pause");
	}
	// Dem so dong
	wchar_t str[2400];
	int i; dem = 0;

	while (fgetws(str, 2400, FileSV) != NULL)
	{
		dem++;
	}
	// Doc Vao cac bien trong struct
	
	rewind(FileSV);
	wchar_t *token;
	for (i = 1; i <= dem; i++)
	{
		fgetws(str, 2400, FileSV);
		//Doc MSSV
		token = wcstok(str, L",");
		XoaKep(token);
		SV[i].MSSV = token;
		//Doc Ho ten
		token = wcstok(NULL, L",");
		XoaKep(token);
		SV[i].HoTen = token;
		//Doc email
		token = wcstok(NULL, L",");
		XoaKep(token);
		SV[i].email = token;
		//Doc Khoa
		token = wcstok(NULL, L",");
		XoaKep(token);
		SV[i].Khoa = token;

		//Doc Nam Hoc
		token = wcstok(NULL, L",");
		XoaKep(token);
		SV[i].NamHoc = token;

		//Doc Ngay Sinh
		token = wcstok(NULL, L",");
		XoaKep(token);
		SV[i].NgaySinh = token;

		//Doc Anh
		token = wcstok(NULL, L",");
		XoaKep(token);
		SV[i].Anh = token;

		//Doc Ban Than
		token = wcstok(NULL, L"\"\"");
		SV[i].BanThan = token; XoaPhay(token);

		//Doc SoThich
		token = wcstok(NULL, L"\n");
		if (token != NULL)
		{	
		XoaPhay(token);
		XoaKep(token);
		SV[i].SoThich = token;
	    }
		FILE *f;
		wchar_t name[14];
		for (int j = 0; j <= wcslen(SV[i].MSSV); j++)
		{
			name[j] = SV[i].MSSV[j];
		}
		wchar_t* name_html = wcscat(name, L".html");
		f = _wfopen(name_html, L"w,ccs=UTF-16LE");

		fwprintf(f, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f, L"<head>\n");
		fwprintf(f, L"<meta http-equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" / >\n");
		fwprintf(f, L"<link rel = \"stylesheet\" type = \"text/css\" href = \"personal.css\" / >\n");
		fwprintf(f, L"<title>HCMUS - %ls</title>\n", SV[i].HoTen);
		fwprintf(f, L"</head>\n");
		fwprintf(f, L"<body>\n");
		fwprintf(f, L"<div class = \"Layout_container\">\n");
		fwprintf(f, L"<!--Begin Layout Banner Region-->\n");
		fwprintf(f, L"<div class = \"Layout_Banner\" >\n");
		fwprintf(f, L"<div><img id = \"logo\" src = \"Images/logo.jpg\" height = \"105\" / ></div>\n");
		fwprintf(f, L"<div class = \"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Layout Banner Region-->\n");
		fwprintf(f, L"<!--Begin Layout MainContents Region-->\n");
		fwprintf(f, L"<div class = \"Layout_MainContents\">\n");
		fwprintf(f, L"<!--Begin Below Banner Region-->\n");
		fwprintf(f, L"<div class = \"Personal_Main_Information\">\n");
		fwprintf(f, L"<!--Begin Thông tin cá nhân của thầy cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_Location\">\n");
		fwprintf(f, L"<img src = \"Images/LogoFooter.jpg\" width = \"27\" height = \"33\" / >\n");
		fwprintf(f, L"<span class = \"Personal_FullName\">%ls - %ls</span>\n", SV[i].HoTen, SV[i].MSSV);
		fwprintf(f, L"<div class = \"Personal_Department\">KHOA %ls</div>\n", SV[i].Khoa);
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"<div class = \"Personal_Phone\">\n");
		fwprintf(f, L"Email: %ls\n", SV[i].email);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Thông tin cá nhân c ? a th ? y cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_HinhcanhanKhung\">\n");
		fwprintf(f, L"<img src = \"Images/%ls\" class = \"Personal_Hinhcanhan\" / >\n", SV[i].Anh);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Below Banner Region-->\n");
		fwprintf(f, L"<!--Begin MainContents Region-->\n");
		fwprintf(f, L"<div class = \"MainContain\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<!--Begin Top Region-->\n");
		fwprintf(f, L"<div class = \"MainContain_Top\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class = \"TextInList\">\n");
		fwprintf(f, L"<li>Họ và tên : %ls</li>\n", SV[i].HoTen);
		fwprintf(f, L"<li>MSSV : %ls</li>\n", SV[i].MSSV);
		fwprintf(f, L"<li>Sinh viên khoa %ls</li>\n", SV[i].Khoa);
		fwprintf(f, L"<li>Ngày sinh : %ls</li>\n", SV[i].NgaySinh);
		fwprintf(f, L"<li>Email : %ls</li>\n", SV[i].email);
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Sở thích</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class = \"TextInList\">\n");
		fwprintf(f, L"<li>%ls</li>\n", SV[i].SoThich);
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Mô tả</div>\n");
		fwprintf(f, L"<div class = \"Description\">\n");
		fwprintf(f, L"%ls.\n", SV[i].BanThan);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<!--Begin Layout Footer-->\n");
		fwprintf(f, L"<div class = \"Layout_Footer\">\n");
		fwprintf(f, L"<div class = \"divCopyright\">\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"<img src = \"Images/LogoFooter_gray.jpg\" width = \"34\" height = \"41\"/><br/>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"@2013</br>\n");
		fwprintf(f, L"Đồ án giữ kỳ</br>\n");
		fwprintf(f, L"Kỹ thuật lập trình</br>\n");
		fwprintf(f, L"TH2012 / 03</br>\n");
		fwprintf(f, L"1712928 - Dương Nguyên Trường Vỹ</br>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Layout Footer-->\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</body>\n");
		fwprintf(f, L"</html>");
		fclose(f);
	}

	fflush(stdin);
	fclose(FileSV);
}

void main()
{
	SV SV[100];
	int dem;
	TaoFileTuThongTinSV(dem,SV);
	system("pause");
}