#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

void make_file() {
  int newfile = creat("image.ppm", 0644);
  dup2(newfile, STDOUT_FILENO);
  close(newfile);
}

int main() {
  make_file();

  srand(time(NULL));
  make_file();
  int width, height, maxval;
  width = 1000;
  height = 750;
  maxval = 255;

  printf("P3\n%d %d\n%d\n", width, height, maxval);

  int x, y;
  int r, g, b;
  int i;
  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      r = rand() % 256;
      g = r * r % 256;
      b = g * g % 256;
      printf("%d %d %d ", r, g, b);
    }
    printf("\n");
  }

}
