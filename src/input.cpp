#include<headers/common.h>
#include<headers/input.h>

void key_pressed(bool &is_running,State &state,SDL_Keycode key,Direction &direction) {
  switch (key) {

    case SDLK_SPACE:

      if (state == PLAYING) {
        state = PAUSED;
        break;
      }
      state = PLAYING;
      break;

    case SDLK_ESCAPE:

      is_running = false;
      break;

    case SDLK_UP:

      if (direction==down)break;
      direction = up;
      break;

    case SDLK_DOWN:

      if (direction==up)break;
      direction = down;
      break;

    case SDLK_RIGHT:

      if (direction==left)break;
      direction = right;
      break;

    case SDLK_LEFT:

      if (direction==right)break;
      direction = left;
      break;
  }
}

void input(Game *game, Snake *snake) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {

      case SDL_QUIT:
        game->is_running = false;
        break;

      case SDL_KEYDOWN:
        key_pressed(game->is_running,game->state,event.key.keysym.sym,snake->direction);
        break;
    }
  }
}
