#include "Player.h"
#include "labyrinth.h"
#include "common.h"

static Pixel blend(Pixel oldPixel, Pixel newPixel)
{
  newPixel.r = newPixel.a / 255.0 * (newPixel.r - oldPixel.r) + oldPixel.r;
  newPixel.g = newPixel.a / 255.0 * (newPixel.g - oldPixel.g) + oldPixel.g;
  newPixel.b = newPixel.a / 255.0 * (newPixel.b - oldPixel.b) + oldPixel.b;
  newPixel.a = 255;

  return newPixel;
}

void Draw_Trap(Image &Screen, int x, int y)
{
  int i = 0;

  while (i < Screen.Width() * Screen.Height())
  {
    if ((Screen.data_trap[i].x <= x) && (Screen.data_trap[i].y <= y))
    {
      i = i + 1;

      if ((Screen.data_trap[i].x >= x) && (Screen.data_trap[i].y + 32 >= y))
      {
        i = i - 1;

        Point_s starting_pos_s = {Screen.data_trap[i].x, Screen.data_trap[i].y};
        Trap_1 trap{starting_pos_s};
        trap.Draw(Screen);
        Screen.ScreenSave();
        break;
      }
      i = i - 1;
    }
    i = i + 2;
  }
}

int Checked(int x, int y, Image &screen)
{
  if (screen.GetType(x, y) == 1) //wall
    return 1;
  if (screen.GetType(x, y) == 2) //empty plac
    return 2;
  if (screen.GetType(x, y) == 3) //quit from labyrinth
    return 3;
  if (screen.GetType(x, y) == 4) //door to another room
    return 4;
  if (screen.GetType(x, y) == 5) //trap
    return 5;
}

bool Player::Moved() const
{
  if (coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}
// как изменяются координаты при движении вверх, вниз, вправо и влево
int Player::ProcessInput(MovementDir dir, Image &screen)
{
  
  int move_dist = move_speed * 1;

  switch (dir)
  {
  case MovementDir::UP:
    if (Checked(coords.x + 16, coords.y + 32 + move_dist, screen) != 1)
    {
      old_coords.y = coords.y;
      coords.y += move_dist;
      if (Checked(coords.x + 10, coords.y + 16, screen) == 2)
        return 2;
      if (Checked(coords.x, coords.y, screen) == 3)
        return 3;
      if (Checked(coords.x, coords.y, screen) == 4)
        return 4;
      if (Checked(coords.x, coords.y, screen) == 5)
      {
        Draw_Trap(screen, coords.x, coords.y);
        return 5;
      }
    }
    break;
  case MovementDir::DOWN:
    if (Checked(coords.x + 16, coords.y - move_dist, screen) != 1)
    {
      old_coords.y = coords.y;
      coords.y -= move_dist;
      if (Checked(coords.x + 16, coords.y + 2, screen) == 2)
        return 2;
      if (Checked(coords.x, coords.y + 25, screen) == 3)
        return 3;
      if (Checked(coords.x, coords.y, screen) == 4)
        return 4;
      if (Checked(coords.x, coords.y, screen) == 5)
      {
        Draw_Trap(screen, coords.x, coords.y);
        return 5;
      }
    }
    break;
  case MovementDir::LEFT:
    if (Checked(coords.x - move_dist, coords.y, screen) != 1)
    {
      old_coords.x = coords.x;
      coords.x -= move_dist;
      if (Checked(coords.x + 16, coords.y, screen) == 2)
        return 2;
      if (Checked(coords.x + 16, coords.y, screen) == 3)
        return 3;
      if (Checked(coords.x, coords.y, screen) == 4)
        return 4;
      if (Checked(coords.x, coords.y, screen) == 5)
      {
        Draw_Trap(screen, coords.x, coords.y);
        return 5;
      }
    }
    break;
  case MovementDir::RIGHT:
    if (Checked(coords.x + 20 + move_dist, coords.y + 16, screen) != 1)
    {
      old_coords.x = coords.x;
      coords.x += move_dist;
      if (Checked(coords.x + 16, coords.y - 2, screen) == 2)
        return 2;
      if (Checked(coords.x + 16, coords.y, screen) == 3)
        return 3;
      if (Checked(coords.x, coords.y, screen) == 4)
        return 4;
      if (Checked(coords.x, coords.y, screen) == 5)
      {
        Draw_Trap(screen, coords.x, coords.y);
        return 5;
      }
    }
    break;
  default:
    break;
  }
}

void Player::Draw(Image &screen, float zaya)
{
  static Image zaya_2("resources/zaya_pol_uho.png");
  static Image zaya_3("resources/zaya_sogn_uho.png");
  static Image zaya_1("resources/zaya.png");
  if (Moved())
  {
    for (int y = old_coords.y; y <= old_coords.y + tileSize; ++y)
    {
      for (int x = old_coords.x; x <= old_coords.x + tileSize; ++x)
      {
        screen.PutPixel(x, y, screen.data_save[y * screen.Width() + x]);
      }
    }
    old_coords = coords;
  }

  if (!Moved())
  {
    for (int y = coords.y; y <= coords.y + tileSize; ++y)
    {
      for (int x = coords.x; x <= coords.x + tileSize; ++x)
      {
        //screen.PutPixel(x, y, color);
        if (zaya <= 0.2)
        {
          Pixel pix = blend(screen.data_save[y * screen.Width() + x], zaya_1.GetPixel(x - coords.x, tileSize - y + coords.y));
          screen.PutPixel(x, y, pix);
        }
        else if (zaya <= 0.4)
        {
          Pixel pix = blend(screen.data_save[y * screen.Width() + x], zaya_2.GetPixel(x - coords.x, tileSize - y + coords.y));
          screen.PutPixel(x, y, pix);
        }
        else
        {
          Pixel pix = blend(screen.data_save[y * screen.Width() + x], zaya_3.GetPixel(x - coords.x, tileSize - y + coords.y));
          screen.PutPixel(x, y, pix);
        }
      }
    }
  }
}