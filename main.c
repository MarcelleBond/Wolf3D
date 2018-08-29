#include "wolf3d.h"

int map[24][24] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int butt(int but)
{
  (void)but;
  exit(0);
}

int keywork(int keycode, t_player *p)
{
  printf("%d\n",keycode);

  if (keycode == 53 || keycode == 65307)
    exit(0);
  if (keycode == 0)
    p->playerA -= (0.1f);
  if (keycode == 2)
    p->playerA += (0.1f);
  return(0);
}
int main(/* int argc, char **argv */)
{
  t_player p;
  void *mxl;
  void *win;
  float rayA;
  float dist;
  float eyeX;
  float eyeY;
  float depth;
  int testX;
  int testY;
  int hit;
  int ceiling;
  int floors;

  p.playerA = 0.0;
  p.playerY = 12.0;
  p.playerX = 12.0;
  hit = 0;
  depth = 24;
  mxl = mlx_init();
  win = mlx_new_window(mxl, WIDTH, HEIGHT, "WOLF3D");
  for (int x = 0; x < WIDTH; x++)
  {
    rayA = (p.playerA - FOV / 2.0f) + ((float)x / (float)WIDTH) * FOV;
    dist = 0;
    eyeX = sinf(rayA);
    eyeY = cosf(rayA);
    while (hit != 1 && dist < depth)
    {
      dist += 0.1f;
      testX = (int)(p.playerX + eyeX * dist);
      testY = (int)(p.playerY + eyeY * dist);

      if (testX < 0 || testX >= WIDTH || testY < 0 || testY >= HEIGHT)
      {
        hit = 1;
        dist = depth;
      }
      else
      {
        if (map[testY * WIDTH + testX] == 1)
        {
          hit = 1;
        }
      }
    }
    ceiling = (float)(HEIGHT / 2.0f) - HEIGHT / ((float)dist);
    floors = HEIGHT - ceiling;
    for (int y = 0; y < HEIGHT; y++)
    {
      if (y < ceiling)
        mlx_pixel_put(mxl, win, x, y, 0xFF66FF);
      else if (y > ceiling && y <= floors)
        mlx_pixel_put(mxl, win, x, y, 0x66FFF);
      else
        mlx_pixel_put(mxl, win, x, y, 0xFFF66);
    }
  }
  // mlx_hook(win, 2, 0, keywork, &p);
  mlx_hook(win, 17, 0, butt, 0);
  mlx_loop(mxl);
  return 0;
}
