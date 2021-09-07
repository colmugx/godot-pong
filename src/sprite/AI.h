#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>
#include <CollisionShape2D.hpp>

namespace pong
{

    class AI : public godot::KinematicBody2D
    {
        GODOT_CLASS(AI, godot::KinematicBody2D)

        godot::CollisionShape2D *_collisionShape;
        godot::Node2D *_ball;

    public:
        double _speed;

        static void _register_methods();

        AI();
        ~AI();
        void _init();

        void Ready();

        void PhysicsProcess(double delta);

        double GetDirection();
    };

}
