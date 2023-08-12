#include<headers/common.h>
#include<headers/update.h>

static bool get_collision(int x1,int y1,int x2,int y2) {
  return (x1 == x2 && y1 == y2);
}

static void check_bounds(int &x,int &y) {
  if (x<0) {
    x += WINDOW_WIDTH;
  }
  else if (x+CELL_SIZE > WINDOW_WIDTH) {
    x -= WINDOW_WIDTH;
  }
  else if (y < 0) {
    y += WINDOW_HEIGHT;
  }
  else if (y+CELL_SIZE > WINDOW_HEIGHT) {
    y -= WINDOW_HEIGHT;
  }
}

static bool check_loss(Bone *head) {
  Bone* current = head->next;
  while (current!=nullptr) {
    if (head->x==current->x && head->y==current->y) {
      return true;
    }
    current = current->next;
  }
  return false;
}

void update(Game* game,Snake* snake,Food* food) {
  if (game->state != PLAYING)return;

  static int frame_count = 0;
  frame_count++;
  
  if (frame_count==3) {
    snake->move();
    frame_count = 0;
  }

  if (get_collision(snake->head->x,snake->head->y,food->x,food->y)) {
    snake->add_bone();
    food->spawn();
  }

  check_bounds(snake->head->x,snake->head->y);

  if (check_loss(snake->head)) {
    game->state = LOSE;
  }
}
