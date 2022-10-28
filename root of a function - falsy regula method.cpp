#include<iostream>
#include<math.h>
#define f(x) 
using namespace std;
//fungsi tidak user defined, tetapi didefinisikan terlebih dahulu di header
#define fungsi(x) 1*pow(x,3)+3*pow(x,2)+3*x+1
#define F(x) -3-1*(3/x)-1/pow(x,2)

double iterative(double a, double b, double awal, int iterasi, double toleransi){
	int i=1;
	double x0=awal;
	double x1,tmp;
	double nilaifungsi;
	x1=x0;
	if(awal>=a && awal<=b){
	while(i<=iterasi){
		nilaifungsi=F(x1);
		cout<<"xi+1 : "<<x1<<endl;
		cout<<"xi : "<<nilaifungsi<<endl;
		cout<<"xi : "<<x1<<"|| F(xi) : "<<nilaifungsi<<"|| iterasi : "<<i<<endl;
		cout<<"----------------------------------------"<<endl;
		
		//fungsi berhenti apabila selisih dari nilai fungsi F(xi) dengan xi sendiri mendekati 0, dengan kata lain, gradien fungsi F(x)~0
		if(fabs(nilaifungsi-x1)<toleransi){
			cout<<x1<<" adalah akar dari persamaan dengan error "<<fabs(nilaifungsi-x1)<<endl;
			cout<<"iterasi konvergen"<<endl;
			return x1;
		}
		x1=nilaifungsi;
		i=i+1;
		
	}
	if(i>iterasi){
		cout<<"akar tidak ditemukan setelah "<<iterasi<<" iterasi"<<endl;
		return 0;
	}
	}
	else{
		cout<<"x awal tidak berada di interval ["<<a<<","<<b<<"]"<<endl;
		return 0;
	}
	
}
int main(){
	double a,b,e,awal;
	int iterasi;
	cout<<"=========================================================================================================="<<endl;
	cout<<"--------input di bawah adalah untuk menentukan range domain dan banyak iterasi pencarian akar f(x))-------"<<endl;
	cout<<"=========================================================================================================="<<endl;
	cout<<"batas bawah domain: ";
	cin>>a;
	cout<<"batas atas domain: ";
	cin>>b;
	cout<<"iterasi maks: ";
	cin>>iterasi;
	cout<<"toleransi: ";
	cin>>e;
	cout<<"x awal: ";
	cin>>awal;
	cout<<"=========================================================================================================="<<endl;
	iterative(a,b,awal,iterasi,e);
	
	
	
}
