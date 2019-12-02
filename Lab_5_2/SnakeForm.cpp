#include "SnakeForm.h"


int __stdcall WinMain()
{
	Lab52::SnakeForm^ App = gcnew Lab52::SnakeForm;
	System::Windows::Forms::Application::Run(App);
	return 0;
}