#include<headers/common.h>
#include<headers/render.h>

static void render_game(SDL_Renderer *ren,Bone* head,SDL_Texture* food,SDL_Texture* map,SDL_Texture* head_direction,SDL_Texture* body,int foodx,int foody) {
  SDL_Rect map_rect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
  SDL_Rect food_rect = {foodx,foody,CELL_SIZE,CELL_SIZE};

  SDL_RenderCopy(ren,map,NULL,&map_rect);
  SDL_RenderCopy(ren,food,NULL,&food_rect);

  SDL_Rect head_sprite = { head->x,head->y,CELL_SIZE,CELL_SIZE };
  SDL_RenderCopy(ren,head_direction,NULL,&head_sprite);

  Bone* current = head->next;
  while(current!=nullptr){
    SDL_Rect sprite = { current->x,current->y,CELL_SIZE,CELL_SIZE };
    SDL_RenderCopy(ren,body,NULL,&sprite);
    current = current->next;
  }
  free(current);
}

static void render_start(SDL_Renderer *ren,SDL_Texture* start){
  SDL_Rect map_rect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
  SDL_RenderCopy(ren,start,NULL,&map_rect);
}

static void render_lose(SDL_Renderer *ren,SDL_Texture* lose) {
  SDL_Rect map_rect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
  SDL_RenderCopy(ren,lose,NULL,&map_rect);
}

static void render_pause(SDL_Renderer *ren,SDL_Texture* pause) {
  SDL_Rect map_rect = {0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
  SDL_RenderCopy(ren,pause,NULL,&map_rect);
}

void render(Game *game,Snake *snake, Food* food) {

  switch (game->state) {
    case START:
      render_start(game->ren,game->start);
      break;
    case PLAYING:
      render_game(game->ren,snake->head,game->food,game->map,snake->head_direction,snake->body,food->x,food->y);
      break;
    case LOSE:
      render_lose(game->ren,game->lose);
      break;
    case PAUSED:
      render_pause(game->ren,game->pause);
      break;
  }
  SDL_RenderPresent(game->ren);

}
