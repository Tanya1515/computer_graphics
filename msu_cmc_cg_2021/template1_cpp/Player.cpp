#include "Player.h"

static Pixel blend(Pixel oldPixel, Pixel newPixel)
{
  newPixel.r = newPixel.a / 255.0 * (newPixel.r - oldPixel.r) + oldPixel.r;
  newPixel.g = newPixel.a / 255.0 * (newPixel.g - oldPixel.g) + oldPixel.g;
  newPixel.b = newPixel.a / 255.0 * (newPixel.b - oldPixel.b) + oldPixel.b;
  newPixel.a = 255;

  return newPixel;
}

bool Checked(int x, int y, Image &screen)
{
  if (screen.GetType(x, y) == 1)
    return false;
  return true;
}

bool Player::Moved() const
{
  if (coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}
// как изменяются координаты при движении вверх, вниз, вправо и влево
void Player::ProcessInput(MovementDir dir, Image &screen)
{
  int move_dist = move_speed * 1;
  switch (dir)
  {
  case MovementDir::UP:
    if (Checked(coords.x + 16, coords.y + 32 + move_dist, screen))
    {
      old_coords.y = coords.y;
      coords.y += move_dist;
    }
    break;
  case MovementDir::DOWN:
    if (Checked(coords.x + 16, coords.y - move_dist, screen))
    {
      old_coords.y = coords.y;
      coords.y -= move_dist;
    }
    break;
  case MovementDir::LEFT:
    if (Checked(coords.x - move_dist, coords.y, screen))
    {
      old_coords.x = coords.x;
      coords.x -= move_dist;
    }
    break;
  case MovementDir::RIGHT:
    if (Checked(coords.x + 32 + move_dist, coords.y, screen))
    {
      old_coords.x = coords.x;
      coords.x += move_dist;
    }
    break;
  default:
    break;
  }
}

void Player::Draw(Image &screen)
{
  static Image floor_2("resources/zaya_pol_uho.png");
  static Image floor_3("resources/zaya_sogn_uho.png");
  static Image floor_1("resources/zaya.png");
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
        Pixel pix = blend(screen.data_save[y * screen.Width() + x], floor_1.GetPixel(x - coords.x, tileSize - y + coords.y));
        screen.PutPixel(x, y, pix);
      }
    }
  }
}