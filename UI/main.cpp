#include "startUI.h"
#include <gtkmm/application.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "schultz.vwcp.startUI");

    StartUI startUI;
    
    return app->run(startUI);
}
