#include "world.h"

using namespace godot;
using namespace pong;

void World::_register_methods()
{
    register_method("_ready", &World::Ready);

    register_method("_on_LeftGoal_exited", &World::OnRightGoal);
    register_method("_on_RightGoal_exited", &World::OnLeftGoal);
}

World::World() {}
World::~World() {}

void World::_init()
{
}

void World::Ready()
{
    _ball = get_node<Ball>("Ball");
    _paddle = get_node<Paddle>("LeftPaddle");
}

void World::OnLeftGoal(Node2D *body)
{
    Godot::print("Left Goal");
    _ball->Reset(1.0);
}

void World::OnRightGoal(Node2D *body)
{
    Godot::print("Right Goal");
    _ball->Reset(-1.0);
}