#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
#define inputFileDSKQ "dsketqua.txt"
#define outputFile "ketquahoctap.txt"
struct hocphan
{
	char mahocphan[21];
	char tenhocphan[21];
	char ngaybatdau[21];
	char ngayketthuc[21];
};
struct sinhvien
{
	char masinhvien[21];
	char holot[21];
	char ten[21];
	char ngaysinh[21];
	char sdt[21];
};
struct detai
{
	char madetai[21];
	char tendetai[21];
	int slsv;
	char mahocphan[21];
	hocphan hp;
};
struct ketqua
{
	char masinhvien[21];
	char madetai[21];
	char tendetai[21];
	int diembaocao;
	int diemcaidat;
	int diemtrinhbay;
	detai dt;
	sinhvien sv;
};
struct DLSV
{
	hocphan a;
	sinhvien b;
	detai c;
	ketqua d;
};
typedef DLSV ItemType;
struct SNode
{
	ItemType Info;
	SNode *Next;

};
struct SList
{
	SNode *Head;
	SNode *Tail;
};
void InitSList(SList &sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
int IsEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1;
	else
		return 0;
}
SNode* CreateSNode(ItemType x)
{
	SNode* p = new SNode;
	if (p == NULL)
	{
		printf("\nKhong the cap phat nut moi!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
int InsertHead(SList &sl, SNode* p)
{
	if (p == NULL)
		return 0;
	if (IsEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}
int Inserttail(SList &sl, SNode *p)
{
	if (p == NULL)
		return 0;
	if (IsEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}
int InsertAfter(SList &sl, SNode *q, SNode *p)
{
	if (p == NULL || q == NULL)
		return 0;
	p->Next = q->Next;
	q->Next = p;
	if (sl.Tail == q)
		sl.Tail = p;
	return 1;
}
void ShowSListhocphan(SList sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
		printf("[%s, %s, %s, %s]\n", p->Info.a.mahocphan, p->Info.a.tenhocphan, p->Info.a.ngaybatdau, p->Info.a.ngayketthuc);
	printf("\n=====================================\n");
}
void ShowSListsinhvien(SList sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
		printf("[%s, %s %s, %s, %s ]\n", p->Info.b.masinhvien, p->Info.b.holot, p->Info.b.ten, p->Info.b.ngaysinh, p->Info.b.sdt);
	printf("\n=====================================\n");
}
void ShowSListdetai(SList sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
		printf("[%s, %s, %d, %s]\n", p->Info.c.madetai, p->Info.c.tendetai, p->Info.c.slsv, p->Info.c.mahocphan);
	printf("\n=====================================\n");
}
void ShowSListketqua(SList sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
		printf("[%s, %s, %s, %d, %d, %d]\n", p->Info.d.masinhvien, p->Info.d.madetai, p->Info.d.tendetai, p->Info.d.diembaocao,
		p->Info.d.diemcaidat, p->Info.d.diemtrinhbay);
	printf("\n=====================================\n");
}
void createFrom_Filehocphan(SList &sl)
{

	int n, kq;
	ItemType x;
	FILE* f = fopen("hocphan.txt", "rt");
	fscanf(f, "%d", &n);
	for (int i = 0; i<n; i++)
	{
		fscanf(f, "%s", &x.a.mahocphan);
		fscanf(f, "%s", &x.a.tenhocphan);
		fscanf(f, "%s", &x.a.ngaybatdau);
		fscanf(f, "%s", &x.a.ngayketthuc);
		SNode* p = CreateSNode(x);
		kq = InsertHead(sl, p);
		if (kq == 0)
			printf("\nKhong them duoc nut moi.");
	}
	fclose(f);
}
void createFrom_Filesinhvien(SList &sl)
{

	int n, kq;
	ItemType x;
	FILE* f = fopen("sinhvien.txt", "rt");
	fscanf(f, "%d", &n);
	for (int i = 0; i<n; i++)
	{
		fscanf(f, "%s", &x.b.masinhvien);
		fscanf(f, "%s", &x.b.holot);
		fscanf(f, "%s", &x.b.ten);
		fscanf(f, "%s", &x.b.ngaysinh);
		fscanf(f, "%s", &x.b.sdt);
		SNode* p = CreateSNode(x);
		kq = InsertHead(sl, p);
		if (kq == 0)
			printf("\nKhong them duoc nut moi.");
	}
	fclose(f);
}
void createFrom_Filedetai(SList &sl)
{

	int n, kq;
	ItemType x;
	FILE* f = fopen("detai.txt", "rt");
	fscanf(f, "%d", &n);
	for (int i = 0; i<n; i++)
	{
		fscanf(f, "%s", &x.c.madetai);
		fscanf(f, "%s", &x.c.tendetai);
		fscanf(f, "%d", &x.c.slsv);
		fscanf(f, "%s", &x.c.mahocphan);
		SNode* p = CreateSNode(x);
		kq = InsertHead(sl, p);
		if (kq == 0)
			printf("\nKhong them duoc nut moi.");
	}
	fclose(f);
}
void createFrom_Fileketqua(SList &sl)
{

	int n, kq;
	ItemType x;
	FILE* f = fopen("ketqua.txt", "rt");
	fscanf(f, "%d", &n);
	for (int i = 0; i<n; i++)
	{
		fscanf(f, "%s", &x.d.masinhvien);
		fscanf(f, "%s", &x.d.madetai);
		fscanf(f, "%s", &x.d.tendetai);
		fscanf(f, "%d", &x.d.diembaocao);
		fscanf(f, "%d", &x.d.diemcaidat);
		fscanf(f, "%d", &x.d.diemtrinhbay);
		SNode* p = CreateSNode(x);
		kq = InsertHead(sl, p);
		if (kq == 0)
			printf("\nKhong them duoc nut moi.");
	}
	fclose(f);
}
void adddetai(SList &sl)
{
	int kq;
	ItemType x;
	printf("nhap ma de tai\n");
	fflush(stdin);
	gets(x.c.madetai);
	printf("nhap ten de tai\n");
	fflush(stdin);
	gets(x.c.tendetai);
	printf("nhap so luong sinh vien\n");
	scanf_s("%d", &x.c.slsv);
	printf("nhap ma hoc phan\n");
	fflush(stdin);
	gets(x.c.mahocphan);
	SNode* p = CreateSNode(x);
	kq = Inserttail(sl, p);
	if (kq == 0)
		printf("\nKhong them duoc nut moi.");
}
void searchTheoTenHP(SList sl, char s[])
{
	if (sl.Head == NULL)
	{
		printf("\nDanh sach rong");
		return;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (stricmp(p->Info.d.dt.hp.tenhocphan, s) == 0)
		{
			printf("\nMa SV : %s", p->Info.b.masinhvien);
			printf("\nHo lot : %s", p->Info.b.holot);
			printf("\nTen SV : %s", p->Info.b.ten);
			printf("\nNgay sinh : %s", p->Info.b.ngaysinh);
			printf("\nSo dien thoai : %s", p->Info.b.sdt);
			printf("\n--------------------------------------------");
		}
	}
}
float maxDiemTK1HP(SList sl, char s[])
{
	float max = -1;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (stricmp(p->Info.d.dt.hp.mahocphan, s) == 0)
		{
			float x = p->Info.d.diembaocao * 0.4 + p->Info.d.diemtrinhbay * 0.2 + p->Info.d.diemcaidat * 0.4;
			if (x > max)
				max = x;
		}
	}return max;
}
void xuatSVDiemTKMaxMoiHP(SList sl, hocphan h[], int nHP)
{
	if (sl.Head == NULL)
	{
		printf("\nDanh sach rong");
		return;
	}
	for (int i = 0; i < nHP; i++)
	{
		printf("\n\nSinh vien co diem tong ket cao nhat mon %s:", h[i].tenhocphan);
		printf("\n----------------------------------------------------------------");
		float d = maxDiemTK1HP(sl, h[i].mahocphan);
		for (SNode* p = sl.Head; p != NULL; p = p->Next)
		{
			float x = p->Info.d.diembaocao * 0.4 + p->Info.d.diemtrinhbay * 0.2 + p->Info.d.diemcaidat * 0.4;
			if (stricmp(p->Info.d.dt.hp.mahocphan, h[i].mahocphan) == 0 && x == d)
			{
				printf("\nMa SV : %s", p->Info.b.masinhvien);
				printf("\nHo lot : %s", p->Info.b.holot);
				printf("\nTen SV : %s", p->Info.b.ten);
				printf("\nNgay thang nam sinh : %s", p->Info.b.ngaysinh);
				printf("\nSo dien thoai : %s", p->Info.b.sdt);
				printf("\nDiem tong ket: %.3f", x);
				printf("\n");
			}
		}
	}
}
void xuatHPDiemTongKetMax(SList sl, hocphan h[], int nHP)
{
	if (sl.Head == NULL)
	{
		printf("\nDanh sach rong");
		return;
	}

	char s[26];
	float d = maxDiemTK1HP(sl, h[0].mahocphan);
	strcpy(s, h[0].mahocphan);

	for (int i = 1; i < nHP; i++)
	{
		if (maxDiemTK1HP(sl, h[i].mahocphan) > d)
		{
			d = maxDiemTK1HP(sl, h[i].mahocphan);
			strcpy(s, h[i].mahocphan);
		}
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (stricmp(p->Info.d.dt.hp.mahocphan, s) == 0)
		{
			printf("\nMa HP : %s", p->Info.d.dt.hp.mahocphan);
			printf("\nTen HP : %s", p->Info.d.dt.hp.tenhocphan);
			printf("\nNgay bat dau : %s", p->Info.d.dt.hp.ngaybatdau);
			printf("\nNgay ket thuc : %s", p->Info.d.dt.hp.ngayketthuc);
			break;
		}
	}
}
void swap(ItemType &x, ItemType &y)
{
	ItemType temp = x;
	x = y;
	y = temp;
}
void interchangeSort_Asc(SList &sl)
{
	SNode *p, *q;
	for (p = sl.Head; p->Next != NULL; p = p->Next)
	{
		for (q = p->Next; q != NULL; q = q->Next)
		{
			if (p->Info.c.slsv < q->Info.c.slsv)
				swap(p->Info, q->Info);
		}
	}
}
void ShowSListdetaiNhoHon3(SList sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (p->Info.c.slsv <= 3)
		{
			interchangeSort_Asc(sl);
			printf("[%s, %s, %d, %s]\n", p->Info.c.madetai, p->Info.c.tendetai, p->Info.c.slsv, p->Info.c.mahocphan);
		}
	}
	printf("\n=====================================\n");
}
void saveItem(FILE *fo, ketqua x)
{ 
	fprintf(fo, "%-30s%-20s%-20s%10d%10d%10d", x.masinhvien, x.madetai, x.tendetai, x.diembaocao,x.diemcaidat,x.diemtrinhbay);
}
void saveSList(char fName[], SList sl)
{
	FILE *fo;
	fo = fopen(fName, "w+");
	if (!fo)
	{
		printf("Loi mo file de ghi!");
		return;
	}
	fprintf(fo, "BANG DIEM SINH VIEN\n");
	SNode *p = sl.Head;
	int i = 1;
	while (p != NULL)
	{
		saveItem(fo, p->Info.d);
		p = p->Next;
	}
	fclose(fo);
	printf("\nLuu file thanh cong!");
}
void menu()
{
	printf("\n=====================================\n");
	printf("0. Thoat chuong trinh");
	printf("\n1. doc du lieu tu file");
	printf("\n2. Them 1 de tai moi vao ");
	printf("\n3.Tim kiem sinh vien ");
	printf("\n4.In ket qua cua sinh vien");
	printf("\n5.Tim thong tin cua sinh vien co diem tong cao nhat");
	printf("\n6.Tim lop hoc phan co diem tong cao nhat");
	printf("\n7.Sap xep danh sach sinh vien theo ten hoc phan");
	printf("\n8.In thong tin cua cac de tai co so sinh vien nho hon bang 3");
	printf("\n9.In bang diem sinh vien hoc lop hoc phan khi biet ma lop hoc phan");
	printf("\n=====================================\n");
}
void process()
{
	hocphan h[21];
	int nHP;
	char s[21];
	int chon, xoa, tim;
	ItemType x;
	SNode *P, *Q;
	SList hp;
	SList sv;
	SList dt;
	SList kq;
	InitSList(hp);
	InitSList(sv);
	InitSList(dt);
	InitSList(kq);
	do {
		menu();
		printf("\nNhap vao lua chon: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 0:
			exit(0);
			break;
		case 1:
			createFrom_Filehocphan(hp);
			createFrom_Filesinhvien(sv);
			createFrom_Filedetai(dt);
			createFrom_Fileketqua(kq);
			printf("=====================================\n");
			printf("danh sach hoc phan:\n");
			ShowSListhocphan(hp);
			printf("danh sach sinh vien:\n");
			ShowSListsinhvien(sv);
			printf("danh sach de tai:\n");
			ShowSListdetai(dt);
			printf("danh sach ket qua:\n");
			ShowSListketqua(kq);
			break;
		case 2:
			adddetai(dt);
			printf("danh sach de tai:\n");
			ShowSListdetai(dt);
			break;
		case 3:
			searchTheoTenHP(hp, s);
			ShowSListhocphan(hp);
			break;
		case 4:
			printf("danh sach ket qua:\n");
			ShowSListketqua(kq);
			break;
		case 5:
			maxDiemTK1HP(kq, s);
			xuatSVDiemTKMaxMoiHP(kq, h, nHP);
			break;
		case 6:
			xuatHPDiemTongKetMax(kq, h, nHP);
			break;
		case 7:
			break;
		case 8:
			createFrom_Filedetai(dt);
			printf("Danh sach de tai nho hon 3");
			ShowSListdetaiNhoHon3(dt);
			break;
		case 9:
			saveSList(outputFile, kq);
			break;
		default:
			printf("\nVui long kiem tra lai lua chon !");
			break;
		}

	} while (chon != 0);
}


//==============================================
void main()
{
	process();
}