#pragma once
#include "MediaStorage/MediaStorage.hpp"
#include <cstdint>
#include <filesystem>
#include <memory>
#include <sol/sol.hpp>
#include <raylib.h>
#include <Base/Standard_Defs.hpp>

struct Game
{
  void init();
  void deinit();
  void handle_input();
  void update();
  void draw();
  void run();

  sol::state g_lstate;

  Image image;
  Texture2D texture;

  std::unique_ptr<MediaStorage> media_storage;

  bool scene_running = false;
  bool is_running = false;
  uint16_t windowW;
  uint16_t windowH;
};

inline bool file_exists(const std::string &name)
{
  return std::filesystem::exists(name);
}
