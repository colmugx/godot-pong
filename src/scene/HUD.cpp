#include "HUD.h"

using namespace godot;
using namespace pong;

void HUD::_register_methods()
{
    register_method("_ready", &HUD::Ready);
    register_method("_process", &HUD::Process);

    register_method("LeftIncrease", &HUD::LeftIncrease);
    register_method("RightIncrease", &HUD::RightIncrease);
}

HUD::HUD() {}
HUD::~HUD() {}

void HUD::_init()
{
}

void HUD::Ready()
{
    _leftScore = 0, _rightScore = 0;
    _leftLabel = get_node<Label>("LeftScore");
    _rightLebel = get_node<Label>("RightScore");
}

void HUD::Process()
{
    _leftLabel->set_text(String::num_int64(_leftScore));
    _rightLebel->set_text(String::num_int64(_rightScore));
}

void HUD::LeftIncrease()
{
    ++_leftScore;
}

void HUD::RightIncrease()
{
    ++_rightScore;
}
