#include "labyrinth.h"
#include <iostream>

static Pixel blend(Pixel oldPixel, Pixel newPixel)
{
    newPixel.r = newPixel.a / 255.0 * (newPixel.r - oldPixel.r) + oldPixel.r;
    newPixel.g = newPixel.a / 255.0 * (newPixel.g - oldPixel.g) + oldPixel.g;
    newPixel.b = newPixel.a / 255.0 * (newPixel.b - oldPixel.b) + oldPixel.b;
    newPixel.a = 255;

    return newPixel;
}

void nothing::Draw(Image &screen)
{
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            screen.PutPixel(x, y, backgroundColor);
        }
    }
}

void Path_1::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x, y - coords.y);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Wall_1::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 132, y - coords.y);
            screen.PutPixel(x, y, pix);
            //screen.PutType(x, y, 1);
        }
    }
}

void Wall_2::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 132, y - coords.y + 100);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Path_2::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x, y - coords.y + 100);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Wall_3::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 132, y - coords.y + 193);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Path_3::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x, y - coords.y + 200);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Wall_4::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 132, y - coords.y + 293);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Path_4::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x, y - coords.y + 300);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Door_1::Draw(Image &screen)
{
    static Image floor("resources/doors.png");
    static int shift_y = 0;
    static int shift_x = 0;
    for (int y = coords.y; y <= coords.y + 52; ++y)
    {
        for (int x = coords.x; x <= coords.x + 32; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 33, y - coords.y + 48);
            screen.PutPixel(coords.x + shift_x, coords.y + shift_y, pix);
            shift_y++;
        }
        shift_x++;
        shift_y = 0;
    }
}

void Door_2::Draw(Image &screen)
{
    static Image floor("resources/doors.png");
    static int shift_y = 0;
    static int shift_x = 0;
    for (int y = coords.y; y <= coords.y + 52; ++y)
    {
        for (int x = coords.x; x <= coords.x + 32; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 94, y - coords.y + 48);
            screen.PutPixel(coords.x + shift_x, coords.y + shift_y, pix);
            shift_y++;
        }
        shift_x++;
        shift_y = 0;
    }
}

void Door_3::Draw(Image &screen)
{
    static Image floor("resources/doors.png");
    static int shift_y = 0;
    static int shift_x = 0;
    for (int y = coords.y; y <= coords.y + 52; ++y)
    {
        for (int x = coords.x; x <= coords.x + 32; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 190, y - coords.y + 48);
            screen.PutPixel(coords.x + shift_x, coords.y + shift_y, pix);
            shift_y++;
        }
        shift_x++;
        shift_y = 0;
    }
}

void Door_4::Draw(Image &screen)
{
    static Image floor("resources/doors.png");
    static int shift_y = 0;
    static int shift_x = 0;
    for (int y = coords.y; y <= coords.y + 52; ++y)
    {
        for (int x = coords.x; x <= coords.x + 33; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 287, y - coords.y + 190);
            screen.PutPixel(coords.x + shift_x, coords.y + shift_y, pix);
            shift_y++;
        }
        shift_x++;
        shift_y = 0;
    }
}

void Trap_1::Draw(Image &screen)
{
    static Image floor("resources/Obstacles.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 62; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 448, y - coords.y + 350);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Trap_2::Draw(Image &screen)
{
    static Image floor("resources/Obstacles.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 62; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 385, y - coords.y + 250);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Bush_1::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 262, y - coords.y + 50);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Bush_2::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 262, y - coords.y + 150);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Bush_3::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 31; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 262, y - coords.y + 250);
            screen.PutPixel(x, y, pix);
        }
    }
}

void Bush_4::Draw(Image &screen)
{
    static Image floor("resources/pole.png");
    for (int y = coords.y; y <= coords.y + 30; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 262, y - coords.y + 345);
            screen.PutPixel(x, y, pix);
        }
    }
}