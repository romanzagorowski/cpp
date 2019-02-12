#include "pch.h"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    // Load the GtkBuilder file and instantiate its widgets
    auto builder = Gtk::Builder::create();

    try
    {
        builder->add_from_file("glade01.glade");
    }
    catch(const Glib::FileError& ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Glib::MarkupError& ex)
    {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Gtk::BuilderError& ex)
    {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 1;
    }

    Gtk::Window* win;

    builder->get_widget("main_window", win);
    // std::assert(nullptr != win);

    if(nullptr != win)
    {
        std::cout << "The 'main_window' widget got successfully!" << std::endl;

        app->run(*win);

        delete win;
    }
    else
    {
        std::cerr << "Failed to get 'main_window' widget..." << std::endl;
    }

    return 0;
}

