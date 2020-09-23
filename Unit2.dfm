object Kazachenko_UVP3_edit: TKazachenko_UVP3_edit
  Left = 612
  Top = 322
  Width = 642
  Height = 246
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
    Width = 94
    Height = 13
    Caption = #1059#1044#1050' '#1084#1077#1088#1086#1087#1088#1080#1103#1090#1080#1103
  end
  object lblName: TLabel
    Left = 8
    Top = 40
    Width = 120
    Height = 13
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1084#1077#1088#1086#1087#1088#1080#1103#1090#1080#1103
  end
  object lblTyptEvt: TLabel
    Left = 8
    Top = 64
    Width = 89
    Height = 13
    Caption = #1058#1080#1087' '#1084#1077#1088#1086#1087#1088#1080#1103#1090#1080#1103
  end
  object lblDateEvt: TLabel
    Left = 8
    Top = 88
    Width = 96
    Height = 13
    Caption = #1044#1072#1090#1072' '#1084#1077#1088#1086#1087#1088#1080#1103#1090#1080#1103
  end
  object lblPeopleCnt: TLabel
    Left = 8
    Top = 112
    Width = 119
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1091#1095#1072#1089#1090#1085#1080#1082#1086#1074
  end
  object lblFioHeroes: TLabel
    Left = 8
    Top = 136
    Width = 177
    Height = 13
    Caption = #1060#1072#1084#1080#1083#1080#1080' '#1086#1090#1083#1080#1095#1080#1074#1096#1080#1093#1089#1103' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
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
    Top = 160
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = btOkClick
  end
  object btCancel: TButton
    Left = 472
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = btCancelClick
  end
  object edtUDK: TEdit
    Left = 192
    Top = 8
    Width = 97
    Height = 21
    TabOrder = 2
  end
  object edtName: TEdit
    Left = 192
    Top = 32
    Width = 201
    Height = 21
    TabOrder = 3
  end
  object cmbTyptEvt: TComboBox
    Left = 192
    Top = 56
    Width = 145
    Height = 21
    ItemHeight = 13
    ItemIndex = 1
    TabOrder = 4
    Text = #1059#1095#1077#1073#1085#1086#1077
    Items.Strings = (
      'C'#1087#1086#1088#1090#1080#1074#1085#1086#1077
      #1059#1095#1077#1073#1085#1086#1077
      #1042#1086#1089#1087#1080#1090#1072#1090#1077#1083#1100#1085#1086#1077)
  end
  object dtpDateEvt: TDateTimePicker
    Left = 192
    Top = 80
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
  object edtPeopleCnt: TEdit
    Left = 192
    Top = 104
    Width = 105
    Height = 21
    TabOrder = 6
  end
  object edtFioHeroes: TEdit
    Left = 192
    Top = 128
    Width = 401
    Height = 21
    TabOrder = 7
  end
  object edtNumRec: TEdit
    Left = 464
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 8
  end
end
