#include <stdio.h>
#include <string.h>
#include <iostream>
#include <wchar.h>
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
struct SinhVien
{
	wchar_t email[30];
	wchar_t HoTen[30];
	wchar_t MSSV[10];
	wchar_t	Khoa[30];
	wchar_t NamHoc[4];
	wchar_t NgaySinh[10]; //	dd/mm/yyyy (10 char)
	wchar_t Anh[14];	//	(mssv).img	(14 char)
	wchar_t BanThan[1000];
	wchar_t SoThich[1000];
};
typedef SinhVien SV;

int readSV(int &flagVitri)
{
	_setmode(_fileno(stdout), _O_U16TEXT);  //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	FILE *FileSV;
	FileSV = _wfopen(L"ThongTin.csv", L"r,ccs=UTF-16LE");
	if (!FileSV) // check file
	{
		printf("File could not be opened.\n");
		system("pause");
	}
	fseek(FileSV, 0, SEEK_END);
	int FileLength = ftell(FileSV);
	for (int i = 0; i <= FileLength; i++)
	{ 
		//chưa biết :)
	}
	SV SV;
	fseek(FileSV, 0, SEEK_SET);
	//Doc MSSV
	fwscanf(FileSV, L"%[^,],", &SV.MSSV);
	flagVitri = ftell(FileSV)+wcslen(SV.MSSV)-2;
	fseek(FileSV, flagVitri, SEEK_SET);

	//Doc Ho ten
	fwscanf(FileSV, L"%[^,],", &SV.HoTen);
	flagVitri = ftell(FileSV) + wcslen(SV.HoTen) +1;
	fseek(FileSV, flagVitri, SEEK_SET);
	
	//Doc email
	fwscanf(FileSV, L"%[^,],", &SV.email);
	flagVitri = ftell(FileSV) + wcslen(SV.email) -5;
	fseek(FileSV, flagVitri, SEEK_SET);

	//Doc Khoa
	fwscanf(FileSV, L"%[^,],", &SV.Khoa);
	flagVitri = ftell(FileSV) + wcslen(SV.Khoa) + 1;
	fseek(FileSV, flagVitri, SEEK_SET);

	//Doc Nam Hoc
	fwscanf(FileSV, L"%[^,],", &SV.NamHoc);
	flagVitri = ftell(FileSV) + 5;
	fseek(FileSV, flagVitri, SEEK_SET);
	
	//Doc Ngay Sinh
	fwscanf(FileSV, L"%[^,],", &SV.NgaySinh);
	flagVitri = ftell(FileSV) + wcslen(SV.NgaySinh) + 1;
	fseek(FileSV, flagVitri, SEEK_SET);
	
	//Doc Anh
	fwscanf(FileSV, L"%[^,],", &SV.Anh);
	flagVitri = ftell(FileSV) + wcslen(SV.Anh) + 1;
	fseek(FileSV, flagVitri, SEEK_SET);
	
	//Doc Ban Than
	fwscanf(FileSV, L"%[^,],", &SV.BanThan);
	flagVitri = ftell(FileSV) + wcslen(SV.BanThan) + 1;
	fseek(FileSV, flagVitri, SEEK_SET);
	
	//Doc SoThich
	fwscanf(FileSV, L"%[^\n]\n", &SV.SoThich);
	flagVitri = ftell(FileSV) + wcslen(SV.SoThich) + 1;
	fseek(FileSV, flagVitri, SEEK_SET);

	fclose(FileSV);
	wprintf(L"MSSV: %ls\n", SV.MSSV);
	wprintf(L"Ho ten: %ls\n", SV.HoTen);
	wprintf(L"Khoa: %ls\n", SV.Khoa);
	wprintf(L"Email: %ls\n", SV.email);
	wprintf(L"Khoa' hoc: %ls\n", SV.NamHoc);
	wprintf(L"Anh: %ls\n", SV.Anh);
	wprintf(L"Ngay sinh: %ls\n", SV.NgaySinh);
	wprintf(L"Ban Than: %ls\n", SV.BanThan);
	wprintf(L"So thich: %ls\n", SV.SoThich);
	return 0;
}

