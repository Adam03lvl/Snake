#include<iostream>
#include<headers/common.h>

Game::Game() {
  if (SDL_Init(SDL_INIT_VIDEO)!=0) {
    std::cerr << "couldn't initialize SDL: " << SDL_GetError() << "\n";
    delete(this);
    exit(-1);
  }

  if (IMG_Init(IMG_INIT_PNG) == 0) {
    std::cerr << "couldn't initialize IMG: " << IMG_GetError() << "\n";
    delete(this);
    exit(-1);
  }

  win = SDL_CreateWindow(
    "Snake",
    0,
    0,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_FULLSCREEN
  );
  ren = SDL_CreateRenderer(win, -1, 0);

  if (!win || !ren) {
    std::cerr << "error opening window: " << SDL_GetError() << "\n";
    delete(this);
    exit(-1);
  }

  SDL_Surface* image=IMG_Load("res/start.png");
  start = SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  image=IMG_Load("res/background.png");
  map = SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  image=IMG_Load("res/food.png");
  food = SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  image=IMG_Load("res/pause.png");
  pause= SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);
    
  image=IMG_Load("res/lose.png");
  lose= SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  is_running = true;
  state = START;
}

Game::~Game() {
  std::cout << "deleting game..."<<"\n";
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  IMG_Quit();
  SDL_Quit();
  std::cout << "done"<<"\n";
}

