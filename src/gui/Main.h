#ifndef MAIN_H_
#define MAIN_H_

#include "wx/wx.h"
#include "Main.h"

class BlueMain: public wxApp
{
    virtual bool OnInit();
    
    wxFrame * mainWindow;
};

DECLARE_APP(BlueMain)

#endif
