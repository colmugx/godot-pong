#include "Paddle.h"

using namespace godot;
using namespace pong;

void Paddle::_register_methods()
{
    register_property("speed", &Paddle::speed, 200.0);

    register_method("_physics_process", &Paddle::PhysicsProcess);
    register_method("_ready", &Paddle::Ready);
}

Paddle::Paddle() {}
Paddle::~Paddle() {}

void Paddle::_init()
{
    _input = Input::get_singleton();
    speed = 200.0;
}

void Paddle::Ready()
{
}

void Paddle::PhysicsProcess(const double delta)
{
    Vector2 *vec = new Vector2(0.0, 0.0);

    if (_input->is_action_pressed("ui_down"))
    {
        ++vec->y;
    }
    if (_input->is_action_pressed("ui_up"))
    {
        --vec->y;
    }

    if (vec->length() > 0.0)
    {
        *vec = vec->normalized() * speed;
    }

    move_and_collide(*vec * delta);
}