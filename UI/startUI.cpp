#include "startUI.h"
#include <iostream>

using namespace std;

StartUI::StartUI()
    : mainBox(Gtk::ORIENTATION_VERTICAL),
      topbar(Gtk::ORIENTATION_HORIZONTAL),
      vwcpLabel("VWCP", Gtk::Align::ALIGN_START, Gtk::Align::ALIGN_CENTER),
      dateLabel("Monday, Dec 23 2019", Gtk::Align::ALIGN_END, Gtk::Align::ALIGN_CENTER),
      bodyContainer(Gtk::ORIENTATION_VERTICAL),
      body(Gtk::ORIENTATION_VERTICAL),
      greetingLabel("Good Morning", Gtk::Align::ALIGN_CENTER, Gtk::Align::ALIGN_START),
      timeLabel("10:00 am", Gtk::Align::ALIGN_CENTER, Gtk::Align::ALIGN_START),
      driveButton("Drive"),
      warningBox(Gtk::ORIENTATION_HORIZONTAL),
      warningSym("img/warningSym.png"),
      warningLabel("Always drive safe and do not drive distracted.", Gtk::Align::ALIGN_START, Gtk::Align::ALIGN_CENTER),
      bkgd("img/bkgd_cropped.jpg"),
      APP_WIDTH(800),
      APP_HEIGHT(480)
{
    basicSetup();
    addMainWidgets();
}

StartUI::~StartUI() {

}

int StartUI::getAppWidth() {
    return APP_WIDTH;
}

int StartUI::getAppHeight() {
    return APP_HEIGHT;
}

void StartUI::basicSetup() {
    set_title("VWCP-UI");
    
    set_size_request(APP_WIDTH, APP_HEIGHT);
    
    set_resizable(false);

    //fullscreen();
}

void StartUI::addMainWidgets() {
    topbar.set_name("topbar");
    topbar.set_size_request(APP_WIDTH, APP_HEIGHT * 0.10);

    vwcpLabel.set_name("vwcpLabel");
    vwcpLabel.set_padding(10, 0);

    dateLabel.set_name("dateLabel");
    dateLabel.set_padding(10, 0);
    
    topbar.pack_start(vwcpLabel);
    topbar.pack_start(dateLabel);

    bodyContainer.set_name("bodyContainer");
    bodyContainer.set_size_request(APP_WIDTH, APP_HEIGHT * 0.90);
    
    body.set_name("body");
    body.set_size_request(APP_WIDTH, APP_HEIGHT * 0.90);
    body.set_halign(Gtk::Align::ALIGN_CENTER);
    body.set_valign(Gtk::Align::ALIGN_CENTER);
    body.set_spacing(APP_HEIGHT * 0.10);
    
    bodyContainer.pack_start(body);
    
    greetingLabel.set_name("greetingLabel");
    //greetingLabel.set_padding(0, 46);

    timeLabel.set_name("timeLabel");
    //timeLabel.set_padding();

    driveButton.set_name("driveButton");
    driveButton.set_halign(Gtk::Align::ALIGN_CENTER);
    driveButton.set_valign(Gtk::Align::ALIGN_START);
    driveButton.get_child()->set_name("driveButtonLabel");
    driveButton.set_size_request(208, 42);
    driveButton.signal_clicked().connect(sigc::mem_fun(*this,
						       &StartUI::onDriveButtonClicked));
    //driveButton.set_padding();

    warningBox.set_name("warningBox");
    warningBox.set_halign(Gtk::Align::ALIGN_CENTER);
    warningBox.set_valign(Gtk::Align::ALIGN_START);
    warningBox.set_spacing(15);
    
    warningSym.set_alignment(Gtk::Align::ALIGN_START, Gtk::Align::ALIGN_CENTER);
    //warningSym.set_padding();
    
    warningLabel.set_name("warningLabel");
    //warningLabel.set_padding();

    warningBox.pack_start(warningSym);
    warningBox.pack_start(warningLabel);
    
    body.pack_start(greetingLabel);
    body.pack_start(timeLabel);
    body.pack_start(driveButton);
    body.pack_start(warningBox);
    
    setCSS(topbar, "startUIStyle.css");
    setCSS(vwcpLabel, "startUIStyle.css");
    setCSS(dateLabel, "startUIStyle.css");

    setCSS(bodyContainer, "startUIStyle.css");
    setCSS(body, "startUIStyle.css");
    setCSS(greetingLabel, "startUIStyle.css");
    setCSS(timeLabel, "startUIStyle.css");
    setCSS(driveButton, "startUIStyle.css");
    setCSS(*(driveButton.get_child()), "startUIStyle.css");
    setCSS(warningBox, "startUIStyle.css");
    setCSS(warningLabel, "startUIStyle.css");
    
    mainBox.pack_start(topbar);
    mainBox.pack_start(bodyContainer);
    
    mainOverlay.add(bkgd);
    mainOverlay.add_overlay(mainBox);
    add(mainOverlay);

    bkgd.show();
    topbar.show();
    vwcpLabel.show();
    dateLabel.show();
    bodyContainer.show();
    body.show();
    greetingLabel.show();
    timeLabel.show();
    driveButton.show();
    warningBox.show();
    warningSym.show();
    warningLabel.show();
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

void StartUI::onDriveButtonClicked() {
    cout << "driveButton clicked! [TEST]" << endl;
}
