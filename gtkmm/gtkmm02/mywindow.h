#pragma once

class MyWindow : public Gtk::Window
{
public:
    MyWindow();

protected:
    void on_button_clicked();

private:
    Gtk::Button button;
};

