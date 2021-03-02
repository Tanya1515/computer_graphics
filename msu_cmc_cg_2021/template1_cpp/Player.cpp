#include "Player.h"

static Pixel blend(Pixel oldPixel, Pixel newPixel)
{
  newPixel.r = newPixel.a / 255.0 * (newPixel.r - oldPixel.r) + oldPixel.r;
  newPixel.g = newPixel.a / 255.0 * (newPixel.g - oldPixel.g) + oldPixel.g;
  newPixel.b = newPixel.a / 255.0 * (newPixel.b - oldPixel.b) + oldPixel.b;
  newPixel.a = 255;

  return newPixel;
}

bool Player::Moved() const
{
  if (coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}
// как изменяются координаты при движении вверх, вниз, вправо и влево
void Player::ProcessInput(MovementDir dir)
{
  int move_dist = move_speed * 1;
  switch (dir)
  {
  case MovementDir::UP:
    old_coords.y = coords.y;
    coords.y += move_dist;
    break;
  case MovementDir::DOWN:
    old_coords.y = coords.y;
    coords.y -= move_dist;
    break;
  case MovementDir::LEFT:
    old_coords.x = coords.x;
    coords.x -= move_dist;
    break;
  case MovementDir::RIGHT:
    old_coords.x = coords.x;
    coords.x += move_dist;
    break;
  default:
    break;
  }
}

void Player::Draw(Image &screen)
{

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
  Image floor("resources/zaya.png");
  for (int y = coords.y; y <= coords.y + tileSize; ++y)
  {
    for (int x = coords.x; x <= coords.x + tileSize; ++x)
    {
      Pixel pix = blend(screen.data_save[y * screen.Width() + x], floor.GetPixel(x - coords.x, tileSize - y + coords.y));
      screen.PutPixel(x, y, pix);
    }
  }
}