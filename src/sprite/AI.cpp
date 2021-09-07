#include "AI.h"

using namespace godot;
using namespace pong;

void AI::_register_methods()
{
    register_property("speed", &AI::_speed, 200.0);

    register_method("_physics_process", &AI::PhysicsProcess);
    register_method("_ready", &AI::Ready);
}

AI::AI() {}
AI::~AI() {}

void AI::_init()
{
    _speed = 200.0;
}

void AI::Ready()
{
    _ball = get_node<Node2D>(NodePath("/root/World/Ball"));
}

void AI::PhysicsProcess(const double delta)
{
    move_and_collide(Vector2(0.0, GetDirection()) * _speed * delta);
}

double AI::GetDirection()
{
    Vector2 ballPos = _ball->get_position();
    Vector2 selfPos = get_position();

    if (abs(ballPos.y - selfPos.y) > 25.0)
    {
        return ballPos.y > selfPos.y ? 1.0 : -1.0;
    }
    else
    {
        return 0.0;
    }
}