#include "Base/Standard_Defs.hpp"
#include "MediaStorage/MediaStorage.hpp"
#include "raylib.h"
#include <Base/Game.hpp>
#include <memory>

void Game::init()
{
  g_lstate.open_libraries(sol::lib::base, sol::lib::os, sol::lib::utf8, sol::lib::math);
  if(!file_exists("ini.lua"))
  {
    windowW = window_default_width;
    windowH = window_default_height;
  }
  else
  {
    g_lstate.script_file("ini.lua");
    sol::table config = g_lstate["config"];
  
    if(!config.valid())
    {
      windowW = window_default_width;
      windowH = window_default_height;
    }
    else
    {
      windowW = config["width"];
      windowH = config["height"];
    }
  }

  InitWindow(windowW, windowH, "Game");
  InitAudioDevice();
  if(IsWindowReady() && IsAudioDeviceReady())
  {
    is_running = true;
  }
  SetTargetFPS(60);
  SetExitKey(KEY_NULL);

  DisableCursor();
  image = LoadImage("NRU_2.png");
  texture = LoadTextureFromImage(image);
  media_storage = std::make_unique<MediaStorage>();

  media_storage->add_image("test", "NRU_2.png");
  media_storage->image_to_texture("test");
}

void Game::handle_input()
{
  
}

void Game::update()
{

}

void Game::draw()
{
  BeginDrawing();
  
  ClearBackground(MAGENTA);

  if(scene_running == false)
  {
    DrawText("No scene loaded!", windowW / 2 - 100, windowH / 2, 50, RAYWHITE);
  }
  DrawTexture(*media_storage->get_texture("test"), windowW/2 - texture.width/2, windowH/2 - texture.height/2, WHITE);
  EndDrawing();
}

void Game::run()
{
  while(is_running)
  {
    handle_input();
    update();
    draw();
  }
  deinit();
}

void Game::deinit()
{
  media_storage->clear_assets();
  CloseAudioDevice();
  CloseWindow();
}
