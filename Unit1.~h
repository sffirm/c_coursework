//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TKazachenko_UVP3 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *mmMainMenu;
        TMenuItem *File_ops;
        TMenuItem *Exit_programm;
        TMenuItem *File_Create;
        TMenuItem *Insert_to_end;
        TMenuItem *Insert_by_number;
        TMenuItem *Show_records;
        TMenuItem *Delete_by_number;
        TMenuItem *Show_by_type;
        TMenuItem *Delete_file;
        TMenuItem *Backup;
        TMenuItem *Restore;
        TMenuItem *Delete_by_name;
        TMenuItem *Change_count;
        TStringGrid *sgFindResult;
        void __fastcall Exit_programmClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall sgFindResultDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall File_CreateClick(TObject *Sender);
        void __fastcall Insert_to_endClick(TObject *Sender);
        void __fastcall Insert_by_numberClick(TObject *Sender);
        void __fastcall Show_recordsClick(TObject *Sender);
        void __fastcall Delete_by_numberClick(TObject *Sender);
        void __fastcall Show_by_typeClick(TObject *Sender);
        void __fastcall Delete_fileClick(TObject *Sender);
        void __fastcall BackupClick(TObject *Sender);
        void __fastcall RestoreClick(TObject *Sender);
        void __fastcall Delete_by_nameClick(TObject *Sender);
        void __fastcall Change_countClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        char * _fileName ;
        char * _fileTmp ;
        char * _fileReserv ;
        __fastcall TKazachenko_UVP3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKazachenko_UVP3 *Kazachenko_UVP3;
//---------------------------------------------------------------------------
#endif
