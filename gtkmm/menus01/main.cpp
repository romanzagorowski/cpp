#include "pch.h"
#include "mywindow.h"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    MyWindow win;

    return app->run(win);
}

