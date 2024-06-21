#pragma once
#include <map>
#include <string>
#include <raylib.h>

struct MediaStorage
{
  void clear_assets();
  void add_texture(const std::string &asset_id, const std::string &filepath);
  void add_image(const std::string &asset_id, const std::string &filepath);
  void add_sound(const std::string &asset_id, const std::string &filepath);
  void add_music(const std::string &asset_id, const std::string &filepath);
  void add_text(const std::string &asset_id, const std::string &filepath);

  Texture2D     *get_texture(const std::string &asset_id);//Load into GPU
  Image         *get_image(const std::string &asset_id);//Load into memory(RAM)
  Sound         *get_sound(const std::string &asset_id);
  Music         *get_music(const std::string &asset_id);
  std::string   *get_text(const std::string &asset_id);

  void image_to_texture(const std::string &asset_id);//Use this for scenes
  void unload_textures();//Use this for scenes
  
  std::map<std::string, Texture2D*>   textures;
  std::map<std::string, Image*>       images;
  std::map<std::string, Font*>        fonts;
  std::map<std::string, std::string*> texts;
  std::map<std::string, Sound*>       sounds;
  std::map<std::string, Music*>       musics;
};
