#include "World.h"

using namespace godot;
using namespace pong;

void World::_register_methods()
{
    register_method("_process", &World::Process);
    register_method("_ready", &World::Ready);

    register_method("_on_fadeIn_finished", &World::OnFadeInFinished);
    register_method("_on_countDown_timeout", &World::OnCountDown);

    register_method("_on_LeftGoal_exited", &World::OnRightGoal);
    register_method("_on_RightGoal_exited", &World::OnLeftGoal);
}

World::World() {}
World::~World() {}

void World::_init()
{
    direction = LEFT;
}

void World::Ready()
{
    _ball = get_node<Ball>("Ball");
    _paddle = get_node<Paddle>("LeftPaddle");
    _hud = get_node<HUD>("HUD");
    _maskPlayer = get_node<AnimationPlayer>("Mask/AnimationPlayer");
    _hudPlayer = get_node<AnimationPlayer>("HUD/AnimationPlayer");
    _countDownTimer = get_node<Timer>("CountDownTimer");
    _countDownLabel = get_node<Label>("CountDownLabel");

    // 执行入场动画
    _maskPlayer->play("fadeIn");
}

void World::Process(const double delta)
{
    _countDownLabel->set_text(String::num_int64(_countDownTimer->get("time_left")));
}

void World::ResetGame()
{
    _ball->Reset(0.0, 0.0);
    _countDownTimer->start();
}

void World::OnLeftGoal(Node2D *body)
{
    _hud->LeftIncrease();
    direction = RIGHT;
    ResetGame();
}

void World::OnRightGoal(Node2D *body)
{
    _hud->RightIncrease();
    direction = LEFT;
    ResetGame();
}

void World::OnFadeInFinished()
{
    _hudPlayer->play("show");
    ResetGame();
}

void World::OnCountDown()
{
    double dir = 0.0;
    switch (direction)
    {
    case LEFT:
        dir = -1.0;
        break;
    case RIGHT:
        dir = 1.0;
        break;
    }

    _ball->Reset(dir);
}