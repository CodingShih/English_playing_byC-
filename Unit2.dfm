object Form2: TForm2
  Left = 286
  Top = 96
  Width = 1043
  Height = 563
  Caption = 'Form2'
  Color = 8421631
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object STAGE: TGroupBox
    Left = 0
    Top = 0
    Width = 1035
    Height = 532
    Align = alClient
    Caption = #38364#21345
    Color = 8454143
    Font.Charset = CHINESEBIG5_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #27161#26999#39636
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 0
    object RETURN: TButton
      Left = 384
      Top = 24
      Width = 233
      Height = 49
      Caption = #36820#22238#19978#23652
      TabOrder = 0
      OnClick = RETURNClick
    end
    object Panel1: TPanel
      Left = 2
      Top = 0
      Width = 1031
      Height = 530
      Color = 14211288
      TabOrder = 1
      object Label7: TLabel
        Left = 440
        Top = 32
        Width = 15
        Height = 27
        Font.Charset = CHINESEBIG5_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = #27161#26999#39636
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 496
        Top = 64
        Width = 28
        Height = 53
        Font.Charset = CHINESEBIG5_CHARSET
        Font.Color = clRed
        Font.Height = -53
        Font.Name = #27161#26999#39636
        Font.Style = [fsBold]
        ParentFont = False
      end
      object GroupBox1: TGroupBox
        Left = 1
        Top = 1
        Width = 392
        Height = 528
        Align = alLeft
        Caption = 'GroupBox1'
        Color = 8421631
        ParentColor = False
        TabOrder = 0
        OnClick = selecting
        object Question: TLabel
          Left = 16
          Top = 56
          Width = 58
          Height = 21
          Caption = #38988#30446':'
        end
        object QuestionC: TLabel
          Left = 120
          Top = 56
          Width = 12
          Height = 21
          Color = 8421631
          ParentColor = False
        end
      end
      object GroupBox2: TGroupBox
        Left = 638
        Top = 1
        Width = 392
        Height = 528
        Align = alRight
        Caption = #35352#37636#29256
        Color = 8454016
        ParentColor = False
        TabOrder = 1
        object ScoreBoard: TLabel
          Left = 0
          Top = 23
          Width = 12
          Height = 21
        end
      end
      object GMAESTOP: TButton
        Left = 424
        Top = 200
        Width = 177
        Height = 97
        Caption = #36938#25138#26283#20572
        TabOrder = 2
        OnClick = GAMESTOP
      end
      object RETURNtoSTAGE: TButton
        Left = 424
        Top = 336
        Width = 177
        Height = 97
        Caption = #36820#22238#19978#23652
        TabOrder = 3
        OnClick = RETURNtoSTAGEClick
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 400
    Top = 16
  end
  object Timer2: TTimer
    OnTimer = Timer2Timer
    Left = 400
    Top = 96
  end
end
