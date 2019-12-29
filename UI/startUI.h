#ifndef STARTUI_H
#define STARTUI_H

#include <gtkmm/window.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/box.h>
#include <gtkmm/toolbar.h>
#include <gtkmm/button.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/widget.h>
#include <glibmm/ustring.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/image.h>
#include <gtkmm/overlay.h>
#include <gtkmm/scrolledwindow.h>

class StartUI : public Gtk::ApplicationWindow {
 public:
    StartUI();
    virtual ~StartUI();

 protected:
    void basicSetup();
    void addMainWidgets();
    void setCSS(const Gtk::Widget& widget, const Glib::ustring& filename);
    
    // signal handlers:
    
    // member widgets:
    Gtk::Overlay mainOverlay;
    Gtk::Box mainBox;
    Gtk::Toolbar topbar;
    Gtk::Box bodyBox;
    Gtk::Image bkgd;
};

#endif
