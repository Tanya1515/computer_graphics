#include "Image.h"

struct Point_s
{
    int x;
    int y;
};

struct Labyrinth
{
    explicit Labyrinth(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};