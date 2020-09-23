object Kazachenko_UVP3_edit: TKazachenko_UVP3_edit
  Left = 488
  Top = 178
  Width = 642
  Height = 303
  Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1079#1072#1087#1080#1089#1077#1081
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblUDK: TLabel
    Left = 8
    Top = 16
    Width = 77
    Height = 13
    Caption = #1055#1086#1088#1086#1076#1072' '#1089#1086#1073#1072#1082#1080
  end
  object lblName: TLabel
    Left = 8
    Top = 40
    Width = 36
    Height = 13
    Caption = #1050#1083#1080#1095#1082#1072
  end
  object lblTyptEvt: TLabel
    Left = 8
    Top = 64
    Width = 79
    Height = 13
    Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103
  end
  object lblDateEvt: TLabel
    Left = 8
    Top = 88
    Width = 20
    Height = 13
    Caption = #1055#1086#1083
  end
  object lblPeopleCnt: TLabel
    Left = 8
    Top = 112
    Width = 112
    Height = 13
    Caption = #1053#1072#1083#1080#1095#1080#1077' '#1088#1086#1076#1086#1089#1083#1086#1074#1085#1086#1081
  end
  object lblFioHeroes: TLabel
    Left = 8
    Top = 136
    Width = 84
    Height = 13
    Caption = #1060#1048#1054' '#1074#1083#1072#1076#1077#1083#1100#1094#1072
  end
  object lblNumRec: TLabel
    Left = 360
    Top = 8
    Width = 73
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1079#1072#1087#1080#1089#1080
  end
  object btOk: TButton
    Left = 392
    Top = 216
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = btOkClick
  end
  object btCancel: TButton
    Left = 472
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btCancelClick
  end
  object editPoroda: TEdit
    Left = 160
    Top = 8
    Width = 97
    Height = 21
    TabOrder = 2
  end
  object editName: TEdit
    Left = 160
    Top = 32
    Width = 201
    Height = 21
    TabOrder = 3
  end
  object editPol: TComboBox
    Left = 160
    Top = 80
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 4
    Text = #1059#1095#1077#1073#1085#1086#1077
    Items.Strings = (
      #1052#1072#1083#1100#1095#1080#1082
      #1044#1077#1074#1086#1095#1082#1072)
  end
  object editDate_rozd: TDateTimePicker
    Left = 160
    Top = 56
    Width = 105
    Height = 21
    CalAlignment = dtaLeft
    Date = 43919.9509517014
    Time = 43919.9509517014
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 5
  end
  object edtFioHeroes: TEdit
    Left = 160
    Top = 128
    Width = 401
    Height = 21
    TabOrder = 6
  end
  object edtNumRec: TEdit
    Left = 464
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object editRodosl: TComboBox
    Left = 160
    Top = 104
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 8
    Text = #1059#1095#1077#1073#1085#1086#1077
    Items.Strings = (
      #1044#1072
      #1053#1077#1090)
  end
end
