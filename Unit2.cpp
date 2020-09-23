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
  char udk[10];
  char name[50];
  char type_evt[30];
  char date_evt[10];
  char people_cnt[8];
  char fio_heroes[60];
};

event_type event;

void create_file();
void insert_to_end();
void insert_by_number();
void delete_by_number();
void show_by_type();
void delete_by_name();
void change_count();

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
      show_by_type();
      break;
    case 9:
      delete_by_name();
      break;
    case 10:
      change_count();
      break;
  }
}
//---------------------------------------------------------------------------

void create_file(){
  FILE *p;
  if ( ( p = fopen(Kazachenko_UVP3->_fileName,"wb")) == NULL ){
     MessageDlg("Ошибка создания файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
  }
  strcpy(event.udk, Kazachenko_UVP3_edit->edtUDK->Text.c_str());
  strcpy(event.name,Kazachenko_UVP3_edit->edtName->Text.c_str());
  strcpy(event.type_evt,Kazachenko_UVP3_edit->cmbTyptEvt->Text.c_str());
  strcpy(event.date_evt,Kazachenko_UVP3_edit->dtpDateEvt->Date.DateString().c_str());
  strcpy(event.people_cnt,Kazachenko_UVP3_edit->edtPeopleCnt->Text.c_str());
  strcpy(event.fio_heroes,Kazachenko_UVP3_edit->edtFioHeroes->Text.c_str());
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
    strcpy(event.udk, Kazachenko_UVP3_edit->edtUDK->Text.c_str());
    strcpy(event.name,Kazachenko_UVP3_edit->edtName->Text.c_str());
    strcpy(event.type_evt,Kazachenko_UVP3_edit->cmbTyptEvt->Text.c_str());
    strcpy(event.date_evt,Kazachenko_UVP3_edit->dtpDateEvt->Date.DateString().c_str());
    strcpy(event.people_cnt,Kazachenko_UVP3_edit->edtPeopleCnt->Text.c_str());
    strcpy(event.fio_heroes,Kazachenko_UVP3_edit->edtFioHeroes->Text.c_str());
    fwrite(&event,sizeof(event),1,p);
    fclose(p);
  } else {
    MessageDlg("Файл не существует",mtWarning,TMsgDlgButtons()<<mbOK,0);
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
       Kazachenko_UVP3->sgFindResult->Cells[1][i] = event.udk;          //"УДК  мероприятия"
       Kazachenko_UVP3->sgFindResult->Cells[2][i] = event.name;         //Название мероприятия";
       Kazachenko_UVP3->sgFindResult->Cells[3][i] = event.type_evt;     //"Тип мероприятия";
       Kazachenko_UVP3->sgFindResult->Cells[4][i] = event.date_evt;     //"Дата мероприятия"
       Kazachenko_UVP3->sgFindResult->Cells[5][i] = event.people_cnt;   //Количество человек принявших участие в мероприятии"
       Kazachenko_UVP3->sgFindResult->Cells[6][i] = event.fio_heroes;   //"Фамилии отличившихся студентов"
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
    MessageDlg("Ошибка чтения исходного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  if ( (p2 = fopen(Kazachenko_UVP3->_fileTmp,"wb") ) == NULL ){
    MessageDlg("Ошибка создания временного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  for (i=0; i<n; i++)
  {
    if ( fread(&event, sizeof(event), 1, p1) != 0 )
    {
      fwrite(&event, sizeof(event), 1, p2);
    }
  }

  strcpy(event.udk, Kazachenko_UVP3_edit->edtUDK->Text.c_str());
  strcpy(event.name,Kazachenko_UVP3_edit->edtName->Text.c_str());
  strcpy(event.type_evt,Kazachenko_UVP3_edit->cmbTyptEvt->Text.c_str());
  strcpy(event.date_evt,Kazachenko_UVP3_edit->dtpDateEvt->Date.DateString().c_str());
  strcpy(event.people_cnt,Kazachenko_UVP3_edit->edtPeopleCnt->Text.c_str());
  strcpy(event.fio_heroes,Kazachenko_UVP3_edit->edtFioHeroes->Text.c_str());
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
    MessageDlg("Ошибка чтения исходного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  if ( (p2 = fopen(Kazachenko_UVP3->_fileTmp,"wb") ) == NULL ){
    MessageDlg("Ошибка создания временного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
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
     MessageDlg("Запись с указанным номером не найдена",mtWarning,TMsgDlgButtons()<<mbOK,0);
  }
  Kazachenko_UVP3->Show();
  Kazachenko_UVP3_edit->Close();
}

void show_by_type()
{
  char type_evt[30];
  strcpy(type_evt, Kazachenko_UVP3_edit->cmbTyptEvt->Text.c_str());
  for (int i =1; i < Kazachenko_UVP3->sgFindResult->ColCount; i++)
    for (int j=1; j < Kazachenko_UVP3->sgFindResult->RowCount; j++)
      Kazachenko_UVP3->sgFindResult->Cells[i][j] = "";
  FILE *p;
  if ( ( p = fopen(Kazachenko_UVP3->_fileName,"rb")) == NULL){
    MessageDlg("Ошибка чтения исходного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
    return;
  }
  int i = 0;
  while (fread(&event,sizeof(event),1,p) != 0)
  {
     if ( strcmp(event.type_evt, type_evt) == 0 )
     {
       i++;
       Kazachenko_UVP3->sgFindResult->Cells[1][i] = event.udk;          //"УДК  мероприятия"
       Kazachenko_UVP3->sgFindResult->Cells[2][i] = event.name;         //Название мероприятия";
       Kazachenko_UVP3->sgFindResult->Cells[3][i] = event.type_evt;     //"Тип мероприятия";
       Kazachenko_UVP3->sgFindResult->Cells[4][i] = event.date_evt;     //"Дата мероприятия"
       Kazachenko_UVP3->sgFindResult->Cells[5][i] = event.people_cnt;   //Количество человек принявших участие в мероприятии"
       Kazachenko_UVP3->sgFindResult->Cells[6][i] = event.fio_heroes;   //"Фамилии отличившихся студентов"
       Kazachenko_UVP3->sgFindResult->RowCount    = i+1;
    }
  }
  fclose(p);
  if ( i == 0 ){
    MessageDlg("Мероприятий указанного типа не найдено",mtWarning,TMsgDlgButtons()<<mbOK,0);
  }
  Kazachenko_UVP3->Show();
  Kazachenko_UVP3_edit->Close();
}

void removeFile(){
  int pr;
  pr=MessageDlg("Подтвердите удаление файла",mtWarning,TMsgDlgButtons()<<mbYes<<mbNo,0);
  if (pr==mrYes)
  {
     if ( unlink(Kazachenko_UVP3->_fileName) == 0){
       MessageDlg("Файл удален",mtWarning,TMsgDlgButtons()<<mbOK,0);
     }else{
       MessageDlg("Ошибка удаления файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
     }
  }
  else
    MessageDlg("Файл не удален",mtWarning,TMsgDlgButtons()<<mbOK,0);
}

void copyFileToFile( char * fileFrom, char * fileTo){
    FILE *p1,*p2;
    if ( ( p1 = fopen( fileFrom, "rb" ) ) == NULL ){
      MessageDlg("Ошибка чтения исходного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    if ( ( p2 = fopen( fileTo ,"wb") ) == NULL ){
      MessageDlg("Ошибка создания результирующего файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    while( fread(&event,sizeof(event),1,p1) != 0 )
      fwrite(&event,sizeof(event),1,p2);
    fcloseall();
    MessageDlg("Операция выполнена успешно",mtWarning,TMsgDlgButtons()<<mbOK,0);
}

void delete_by_name(){
    FILE *p1,*p2;
    char lv_name[50];
    int lv_kol = 0;
    strcpy(lv_name,Kazachenko_UVP3_edit->edtName->Text.c_str());
    if ( ( p1 = fopen( Kazachenko_UVP3->_fileName, "rb" ) ) == NULL ){
      MessageDlg("Ошибка чтения исходного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    if ( ( p2 = fopen( Kazachenko_UVP3->_fileTmp, "wb") ) == NULL ){
      MessageDlg("Ошибка создания временного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    while( fread(&event,sizeof(event),1,p1) != 0 )
    {
      if ( strcmp(lv_name, event.name ) != 0 ){
        fwrite(&event,sizeof(event),1,p2);
      }else{
        lv_kol++;
      }
    }
    fcloseall();
    unlink(Kazachenko_UVP3->_fileName);
    rename(Kazachenko_UVP3->_fileTmp,Kazachenko_UVP3->_fileName);
    MessageDlg( "Количество удаленных строк: " + AnsiString(lv_kol),mtWarning,TMsgDlgButtons()<<mbOK,0);
    Kazachenko_UVP3->Show();
    Kazachenko_UVP3_edit->Close();
}

void change_count(){
    FILE *p1,*p2;
    char lv_name[50], lv_people_cnt[8];
    int lv_kol = 0;

    strcpy(lv_name, Kazachenko_UVP3_edit->edtName->Text.c_str() );
    strcpy(lv_people_cnt, Kazachenko_UVP3_edit->edtPeopleCnt->Text.c_str() );
    if ( ( p1 = fopen( Kazachenko_UVP3->_fileName, "rb" ) ) == NULL ){
      MessageDlg("Ошибка чтения исходного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    if ( ( p2 = fopen( Kazachenko_UVP3->_fileTmp, "wb") ) == NULL ){
      MessageDlg("Ошибка создания временного файла",mtWarning,TMsgDlgButtons()<<mbOK,0);
      return;
    };
    while( fread(&event,sizeof(event),1,p1) != 0 )
    {
      if ( strcmp(lv_name, event.name ) == 0 ){
        strcpy(event.people_cnt, lv_people_cnt);
        lv_kol++;
      }
      fwrite(&event,sizeof(event),1,p2);
    }
    fcloseall();
    unlink(Kazachenko_UVP3->_fileName);
    rename(Kazachenko_UVP3->_fileTmp,Kazachenko_UVP3->_fileName);
    MessageDlg( "Количество измененных строк: " + AnsiString(lv_kol),mtWarning,TMsgDlgButtons()<<mbOK,0);
    Kazachenko_UVP3->Show();
    Kazachenko_UVP3_edit->Close();
}
void __fastcall TKazachenko_UVP3_edit::FormShow(TObject *Sender)
{
    switch (type_operation) {
    case 1:
      Kazachenko_UVP3_edit->Caption = "Создание нового файла";
      edtUDK->Visible = true;
      edtName->Visible = true;
      edtNumRec->Visible = false;
      edtPeopleCnt->Visible = true;
      edtFioHeroes->Visible = true;
      cmbTyptEvt->Visible = true;
      dtpDateEvt->Visible = true;
      break;
    case 2:
      Kazachenko_UVP3_edit->Caption = "Добавление записи в конец файла";
      edtUDK->Visible = true;
      edtName->Visible = true;
      edtNumRec->Visible = false;
      edtPeopleCnt->Visible = true;
      edtFioHeroes->Visible = true;
      cmbTyptEvt->Visible = true;
      dtpDateEvt->Visible = true;
      break;
    case 3:
      Kazachenko_UVP3_edit->Caption = "Добавление записи по номеру";
      edtUDK->Visible = true;
      edtName->Visible = true;
      edtNumRec->Visible = true;
      edtPeopleCnt->Visible = true;
      edtFioHeroes->Visible = true;
      cmbTyptEvt->Visible = true;
      dtpDateEvt->Visible = true;
      break;
    case 4:
      Kazachenko_UVP3_edit->Caption = "Удаление записи в конец файла";
      edtUDK->Visible = false;
      edtName->Visible = false;
      edtNumRec->Visible = true;
      edtPeopleCnt->Visible = false;
      edtFioHeroes->Visible = false;
      cmbTyptEvt->Visible = false;
      dtpDateEvt->Visible = false;
      break;
    case 5:
      Kazachenko_UVP3_edit->Caption = "Показать записи по типу";
      edtUDK->Visible = false;
      edtName->Visible = false;
      edtNumRec->Visible = false;
      edtPeopleCnt->Visible = false;
      edtFioHeroes->Visible = false;
      cmbTyptEvt->Visible = true;
      dtpDateEvt->Visible = false;
      break;
    case 9:
      Kazachenko_UVP3_edit->Caption = "Удалить записи по заданному имени";
      edtUDK->Visible = false;
      edtName->Visible = true;
      edtNumRec->Visible = false;
      edtPeopleCnt->Visible = false;
      edtFioHeroes->Visible = false;
      cmbTyptEvt->Visible = false;
      dtpDateEvt->Visible = false;
      break;
    case 10:
      Kazachenko_UVP3_edit->Caption = "Изменить количество для записей с заданным именем";
      edtUDK->Visible = false;
      edtName->Visible = true;
      edtNumRec->Visible = false;
      edtPeopleCnt->Visible = true;
      edtFioHeroes->Visible = false;
      cmbTyptEvt->Visible = false;
      dtpDateEvt->Visible = false;
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

