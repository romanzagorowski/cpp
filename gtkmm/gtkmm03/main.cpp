#include "pch.h"
#include "mywindow.h"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    MyWindow win;
    //win.set_default_size(800, 600);

    return app->run(win);
}

