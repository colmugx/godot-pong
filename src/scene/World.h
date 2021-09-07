#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <AnimationPlayer.hpp>
#include <Timer.hpp>
#include <Label.hpp>

#include "sprite/Ball.h"
#include "sprite/Paddle.h"
#include "HUD.h"

namespace pong
{
    enum EDirection
    {
        LEFT,
        RIGHT
    };

    class World : public godot::Node2D
    {
        GODOT_CLASS(World, godot::Node2D)

        godot::AnimationPlayer *_maskPlayer;
        godot::AnimationPlayer *_hudPlayer;
        godot::Timer *_countDownTimer;
        godot::Label *_countDownLabel;

        Ball *_ball;
        Paddle *_paddle;
        HUD *_hud;

        EDirection direction;

    public:
        static void _register_methods();

        World();
        ~World();
        void _init();

        void Ready();
        void Process(double delta);

        void ResetGame();

        void OnLeftGoal(godot::Node2D *body);
        void OnRightGoal(godot::Node2D *body);
        void OnFadeInFinished();
        void OnCountDown();
    };

}
