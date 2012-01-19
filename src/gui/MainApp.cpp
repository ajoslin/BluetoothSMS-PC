#include "gui/MainApp.h"
#include "gui/MainFrame.h"
#include "appstrings.h"

bool MainApp::OnInit()
{
	main_frame = new MainFrame(wxT(STR_TITLE));
	main_frame->SetSize(650,575);
	main_frame->Show(true);
	SetTopWindow(main_frame);

	return true;
}

IMPLEMENT_APP(MainApp)
