#pragma once

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>
#include <Input.hpp>

namespace pong
{

    class Paddle : public godot::KinematicBody2D
    {
        GODOT_CLASS(Paddle, godot::KinematicBody2D)

        godot::Input *_input;

    public:
        double speed;

        static void _register_methods();

        Paddle();
        ~Paddle();
        void _init();

        void Ready();

        void PhysicsProcess(double delta);
    };

}
