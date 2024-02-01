#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
class SkySphere :
    public GameObject
{
    int hSkySphere;

    SkySphere();
    void Initialize();
    void Draw();
    void Rerease();
};

