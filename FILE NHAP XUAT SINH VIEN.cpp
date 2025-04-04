#include <iostream>
#include <string>
#define so_mon 3 
using namespace std ;
struct sinhvien {
	string mssv ;
	string hoten ;
	string quequan;
	double diem[so_mon];
};
struct dssinhvien{
	sinhvien *a ;
	int n ; 
};
void nhap1sv (sinhvien &sv){
	cout<<" Moi ban nhap ma ssv : ";
	getline (cin,sv.mssv);
	cout<<" Moi ban nhap ho va ten :";
	getline (cin,sv.hoten);
	cout<<" Moi ban nhap que quan :";
	getline (cin,sv.quequan);
	for (int i = 0 ; i<so_mon ; i++){
		cout<<" diem mon thu "<<i<<" = ";
		cin>>sv.diem[i];
	}
}
void xuat1sv (const sinhvien sv){
	cout<<" Ma so sinh vien = "<<sv.mssv<<endl;
	cout<<" Ho ten : "<<sv.hoten<<endl;
	cout<<" que quan : "<<sv.quequan<<endl;
	for (int i = 0 ; i<so_mon ; i++){
		cout<<sv.diem[i]<<"\t";
	}
	cout<<endl;
}
void nhapdanhsachsv(dssinhvien &ds){
	cout<<" so luong n = ";
	cin>>ds.n;
	ds.a= new sinhvien[ds.n];
	for (int i = 0 ; i<ds.n ; i++){
		cout<<" nhap sinh vien thu "<<i<<endl;
		nhap1sv(ds.a[i]);
	}
}
int main (){
	sinhvien s ;
	nhap1sv(s);
	xuat1sv(s);
}
