#include<vector>
#include"libOne.h"
float a = 1, b = -4, c = 3, d =0;
float cubic(float x) {
    return
        a * x * x * x +
        b * x * x +
        c * x +
        d;
}
void gmain()
{
    window(1920, 1080, full);
    //Colors
    colorMode(HSV, 100);
    angleMode(DEGREES);
    COLOR black(0, 0, 0);
    COLOR white(0, 0, 100);
    COLOR gray(0, 0, 50);
    COLOR red(330, 100, 100);
    COLOR yellow(65, 100, 80);
    COLOR rainbow;
    int img = loadImage("cubic.png");
    //Main Loop
    while (notQuit) {
        if (isTrigger(KEY_Q))a += 1.f;
        if (isTrigger(KEY_A))a -= 1.f;
        if (isTrigger(KEY_W))b += 1.f;
        if (isTrigger(KEY_S))b -= 1.f;
        if (isTrigger(KEY_E))c += 1.f;
        if (isTrigger(KEY_D))c -= 1.f;
        if (isTrigger(KEY_R))d += 1.f;
        if (isTrigger(KEY_F))d -= 1.f;
        if (isTrigger(KEY_SPACE))a = b = c = d = 0;

        clear(900, 100, 0);
        mathAxis(8.9f,100);
        float x = -10;
        float dt = 0.01f;
        VECTOR sp(x,cubic(x));
        for (x += dt; x <= 10; x += dt) {
            VECTOR ep(x, cubic(x));
            stroke(360 * (x - dt)/10, 50, 100);
            strokeWeight(5);
            mathLine(sp.x, sp.y, ep.x, ep.y);
            sp = ep;
        }
        image(img, 0, 0, 0, 1);
        fill(white); printPosX(50); printPosY(80);
        print((let)"a=" + a);
        print((let)"b=" + b);
        print((let)"c=" + c);
        print((let)"d=" + d);
    }
}
