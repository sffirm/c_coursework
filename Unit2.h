//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TKazachenko_UVP3_edit : public TForm
{
__published:	// IDE-managed Components
        TButton *btOk;
        TButton *btCancel;
        TEdit *editPoroda;
        TLabel *lblPoroda;
        TLabel *lblName;
        TEdit *editName;
        TLabel *lblDate;
        TComboBox *editPol;
        TLabel *lblPol;
        TDateTimePicker *editDate_rozd;
        TLabel *lblRodosl;
        TLabel *lblFio;
        TEdit *editOwner;
        TEdit *edtNumRec;
        TLabel *lblNumb;
        TComboBox *editRodosl;
        TEdit *editCost;
        TLabel *lblCost;
        TLabel *lblYear;
        TEdit *editYear;
        void __fastcall btOkClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        int type_operation;
        void show_result();
        __fastcall TKazachenko_UVP3_edit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKazachenko_UVP3_edit *Kazachenko_UVP3_edit;
//---------------------------------------------------------------------------
#endif
