//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TKazachenko_UVP3_edit *Kazachenko_UVP3_edit;
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

void create_file();
void insert_to_end();
void insert_by_number();
void delete_by_number();
void show_dogs();
void change_cost();

//---------------------------------------------------------------------------
__fastcall TKazachenko_UVP3_edit::TKazachenko_UVP3_edit(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKazachenko_UVP3_edit::btOkClick(TObject *Sender)
{
  switch (type_operation) {
    case 1:
      create_file();
      show_result();
      break;
    case 2:
      insert_to_end();
      show_result();
      break;
    case 3:
      insert_by_number();
      show_result();
      break;
    case 4:
      delete_by_number();
      show_result();
      break;
    case 5:
      show_dogs();
      break;
    case 10:
      change_cost();
      break;
  }
}
//---------------------------------------------------------------------------

void create_file(){
  FILE *p;
  if ( ( p = fopen(Kazachenko_UVP3->_fileName,"wb")) == NULL ){
     MessageDlg("������ �������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
  }
  strcpy(event.poroda, Kazachenko_UVP3_edit->editPoroda->Text.c_str());
  strcpy(event.name,Kazachenko_UVP3_edit->editName->Text.c_str());
  strcpy(event.date_rozd,Kazachenko_UVP3_edit->editDate_rozd->Date.DateString().c_str());
  strcpy(event.pol,Kazachenko_UVP3_edit->editPol->Text.c_str());
  strcpy(event.rodoslovn,Kazachenko_UVP3_edit->editRodosl->Text.c_str());
  strcpy(event.fio_owner,Kazachenko_UVP3_edit->editOwner->Text.c_str());
  strcpy(event.cost,Kazachenko_UVP3_edit->editCost->Text.c_str());
  fwrite(&event,sizeof(event),1,p);
  fclose(p);
  Kazachenko_UVP3->Show();
  Kazachenko_UVP3_edit->Close();
}

void insert_to_end(){
  FILE *p;
  p = fopen(Kazachenko_UVP3->_fileName,"ab");
  if ( p != NULL )
  {
    strcpy(event.poroda, Kazachenko_UVP3_edit->editPoroda->Text.c_str());
    strcpy(event.name,Kazachenko_UVP3_edit->editName->Text.c_str());
    strcpy(event.date_rozd,Kazachenko_UVP3_edit->editDate_rozd->Date.DateString().c_str());
    strcpy(event.pol,Kazachenko_UVP3_edit->editPol->Text.c_str());
    strcpy(event.rodoslovn,Kazachenko_UVP3_edit->editRodosl->Text.c_str());
    strcpy(event.fio_owner,Kazachenko_UVP3_edit->editOwner->Text.c_str()); 
    strcpy(event.cost,Kazachenko_UVP3_edit->editCost->Text.c_str());
    fwrite(&event,sizeof(event),1,p);
    fclose(p);
  } else {
    MessageDlg("���� �� ����������",mtWarning,TMsgDlgButtons()<<mbOK,0);
  }
  Kazachenko_UVP3->Show();
  Kazachenko_UVP3_edit->Close();
}

void TKazachenko_UVP3_edit::show_result()
{
  FILE *p;
  for (int i =1; i < Kazachenko_UVP3->sgFindResult->ColCount; i++)
      for (int j=1; j < Kazachenko_UVP3->sgFindResult->RowCount; j++)
         Kazachenko_UVP3->sgFindResult->Cells[i][j] = "";
  if ( ( p = fopen(Kazachenko_UVP3->_fileName,"rb") ) != NULL ) {
    int i = 0;
    while (fread(&event,sizeof(event),1,p) != 0)
    {
       i++;
       Kazachenko_UVP3->sgFindResult->Cells[1][i] = event.poroda;
       Kazachenko_UVP3->sgFindResult->Cells[2][i] = event.name;
       Kazachenko_UVP3->sgFindResult->Cells[3][i] = event.date_rozd;
       Kazachenko_UVP3->sgFindResult->Cells[4][i] = event.pol;
       Kazachenko_UVP3->sgFindResult->Cells[5][i] = event.rodoslovn;
       Kazachenko_UVP3->sgFindResult->Cells[6][i] = event.fio_owner;
       Kazachenko_UVP3->sgFindResult->Cells[7][i] = event.cost;
       Kazachenko_UVP3->sgFindResult->RowCount    = i+1;
    }
    fclose(p);
  }
}

void insert_by_number()
{
  int i,n;
  FILE *p1,*p2;
  n = StrToInt(Kazachenko_UVP3_edit->edtNumRec->Text);
  if ( ( p1 = fopen(Kazachenko_UVP3->_fileName,"rb")) == NULL){
    MessageDlg("������ ������ ��������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  if ( (p2 = fopen(Kazachenko_UVP3->_fileTmp,"wb") ) == NULL ){
    MessageDlg("������ �������� ���������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  for (i=0; i<n; i++)
  {
    if ( fread(&event, sizeof(event), 1, p1) != 0 )
    {
      fwrite(&event, sizeof(event), 1, p2);
    }
  }

  strcpy(event.poroda, Kazachenko_UVP3_edit->editPoroda->Text.c_str());
  strcpy(event.name,Kazachenko_UVP3_edit->editName->Text.c_str());
  strcpy(event.date_rozd,Kazachenko_UVP3_edit->editDate_rozd->Date.DateString().c_str());
  strcpy(event.pol,Kazachenko_UVP3_edit->editPol->Text.c_str());
  strcpy(event.rodoslovn,Kazachenko_UVP3_edit->editRodosl->Text.c_str());
  strcpy(event.fio_owner,Kazachenko_UVP3_edit->editOwner->Text.c_str());
  strcpy(event.cost,Kazachenko_UVP3_edit->editCost->Text.c_str());
  fwrite(&event,sizeof(event),1,p2);

  while(fread(&event,sizeof(event),1,p1)!=0) fwrite(&event,sizeof(event),1,p2);
  fcloseall();
  unlink(Kazachenko_UVP3->_fileName);
  rename(Kazachenko_UVP3->_fileTmp,Kazachenko_UVP3->_fileName);
  Kazachenko_UVP3->Show();
  Kazachenko_UVP3_edit->Close();
}

void delete_by_number()
{
  int i,n,flag;
  FILE *p1,*p2;
  n = StrToInt(Kazachenko_UVP3_edit->edtNumRec->Text);
  if ( ( p1 = fopen(Kazachenko_UVP3->_fileName,"rb")) == NULL){
    MessageDlg("������ ������ ��������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  if ( (p2 = fopen(Kazachenko_UVP3->_fileTmp,"wb") ) == NULL ){
    MessageDlg("������ �������� ���������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  i = flag = 0;
  while( fread(&event, sizeof(event), 1, p1) != 0 )
  {
    if ( i++ != n )
    {
      fwrite(&event, sizeof(event), 1, p2);
      flag = 1;
    }
  }

  fcloseall();
  unlink(Kazachenko_UVP3->_fileName);
  rename(Kazachenko_UVP3->_fileTmp,Kazachenko_UVP3->_fileName);
  if (flag == 0){
     MessageDlg("������ � ��������� ������� �� �������",mtWarning,TMsgDlgButtons()<<mbOK,0);
  }
  Kazachenko_UVP3->Show();
  Kazachenko_UVP3_edit->Close();
}

void show_dogs()
{
  char type_evt[30];
  char year[20];
  strcpy(type_evt, Kazachenko_UVP3_edit->editYear->Text.c_str());
  for (int i=1; i < Kazachenko_UVP3->sgFindResult->ColCount; i++)
    for (int j=1; j < Kazachenko_UVP3->sgFindResult->RowCount; j++)
      Kazachenko_UVP3->sgFindResult->Cells[i][j] = "";
  FILE *p;
  if ( ( p = fopen(Kazachenko_UVP3->_fileName,"rb")) == NULL){
    MessageDlg("������ ������ ��������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  int i = 0;
  while (fread(&event,sizeof(event),1,p) != 0)
  {
     strcpy(year, "");
     strcat(year, event.date_rozd + 6);
     if ( (strcmp(event.pol, "�������") == 0) && (strcmp(year, type_evt) == 0) )
     {
       i++;
       Kazachenko_UVP3->sgFindResult->Cells[1][i] = event.poroda;
       Kazachenko_UVP3->sgFindResult->Cells[2][i] = event.name;
       Kazachenko_UVP3->sgFindResult->Cells[3][i] = event.date_rozd;
       Kazachenko_UVP3->sgFindResult->Cells[4][i] = event.pol;
       Kazachenko_UVP3->sgFindResult->Cells[5][i] = event.rodoslovn;
       Kazachenko_UVP3->sgFindResult->Cells[6][i] = event.fio_owner;
       Kazachenko_UVP3->sgFindResult->Cells[7][i] = event.cost;
       Kazachenko_UVP3->sgFindResult->RowCount    = i + 1;
    }
  }
  fclose(p);
  if ( i == 0 ){
    MessageDlg("������� � ������� ����������� �� �������",mtWarning,TMsgDlgButtons()<<mbOK,0);
  }
  Kazachenko_UVP3->Show();
  Kazachenko_UVP3_edit->Close();
}

void removeFile(){
  int pr;
  pr=MessageDlg("����������� �������� �����",mtWarning,TMsgDlgButtons()<<mbYes<<mbNo,0);
  if (pr==mrYes)
  {
     if ( unlink(Kazachenko_UVP3->_fileName) == 0){
       MessageDlg("���� ������",mtWarning,TMsgDlgButtons()<<mbOK,0);
     }else{
       MessageDlg("������ �������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
     }
  }
  else
    MessageDlg("���� �� ������",mtWarning,TMsgDlgButtons()<<mbOK,0);
}

void copyFileToFile( char * fileFrom, char * fileTo){
    FILE *p1,*p2;
    if ( ( p1 = fopen( fileFrom, "rb" ) ) == NULL ){
      MessageDlg("������ ������ ��������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    if ( ( p2 = fopen( fileTo ,"wb") ) == NULL ){
      MessageDlg("������ �������� ��������������� �����",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    while( fread(&event,sizeof(event),1,p1) != 0 )
      fwrite(&event,sizeof(event),1,p2);
    fcloseall();
    MessageDlg("�������� ��������� �������",mtWarning,TMsgDlgButtons()<<mbOK,0);
}

void change_cost(){
    FILE *p1,*p2;
    char dog_name[50], dog_cost[50];
    int count = 0;

    strcpy(dog_name, Kazachenko_UVP3_edit->editName->Text.c_str() );
    strcpy(dog_cost, Kazachenko_UVP3_edit->editCost->Text.c_str() );
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
      if ( strcmp(dog_name, event.name ) == 0 ){
        strcpy(event.cost, dog_cost);
        count++;
      }
      fwrite(&event,sizeof(event),1,p2);
    }
    fcloseall();
    unlink(Kazachenko_UVP3->_fileName);
    rename(Kazachenko_UVP3->_fileTmp,Kazachenko_UVP3->_fileName);
    MessageDlg( "���������� ���������� �����: " + AnsiString(count),mtWarning,TMsgDlgButtons()<<mbOK,0);
    Kazachenko_UVP3->Show();
    Kazachenko_UVP3_edit->Close();
}

void __fastcall TKazachenko_UVP3_edit::FormShow(TObject *Sender)
{
    switch (type_operation) {
    case 1:
      Kazachenko_UVP3_edit->Caption = "�������� ������ �����";
      editPoroda->Visible = true;
      editName->Visible = true;
      edtNumRec->Visible = false;
      editRodosl->Visible = true;
      editOwner->Visible = true;
      editPol->Visible = true;
      editDate_rozd->Visible = true;
      editCost->Visible = true;
      editYear->Visible = false;
      break;
    case 2:
      Kazachenko_UVP3_edit->Caption = "���������� ������ � ����� �����";
      editPoroda->Visible = true;
      editName->Visible = true;
      edtNumRec->Visible = false;
      editRodosl->Visible = true;
      editOwner->Visible = true;
      editPol->Visible = true;
      editDate_rozd->Visible = true;   
      editCost->Visible = true;         
      editYear->Visible = false;
      break;
    case 3:
      Kazachenko_UVP3_edit->Caption = "���������� ������ �� ������";
      editPoroda->Visible = true;
      editName->Visible = true;
      edtNumRec->Visible = true;
      editRodosl->Visible = true;
      editOwner->Visible = true;
      editPol->Visible = true;
      editDate_rozd->Visible = true;   
      editCost->Visible = true;         
      editYear->Visible = false;
      break;
    case 4:
      Kazachenko_UVP3_edit->Caption = "�������� ������ � ����� �����";
      editPoroda->Visible = false;
      editName->Visible = false;
      edtNumRec->Visible = true;
      editRodosl->Visible = false;
      editOwner->Visible = false;
      editPol->Visible = false;
      editDate_rozd->Visible = false;    
      editCost->Visible = false;        
      editYear->Visible = false;
      break;
    case 5:
      Kazachenko_UVP3_edit->Caption = "�������� ������� ��������� �� ���� ��������";
      editPoroda->Visible = false;
      editName->Visible = false;
      edtNumRec->Visible = false;
      editRodosl->Visible = false;
      editOwner->Visible = false;
      editPol->Visible = false;
      editDate_rozd->Visible = false;
      editCost->Visible = false;        
      editYear->Visible = true;
      break;
    case 10:
      Kazachenko_UVP3_edit->Caption = "�������� ��������� ��� �������� ������";
      editPoroda->Visible = false;
      editName->Visible = true;
      edtNumRec->Visible = false;
      editRodosl->Visible = false;
      editOwner->Visible = false;
      editPol->Visible = false;
      editDate_rozd->Visible = false;
      editCost->Visible = true;
      editYear->Visible = false;
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TKazachenko_UVP3_edit::btCancelClick(TObject *Sender)
{
   Kazachenko_UVP3->Show();
   Kazachenko_UVP3_edit->Close();
}
//---------------------------------------------------------------------------



