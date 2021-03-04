#include "Image.h"

struct Point_s
{
    int x;
    int y;
};

struct end
{
    explicit end(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct win
{
    explicit win(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct game_over
{
    explicit game_over(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct nothing
{
    explicit nothing(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Wall_1
{
    explicit Wall_1(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Wall_2
{
    explicit Wall_2(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Wall_3
{
    explicit Wall_3(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Wall_4
{
    explicit Wall_4(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Door
{
    explicit Door(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Door_Half_Open
{
    explicit Door_Half_Open(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Door_Open
{
    explicit Door_Open(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Trap_1
{
    explicit Trap_1(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Trap_2
{
    explicit Trap_2(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Path_1
{
    explicit Path_1(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Path_2
{
    explicit Path_2(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Path_3
{
    explicit Path_3(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Path_4
{
    explicit Path_4(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Bush_1
{
    explicit Bush_1(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Bush_2
{
    explicit Bush_2(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Bush_3
{
    explicit Bush_3(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Bush_4
{
    explicit Bush_4(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};