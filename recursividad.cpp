//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "recursividad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
Cardinal factorial(Cardinal x){
   if (x==0) {
	 return 1;
   }else return factorial(x-1)*x;
}
Cardinal exponente(int b,int exp){
   if (exp==0) {
	   return 1;
   }else return exponente(b,exp-1)*b;
}
Byte digMyr(Cardinal x){
   if (x<10) {
	  return x;
   }else{
	  byte d =digMyr(x/10);
	  if (d>(x%10)) {
		  return d;
	  }else return (x%10);
   }
}
Byte digMnr(Cardinal x){
	if (x<10) {
	  return x;
	}else{
	  byte d= digMnr(x/10);
	  if (d<(x%10)) {
		return d;
	  }else return x%10;
	}
}
Byte sumNum(Byte n){
   if (n==0) {
	   return 0;
   }else return sumNum(n-1)+n;
}
byte countDig(Cardinal x){
   if (x<10) {
	  return 1;
   }else return 1 + countDig(x/10);
}
Byte getDig(Cardinal x,byte pos){
   byte d = countDig(x);
   if (pos==d) {
	  return x%10;
   }else return getDig(x/10,pos);
}
void __fastcall TForm3::racursionnumeros2Click(TObject *Sender)
{
   Cardinal n;
   n = StrToInt(Edit1->Text);
   Edit2->Text = factorial(n);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::digmenor2Click(TObject *Sender)
{
	int n =StrToInt(Edit1->Text);
	Edit2->Text =sumNum(n);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::obtenerdigito1Click(TObject *Sender)
{
	int n =StrToInt(Edit1->Text);
	int p =StrToInt(Edit2->Text);
	Edit2->Text =getDig(n,p);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::exponente2Click(TObject *Sender)
{
	int n =StrToInt(Edit1->Text);
	Edit2->Text =digMyr(n);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::digmenor1Click(TObject *Sender)
{
    int n =StrToInt(Edit1->Text);
    Edit2->Text =digMnr(n);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::exponente1Click(TObject *Sender)
{
	int n =StrToInt(Edit1->Text);
	int exp =StrToInt(Edit2->Text);
	Edit2->Text =exponente(n,exp);
}
//---------------------------------------------------------------------------
