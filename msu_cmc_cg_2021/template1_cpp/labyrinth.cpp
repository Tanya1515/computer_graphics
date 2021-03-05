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

void Thorns::Draw(Image &screen)
{
    static Image floor("resources/throns.png");
    for (int y = coords.y; y <= coords.y + 16; ++y)
    {
        for (int x = coords.x; x <= coords.x + 16; ++x)
        {
            Pixel pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y, pix);
            screen.PutType(x, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y + 16, pix);
            screen.PutType(x, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y + 16, pix);
            screen.PutType(x + 16, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y, pix);
            screen.PutType(x + 16, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y + 16, pix);
            screen.PutType(x + 33, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y, pix);
            screen.PutType(x + 33, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y, pix);
            screen.PutType(x + 50, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y + 16, pix);
            screen.PutType(x + 50, y + 16, 2);
        }
    }
}

void Thorns_t::Draw(Image &screen)
{
    static Image floor("resources/t.png");
    for (int y = coords.y; y <= coords.y + 16; ++y)
    {
        for (int x = coords.x; x <= coords.x + 16; ++x)
        {
            Pixel pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y, pix);
            screen.PutType(x, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y + 16, pix);
            screen.PutType(x, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y + 16, pix);
            screen.PutType(x + 16, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y, pix);
            screen.PutType(x + 16, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y + 16, pix);
            screen.PutType(x + 33, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y, pix);
            screen.PutType(x + 33, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y, pix);
            screen.PutType(x + 50, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y + 16, pix);
            screen.PutType(x + 50, y + 16, 2);
        }
    }
}

void Thorns_r::Draw(Image &screen)
{
    static Image floor("resources/r.png");
    for (int y = coords.y; y <= coords.y + 16; ++y)
    {
        for (int x = coords.x; x <= coords.x + 16; ++x)
        {
            Pixel pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y, pix);
            screen.PutType(x, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y + 16, pix);
            screen.PutType(x, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y + 16, pix);
            screen.PutType(x + 16, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y, pix);
            screen.PutType(x + 16, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y + 16, pix);
            screen.PutType(x + 33, y + 16, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y, pix);
            screen.PutType(x + 33, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y, pix);
            screen.PutType(x + 50, y, 2);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y + 16, pix);
            screen.PutType(x + 50, y + 16, 2);
        }
    }
}

void Thorns_h::Draw(Image &screen)
{
    static Image floor("resources/h.png");
    for (int y = coords.y; y <= coords.y + 16; ++y)
    {
        for (int x = coords.x; x <= coords.x + 16; ++x)
        {
            Pixel pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y, pix);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x, y + 16, pix);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y + 16, pix);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 16, y, pix);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y + 16, pix);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 33, y, pix);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y, pix);

            pix = blend(screen.data_save[y + 32 + x + 54], floor.GetPixel(x - coords.x, y - coords.y));
            screen.PutPixel(x + 50, y + 16, pix);
        }
    }
}

void end::Draw(Image &screen)
{
    static Image floor("resources/end.png");
    static int shift_y = 0;
    static int shift_x = 0;
    for (int y = coords.y; y <= coords.y + 52; ++y)
    {
        for (int x = coords.x; x <= coords.x + 32; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 385, y - coords.y + 6);
            screen.PutPixel(coords.x + shift_x, coords.y + shift_y, pix);
            shift_y++;
            screen.PutType(x, y, 3);
        }
        shift_x++;
        shift_y = 0;
    }
}

void win::Draw(Image &screen)
{
    static Image floor("resources/win.png");
    for (int y = coords.y; y <= coords.y + 280; ++y)
    {
        for (int x = coords.x; x <= coords.x + 440; ++x)
        {
            Pixel pix = blend(screen.data_save[y * screen.Width() + x], floor.GetPixel(x - coords.x, 280 - y + coords.y));
            screen.PutPixel(x, y, pix);
        }
    }
}

void game_over::Draw(Image &screen)
{
    static Image floor("resources/game_over.png");
    for (int y = coords.y; y <= coords.y + 273; ++y)
    {
        for (int x = coords.x; x <= coords.x + 552; ++x)
        {
            Pixel pix = blend(screen.data_save[y * screen.Width() + x], floor.GetPixel(x - coords.x, 273 - y + coords.y));
            screen.PutPixel(x, y, pix);
        }
    }
}

void nothing::Draw(Image &screen)
{
    for (int y = coords.y; y <= coords.y + 32; ++y)
    {
        for (int x = coords.x; x <= coords.x + 54; ++x)
        {
            screen.PutPixel(x, y, backgroundColor);
            screen.PutType(x, y, 2);
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
            screen.PutType(x, y, 1);
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
            screen.PutType(x, y, 1);
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
            screen.PutType(x, y, 1);
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
            screen.PutType(x, y, 1);
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

void Door::Draw(Image &screen)
{
    static Image floor("resources/doors.png");
    int shift_y = 0;
    int shift_x = 0;
    for (int y = coords.y; y <= coords.y + 52; ++y)
    {
        for (int x = coords.x; x <= coords.x + 32; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x + 192, y - coords.y + 143);
            screen.PutPixel(coords.x + shift_x, coords.y + shift_y, pix);
            screen.PutType(coords.x + shift_x, coords.y + shift_y, 4);
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
        for (int x = coords.x; x <= coords.x + 54; ++x)
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
        for (int x = coords.x; x <= coords.x + 54; ++x)
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
            screen.PutType(x, y, 5);
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
            screen.PutType(x, y, 5);
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
            screen.PutType(x, y, 5);
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
            screen.PutType(x, y, 5);
        }
    }
}