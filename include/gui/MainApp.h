#ifndef Main_L
#define Main_L

#include "wx/wx.h"

class MainApp: public wxApp
{
    virtual bool OnInit();
    
    wxFrame * main_frame;
};

DECLARE_APP(MainApp)

#endif

