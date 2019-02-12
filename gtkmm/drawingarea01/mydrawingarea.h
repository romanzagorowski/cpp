#pragma once

#include "pch.h"

class MyDrawingArea : public Gtk::DrawingArea
{
private:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};

