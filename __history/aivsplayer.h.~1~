//---------------------------------------------------------------------------

#ifndef aivsplayerH
#define aivsplayerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.IB.hpp>
#include <FireDAC.Phys.IBDef.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <vector>
#include <climits>
#include <algorithm> // For std::max and std::min
using std::vector;
using std::pair;
using std::max;
using std::min;
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TLabel *Label1;
	TButton *Button10;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TLabel *WinnerLabel;
	TFDConnection *EmployeeConnection;
	TFDQuery *UsersTable;
	TFDQuery *GameresultsTable;
	TButton *Button11;
	TButton *Button12;
	void __fastcall ButtonClick(TObject *Sender);
    void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
private:	// User declarations
	int id;
bool TForm5:: checkisWinner();
void TForm5::StartNewGame();
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
	__property int ID = { read = id , write = id};

	void __fastcall TForm5::ResetButtonFonts();

};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
