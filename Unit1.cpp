//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <jpeg.hpp>
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CLOSEClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GAMESTARTClick(TObject *Sender)
{
  Form2->Show();
  Form1->Hide();
  Form2->Panel1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
  ShowMessage
  ("遊戲說明:\n本遊戲由40個關卡組成,每個關卡共有10題,\n請依照題目給的英文單字選出中文意思,每題限時15秒,\n裡面的單字皆為多益常考單字,共有約200個，祝遊玩愉快!");
}
//---------------------------------------------------------------------------

