#include<headers/common.h>

Snake::Snake(SDL_Renderer *ren) {
  Bone* entry = new Bone();

  entry->x = 120;
  entry->y = 120;
  entry->next = nullptr;

  head = entry;
  tail = entry;

  direction=down;

  SDL_Surface* image=IMG_Load("res/head-up.png");
  head_up= SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  image=IMG_Load("res/head-down.png");
  head_down= SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  image=IMG_Load("res/head-left.png");
  head_left= SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  image=IMG_Load("res/head-right.png");
  head_right= SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);
    
  image=IMG_Load("res/body.png");
  body= SDL_CreateTextureFromSurface(ren,image);
  SDL_FreeSurface(image);

  head_direction = head_down;
}

void Snake::move() {
  head->lastx=head->x;
  head->lasty=head->y;
  
  Bone* current = head;
  while (current != tail) {
    current->next->lastx = current->next->x;
    current->next->lasty = current->next->y;
    current->next->x = current->lastx;
    current->next->y = current->lasty;
    current = current->next;
  }

  switch (direction) {
    case up:
      head_direction = head_up;
      head->y -= CELL_SIZE;
      head->x += 0;    
      break;
    case down:
      head_direction = head_down;
      head->y += CELL_SIZE;
      head->x += 0;    
      break;
    case left:
      head_direction = head_left;
      head->x -= CELL_SIZE;
      head->y += 0;    
      break;
    case right:
      head_direction = head_right;
      head->x += CELL_SIZE;
      head->y += 0;    
      break;
  }
}

void Snake::add_bone() {
  Bone* entry = new Bone();

  entry->x = tail->lastx;
  entry->y = tail->lasty;
  entry->next = nullptr;

  tail->next = entry;
  tail = entry;
}

Snake::~Snake() {
  Bone* current = head;
  while (current!=nullptr) {
    Bone *tmp = current;
    current=current->next;
    free(tmp);
  }
  free(current);
}
