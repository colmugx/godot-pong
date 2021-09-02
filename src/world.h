#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>

#include "ball.h"
#include "paddle.h"

namespace pong
{
    class World : public godot::Node2D
    {
        GODOT_CLASS(World, godot::Node2D)

        Ball *_ball;
        Paddle *_paddle;

    public:
        static void _register_methods();

        World();
        ~World();
        void _init();

        void Ready();

        void OnLeftGoal(godot::Node2D *body);
        void OnRightGoal(godot::Node2D *body);
    };

}
