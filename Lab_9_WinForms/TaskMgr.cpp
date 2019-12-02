#include "TaskMgr.h"


int __stdcall WinMain()
{
	Lab9WinForms::TaskMgr^ App = gcnew Lab9WinForms::TaskMgr;
	System::Windows::Forms::Application::Run(App);
	return 0;
}