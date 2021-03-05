#ifndef MAIN_IMAGE_H
#define MAIN_IMAGE_H

#include <string>

constexpr int tileSize = 32;

struct Point_Trap
{
  int x;
  int y;
};

struct Pixel
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
};

constexpr Pixel backgroundColor{0, 0, 0, 0};

struct Image
{
  explicit Image(const std::string &a_path);
  Image(int a_width, int a_height, int a_channels);

  int Save(const std::string &a_path);

  int Width() const { return width; }
  int Height() const { return height; }
  int Channels() const { return channels; }
  size_t Size() const { return size; }
  Pixel *Data() { return data; }
  void ScreenSave();
  void ScreenType();
  Pixel *data_save = nullptr;
  int *data_obj = nullptr;
  Point_Trap *data_trap = nullptr;
  Point_Trap *data_throns = nullptr;
  int amount_of_throns;

  Pixel GetPixel(int x, int y) { return data[width * y + x]; }
  void PutPixel(int x, int y, const Pixel &pix) { data[width * y + x] = pix; }
  void PutType(int x, int y, int type) { data_obj[width * (y) + x] = type; }
  int GetType(int x, int y) { return data_obj[width * (y) + x]; }

  ~Image();

private:
  int width = -1;
  int height = -1;
  int channels = 3;
  size_t size = 0;
  Pixel *data = nullptr;

  bool self_allocated = false;
};

#endif //MAIN_IMAGE_H
