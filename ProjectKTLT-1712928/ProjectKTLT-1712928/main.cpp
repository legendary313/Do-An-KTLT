#include <stdio.h>
#include <string.h>

struct SinhVien
{
	wchar_t HoTen[30];
	char MSSV[10];
	wchar_t Khoa[30];
	int NamHoc;
	char NgaySinh;
	char Anh;
	wchar_t BanThan[1000];
	wchar_t SoThich[1000];
};
typedef SinhVien SV;

int readSV()
{
	SV SV;
	FILE *FileSV;


	char *buf = new char[256];
	char *tmp;
	if ((FileSV = fopen("Test.csv", "r")) == NULL) //Đọc file
	{
		printf("File could not be opened.\n");
	}
	int i = 0;
	int j = 0;
	int flag = 0;
	while (fgets(buf, 255, FileSV) != NULL)
	{
		if ((strlen(buf)>0) && (buf[strlen(buf) - 1] == '\n'))
			buf[strlen(buf) - 1] = '\n';

	if ((FileSV = fopen("ThongTin.csv", "r")) == NULL) //Đọc file
	{
		printf("File could not be opened.\n");
	}
	tmp = strtok(NULL, ",");
	SV.MSSV = tmp;

	tmp = strtok(NULL, ",");
	SV.HoTen = tmp;

	tmp = strtok(NULL, ",");
	SV.Khoa = tmp;

	tmp = strtok(buf, ",");
	SV.NamHoc = tmp;


	tmp = strtok(NULL, ",");
	SV.NgaySinh = tmp;

	tmp = strtok(NULL, ",");
	SV.Anh = tmp;

	tmp = strtok(NULL, ",");
	for (j; strcpy(tmp, '\0') != 0; j++)
	{
		SV.SoThich[j] = tmp;
	}
	//tempStudent.ID = atoi(buf);

	i++;
	flag = -1;
	}
	//free(buf);
	fclose(FileSV);
		/*if (SV.MSSV != 0)
			printf("MSSV: %s\n", SV.MSSV);
		printf("Ho ten: %s\n", SV.HoTen);
		printf("Khoa: %s\n", SV.Khoa);
		printf("Khoa' hoc: %d\n", SV.NamHoc);
		printf("Ngay sinh: %s\n", SV.NgaySinh);
		for (int k = 0; k<j; k++)
			printf("So thich: %s\n", SV.SoThich);
	}
	return 0;*/
}