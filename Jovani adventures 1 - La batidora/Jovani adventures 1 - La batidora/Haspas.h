#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include<math.h>

#define _USE_MATH_DEFINES

class Helice
{
public:
    Helice();
    ~Helice();
    int direccion(int variable)
    {
        int i = variable;
        while (i != 0) {
            variable = (i * M_PI) / 180;
            if (variable == 360)
            {
                i = 0;
            }
            i++;
        }
        return variable;
    }
    int changespeed(int newspeed) {
        speed = speed + newspeed;
    };
    int changehigh(int newhigh) {
        high = high + newhigh;
    }
    int changewidth(int newwidth) {
        width = width + newwidth;
    }
    bool Init();
    void Release();

    bool Input();
    bool Update();
    void Draw();

private:

    int speed;
    int high;
    int width;
};