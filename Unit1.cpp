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
  ("�C������:\n���C����40�����d�զ�,�C�����d�@��10�D,\n�Ш̷��D�ص����^���r��X����N��,�C�D����15��,\n�̭�����r�Ҭ��h�q�`�ҳ�r,�@����200�ӡA���C���r��!");
}
//---------------------------------------------------------------------------

