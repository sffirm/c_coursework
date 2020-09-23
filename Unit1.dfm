object Kazachenko_UVP3: TKazachenko_UVP3
  Left = 499
  Top = 183
  Width = 965
  Height = 552
  Caption = #1050#1083#1091#1073' '#1089#1086#1073#1072#1082#1086#1074#1086#1076#1089#1090#1074#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = mmMainMenu
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object sgFindResult: TStringGrid
    Left = 0
    Top = 0
    Width = 949
    Height = 493
    Align = alClient
    ColCount = 8
    DefaultColWidth = 10
    DefaultRowHeight = 50
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
    TabOrder = 0
    OnDrawCell = sgFindResultDrawCell
    ColWidths = (
      10
      148
      137
      111
      115
      135
      139
      139)
    RowHeights = (
      50
      24
      26
      23
      20)
  end
  object mmMainMenu: TMainMenu
    Left = 8
    Top = 176
    object File_ops: TMenuItem
      Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1092#1072#1081#1083#1086#1084
      object File_Create: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1085#1080#1077' '#1092#1072#1081#1083#1072
        OnClick = File_CreateClick
      end
      object Insert_to_end: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1079#1072#1087#1080#1089#1077#1081' '#1074'  '#1082#1086#1085#1077#1094' '#1092#1072#1081#1083#1072
        OnClick = Insert_to_endClick
      end
      object Insert_by_number: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1079#1072#1087#1080#1089#1080' '#1087#1086' '#1085#1086#1084#1077#1088#1091
        OnClick = Insert_by_numberClick
      end
      object Show_records: TMenuItem
        Caption = #1042#1099#1074#1086#1076' '#1085#1072' '#1101#1082#1088#1072#1085' '#1074#1089#1077#1093' '#1079#1072#1087#1080#1089#1077#1081' '#1074' '#1074#1080#1076#1077' '#1090#1072#1073#1083#1080#1094#1099' '
        OnClick = Show_recordsClick
      end
      object Delete_by_number: TMenuItem
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1079#1072#1087#1080#1089#1080' '#1087#1086'  '#1085#1086#1084#1077#1088#1091
        OnClick = Delete_by_numberClick
      end
      object Show_by_type: TMenuItem
        Caption = #1042#1099#1074#1077#1089#1090#1080' '#1089#1087#1080#1089#1086#1082' '#1089#1086#1073#1072#1082'-'#1084#1072#1083#1100#1095#1080#1082#1086#1074',  '#1082#1086#1090#1086#1088#1099#1077' '#1088#1086#1076#1080#1083#1080#1089#1100' '#1074' '#1079#1072#1076#1072#1085#1085#1099#1081' '#1075#1086#1076
        OnClick = Show_by_typeClick
      end
      object Delete_file: TMenuItem
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077'  '#1092#1072#1081#1083#1072
        OnClick = Delete_fileClick
      end
      object Backup: TMenuItem
        Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1085#1080#1077' '#1076#1072#1085#1085#1099#1093' '#1080#1079' '#1092#1072#1081#1083#1072' '#1074' '#1088#1077#1079#1077#1088#1074#1085#1099#1081' '#1092#1072#1081#1083
        OnClick = BackupClick
      end
      object Restore: TMenuItem
        Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1092#1072#1081#1083#1072' '#1080#1079' '#1088#1077#1079#1077#1088#1074#1085#1086#1075#1086' '#1092#1072#1081#1083#1072
        OnClick = RestoreClick
      end
      object Delete_by_name: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100'  '#1074#1089#1077' '#1079#1072#1087#1080#1089#1080'  '#1087#1086' '#1079#1072#1076#1072#1085#1085#1086#1084#1091' '#1084#1077#1088#1086#1087#1088#1080#1103#1090#1080#1102
        OnClick = Delete_by_nameClick
      end
      object Change_count: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1089#1090#1086#1080#1084#1086#1089#1090#1100' '#1076#1083#1103' '#1079#1072#1076#1072#1085#1085#1086#1081' '#1089#1086#1073#1072#1082#1080
        OnClick = Change_countClick
      end
    end
    object Exit_programm: TMenuItem
      Caption = #1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      OnClick = Exit_programmClick
    end
  end
end
