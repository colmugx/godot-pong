#include "scene/HUD.h"
#include "scene/TitleScreen.h"
#include "scene/MenuButton.h"
#include "scene/World.h"
#include "sprite/Ball.h"
#include "sprite/Paddle.h"
#include "sprite/AI.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o)
{
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o)
{
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
    godot::Godot::nativescript_init(handle);

    godot::register_class<pong::MenuButton>();
    godot::register_class<pong::TitleScreen>();
    godot::register_class<pong::World>();
    godot::register_class<pong::HUD>();

    godot::register_class<pong::Ball>();
    godot::register_class<pong::Paddle>();
    godot::register_class<pong::AI>();
}
