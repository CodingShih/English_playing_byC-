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
TForm2 *Form2;                   // 直行h 橫列v    //q=a 行  w=b 列
const int h=10,v=4,q=2,w=2;      // 40個關卡，可以動態顯示按鈕在STAGE上

TButton *BUTTON[v][h]; //10行4列
int i,j,k=1;       // k用是用來顯示動態按鈕上的數字的(關卡數)

TLabel *select[q][w];  // 2乘2      動態顯示作答選項4個在GroupBox1上
int a,b;
int countdown=3,timelimit=12;
// 關卡開始前會有三秒的準備時間，十題每題的作答時間是12秒
int PGT=1;


struct English1             //用結構將英文和中文的每個單字對上位址
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
{                        //回遊戲開始介面(從Form2回到Form1)
  Form1->Show();         //按下的同時會刪除動態按鈕
  Form2->Hide();
  for (i=0;i<h;i++)
  {
    for (j=0;j<v;j++)
    {
      delete BUTTON[j][i];
    }
  }

  for (a=0;a<w;a++)     //刪除在Form2的GroupBox1上的動態Label，回到遊戲開始介面
  {
    for (b=0;b<q;b++)
    {
      delete select[b][a];
    }
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::RETURNtoSTAGEClick(TObject *Sender)
{                              //回上一層
  Panel1->Hide();              //回到選擇關卡介面
  for (i=0;i<h;i++)        //讓隱藏的按鈕秀出來
  {                            
    for (j=0;j<v;j++)
    {
      BUTTON[j][i]->Show();
    }
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::GAMESTOP(TObject *Sender)
{                        //遊戲暫停
  Timer2->Enabled=!Timer2->Enabled;
  GroupBox1->Enabled=!GroupBox1->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
  for (int i=0;i<197;i++)
  {                                  // 對上位址
    KIGON[i].enggon=i;
    CHIGON[i].chigon=i;
  }

   //英文單字區

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



 // 中文單字區
 CHIGON[0].Chinese="察覺";CHIGON[1].Chinese="船上";CHIGON[2].Chinese="絕對地";
 CHIGON[3].Chinese="事故";CHIGON[4].Chinese="成就";CHIGON[5].Chinese="認定";
 CHIGON[6].Chinese="準確";CHIGON[7].Chinese="達到";CHIGON[8].Chinese="英畝";
 CHIGON[9].Chinese="行動";CHIGON[10].Chinese="活動";CHIGON[11].Chinese="適應";
 CHIGON[12].Chinese="另外";CHIGON[13].Chinese="承認";CHIGON[14].Chinese="採用";
 CHIGON[15].Chinese="前進";CHIGON[16].Chinese="進步";CHIGON[17].Chinese="冒險";
 CHIGON[18].Chinese="廣告";CHIGON[19].Chinese="忠告";CHIGON[20].Chinese="加上";
 CHIGON[21].Chinese="實惠的";CHIGON[22].Chinese="經紀人";CHIGON[23].Chinese="積極的";
 CHIGON[24].Chinese="農業";CHIGON[25].Chinese="幫忙";CHIGON[26].Chinese="航空";
 CHIGON[27].Chinese="驚人的";CHIGON[28].Chinese="外僑";CHIGON[29].Chinese="鋁";
 CHIGON[30].Chinese="業餘";CHIGON[31].Chinese="驚奇";CHIGON[32].Chinese="野心勃勃的";
 CHIGON[33].Chinese="分量";CHIGON[34].Chinese="娛樂";
 CHIGON[35].Chinese="分析";
 CHIGON[36].Chinese="祖先";
 CHIGON[37].Chinese="古老的";
 CHIGON[38].Chinese="公告";
 CHIGON[39].Chinese="惹惱";
 CHIGON[40].Chinese="焦急地";
 CHIGON[41].Chinese="明顯的";
 CHIGON[42].Chinese="申訴";
 CHIGON[43].Chinese="容貌";
 CHIGON[44].Chinese="申請";
 CHIGON[45].Chinese="合適的";
 CHIGON[46].Chinese="贊同";
 CHIGON[47].Chinese="區域";
 CHIGON[48].Chinese="按理說";
 CHIGON[49].Chinese="武裝的";
 CHIGON[50].Chinese="激發";
 CHIGON[51].Chinese="逮捕";
 CHIGON[52].Chinese="文章";
 CHIGON[53].Chinese="灰燼";
 CHIGON[54].Chinese="方面";
 CHIGON[55].Chinese="組合";
 CHIGON[56].Chinese="裝配";
 CHIGON[57].Chinese="協助";
 CHIGON[58].Chinese="相關";
 CHIGON[59].Chinese="氣氛";
 CHIGON[60].Chinese="嘗試";
 CHIGON[61].Chinese="出席";
 CHIGON[62].Chinese="態度";
 CHIGON[63].Chinese="吸引";
 CHIGON[64].Chinese="作者";
 CHIGON[65].Chinese="權威";
 CHIGON[66].Chinese="自動的";
 CHIGON[67].Chinese="可得的";
 CHIGON[68].Chinese="平均";
 CHIGON[69].Chinese="播放";
 CHIGON[70].Chinese="芭蕾";
 CHIGON[71].Chinese="香蕉船";
 CHIGON[72].Chinese="僅僅";
 CHIGON[73].Chinese="桶子";
 CHIGON[74].Chinese="障礙";
 CHIGON[75].Chinese="基礎";
 CHIGON[76].Chinese="電池";
 CHIGON[77].Chinese="海灣";
 CHIGON[78].Chinese="野獸";
 CHIGON[79].Chinese="肚子";
 CHIGON[80].Chinese="果實";
 CHIGON[81].Chinese="投標";
 CHIGON[82].Chinese="十億";
 CHIGON[83].Chinese="傳記";
 CHIGON[84].Chinese="餅乾";
 CHIGON[85].Chinese="開花";
 CHIGON[86].Chinese="花朵";
 CHIGON[87].Chinese="邊界";
 CHIGON[88].Chinese="分支";
 CHIGON[89].Chinese="爆發";
 CHIGON[90].Chinese="傑出的、燦爛的";
 CHIGON[91].Chinese="殘酷的";
 CHIGON[92].Chinese="自助餐";
 CHIGON[93].Chinese="燈泡";
 CHIGON[94].Chinese="燻肉";
 CHIGON[95].Chinese="約會、約定";
 CHIGON[96].Chinese="出席人數、出席";
 CHIGON[97].Chinese="櫥櫃";
 CHIGON[98].Chinese="日曆、月曆、行事曆";
 CHIGON[99].Chinese="辦事員、書記";
 CHIGON[100].Chinese="人名住址簿";
 CHIGON[101].Chinese="複製、副本";
 CHIGON[102].Chinese="歸檔";
 CHIGON[103].Chinese="待處理文件盒";
 CHIGON[104].Chinese="檢測、監視、追蹤";
 CHIGON[105].Chinese="已處理文件盒";
 CHIGON[106].Chinese="分隔；分隔物（如牆壁等）";
 CHIGON[107].Chinese="郵費";
 CHIGON[108].Chinese="準時、守時";
 CHIGON[109].Chinese="時間表；計畫表";
 CHIGON[110].Chinese="換班；輪班；值班";
 CHIGON[111].Chinese="全體職員";
 CHIGON[112].Chinese="罷工";
 CHIGON[113].Chinese="工作、任務";
 CHIGON[114].Chinese="工作人員；勞動人口";
 CHIGON[115].Chinese="分配；工作，分派";
 CHIGON[116].Chinese="公報；告示";
 CHIGON[117].Chinese="計算器";
 CHIGON[118].Chinese="用複寫紙複製的副本";
 CHIGON[119].Chinese="同事，同僚";
 CHIGON[120].Chinese="文件，證件";
 CHIGON[121].Chinese="分機（電話）；延期";
 CHIGON[122].Chinese="對講機";
 CHIGON[123].Chinese="便條；便箋；備忘錄";
 CHIGON[124].Chinese="接線生";
 CHIGON[125].Chinese="加班的時間";
 CHIGON[126].Chinese="作品夾，公事包";
 CHIGON[127].Chinese="印刷品";
 CHIGON[128].Chinese="接待員";
 CHIGON[129].Chinese="秘書";
 CHIGON[130].Chinese="速記，速記法";
 CHIGON[131].Chinese="釘書機";
 CHIGON[132].Chinese="遲緩；遲到的；遲延的";
 CHIGON[133].Chinese="打字員";
 CHIGON[134].Chinese="影印";
 CHIGON[135].Chinese="撥出；分配；配置";
 CHIGON[136].Chinese="申請人";
 CHIGON[137].Chinese="授權；委託";
 CHIGON[138].Chinese="能力；才幹；潛力；性能";
 CHIGON[139].Chinese="（暫時）解雇";
 CHIGON[140].Chinese="合作；通敵";
 CHIGON[141].Chinese="諮詢；商量；商議；會議";
 CHIGON[142].Chinese="履歷";
 CHIGON[143].Chinese="合格的，合適的";
 CHIGON[144].Chinese="雇主";
 CHIGON[145].Chinese="行政或管理人員";
 CHIGON[146].Chinese="任命；指定";
 CHIGON[147].Chinese="有益於；受益";
 CHIGON[148].Chinese="候選人";
 CHIGON[149].Chinese="憑證；證書";
 CHIGON[150].Chinese="有能力的，勝任的";
 CHIGON[151].Chinese="協調；調整";
 CHIGON[152].Chinese="截至期限";
 CHIGON[153].Chinese="受雇者";
 CHIGON[154].Chinese="專門技術或知識";
 CHIGON[155].Chinese="補助金";
 CHIGON[156].Chinese="收入或所得";
 CHIGON[157].Chinese="評價；估價";
 CHIGON[158].Chinese="職業";
 CHIGON[159].Chinese="兼任的；兼職的";
 CHIGON[160].Chinese="不變的，永久的";
 CHIGON[161].Chinese="升遷；促銷";
 CHIGON[162].Chinese="吸收；徵募";
 CHIGON[163].Chinese="履歷表";
 CHIGON[164].Chinese="薪水";
 CHIGON[165].Chinese="年金";
 CHIGON[166].Chinese="罰金";
 CHIGON[167].Chinese="押金";
 CHIGON[168].Chinese="超時";
 CHIGON[169].Chinese="養老金；退休金";
 CHIGON[170].Chinese="租金";
 CHIGON[171].Chinese="推薦；推薦書；勸告";
 CHIGON[172].Chinese="辭職";
 CHIGON[173].Chinese="退休";
 CHIGON[174].Chinese="報酬；酬勞";
 CHIGON[175].Chinese="產生；增加";
 CHIGON[176].Chinese="獲得；習得";
 CHIGON[177].Chinese="放大；加強；擴展";
 CHIGON[178].Chinese="有用的東西；優點；長處";
 CHIGON[179].Chinese="買進全部產權或股權；收購全部";
 CHIGON[180].Chinese="法人；公司";
 CHIGON[181].Chinese="減少；取消";
 CHIGON[182].Chinese="企業";
 CHIGON[183].Chinese="公平；公正";
 CHIGON[184].Chinese="財政家；金融業者；資本家；投資者";
 CHIGON[185].Chinese="統合；整合";
 CHIGON[186].Chinese="合併；併吞";
 CHIGON[187].Chinese="未決定的；待決定的；即將發生";
 CHIGON[188].Chinese="初步的，開始的";
 CHIGON[189].Chinese="提議；建議";
 CHIGON[190].Chinese="期望或預見的事；展望；期望";
 CHIGON[191].Chinese="繁榮；成功；興隆";
 CHIGON[192].Chinese="計畫；設計；圖謀";
 CHIGON[193].Chinese="茂盛；興旺；繁榮";
 CHIGON[194].Chinese="低估價值；看輕";










  Panel1->Hide();       //進入選擇關卡介面

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
      BUTTON[i][j]->Caption=k;      //按鈕上顯示關卡數
      k++;
      BUTTON[i][j]->OnClick=Panel1Show;   //讓動態按鈕按下能促使Panel出現
    }
  }


    for (a=0;a<q;a++)      // 4個選項
    {
      for (b=0;b<w;b++)
      {
        select[a][b]=new TLabel(Form2);     //  clRed
        select[a][b]->Parent=GroupBox1;
        select[a][b]->Width=129;            //紫色選項(0x00E19DC2)  正確
        select[a][b]->Height=73;            //藍色選項(0x00FF8080)  未選時
        select[a][b]->Left=48+(b*184);
        select[a][b]->Top=176+(a*184);                  //用TIMER和SWITCH
        select[a][b]->Color=(TColor)(0x00FF8080);
        select[a][b]->OnClick=selecting;
      }                     //  藍色是一開始選項的顏色，選對的那個藍色就變紫色
    }
   Timer1->Enabled=false;



}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel1Show(TObject *Sender)
{
  Panel1->Show();              // 按下動態按鈕可以讓Panel秀出來
  GroupBox1->Enabled=false;

  for (i=0;i<h;i++)            // 因為動態物件會重疊，所以Panel一秀出來，
  {                            // 就隱藏動態按鈕。
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
   QuestionC->Caption=CHIGON[RANDOM].Chinese;    // 題目顯示 也就是出題目啦
   QuestionC->Tag=CHIGON[RANDOM].chigon;


   for (a=0;a<q;a++)      // 4個選項顯示
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
{  /* 第一個Timer，用來從按鈕點進去關卡時，     Timer1一開始先被關掉
      讓一進去可以先暫停個3秒(倒數三秒)，再開始作答。*/

  Label7->Caption="倒數"+AnsiString(countdown--)+"秒";

  if (countdown==-1)   //為了可以完整地倒數完3秒
  {
    Timer1->Enabled=false;
    Sleep(100);
    Label7->Caption="開始選擇!!";
  }                                        
  else if (countdown<=-1)                   
  {
    countdown=4;
    Label7->Caption="倒數"+AnsiString(countdown--)+"秒";
    Sleep(100);
    Label7->Caption="開始選擇!!";
  }

  if (Label7->Caption=="開始選擇!!")        //一開始GroupBox1在PanelShow關掉，
  {                                         //當顯示(開始選擇!!)時再開啟。
    GroupBox1->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer2Timer(TObject *Sender)
{  // 第二個Timer，用來讓關卡裡十題每題都能從12秒開始倒數

    if (Label7->Caption=="開始選擇!!")  // Timer1停止運作的時候，Timer2開始倒數工作。
    {
      Timer2->Enabled=true;
      Label14->Caption=AnsiString(timelimit--);
    }

   switch(timelimit)
   {                                  //產生下一題的新秒數
     case -1 :
      Sleep(400);
      timelimit=12;
      Label14->Caption=AnsiString(timelimit--);
      select[random(2)][random(2)]->Tag=10000;      //將題目對上選項
      RANDOM=random(197);
      QuestionC->Caption=CHIGON[RANDOM].Chinese;    // 時間到了換新題目
      QuestionC->Tag=CHIGON[RANDOM].chigon;

      for (a=0;a<q;a++)      // 4個選項顯示        //也換上新選項
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
    if (timelimit<=-1)    //產生下一題
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
  TLabel *dasabi=(TLabel *)Sender;     //按下四個Label後會發生的事
  if (dasabi->Tag==QuestionC->Tag)      // 判斷答對
  {
      dasabi->Color=(TColor)(0x00E19DC2);  //答對後，對的選項變成紫色
      Panel1->Refresh();
      Sleep(450);
      {
        ScoreBoard->Caption=ScoreBoard->Caption+"\n"+"第"+AnsiString(PGT++)+"題:  "
       +"答對O~，"+"\n"+"正確答案正是"+KIGON[QuestionC->Tag].English+" !";

        timelimit=12;
        select[random(2)][random(2)]->Tag=10000;      //將題目對上選項

        original_RANDOM=random(197);
        QuestionC->Caption=CHIGON[original_RANDOM].Chinese;    // 答對了就換新題目
        QuestionC->Tag=CHIGON[original_RANDOM].chigon;

        for (a=0;a<q;a++)      // 4個選項顯示        //也換上新選項
        {
          for (b=0;b<w;b++)
          {
            select[a][b]->Color=(TColor)(0x00FF8080);  //換新題後選項變回藍色

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
  else     //答錯
  {
    dasabi->Color=(TColor)(clRed);           //選錯的選項變成紅色
    Panel1->Refresh();
    Sleep(450);
    {
      ScoreBoard->Caption=ScoreBoard->Caption+"\n"+"第"+AnsiString(PGT++)+"題:  "
       +"答錯X!，"+"\n"+"正確答案應是"+KIGON[QuestionC->Tag].English+" !";
      timelimit=12;
      select[random(2)][random(2)]->Tag=10000;      //將題目對上選項
       RANDOM=random(197);
      QuestionC->Caption=CHIGON[RANDOM].Chinese;    // 答錯就換新題目
      QuestionC->Tag=CHIGON[RANDOM].chigon;

      for (a=0;a<q;a++)      // 4個選項顯示        //也換上新選項
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







