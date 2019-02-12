#include "pch.h"
#include "mywindow.h"

MyWindow::MyWindow()
{
    this->set_title("menus01");
    this->set_default_size(1024, 786);

    this->add(this->drawingArea);
    this->show_all();
}

