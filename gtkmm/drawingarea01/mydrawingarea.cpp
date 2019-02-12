#include "mydrawingarea.h"


bool MyDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    Gtk::Allocation a = this->get_allocation();

    const int w = a.get_width();
    const int h = a.get_height();

    std::cout << "on_draw: width=" << w << ", height=" << h << std::endl;

    cr->set_source_rgb(0.0, 0.0, 0.0);
    cr->paint();

    return true;
}

