#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>

Image::Image(const std::string &a_path)
{
  if ((data = (Pixel *)stbi_load(a_path.c_str(), &width, &height, &channels, 0)) != nullptr)
  {
    size = width * height * channels;
  }
}

Image::Image(int a_width, int a_height, int a_channels)
{
  data = new Pixel[a_width * a_height]{};
  data_obj = new int[a_width * a_height];

  if (data != nullptr)
  {
    width = a_width;
    height = a_height;
    size = a_width * a_height * a_channels;
    channels = a_channels;
    self_allocated = true;
  }
}

void Image::ScreenType()
{
  data_obj = new int[width * height];
  data_trap = new Point_Trap[width * height];
  data_throns = new Point_Trap[width * height];
  for (int i = 0; i <= width * height; i++)
  {
    data_obj[i] = 0;
    data_trap[i] = {0, 0};
    data_throns[i] = {0, 0};
  }
}

void Image::ScreenSave()
{
  data_save = new Pixel[width * height];
  memcpy(data_save, data, width * height * sizeof(Pixel));
}

int Image::Save(const std::string &a_path)
{
  auto extPos = a_path.find_last_of('.');
  if (a_path.substr(extPos, std::string::npos) == ".png" || a_path.substr(extPos, std::string::npos) == ".PNG")
  {
    stbi_write_png(a_path.c_str(), width, height, channels, data, width * channels);
  }
  else if (a_path.substr(extPos, std::string::npos) == ".jpg" || a_path.substr(extPos, std::string::npos) == ".JPG" ||
           a_path.substr(extPos, std::string::npos) == ".jpeg" || a_path.substr(extPos, std::string::npos) == ".JPEG")
  {
    stbi_write_jpg(a_path.c_str(), width, height, channels, data, 100);
  }
  else
  {
    std::cerr << "Unknown file extension: " << a_path.substr(extPos, std::string::npos) << "in file name" << a_path << "\n";
    return 1;
  }

  return 0;
}

Image::~Image()
{
  if (self_allocated)
    delete[] data;
  else
  {
    stbi_image_free(data);
  }
}