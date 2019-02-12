#include "pch.h"
#include "mywindow.h"

MyWindow::MyWindow() :
    button1("Radio button #1"),
    button2("Radio button #2"),
    button3("Radio button #3"),
    box0(Gtk::ORIENTATION_VERTICAL),
    box1(Gtk::ORIENTATION_VERTICAL, 10),
    box2(Gtk::ORIENTATION_VERTICAL, 10),
    close("Close")
{
    //this->button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
    //this->button.signal_toggled().connect(sigc::mem_fun(*this, &MyWindow::on_button_toggled));

    this->set_title("Radio buttons");
    this->set_border_width(0);

    // Put radio buttons 2 and 3 in the same group as button 1
    this->button2.join_group(this->button1);
    this->button3.join_group(this->button1);

    // Add outer box to the window (because the window can only contain a single widget)
    this->add(this->box0);

    // Put the inner boxes and the separator in the outer box
    this->box0.pack_start(this->box1);
    this->box0.pack_start(this->separator);
    this->box0.pack_start(this->box2);

    // Set the inner boxes' borders
    this->box1.set_border_width(10);
    this->box2.set_border_width(10);

    // Put the radio buttons in box1
    this->box1.pack_start(this->button1);
    this->box1.pack_start(this->button2);
    this->box1.pack_start(this->button3);

    // Set the second button active
    this->button2.set_active();

    // Put Close button in box2
    this->box2.pack_start(this->close);

    // Make the Close button the default widget
    this->close.set_can_default();
    this->close.grab_default();

    // Connect to the Close button's clicked signal
    this->close.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));

    // Show all children of thw window
    this->show_all_children();
}

void MyWindow::on_button_clicked()
{
    std::cout << "void MyWindow::on_button_clicked()" << std::endl;

    this->hide();
}

/*
void MyWindow::on_button_toggled()
{
    std::cout << "toggled: get_active() returned " << this->button.get_active() << std::endl;
}
*/


