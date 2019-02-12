#pragma once

class MyWindow : public Gtk::Window
{
public:
    MyWindow();

protected:
    void on_button_clicked();

private:
    Gtk::RadioButton button1;
    Gtk::RadioButton button2;
    Gtk::RadioButton button3;

    Gtk::Box box0, box1, box2;
    Gtk::Separator separator;
    Gtk::Button close;
};

