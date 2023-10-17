#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class SinhVien
{
public:
    char maSV[11];
    char hoTen[50];
    int namSinh;
    char queQuan[50];

    SinhVien()
    {
        maSV[0] = 0;
        hoTen[0] = 0;
        namSinh = 0;
        queQuan[0] = 0;
    }

    void nhap();
    void in();
};

void SinhVien::nhap()
{
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cin.ignore(100, '\n');
    cout << "Nhap ho ten: ";
    cin.getline(hoTen, 50);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cin.ignore(100, '\n');
    cout << "Nhap que quan: ";
    cin.getline(queQuan, 50);
}

void SinhVien::in()
{
    cout << "Ma sinh vien: " << maSV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Nam sinh: " << namSinh << endl;
    cout << "Que quan: " << queQuan << endl;
    cout << "-------------------------------" << endl;
}

void nhapDanhSachHocSinh(vector<SinhVien>& DSSV)
{
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    DSSV.clear();
    DSSV.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":" << endl;
        DSSV[i].nhap();
    }
}

void ghiDanhSachHocSinhVaoFile(const vector<SinhVien>& DSSV, string fileName)
{
    ofstream outFile;
    outFile.open(fileName, ios_base::out);
    if (!outFile.is_open())
    {
        cout << "Khong mo duoc file." << endl;
        return;
    }

    for (const SinhVien& SV : DSSV)
    {
        outFile.write((char*)&SV, sizeof(SinhVien));
    }
    outFile.close();
    cout << "Ghi danh sach hoc sinh vao file thanh cong." << endl;
}

void hienThiDanhSachHocSinh(const vector<SinhVien>& DSSV)
{
    for (const SinhVien& SV : DSSV)
    {
        SV.in();
    }
}

void docDanhSachHocSinhTuFile(vector<SinhVien>& DSSV, string fileName)
{
    ifstream inFile;
    inFile.open(fileName, ios_base::binary);
    if (!inFile.is_open())
    {
        cout << "Khong mo duoc file." << endl;
        return;
    }

    DSSV.clear();
    SinhVien SV;
    while (inFile.read((char*)&SV, sizeof(SinhVien)))
    {
        DSSV.push_back(SV);
    }
    inFile.close();
    cout << "Doc danh sach hoc sinh tu file thanh cong." << endl;
}

int timKiemHocSinhTheoMaSV(const vector<SinhVien>& DSSV, char* maSV)
{
    for (int i = 0; i < DSSV.size(); i++)
    {
        if (strcmp(DSSV[i].maSV, maSV) == 0)
        {
            return i;
        }
    }
    return -1;
}

void chenHocSinhVaoDanhSach(vector<SinhVien>& DSSV)
{
    SinhVien SV;
    cout << "Nhap thong tin hoc sinh can chen:" << endl;
    SV.nhap();

    DSSV.push_back(SV);
    cout << "Chen hoc sinh vao danh sach thanh cong." << endl;
}

void xoaHocSinhTheoMaSV(vector<SinhVien>& DSSV, char* maSV)
{
    int index = timKiemHocSinhTheoMaSV(DSSV, maSV);
    if (index != -1)
    {
        DSSV.erase(DSSV.begin() + index);
        cout << "Xoa hoc sinh khoi danh sach thanh cong." << endl;
    }
    else
    {
        cout << "Khong tim thay hoc sinh co maSV nay trong danh sach." << endl;
    }
}

bool soSanhMaSVGiamDan(const SinhVien& a, const SinhVien& b)
{
    return strcmp(a.maSV,