void html(SV SV)
{
	FILE *html;
	wchar_t name[14];
	for (int i = 0; i <= wcslen(SV.MSSV); i++)
	{
		name[i] = SV.MSSV[i];
	}
	wchar_t* name_html = wcscat(name, L".html");
	html = _wfopen(name_html, L"w,ccs=UTF-16LE");
	fwprintf(html,L"!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">");
	fwprintf(html,L"<html xmlns = \"http://www.w3.org/1999/xhtml\">");
	fwprintf(html,L"<head>");
	fwprintf(html,L"<meta http - equiv = \"Content - Type\" content = \"text / html; charset = utf - 8\" / >");
	fwprintf(html,L"<link rel = \"stylesheet\" type = \"text / css\" href = \"personal.css\" / >");
	fwprintf(html,L"<title>0< / title>");
	fwprintf(html,L"< / head>");
	fwprintf(html,L"<body>");
	fwprintf(html,L"<div class = \"Layout_container\">");
	fwprintf(html,L"<!--Begin Layout Banner Region-->");
	fwprintf(html,L"<div class = \"Layout_Banner\" >");
	fwprintf(html,L"<div><img id = \"logo\" src = \"Images / logo.jpg\" height = \"105\" / >< / div>");
	fwprintf(html, L"<div class = \"Header_Title\">TRƯỜNG ÐẠI HỌC KHOA HỌC TỰ NHIÊN < / div>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<!--End Layout Banner Region-->");
	fwprintf(html, L"<!--Begin Layout MainContents Region-->");
	fwprintf(html, L"<div class = \"Layout_MainContents\">");
	fwprintf(html, L"<!--Begin Below Banner Region-->");
	fwprintf(html, L"<div class = \"Personal_Main_Information\">");
	fwprintf(html, L"<!--Begin Thông tin cá nhân của thầy cô----------------------------------------------------------------------------------------->");
	fwprintf(html, L"<div class = \"Personal_Location\">");
	fwprintf(html, L"<img src = \"Images / LogoFooter.jpg\" width = \"27\" height = \"33\" / >");
	fwprintf(html, L"<div class = \"Personal_FullName\">Dương Nguyên Trường Vỹ   < / div>");
	fwprintf(html, L"<div class = \"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN< / div>");
	fwprintf(html, L"<br / >");
	fwprintf(html, L"<div class = \"Personal_Phone\">");
	fwprintf(html, L"Email: truongvy99413");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<br / >");
	fwprintf(html, L"<br / >");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<!--End Thông tin cá nhân của thầy cô------------------------------------------------------------------------------------------>");
	fwprintf(html, L"<div class = \"Personal_HinhcanhanKhung\">");
	fwprintf(html, L"<img src = \"Images / 1712928.jpg\" class = \"Personal_Hinhcanhan\" / >");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<!--End Below Banner Region-->");
	fwprintf(html, L"<!--Begin MainContents Region-->");
	fwprintf(html, L"<div class = \"MainContain\">");
	fwprintf(html, L"<!--Begin Top Region-->");
	fwprintf(html, L"<div class = \"MainContain_Top\">");
	fwprintf(html, L"<div class = \"InfoGroup\">Thông tin cá nhân< / div>");
	fwprintf(html, L"<div>");
	fwprintf(html, L"<ul class = \"TextInList\">");
	fwprintf(html, L"<li>Họ và tên : Dương Nguyên Trường Vỹ< / li>");
	fwprintf(html, L"<li>MSSV : 1212928< / li>");
	fwprintf(html, L"<li>Sinh viên khoa Công nghệ thông tin< / li>");
	fwprintf(html, L"<li>Ngày sinh : 13 / 04 / 1999< / li>");
	fwprintf(html, L"<li>Email : nva@gmail.com< / li>");
	fwprintf(html, L"< / ul>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<div class = \"InfoGroup\">Sở thích< / div>");
	fwprintf(html, L"<div>");
	fwprintf(html, L"<ul class = \"TextInList\">");
	fwprintf(html, L"<li>Âm nhạc : POP, Balad< / li>");
	fwprintf(html, L"<li>Ẩm thực : bún riêu, bún thịt nướng< / li>");
	fwprintf(html, L"< / ul>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<div class = \"InfoGroup\">Mô tả< / div>");
	fwprintf(html, L"<div class = \"Description\">");
	fwprintf(html, L"Tôi là một nguời rất thân thiện.");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<!--Begin Layout Footer-->");
	fwprintf(html, L"<div class = \"Layout_Footer\">");
	fwprintf(html, L"<div class = \"divCopyright\">");
	fwprintf(html, L"<br / >");
	fwprintf(html, L"<img src = \"Images / LogoFooter_gray.jpg\" width = \"34\" height = \"41\" / ><br / >");
	fwprintf(html, L"<br / >");
	fwprintf(html, L"<center>@2013< / br>");
	fwprintf(html, L"Ðồ án giữa kì< / br>");
	fwprintf(html, L"Kĩ thuật lập trình< / br>");
	fwprintf(html, L"TH2012 / 03< / br>");
	fwprintf(html, L"1712928 - Dương Nguyên Trường Vỹ< / br>");
	fwprintf(html, L"< / center>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"<!--End Layout Footer-->");
	fwprintf(html, L"< / div>");
	fwprintf(html, L"< / body>");
	fwprintf(html, L"< / html>");
}

void main()
{
	int flagVitri;
	readSV(flagVitri);
	system("pause");
}

