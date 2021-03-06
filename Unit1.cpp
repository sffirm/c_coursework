//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop  
#include <conio.h>
#include <string.h>
#include <stdio.h>

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKazachenko_UVP3 *Kazachenko_UVP3;
void removeFile();
void copyFileToFile( char * fileFrom, char * fileTo);
struct event_type{
  char poroda[50];
  char name[50];
  char date_rozd[30];
  char pol[10];
  char rodoslovn[8];
  char fio_owner[60];
  char cost[60];
};

event_type event;
//---------------------------------------------------------------------------
__fastcall TKazachenko_UVP3::TKazachenko_UVP3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKazachenko_UVP3::Exit_programmClick(TObject *Sender)
{
  Kazachenko_UVP3->Close();        
}
//---------------------------------------------------------------------------
void __fastcall TKazachenko_UVP3::FormCreate(TObject *Sender)
{
  sgFindResult->Cells[1][0] = "������ ������";
  sgFindResult->Cells[2][0] = "������";
  sgFindResult->Cells[3][0] = "���� ��������";
  sgFindResult->Cells[4][0] = "���";
  sgFindResult->Cells[5][0] = "������� ����������� ";
  sgFindResult->Cells[6][0] = "��� ���������";
  sgFindResult->Cells[7][0] = "���������";
  Kazachenko_UVP3->_fileName  = "Events.dat";
  Kazachenko_UVP3->_fileTmp  = "Events.tmp";
  Kazachenko_UVP3->_fileReserv  = "Events.res";
  Kazachenko_UVP3_edit->show_result();
  sgFindResult->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::sgFindResultDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
   String Text;
   Text = sgFindResult->Cells[ACol][ARow];
   sgFindResult->Canvas->FillRect(Rect);
   DrawText(sgFindResult->Canvas->Handle, Text.c_str(), Text.Length(), &Rect, DT_WORDBREAK);
}
//---------------------------------------------------------------------------



void __fastcall TKazachenko_UVP3::File_CreateClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 1;
   Kazachenko_UVP3_edit->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Insert_to_endClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 2;
   sgFindResult->Visible = false;
   Kazachenko_UVP3_edit->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Insert_by_numberClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 3;
   sgFindResult->Visible = false;
   Kazachenko_UVP3_edit->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Show_recordsClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->show_result();
   sgFindResult->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Delete_by_numberClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 4;
   sgFindResult->Visible = false;
   Kazachenko_UVP3_edit->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Show_by_typeClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 5;
   sgFindResult->Visible = true;
   Kazachenko_UVP3_edit->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Delete_fileClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 6;
   sgFindResult->Visible = false;
   removeFile();
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::BackupClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 7;
   sgFindResult->Visible = false;
   copyFileToFile( Kazachenko_UVP3->_fileName, Kazachenko_UVP3->_fileReserv );
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::RestoreClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 8;
   sgFindResult->Visible = false;
   copyFileToFile( Kazachenko_UVP3->_fileReserv, Kazachenko_UVP3->_fileName );
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Delete_by_nameClick(TObject *Sender)
{                      
    Kazachenko_UVP3_edit->type_operation = 9;
    FILE *p1,*p2;
    char rodosl[50];
    int count = 0;
    strcpy(rodosl, "���");
    if ( ( p1 = fopen( Kazachenko_UVP3->_fileName, "rb" ) ) == NULL ){
      MessageDlg("������ ������ ��������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    if ( ( p2 = fopen( Kazachenko_UVP3->_fileTmp, "wb") ) == NULL ){
      MessageDlg("������ �������� ���������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    while( fread(&event,sizeof(event),1,p1) != 0 )
    {
      if ( strcmp(rodosl, event.rodoslovn ) != 0 ){
        fwrite(&event,sizeof(event),1,p2);
      }else{
        count++;
      }
    }
    fcloseall();
    unlink(Kazachenko_UVP3->_fileName);
    rename(Kazachenko_UVP3->_fileTmp,Kazachenko_UVP3->_fileName);
    MessageDlg( "���������� ��������� �����: " + AnsiString(count),mtWarning,TMsgDlgButtons()<<mbOK,0);
    Kazachenko_UVP3_edit->show_result();
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3::Change_countClick(TObject *Sender)
{
   Kazachenko_UVP3_edit->type_operation = 10;
   sgFindResult->Visible = false;
   Kazachenko_UVP3_edit->ShowModal();
}
//---------------------------------------------------------------------------



