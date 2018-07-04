#pragma once

#include "config.h"

#include "gui_modules/module.h"
#include "gui_modules/emu.h"
#include "gui_modules/menu.h"

class SDL_GUI final {
private:
  // Config manager (also has CLI args)
  Config config;

  // Initialized once, passed by const-ref to all gui modules
  SDLCommon sdl_common;

  /*----------  Modules  ----------*/

  EmuModule*  emu  = nullptr;
  MenuModule* menu = nullptr;

private:
  void input_global(const SDL_Event&);

public:
  ~SDL_GUI();

  int init(int argc, char* argv[]);
  int run();
};