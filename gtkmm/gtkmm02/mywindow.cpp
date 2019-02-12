#include "pch.h"
#include "mywindow.h"

MyWindow::MyWindow()
{
    this->button.add_pixlabel("info.xpm", "Cool button");

    this->button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
    this->set_title("Pixmap'd buttons!");
    this->set_border_width(10);
    this->add(this->button);
    this->show_all_children();
}

void MyWindow::on_button_clicked()
{
    std::cout << "void MyWindow::on_button_clicked()" << std::endl;
}

