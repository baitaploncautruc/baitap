#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
 
struct SanPham {
    int id;
    char tensp[30];
    int soluong;
    float gia;
   char ngaysx[30];
};
typedef SanPham SP;
void printLine(int n);
int idLonNhat(SP a[], int n);
void nhapThongTinSP(SP &sp, int id);
void nhapSP(SP a[], int id, int n);
void capNhatThongTinSP(SP &sp);
void capNhatSP(SP a[], int id, int n);
int xoaTheoID(SP a[], int id, int n);
void timKiemTheoTen(SP a[], char tensp[], int n);
void sapXepTheoTen(SP a[], int n);
void showStudent(SP a[], int n);
int docFile(SP a[], char fileName[]);
void ghiFile(SP a[], int n, char fileName[]);
void pressAnyKey();
int main() {
    int key;
    char fileName[] = "filesanpham.txt";
    SP arraySP[MAX];
    int soluongSP = 0;
    int idCount = 0; 
     
    // nhap danh sach sinh vien tu file
    soluongSP = docFile(arraySP, fileName);
    idCount = idLonNhat (arraySP, soluongSP);
 
    while(true) {
        cout << "QUAN LY SAN PHAM C/C++\n";
        cout << "1.Them san pham.                               \n";
        cout << "2.Cap nhat thong tin san pham bang ID.          \n";
        cout << "3.Xoa san pham bang ID.                         \n";
        cout << "4.Tim kiem san pham theo ten.                  \n";
        cout << "5.Sap xep san pham theo ten.                   \n";
        cout << "6.Hien thi danh sach cac san pham.                 \n";
        cout << "7.Ghi danh sach san pham vao file.             \n";
        cout << "0.Thoat                                         \n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them san pham.";
                idCount++;
                nhapSP(arraySP, idCount, soluongSP);
                printf("\nThem san pham thanh cong!");
                soluongSP++;
                pressAnyKey();
                break;
            case 2:
                if(soluongSP > 0) {
                    int id;
                    cout << "\n2. Cap nhat thong tin san pham. ";
                    cout << "\n Nhap ID: "; cin >> id;
                    capNhatSP(arraySP, id, soluongSP);
                }else{
                    cout << "\nDanh sach san pham trong!";
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongSP > 0) {
                    int id;
                    cout << "\n3. Xoa san pham.";
                    cout << "\n Nhap ID: "; cin >> id;
                    if (xoaTheoID(arraySP, id, soluongSP) == 1) {
                        printf("\nDan pham co id = %d da bi xoa.", &id);
                        soluongSP--;
                    }
                }else{
                    cout << "\nDanh sach san pham trong!";
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongSP > 0) {
                    cout << "\n4. Tim kiem san pham theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    timKiemTheoTen(arraySP, strTen, soluongSP);
                }else{
                    cout << "\nDanh sach san pham trong!";
                }
                pressAnyKey();
                break;
            case 5:
                if(soluongSP > 0) {
                    cout << "\n6. Sap xep san pham theo ten.";
                    sapXepTheoTen(arraySP, soluongSP);
                    showStudent(arraySP, soluongSP);
                } else {
                    cout << "\nDanh sach san pham trong!";
                }
                pressAnyKey();
                break;
            case 6:
                if(soluongSP > 0){
                    cout << "\n7. Hien thi danh sach san pham.";
                    showStudent(arraySP, soluongSP);
                }else{
                    cout << "\nDanh sach san pham trong!";
                }
                pressAnyKey();
                break;
            case 7:
                if(soluongSP > 0){
                    cout << "\n8. Ghi danh sach san pham vao file.";
                    ghiFile(arraySP, soluongSP, fileName);
                }else{
                    cout << "\nDanh sach san pham trong!";
                }
                printf("\nGhi danh sach san pham vao file %s thanh cong!", fileName);
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
void nhapThongTinSP(SP &sp, int id) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(sp.tensp);
    cout << " Nhap so luong: "; cin >> sp.soluong;
    cout << " Nhap gia: "; cin >> sp.gia;
    cout << " Nhap ngay san xuat: "; cin >> sp.ngaysx;
    sp.id = id;
}
 
void nhapSP(SP a[], int id, int n) {
    printLine(40);
    printf("\n Nhap san pham thu %d:", n + 1);
    nhapThongTinSP(a[n], id);
    printLine(40);
}
 
void capNhatThongTinSP(SP &sp) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(sp.tensp);
    cout << " Nhap so luong: "; cin >> sp.soluong;
    cout << " Nhap gia: "; cin >> sp.gia;
    cout << " Nhap ngay san xuat: "; cin >> sp.ngaysx;
}
 
void capNhatSP(SP a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin san pham co ID = " << id;
            capNhatThongTinSP(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n San pham co ID = %d khong ton tai.", id);
    }
}
 
int xoaTheoID(SP a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa SP co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n San pham co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}
 
void timKiemTheoTen(SP a[], char tensp[], int n) {
    SP arrayFound[MAX];
    char tenSP[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSP, a[i].tensp);
        if(strstr(strupr(tenSP), strupr(tensp))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}
 
void showStudent(SP a[], int n) {
    printLine(100);
    cout <<"\nSTT\tID\tTen San pham\tSo Luong\tGia\tNgay San Xuat";
    for(int i = 0; i < n; i++) {
    	// in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].tensp);
        printf("\t\t%d", a[i].soluong);
        printf("\t%.3f", a[i].gia);
        printf("\t%s", a[i].ngaysx);
    }
    printLine(100);
}
  

void sapXepTheoTen(SP a[], int n) {
    //Sap xep sinh vien theo ten theo thu tu tang dan
    SP tmp;
    char tenSP1[30];
    char tenSP2[30];
    for(int i = 0;i < n; i++) {
        strcpy(tenSP1, a[i].tensp);
        for(int j = i+1; j < n; j++) {
            strcpy(tenSP2, a[j].tensp);
            if(strcmp(strupr(tenSP1), strupr(tenSP2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
int idLonNhat (SP a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for(int i = 0;i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
 
int docFile(SP a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << " "; puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].id, &a[i].tensp, 
             &a[i].soluong, &a[i].gia, &a[i].ngaysx) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong san pham co san trong file la: " << i << endl;
    cout << endl;
    fclose (fp);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}
 
void ghiFile(SP a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].id, a[i].tensp, a[i].soluong, a[i].gia, a[i].ngaysx);
    }
    fclose (fp);
}
 
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
 
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
