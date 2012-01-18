#ifndef MAIN_H_
#define MAIN_H_

#include "wx/wx.h"

class BlueMain: public wxApp
{
    virtual bool OnInit();
    
    wxFrame * mainFrame;
};

DECLARE_APP(BlueMain)

#endif
