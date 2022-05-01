//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include <jpeg.hpp>
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;                   // ����h ��Cv    //q=a ��  w=b �C
const int h=10,v=4,q=2,w=2;      // 40�����d�A�i�H�ʺA��ܫ��s�bSTAGE�W

TButton *BUTTON[v][h]; //10��4�C
int i,j,k=1;       // k�άO�Ψ���ܰʺA���s�W���Ʀr��(���d��)

TLabel *select[q][w];  // 2��2      �ʺA��ܧ@���ﶵ4�ӦbGroupBox1�W
int a,b;
int countdown=3,timelimit=12;
// ���d�}�l�e�|���T���ǳƮɶ��A�Q�D�C�D���@���ɶ��O12��
int PGT=1;


struct English1             //�ε��c�N�^��M���媺�C�ӳ�r��W��}
{
  int enggon;
  String English;
};
English1 KIGON[197];

struct Chinese1
{
  int chigon;
  String Chinese;
};
Chinese1 CHIGON[197];

int RANDOM=random(197);
int RRANDOM=random(197);
int original_RANDOM=random(197);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RETURNClick(TObject *Sender)
{                        //�^�C���}�l����(�qForm2�^��Form1)
  Form1->Show();         //���U���P�ɷ|�R���ʺA���s
  Form2->Hide();
  for (i=0;i<h;i++)
  {
    for (j=0;j<v;j++)
    {
      delete BUTTON[j][i];
    }
  }

  for (a=0;a<w;a++)     //�R���bForm2��GroupBox1�W���ʺALabel�A�^��C���}�l����
  {
    for (b=0;b<q;b++)
    {
      delete select[b][a];
    }
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::RETURNtoSTAGEClick(TObject *Sender)
{                              //�^�W�@�h
  Panel1->Hide();              //�^�������d����
  for (i=0;i<h;i++)        //�����ê����s�q�X��
  {                            
    for (j=0;j<v;j++)
    {
      BUTTON[j][i]->Show();
    }
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::GAMESTOP(TObject *Sender)
{                        //�C���Ȱ�
  Timer2->Enabled=!Timer2->Enabled;
  GroupBox1->Enabled=!GroupBox1->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
  for (int i=0;i<197;i++)
  {                                  // ��W��}
    KIGON[i].enggon=i;
    CHIGON[i].chigon=i;
  }

   //�^���r��

  KIGON[0].English="aware";KIGON[1].English="aboard";KIGON[2].English="absolutely";
  KIGON[3].English="accident";KIGON[4].English="accomplishment";KIGON[5].English="account";
  KIGON[6].English="accurate";KIGON[7].English="achieve";KIGON[8].English="acre";
  KIGON[9].English="action";KIGON[10].English="activity";KIGON[11].English="adapt";
  KIGON[12].English="additional";KIGON[13].English="admission";
  KIGON[14].English="adopt";KIGON[15].English="advance";KIGON[16].English="advancement";
  KIGON[17].English="adventure";KIGON[18].English="advertising";KIGON[19].English="advise";
  KIGON[20].English="affiliate";KIGON[21].English="affordable";KIGON[22].English="agent";
  KIGON[23].English="aggressive";KIGON[24].English="agriculture";KIGON[25].English="aid";
  KIGON[26].English="airline";KIGON[27].English="alarming";KIGON[28].English="alien";
  KIGON[29].English="aluminum";KIGON[30].English="amateur";KIGON[31].English="amaze";
  KIGON[32].English="ambitious";KIGON[33].English="amount";KIGON[34].English="amusement";
  KIGON[35].English="analyze";KIGON[36].English="ancestor";KIGON[37].English="ancient";
  KIGON[38].English="announcement";KIGON[39].English="annoy";KIGON[40].English="anxiously";
  KIGON[41].English="apparent";KIGON[42].English="appeal";KIGON[43].English="appearance";
  KIGON[44].English="apply";KIGON[45].English="appropriate";KIGON[46].English="approval";
  KIGON[47].English="area";KIGON[48].English="arguably";KIGON[49].English="armed";
  KIGON[50].English="arouse";KIGON[51].English="arrest";KIGON[52].English="article";
  KIGON[53].English="ash";KIGON[54].English="aspect";KIGON[55].English="assemble";
  KIGON[56].English="assembly";KIGON[57].English="assist";KIGON[58].English="associate";
  KIGON[59].English="atmosphere";KIGON[60].English="attempt";KIGON[61].English="attend";
  KIGON[62].English="attitude";KIGON[63].English="attract";KIGON[64].English="author";
  KIGON[65].English="authority";KIGON[66].English="automatic";KIGON[67].English="available";
  KIGON[68].English="average";KIGON[69].English="broadcast";KIGON[70].English="ballet";
  KIGON[71].English="banana split";KIGON[72].English="barely";KIGON[73].English="barrel";
  KIGON[74].English="barrier";KIGON[75].English="basis";KIGON[76].English="battery";
  KIGON[77].English="bay";KIGON[78].English="beast";KIGON[79].English="belly";
  KIGON[80].English="berry";KIGON[81].English="bidding";KIGON[82].English="billion";
  KIGON[83].English="biography";KIGON[84].English="biscuit";KIGON[85].English="bloom";
  KIGON[86].English="blossom";KIGON[87].English="border";KIGON[88].English="branch";
  KIGON[89].English="break out";KIGON[90].English="brilliant";KIGON[91].English="brutal";
  KIGON[92].English="buffet";KIGON[93].English="bulb";KIGON[94].English="bacon";
  KIGON[95].English="appointment";KIGON[96].English="attendance";KIGON[97].English="cabinet";
  KIGON[98].English="calendar";KIGON[99].English="clerk";KIGON[100].English="directory";
  KIGON[101].English="duplicate";KIGON[102].English="filing";KIGON[103].English="in-tray";
 KIGON[104].English="monitor";KIGON[105].English="out-tray";KIGON[106].English="partition";
 KIGON[107].English="postage";KIGON[108].English="punctuality";KIGON[109].English="schedule";
 KIGON[110].English="shift";KIGON[111].English="staff";KIGON[112].English="strike";
 KIGON[113].English="task";KIGON[114].English="work force";KIGON[115].English="assignment";
 KIGON[116].English="bulletin";KIGON[117].English="calculator";KIGON[118].English="carbon copy";
 KIGON[119].English="colleague";KIGON[120].English="document";KIGON[121].English="extension";
 KIGON[122].English="intercom";KIGON[123].English="memo";KIGON[124].English="operator";
 KIGON[125].English="overtime";KIGON[126].English="portfolio";KIGON[127].English="printed matter";
 KIGON[128].English="receptionist";KIGON[129].English="secretary";KIGON[130].English="shorthand";
 KIGON[131].English="stapler";KIGON[132].English="tardy";KIGON[133].English="typist";
 KIGON[134].English="xerox";KIGON[135].English="allocate";KIGON[136].English="applicant";
 KIGON[137].English="authorize";KIGON[138].English="capability";KIGON[139].English="lay off";
 KIGON[140].English="collaboration";KIGON[141].English="consultation";KIGON[142].English="curriculum vitae";
 KIGON[143].English="eligible";KIGON[144].English="emplyer";KIGON[145].English="executive";
 KIGON[146].English="appoint";KIGON[147].English="benefit";KIGON[148].English="candidate";
 KIGON[149].English="certificate";KIGON[150].English="competent";KIGON[151].English="coordinate";
 KIGON[152].English="deadline";KIGON[153].English="employee";KIGON[154].English="expertise";
 KIGON[155].English="subsidy";KIGON[156].English="income";KIGON[157].English="evaluation";
 KIGON[158].English="occupation";KIGON[159].English="part-time";KIGON[160].English="permanent";
 KIGON[161].English="promote";KIGON[162].English="recruit";KIGON[163].English="resume";
 KIGON[164].English="salary";KIGON[165].English="annuity";KIGON[166].English="penalty";
 KIGON[167].English="deposit";KIGON[168].English="overtime";KIGON[169].English="pension";
 KIGON[170].English="rent";KIGON[171].English="recommendation";KIGON[172].English="resign";
 KIGON[173].English="retire";KIGON[174].English="remuneration";KIGON[175].English="accrue";
 KIGON[176].English="acquisition";KIGON[177].English="amplify";KIGON[178].English="asset";
 KIGON[179].English="buyout/buy out";KIGON[180].English="corporation";KIGON[181].English="cutback";
 KIGON[182].English="enterprise";KIGON[183].English="equity";KIGON[184].English="financier";
 KIGON[185].English="integrate";KIGON[186].English="merger";KIGON[187].English="pending";
 KIGON[188].English="preliminary";KIGON[189].English="propose";KIGON[190].English="prospect";
 KIGON[191].English="prosperity";KIGON[192].English="scheme";KIGON[193].English="thrive";
 KIGON[194].English="undervalue";



 // �����r��
 CHIGON[0].Chinese="��ı";CHIGON[1].Chinese="��W";CHIGON[2].Chinese="����a";
 CHIGON[3].Chinese="�ƬG";CHIGON[4].Chinese="���N";CHIGON[5].Chinese="�{�w";
 CHIGON[6].Chinese="�ǽT";CHIGON[7].Chinese="�F��";CHIGON[8].Chinese="�^�a";
 CHIGON[9].Chinese="���";CHIGON[10].Chinese="����";CHIGON[11].Chinese="�A��";
 CHIGON[12].Chinese="�t�~";CHIGON[13].Chinese="�ӻ{";CHIGON[14].Chinese="�ĥ�";
 CHIGON[15].Chinese="�e�i";CHIGON[16].Chinese="�i�B";CHIGON[17].Chinese="�_�I";
 CHIGON[18].Chinese="�s�i";CHIGON[19].Chinese="���i";CHIGON[20].Chinese="�[�W";
 CHIGON[21].Chinese="��f��";CHIGON[22].Chinese="�g���H";CHIGON[23].Chinese="�n����";
 CHIGON[24].Chinese="�A�~";CHIGON[25].Chinese="����";CHIGON[26].Chinese="���";
 CHIGON[27].Chinese="��H��";CHIGON[28].Chinese="�~��";CHIGON[29].Chinese="�T";
 CHIGON[30].Chinese="�~�l";CHIGON[31].Chinese="��_";CHIGON[32].Chinese="���߫k�k��";
 CHIGON[33].Chinese="���q";CHIGON[34].Chinese="�T��";
 CHIGON[35].Chinese="���R";
 CHIGON[36].Chinese="����";
 CHIGON[37].Chinese="�j�Ѫ�";
 CHIGON[38].Chinese="���i";
 CHIGON[39].Chinese="�S�o";
 CHIGON[40].Chinese="�J��a";
 CHIGON[41].Chinese="���㪺";
 CHIGON[42].Chinese="�ӶD";
 CHIGON[43].Chinese="�e��";
 CHIGON[44].Chinese="�ӽ�";
 CHIGON[45].Chinese="�X�A��";
 CHIGON[46].Chinese="�٦P";
 CHIGON[47].Chinese="�ϰ�";
 CHIGON[48].Chinese="���z��";
 CHIGON[49].Chinese="�Z�˪�";
 CHIGON[50].Chinese="�E�o";
 CHIGON[51].Chinese="�e��";
 CHIGON[52].Chinese="�峹";
 CHIGON[53].Chinese="���u";
 CHIGON[54].Chinese="�譱";
 CHIGON[55].Chinese="�զX";
 CHIGON[56].Chinese="�˰t";
 CHIGON[57].Chinese="��U";
 CHIGON[58].Chinese="����";
 CHIGON[59].Chinese="��^";
 CHIGON[60].Chinese="����";
 CHIGON[61].Chinese="�X�u";
 CHIGON[62].Chinese="�A��";
 CHIGON[63].Chinese="�l��";
 CHIGON[64].Chinese="�@��";
 CHIGON[65].Chinese="�v��";
 CHIGON[66].Chinese="�۰ʪ�";
 CHIGON[67].Chinese="�i�o��";
 CHIGON[68].Chinese="����";
 CHIGON[69].Chinese="����";
 CHIGON[70].Chinese="����";
 CHIGON[71].Chinese="������";
 CHIGON[72].Chinese="�ȶ�";
 CHIGON[73].Chinese="��l";
 CHIGON[74].Chinese="��ê";
 CHIGON[75].Chinese="��¦";
 CHIGON[76].Chinese="�q��";
 CHIGON[77].Chinese="���W";
 CHIGON[78].Chinese="���~";
 CHIGON[79].Chinese="�{�l";
 CHIGON[80].Chinese="�G��";
 CHIGON[81].Chinese="���";
 CHIGON[82].Chinese="�Q��";
 CHIGON[83].Chinese="�ǰO";
 CHIGON[84].Chinese="�氮";
 CHIGON[85].Chinese="�}��";
 CHIGON[86].Chinese="�ᦷ";
 CHIGON[87].Chinese="���";
 CHIGON[88].Chinese="����";
 CHIGON[89].Chinese="�z�o";
 CHIGON[90].Chinese="�ǥX���B���ꪺ";
 CHIGON[91].Chinese="�ݻŪ�";
 CHIGON[92].Chinese="�ۧU�\";
 CHIGON[93].Chinese="�O�w";
 CHIGON[94].Chinese="�t��";
 CHIGON[95].Chinese="���|�B���w";
 CHIGON[96].Chinese="�X�u�H�ơB�X�u";
 CHIGON[97].Chinese="�o�d";
 CHIGON[98].Chinese="���B���B��ƾ�";
 CHIGON[99].Chinese="��ƭ��B�ѰO";
 CHIGON[100].Chinese="�H�W��}ï";
 CHIGON[101].Chinese="�ƻs�B�ƥ�";
 CHIGON[102].Chinese="�k��";
 CHIGON[103].Chinese="�ݳB�z���";
 CHIGON[104].Chinese="�˴��B�ʵ��B�l��";
 CHIGON[105].Chinese="�w�B�z���";
 CHIGON[106].Chinese="���j�F���j���]�p������^";
 CHIGON[107].Chinese="�l�O";
 CHIGON[108].Chinese="�ǮɡB�u��";
 CHIGON[109].Chinese="�ɶ���F�p�e��";
 CHIGON[110].Chinese="���Z�F���Z�F�ȯZ";
 CHIGON[111].Chinese="����¾��";
 CHIGON[112].Chinese="�}�u";
 CHIGON[113].Chinese="�u�@�B����";
 CHIGON[114].Chinese="�u�@�H���F�ҰʤH�f";
 CHIGON[115].Chinese="���t�F�u�@�A����";
 CHIGON[116].Chinese="�����F�i��";
 CHIGON[117].Chinese="�p�⾹";
 CHIGON[118].Chinese="�νƼg�Ƚƻs���ƥ�";
 CHIGON[119].Chinese="�P�ơA�P��";
 CHIGON[120].Chinese="���A�ҥ�";
 CHIGON[121].Chinese="�����]�q�ܡ^�F����";
 CHIGON[122].Chinese="������";
 CHIGON[123].Chinese="�K���F�K��F�Ƨѿ�";
 CHIGON[124].Chinese="���u��";
 CHIGON[125].Chinese="�[�Z���ɶ�";
 CHIGON[126].Chinese="�@�~���A���ƥ]";
 CHIGON[127].Chinese="�L��~";
 CHIGON[128].Chinese="���ݭ�";
 CHIGON[129].Chinese="����";
 CHIGON[130].Chinese="�t�O�A�t�O�k";
 CHIGON[131].Chinese="�v�Ѿ�";
 CHIGON[132].Chinese="��w�F��쪺�F�𩵪�";
 CHIGON[133].Chinese="���r��";
 CHIGON[134].Chinese="�v�L";
 CHIGON[135].Chinese="���X�F���t�F�t�m";
 CHIGON[136].Chinese="�ӽФH";
 CHIGON[137].Chinese="���v�F�e�U";
 CHIGON[138].Chinese="��O�F�~�F�F��O�F�ʯ�";
 CHIGON[139].Chinese="�]�Ȯɡ^�Ѷ�";
 CHIGON[140].Chinese="�X�@�F�q��";
 CHIGON[141].Chinese="�ԸߡF�Ӷq�F��ĳ�F�|ĳ";
 CHIGON[142].Chinese="�i��";
 CHIGON[143].Chinese="�X�檺�A�X�A��";
 CHIGON[144].Chinese="���D";
 CHIGON[145].Chinese="��F�κ޲z�H��";
 CHIGON[146].Chinese="���R�F���w";
 CHIGON[147].Chinese="���q��F���q";
 CHIGON[148].Chinese="�Կ�H";
 CHIGON[149].Chinese="���ҡF�Ү�";
 CHIGON[150].Chinese="����O���A�ӥ���";
 CHIGON[151].Chinese="��աF�վ�";
 CHIGON[152].Chinese="�I�ܴ���";
 CHIGON[153].Chinese="������";
 CHIGON[154].Chinese="�M���޳N�Ϊ���";
 CHIGON[155].Chinese="�ɧU��";
 CHIGON[156].Chinese="���J�Ωұo";
 CHIGON[157].Chinese="�����F����";
 CHIGON[158].Chinese="¾�~";
 CHIGON[159].Chinese="�ݥ����F��¾��";
 CHIGON[160].Chinese="���ܪ��A�ä[��";
 CHIGON[161].Chinese="�ɾE�F�P�P";
 CHIGON[162].Chinese="�l���F�x��";
 CHIGON[163].Chinese="�i����";
 CHIGON[164].Chinese="�~��";
 CHIGON[165].Chinese="�~��";
 CHIGON[166].Chinese="�@��";
 CHIGON[167].Chinese="���";
 CHIGON[168].Chinese="�W��";
 CHIGON[169].Chinese="�i�Ѫ��F�h���";
 CHIGON[170].Chinese="����";
 CHIGON[171].Chinese="���ˡF���ˮѡF�U�i";
 CHIGON[172].Chinese="��¾";
 CHIGON[173].Chinese="�h��";
 CHIGON[174].Chinese="���S�F�S��";
 CHIGON[175].Chinese="���͡F�W�[";
 CHIGON[176].Chinese="��o�F�߱o";
 CHIGON[177].Chinese="��j�F�[�j�F�X�i";
 CHIGON[178].Chinese="���Ϊ��F��F�u�I�F���B";
 CHIGON[179].Chinese="�R�i�������v�Ϊ��v�F���ʥ���";
 CHIGON[180].Chinese="�k�H�F���q";
 CHIGON[181].Chinese="��֡F����";
 CHIGON[182].Chinese="���~";
 CHIGON[183].Chinese="�����F����";
 CHIGON[184].Chinese="�]�F�a�F���ķ~�̡F�ꥻ�a�F����";
 CHIGON[185].Chinese="�ΦX�F��X";
 CHIGON[186].Chinese="�X�֡F�֧]";
 CHIGON[187].Chinese="���M�w���F�ݨM�w���F�Y�N�o��";
 CHIGON[188].Chinese="��B���A�}�l��";
 CHIGON[189].Chinese="��ĳ�F��ĳ";
 CHIGON[190].Chinese="����ιw�����ơF�i��F����";
 CHIGON[191].Chinese="�c�a�F���\�F����";
 CHIGON[192].Chinese="�p�e�F�]�p�F�Ͽ�";
 CHIGON[193].Chinese="�Z���F�����F�c�a";
 CHIGON[194].Chinese="�C�����ȡF�ݻ�";










  Panel1->Hide();       //�i�J������d����

  for (i=0;i<v;i++)
  {
    for (j=0;j<h;j++)
    {
      BUTTON[i][j]=new TButton(Form2);
      BUTTON[i][j]->Parent=STAGE;
      BUTTON[i][j]->Width=65;
      BUTTON[i][j]->Height=41;
      BUTTON[i][j]->Left=48+(j*96);
      BUTTON[i][j]->Top=96+(i*96);
      BUTTON[i][j]->Caption=k;      //���s�W������d��
      k++;
      BUTTON[i][j]->OnClick=Panel1Show;   //���ʺA���s���U��P��Panel�X�{
    }
  }


    for (a=0;a<q;a++)      // 4�ӿﶵ
    {
      for (b=0;b<w;b++)
      {
        select[a][b]=new TLabel(Form2);     //  clRed
        select[a][b]->Parent=GroupBox1;
        select[a][b]->Width=129;            //����ﶵ(0x00E19DC2)  ���T
        select[a][b]->Height=73;            //�Ŧ�ﶵ(0x00FF8080)  �����
        select[a][b]->Left=48+(b*184);
        select[a][b]->Top=176+(a*184);                  //��TIMER�MSWITCH
        select[a][b]->Color=(TColor)(0x00FF8080);
        select[a][b]->OnClick=selecting;
      }                     //  �Ŧ�O�@�}�l�ﶵ���C��A��諸�����Ŧ�N�ܵ���
    }
   Timer1->Enabled=false;



}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel1Show(TObject *Sender)
{
  Panel1->Show();              // ���U�ʺA���s�i�H��Panel�q�X��
  GroupBox1->Enabled=false;

  for (i=0;i<h;i++)            // �]���ʺA����|���|�A�ҥHPanel�@�q�X�ӡA
  {                            // �N���ðʺA���s�C
    for (j=0;j<v;j++)
    {
      BUTTON[j][i]->Hide();
    }
  }
  GroupBox1->Caption="Stage ";
  Timer1->Enabled=true;

  randomize();
  select[random(2)][random(2)]->Tag=10000;

    RANDOM=random(197);
   QuestionC->Caption=CHIGON[RANDOM].Chinese;    // �D����� �]�N�O�X�D�ذ�
   QuestionC->Tag=CHIGON[RANDOM].chigon;


   for (a=0;a<q;a++)      // 4�ӿﶵ���
   {
     for (b=0;b<w;b++)
     {
       if (select[a][b]->Tag==10000)
       {
         select[a][b]->Caption=KIGON[RANDOM].English;
         select[a][b]->Tag=KIGON[RANDOM].enggon;
       }
       else
       {
          RRANDOM=random(197);
         select[a][b]->Tag=KIGON[RRANDOM].enggon;
         select[a][b]->Caption=KIGON[RRANDOM].English;
       }
     }
   }


}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{  /* �Ĥ@��Timer�A�Ψӱq���s�I�i�h���d�ɡA     Timer1�@�}�l���Q����
      ���@�i�h�i�H���Ȱ���3��(�˼ƤT��)�A�A�}�l�@���C*/

  Label7->Caption="�˼�"+AnsiString(countdown--)+"��";

  if (countdown==-1)   //���F�i�H����a�˼Ƨ�3��
  {
    Timer1->Enabled=false;
    Sleep(100);
    Label7->Caption="�}�l���!!";
  }                                        
  else if (countdown<=-1)                   
  {
    countdown=4;
    Label7->Caption="�˼�"+AnsiString(countdown--)+"��";
    Sleep(100);
    Label7->Caption="�}�l���!!";
  }

  if (Label7->Caption=="�}�l���!!")        //�@�}�lGroupBox1�bPanelShow�����A
  {                                         //�����(�}�l���!!)�ɦA�}�ҡC
    GroupBox1->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer2Timer(TObject *Sender)
{  // �ĤG��Timer�A�Ψ������d�̤Q�D�C�D����q12��}�l�˼�

    if (Label7->Caption=="�}�l���!!")  // Timer1����B�@���ɭԡATimer2�}�l�˼Ƥu�@�C
    {
      Timer2->Enabled=true;
      Label14->Caption=AnsiString(timelimit--);
    }

   switch(timelimit)
   {                                  //���ͤU�@�D���s���
     case -1 :
      Sleep(400);
      timelimit=12;
      Label14->Caption=AnsiString(timelimit--);
      select[random(2)][random(2)]->Tag=10000;      //�N�D�ع�W�ﶵ
      RANDOM=random(197);
      QuestionC->Caption=CHIGON[RANDOM].Chinese;    // �ɶ���F���s�D��
      QuestionC->Tag=CHIGON[RANDOM].chigon;

      for (a=0;a<q;a++)      // 4�ӿﶵ���        //�]���W�s�ﶵ
      {
        for (b=0;b<w;b++)
        {
          if (select[a][b]->Tag==10000)
          {
            select[a][b]->Caption=KIGON[RANDOM].English;
            select[a][b]->Tag=KIGON[RANDOM].enggon;
          }
          else
          {
            RRANDOM=random(197);
            select[a][b]->Tag=KIGON[RRANDOM].enggon;
            select[a][b]->Caption=KIGON[RRANDOM].English;
          }
        }
      }
   }



   /*
    if (timelimit<=-1)    //���ͤU�@�D
    {
      Sleep(400);
      timelimit=12;
      Label14->Caption=AnsiString(timelimit--);
    }
      */
   // if (timelimit)


}
//---------------------------------------------------------------------------
void __fastcall TForm2::selecting(TObject *Sender)
{
  TLabel *dasabi=(TLabel *)Sender;     //���U�|��Label��|�o�ͪ���
  if (dasabi->Tag==QuestionC->Tag)      // �P�_����
  {
      dasabi->Color=(TColor)(0x00E19DC2);  //�����A�諸�ﶵ�ܦ�����
      Panel1->Refresh();
      Sleep(450);
      {
        ScoreBoard->Caption=ScoreBoard->Caption+"\n"+"��"+AnsiString(PGT++)+"�D:  "
       +"����O~�A"+"\n"+"���T���ץ��O"+KIGON[QuestionC->Tag].English+" !";

        timelimit=12;
        select[random(2)][random(2)]->Tag=10000;      //�N�D�ع�W�ﶵ

        original_RANDOM=random(197);
        QuestionC->Caption=CHIGON[original_RANDOM].Chinese;    // ����F�N���s�D��
        QuestionC->Tag=CHIGON[original_RANDOM].chigon;

        for (a=0;a<q;a++)      // 4�ӿﶵ���        //�]���W�s�ﶵ
        {
          for (b=0;b<w;b++)
          {
            select[a][b]->Color=(TColor)(0x00FF8080);  //���s�D��ﶵ�ܦ^�Ŧ�

            if (select[a][b]->Tag==10000)
            {
              select[a][b]->Caption=KIGON[original_RANDOM].English;
              select[a][b]->Tag=KIGON[original_RANDOM].enggon;
            }
            else
            {
              RRANDOM=random(197);
              select[a][b]->Tag=KIGON[RRANDOM].enggon;
              select[a][b]->Caption=KIGON[RRANDOM].English;
            }
          }
         }
        }

  }
  else     //����
  {
    dasabi->Color=(TColor)(clRed);           //������ﶵ�ܦ�����
    Panel1->Refresh();
    Sleep(450);
    {
      ScoreBoard->Caption=ScoreBoard->Caption+"\n"+"��"+AnsiString(PGT++)+"�D:  "
       +"����X!�A"+"\n"+"���T�������O"+KIGON[QuestionC->Tag].English+" !";
      timelimit=12;
      select[random(2)][random(2)]->Tag=10000;      //�N�D�ع�W�ﶵ
       RANDOM=random(197);
      QuestionC->Caption=CHIGON[RANDOM].Chinese;    // �����N���s�D��
      QuestionC->Tag=CHIGON[RANDOM].chigon;

      for (a=0;a<q;a++)      // 4�ӿﶵ���        //�]���W�s�ﶵ
      {
        for (b=0;b<w;b++)
        {

         select[a][b]->Color=(TColor)(0x00FF8080);

          if (select[a][b]->Tag==10000)
          {
            select[a][b]->Caption=KIGON[RANDOM].English;
            select[a][b]->Tag=KIGON[RANDOM].enggon;
          }
          else
          {
            int RRANDOM=random(197);
            select[a][b]->Tag=KIGON[RRANDOM].enggon;
            select[a][b]->Caption=KIGON[RRANDOM].English;
          }
        }
      }
    
    }
  }
}
//---------------------------------------------------------------------------







