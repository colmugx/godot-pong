#pragma once

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>
#include <Input.hpp>

namespace pong
{

    class Ball : public godot::KinematicBody2D
    {
        GODOT_CLASS(Ball, godot::KinematicBody2D)

        godot::Input *_input;
        godot::Vector2 *_velocity;

    public:
        double speed;

        static void _register_methods();

        Ball();
        ~Ball();
        void _init();

        void Ready();

        void PhysicsProcess(double delta);

        void Reset(double dir);
    };

}
