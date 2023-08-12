#include<headers/common.h>
#include<headers/update.h>
#include<headers/input.h>
#include<headers/render.h>

void frame_delay() {
  static Uint64 last_frame_time = 0;
  Uint64 time_to_wait = FRAME_TARGET_TIME-(SDL_GetTicks64()-last_frame_time);

  if (time_to_wait>0 && time_to_wait<=FRAME_TARGET_TIME) {
    SDL_Delay(time_to_wait);
  }
    
  last_frame_time = SDL_GetTicks64();
}

int main(int argc,char* argv[]) {
  Game* game = new Game();
  Snake* snake = new Snake(game->ren);
  Food* food = new Food();

  while (game->is_running) {
    frame_delay();

    if (game->state == LOSE) {
      food->spawn();
      delete(snake);
      snake = new Snake(game->ren);
    }
    
    input(game,snake);
    update(game,snake,food);
    render(game,snake,food);
  }

  delete(game);
  delete(snake);
  delete(food);
  return 0;
}
