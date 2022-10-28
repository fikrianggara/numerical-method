#include <iostream>
#include <math.h>
using namespace std;

//fungsi untuk mencari nilai suatu persamaan polinom, menerima input dari user berupa x yang memetakan y dan koefisien persamaan polinom	
double fungsi(double x,int koef[], int panjang){
	double nilai=0;
	cout<<"untuk x ="<<x<<endl;
	for(int i=0;i<panjang;i++){
		nilai+=koef[i]*pow(x,(panjang-1-i));
		cout<<" koefisien X^"<<panjang-1-i<<": "<<koef[i]<<endl;
	}
	cout<<"nilai: "<<nilai<<endl;
	
	return nilai;
}

//fungsi untuk mendapatkan akar dari suatu persamaan, menerima input batas atas dan bawah, toleransi, iterasi maksimal, koefisien dari fungsi polinom dan banyaknya koefisien
//fungsi ini hanya akurat jika f(a) dan f(b) berbeda tanda, jika tandanya sama, maka algoritma ini tidak bisa digunakan
double bisection(double a, double b, int iterasi, double e, int koef[], int panjang){
	int i=1;
	double FA=fungsi(a,koef,panjang);
	double FB=fungsi(b,koef, panjang);
	cout<<"FA :"<<FA<<endl;
	cout<<"FB :"<<FB<<endl;
	
	//selama pengulangan belum lebih dari batas yang sudah ditentukan, lakukan pencarian akar
	while(i<=iterasi){
		//p merupakan titik tengah dari a dan b
		double p=a+(b-a)/2;
		double FP=fungsi(p,koef,panjang);
		cout<<"p : "<<p<<endl;
		cout<<"FP : "<<FP<<endl;
		//jika f(p)=0 maka p merupakan akar dari fungsi, atau jika selisih batas atas dan bawah sudah sangat kecil, maka p ditetapkan sebagai akar dari persamaan.
		if(FP==0||((b-a)/2)<e){
			cout<<"(a-b)/2 : "<<(b-a)/2<<endl;
			cout<<"FP : "<<FP<<endl;
			cout<<p<<" merupakan akar dari persamaan"<<endl;
			return p;
			break;
		}
		i+=1;
		//jika f(a) dan f(p) memiliki tanda yang sama, maka nilai a diubah menjadi p, selain itu, nilai b yang berubah menjadi p
		if(FA*FP>0){
			a=p;
			cout<<"nilai a sekarang "<<a<<endl;
			FA=FP;
		} else{
			b=p;
			cout<<"nilai b sekarang "<<b<<endl;
		}
	}
	//jika perulangan sudah melebihi batas yang ditetapkan, maka proses pencarian akar dihentikan
	if(i>iterasi){
		cout<<"iterasi sudah lebih dari "<<iterasi<<"akar tidak ditemukan";
		return 0;
	}
}		
int main() {
  	int derajat;
	double func=0;
	cout<<"masukkan derajat polinomial: ";
	cin>>derajat;
	int koefisien[derajat+1];
	int panjang=sizeof(koefisien)/sizeof(koefisien[0]);
	
	for(int i=0; i<derajat+1;i++){
		cout<<"koefisien ke-"<<i<<": ";
		cin>>koefisien[i];
	}
	double a;
	double b;
	int iterasi;
	double e;
	cout<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	cout<<"iterasi maks: ";
	cin>>iterasi;
	cout<<"toleransi: ";
	cin>>e;
	bisection(a,b,iterasi,e,koefisien,panjang);
	
  return 0;
}
