#pragma once

class MyWindow : public Gtk::Window
{
public:
    MyWindow();

protected:
    void on_button_clicked();
    void on_button_toggled();

private:
    Gtk::ToggleButton button;
};

