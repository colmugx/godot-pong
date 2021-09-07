#pragma once

#include <Godot.hpp>
#include <CanvasLayer.hpp>
#include <Label.hpp>

namespace pong
{

    class HUD : public godot::CanvasLayer
    {
        GODOT_CLASS(HUD, godot::CanvasLayer)

        godot::Label *_leftLabel;
        godot::Label *_rightLebel;

        int _leftScore;
        int _rightScore;

    public:
        static void _register_methods();

        HUD();
        ~HUD();
        void _init();

        void Ready();
        void Process();

        void LeftIncrease();
        void RightIncrease();
    };

}
