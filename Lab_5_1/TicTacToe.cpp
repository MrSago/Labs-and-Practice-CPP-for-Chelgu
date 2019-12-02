#include "TicTacToe.h"

Board BoardApp;
WinType WinCheckApp = NONE;

int __stdcall WinMain()
{
	Lab51::TicTacToe^ App = gcnew Lab51::TicTacToe;
	System::Windows::Forms::Application::Run(App);
	return 0;
}