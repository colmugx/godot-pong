#include "TitleScreen.h"

using namespace godot;
using namespace pong;

void TitleScreen::_register_methods()
{
    register_method("_ready", &TitleScreen::Ready);
    register_method("_process", &TitleScreen::Process);

    register_method("_on_button_pressed", &TitleScreen::onNewGamePressed);
    register_method("_on_githublink_pressed", &TitleScreen::onGithubLinkPressed);
}

TitleScreen::TitleScreen() {}
TitleScreen::~TitleScreen() {}

void TitleScreen::_init()
{
}

void TitleScreen::Ready()
{
    _githubLink = get_node<LinkButton>("Menu/GithubLink");

    // TODO: 多菜单后改为遍历处理
    _menuButton = get_node<MenuButton>("Menu/Row/Buttons/NewGame");
    Array params{};
    params.push_back(_menuButton->scenePath);
    _menuButton->connect("pressed", this, "_on_button_pressed", params);
}

void TitleScreen::Process()
{
}

void TitleScreen::onNewGamePressed(godot::String path)
{
    get_tree()->change_scene(path);
}

void TitleScreen::onGithubLinkPressed()
{
    OS::get_singleton()->shell_open("https://github.com/colmugx/godot-pong");
}