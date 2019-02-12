#pragma once

#include "mydrawingarea.h"

class MyWindow : public Gtk::Window
{
public:
    MyWindow();

private:
    MyDrawingArea drawingArea;
};

