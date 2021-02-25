#include "labyrinth.h"
#include <iostream>

void Labyrinth::Draw(Image &screen)
{
    Image floor("resources/tex.png");
    for (int y = coords.y; y <= coords.y + tileSize / 3; ++y)
    {
        for (int x = coords.x; x <= coords.x + tileSize / 3; ++x)
        {
            Pixel pix = floor.GetPixel(x - coords.x, y - coords.y);
            screen.PutPixel(x, y, pix);
        }
    }
}