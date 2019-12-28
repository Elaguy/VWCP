#include "startUI.h"
#include <iostream>

using namespace std;

StartUI::StartUI() {
    set_title("VWCP-UI");
    
    set_border_width(75);

    set_default_size(800, 480);
}

StartUI::~StartUI() {

}

void StartUI::onButtonClicked() {
    cout << "Hello World [Test]" << endl; 
}
