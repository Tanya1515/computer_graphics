#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"

struct Point
{
  int x;
  int y;
};

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Player
{
  explicit Player(Point pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords){};

  bool Moved() const;
  int ProcessInput(MovementDir dir, Image &screen);
  void Draw(Image &screen, float zaya);
  int move_speed = 4;

private:
  Point coords{.x = 10, .y = 10};
  Point old_coords{.x = 10, .y = 10};
  //Pixel color{.r = 255, .g = 0, .b = 0, .a = 0};
  
};

#endif //MAIN_PLAYER_H
