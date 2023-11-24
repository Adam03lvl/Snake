enum State {
  START,
  PLAYING,
  LOSE,
  PAUSED
};

class Game {
public:
  SDL_Window *win;
  SDL_Renderer *ren;
  SDL_Texture* start;
  SDL_Texture* pause;
  SDL_Texture* lose;
  SDL_Texture* map;
  SDL_Texture* food;

  bool is_running;
  State state;

  Game();
  ~Game();
};
