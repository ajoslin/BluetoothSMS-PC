#include "gui/MainApp.h"
#include "gui/MainFrame.h"
#include "appstrings.h"
#include "gui/dimensions.h"

bool MainApp::OnInit()
{
	main_frame = new MainFrame(wxT(STR_TITLE));
	main_frame->SetSize(DIM_MAINWINDOW_W, DIM_MAINWINDOW_H);
	main_frame->Show(true);
	SetTopWindow(main_frame);

	return true;
}

IMPLEMENT_APP(MainApp)
