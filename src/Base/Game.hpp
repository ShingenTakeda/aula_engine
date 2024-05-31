#pragma once
#include <cstdint>
#include <raylib.h>
#include <Base/Standard_Defs.hpp>

struct Game
{
  void init();
  void handle_input();
  void update();
  void draw();
  void run();

  bool is_running = false;
  uint16_t windowW;
  uint16_t windowH;
};
