#include "startUI.h"
#include <iostream>

using namespace std;

StartUI::StartUI()
    : mainBox(Gtk::ORIENTATION_VERTICAL),
      bkgd("img/bkgd.jpg")
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
    mainLayout.set_size(800, 480);

    add(mainLayout);
    
    topbar.set_name("topbar");
    topbar.set_size_request(800, 48);
    
    body.set_name("body");
    body.set_size_request(800, 432);
    
    setCSS(topbar, "startUIStyle.css");
    setCSS(body, "startUIStyle.css");

    mainBox.pack_start(topbar);
    mainBox.pack_start(body);

    mainLayout.add(mainBox);
    
    topbar.show();
    body.show();
    mainBox.show();
    mainLayout.show();
}

// associates the css file pointed to by 'filename' with the given 'widget'
void StartUI::setCSS(const Gtk::Widget& widget, const Glib::ustring& filename) {
    Glib::RefPtr<Gtk::StyleContext> styleContext = widget.get_style_context();
    Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();

    cssProvider->load_from_path(filename);
    styleContext->add_provider(cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);
    styleContext->context_save();
}
