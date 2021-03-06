#include "Image.h"

struct Point_s
{
    int x;
    int y;
};

struct no_1
{
    explicit no_1(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct no_2
{
    explicit no_2(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct no_3
{
    explicit no_3(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};
struct no_4
{
    explicit no_4(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Thorns
{
    explicit Thorns(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Thorns_t
{
    explicit Thorns_t(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Thorns_r
{
    explicit Thorns_r(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
};

struct Thorns_h
{
    explicit Thorns_h(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

    void Draw(Image &screen);

private:
    Point_s coords{.x = 0, .y = 0};
    Point_s old_coords{.x = 15, .y = 15};
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

struct Trap_1
{
    explicit Trap_1(Point_s pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

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