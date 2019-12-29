#include "startUI.h"
#include <iostream>

using namespace std;

StartUI::StartUI()
    : mainBox(Gtk::ORIENTATION_VERTICAL),
      bkgd("img/bkgd_cropped.jpg")
{
    basicSetup();
    addMainWidgets();
}

StartUI::~StartUI() {

}

void StartUI::basicSetup() {
    set_title("VWCP-UI");
    
    set_size_request(800, 480);
    
    set_resizable(false);
}

void StartUI::addMainWidgets() {
    topbar.set_name("topbar");
    topbar.set_size_request(800, 48);
    
    bodyBox.set_name("bodyBox");
    bodyBox.set_size_request(800, 432);
    
    setCSS(topbar, "startUIStyle.css");
    setCSS(bodyBox, "startUIStyle.css");

    mainBox.pack_start(topbar);
    mainBox.pack_start(bodyBox);

    mainOverlay.add(bkgd);
    mainOverlay.add_overlay(mainBox);
    add(mainOverlay);

    bkgd.show();
    topbar.show();
    bodyBox.show();
    mainBox.show();
    mainOverlay.show();
}

// associates the css file pointed to by 'filename' with the given 'widget'
void StartUI::setCSS(const Gtk::Widget& widget, const Glib::ustring& filename) {
    Glib::RefPtr<Gtk::StyleContext> styleContext = widget.get_style_context();
    Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();

    cssProvider->load_from_path(filename);
    styleContext->add_provider(cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);
    styleContext->context_save();
}
