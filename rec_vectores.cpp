//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "rec_vectores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
int sumElements(TStringGrid *v,int n){
	if (n==0) {
	  return 0;
	}else
	  return StrToInt(v->Cells[n-1][0])+sumElements(v,n-1);
}
int getElementMyr(TStringGrid *v,int n){
	if (n==0) {
	  return 0;
	}else
	if(n==1) {
	  return StrToInt(v->Cells[0][0]);
	}else{
	  int d=getElementMyr(v,n-1);
	  if (StrToInt(v->Cells[n-1][0])>d) {
		  return StrToInt(v->Cells[n-1][0]);
	  }else return d;
	}
}
int getElementMnr(TStringGrid *v,int n){
	 if (n==0)
	   return 0;
	 else
	 if (n==1)
	   return StrToInt(v->Cells[0][0]);
	 else{
	   int d=getElementMnr(v,n-1);
	   if (StrToInt(v->Cells[n-1][0])<d)
		  return StrToInt(v->Cells[n-1][0]);
	   else return d;
	 }
}
int sumElementsPar(TStringGrid *v,int n){
	 if (n>0) {
	   if (n==1) {
		  if ((StrToInt(v->Cells[0][0])%2)==0) {
			return StrToInt(v->Cells[0][0]);
		  }else return 0;
	   }else{
		 if ((StrToInt(v->Cells[n-1][0])%2)==0) {
		   return StrToInt(v->Cells[n-1][0])+sumElementsPar(v,n-1);
		 }else return sumElementsPar(v,n-1);
	   }
	 }else return 0;
}
void cargar(TStringGrid *v,int n){
	if (n==0){
	 v->ColCount =0;
	}else{
	   cargar(v,n-1);
	   v->Cells[n-1][0] =Random(20);
	   v->ColCount =n		;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sumaelementospar1Click(TObject *Sender)
{
	int n =sgrid->ColCount;
	Edit1->Text= sumElementsPar(sgrid,n);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sbarChange(TObject *Sender)
{
	sgrid->ColCount =sbar->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::recursionvectores2Click(TObject *Sender)
{
	 int n=sgrid->ColCount;
	 cargar(sgrid,n);
}
void cargar(TStringGrid *v,int n){
	  if (n>0) {
		cargar(v,n-1);
        v->Cells[n-1][0] = Random(20);
	  }
}
void invertir(TStringGrid *v,int a,int b){
   if (a<b) {
	 int aux =StrToInt(v->Cells[a][0]);
	 v->Cells[a][0] = StrToInt(v->Cells[b][0]);
	 v->Cells[b][0] = aux;
	 invertir(v,a+1,b-1);
   }
}
void intercambiar(TStringGrid *v,int i,int j){
	 int aux =StrToInt(v->Cells[i][0]);
	 v->Cells[i][0] =StrToInt(v->Cells[j][0]);
	 v->Cells[j][0] =aux;
}
void burbujear(TStringGrid *v,int n){
   if (n>1) {
	 burbujear(v,n-1);
	 if (StrToInt(v->Cells[n-2][0])>StrToInt(v->Cells[n-1][0])) {
		int aux=StrToInt(v->Cells[n-2][0]);
		v->Cells[n-2][0] =StrToInt(v->Cells[n-1][0]);
		v->Cells[n-1][0] =aux;
	 }
   }
}
void bubleSort(TStringGrid *v,int n){
	 if (n>1) {
	   burbujear(v,n);
	   bubleSort(v,n-1);
	 }
}
//---------------------------------------------------------------------------
