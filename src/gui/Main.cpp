#include "Main.h"
#include "BlueFrame.h"
#include "defines.h"

bool BlueMain::OnInit()
{
	mainWindow = new BlueFrame(wxT(STR_TITLE));
	mainWindow->SetSize(650,575);
	mainWindow->Show(true);
	SetTopWindow(mainWindow);
}

IMPLEMENT_APP(BlueMain)