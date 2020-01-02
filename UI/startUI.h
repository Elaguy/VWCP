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
#include <gtkmm/label.h>
#include <gtkmm/button.h>

class StartUI : public Gtk::ApplicationWindow {
 public:
    StartUI();
    virtual ~StartUI();
    
    int getAppWidth();
    int getAppHeight();
    
 protected:
    void basicSetup();
    void addMainWidgets();
    void setCSS(const Gtk::Widget& widget, const Glib::ustring& filename);
    
    // overrides:
    
    // signal handlers:
    
    // member widgets:
    Gtk::Overlay mainOverlay;
    Gtk::Box mainBox;

    Gtk::Box topbar;
    Gtk::Label vwcpLabel;
    Gtk::Label dateLabel;

    Gtk::Box bodyContainer;
    Gtk::Box body;
    Gtk::Label greetingLabel;
    Gtk::Label timeLabel;
    Gtk::Button driveButton;
    Gtk::Box warningBox;
    Gtk::Image warningSym;
    Gtk::Label warningLabel;
    
    Gtk::Image bkgd;
    
 private:
    const int APP_WIDTH;
    const int APP_HEIGHT;
};

#endif
