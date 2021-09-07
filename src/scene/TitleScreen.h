#pragma once

#include <Godot.hpp>
#include <Control.hpp>
#include <LinkButton.hpp>
#include <SceneTree.hpp>
#include <OS.hpp>

#include "MenuButton.h"

namespace pong
{
    class TitleScreen : public godot::Control
    {
        GODOT_CLASS(TitleScreen, godot::Control)

        godot::LinkButton *_githubLink;
        MenuButton *_menuButton;

    public:
        static void _register_methods();

        TitleScreen();
        ~TitleScreen();
        void _init();

        void Ready();
        void Process();

        void onNewGamePressed(godot::String path);
        void onGithubLinkPressed();
    };
}
