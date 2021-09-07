#include "MenuButton.h"

using namespace godot;
using namespace pong;

void MenuButton::_register_methods()
{
    register_property<MenuButton, godot::String>("scene", &MenuButton::scenePath, "");
}

MenuButton::MenuButton()
{
}

MenuButton::~MenuButton()
{
}

void MenuButton::_init()
{
}

void MenuButton::Ready()
{
}

void MenuButton::Process()
{
}

void MenuButton::onPressed()
{
}