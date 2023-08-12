#include<headers/common.h>

Food::Food() {
  x = 800;
  y = 800;
}

void Food::spawn() {
  int randx = rand() % WINDOW_WIDTH;
  int randy = rand() % WINDOW_HEIGHT;
  x = randx-randx%CELL_SIZE;
  y = randy-randy%CELL_SIZE;
}
