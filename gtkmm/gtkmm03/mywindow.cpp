#include "pch.h"
#include "mywindow.h"

MyWindow::MyWindow()
{
    this->button.set_label(this->button.get_active() ? "Down" : "Up");

    this->button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
    this->button.signal_toggled().connect(sigc::mem_fun(*this, &MyWindow::on_button_toggled));

    this->set_border_width(10);
    this->add(this->button);
    this->show_all_children();
}

void MyWindow::on_button_clicked()
{
    //std::cout << "void MyWindow::on_button_clicked()" << std::endl;
}

void MyWindow::on_button_toggled()
{
    auto is_active = this->button.get_active();

    std::cout << "toggled: get_active() returned " << this->button.get_active() << std::endl;

    this->button.set_label(is_active ? "Down" : "Up");
}

