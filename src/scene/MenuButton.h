#pragma once

#include <Godot.hpp>
#include <Button.hpp>

namespace pong
{
    class MenuButton : public godot::Button
    {
        GODOT_CLASS(MenuButton, godot::Button)


    public:
        godot::String scenePath;

        static void _register_methods();

        MenuButton();
        ~MenuButton();
        void _init();

        void Ready();
        void Process();

        void onPressed();
    };
}
