//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *STAGE;
        TButton *RETURN;
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TLabel *Question;
        TLabel *QuestionC;
        TLabel *Label7;
        TLabel *ScoreBoard;
        TButton *GMAESTOP;
        TButton *RETURNtoSTAGE;
        TTimer *Timer1;
        TTimer *Timer2;
        TLabel *Label14;
        void __fastcall RETURNClick(TObject *Sender);
        void __fastcall RETURNtoSTAGEClick(TObject *Sender);
        void __fastcall GAMESTOP(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Panel1Show(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall selecting(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
