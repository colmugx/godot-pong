#include "Ball.h"

using namespace godot;
using namespace pong;

void Ball::_register_methods()
{
    register_property("speed", &Ball::speed, 200.0);
    register_method("_physics_process", &Ball::PhysicsProcess);
    register_method("_ready", &Ball::Ready);

    register_method("Reset", &Ball::Reset);
}

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::_init()
{
    speed = 200.0;
    _velocity = new Vector2(0.0, 0.0);
}

void Ball::Ready()
{
}

void Ball::PhysicsProcess(const double delta)
{
    KinematicCollision2D *collision = *move_and_collide(*_velocity * delta * speed);
    if (collision != nullptr)
    {
        *_velocity = _velocity->bounce(collision->get_normal());
    }
}

void Ball::Reset(const double x, const double y)
{
    Vector2 ScreenSize = get_viewport_rect().size;
    set_position(Vector2(ScreenSize.width / 2, ScreenSize.height / 2));

    _velocity->x = x;
    _velocity->y = y;
}
