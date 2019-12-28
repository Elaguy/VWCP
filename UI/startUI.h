#ifndef STARTUI_H
#define STARTUI_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/applicationwindow.h>

class StartUI : public Gtk::ApplicationWindow {
 public:
    StartUI();
    virtual ~StartUI();

 protected:
    // signal handlers:
    void onButtonClicked();

    // member widgets:
    Gtk::Button button;
};

#endif
