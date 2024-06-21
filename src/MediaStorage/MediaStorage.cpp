#include "raylib.h"
#include <MediaStorage/MediaStorage.hpp>

void MediaStorage::add_texture(const std::string &asset_id, const std::string &filepath)
{
  Texture2D *t = new Texture2D; 
  *t  = LoadTexture(filepath.c_str());

  textures.emplace(asset_id, t);
}

void MediaStorage::add_image(const std::string &asset_id, const std::string &filepath)
{
  Image *i = new Image;
  *i = LoadImage(filepath.c_str());

  images.emplace(asset_id, i);
}

void MediaStorage::add_sound(const std::string &asset_id, const std::string &filepath)
{
  Sound *s = new Sound;
  *s = LoadSound(filepath.c_str());

  sounds.emplace(asset_id, s);
}

void MediaStorage::add_music(const std::string &asset_id, const std::string &filepath)
{
  Music *m = new Music;
  *m = LoadMusicStream(filepath.c_str());

  musics.emplace(asset_id, m);
}

void MediaStorage::add_text(const std::string &asset_id, const std::string &filepath)
{

}

void MediaStorage::image_to_texture(const std::string &asset_id)
{
  Texture2D *t = new Texture2D; 
  *t  = LoadTextureFromImage(*get_image(asset_id));

  textures.emplace(asset_id, t);
}

Texture2D *MediaStorage::get_texture(const std::string &asset_id)
{
  return textures[asset_id]; 
}

Image *MediaStorage::get_image(const std::string &asset_id)
{
  return images[asset_id]; 
}

Sound *MediaStorage::get_sound(const std::string &asset_id)
{
  return sounds[asset_id];
}

Music *MediaStorage::get_music(const std::string &asset_id)
{
  return musics[asset_id];
}

std::string *MediaStorage::get_text(const std::string &asset_id)
{
  return texts[asset_id];
}

void MediaStorage::clear_assets()
{
  for(auto image : images)
  {
    UnloadImage(*image.second);
  }
  images.clear();

  for(auto texture : textures)
  {
    UnloadTexture(*texture.second);
  }
  textures.clear();

  for(auto sound : sounds)
  {
    UnloadSound(*sound.second);
  }
  sounds.clear();

  for(auto music : musics)
  {
    UnloadMusicStream(*music.second);
  }
  musics.clear();

  for(auto music : musics)
  {
    UnloadMusicStream(*music.second);
  }
  musics.clear();

  for(auto str : texts)
  {
    delete str.second;
  }
  texts.clear();

  for(auto font : fonts)
  {
    UnloadFont(*font.second);
  }
  fonts.clear();
}
