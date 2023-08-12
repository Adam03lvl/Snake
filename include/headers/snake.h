typedef struct Bone Bone;
typedef struct Bone{
    int x, y;
    int lastx, lasty;
    Bone* next;
}Bone;

enum Direction {
  up,
  down,
  left,
  right
};

class Snake {
public:
  Bone *head;
  Bone *tail;

  Direction direction;
  SDL_Texture* head_direction;

  SDL_Texture* head_up;
  SDL_Texture* head_down;
  SDL_Texture* head_left;
  SDL_Texture* head_right;
  SDL_Texture* body;
  
  Snake(SDL_Renderer* ren);
  void move();
  void add_bone();
  ~Snake();
};