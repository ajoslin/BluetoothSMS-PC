#include <gui/Main.h>
#include <gui/BlueFrame.h>
#include <appstrings.h>

bool BlueMain::OnInit()
{
	mainFrame = new BlueFrame(wxT(STR_TITLE));
	mainFrame->SetSize(650,575);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}
IMPLEMENT_APP(BlueMain)