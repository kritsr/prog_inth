#include <stdio.h>

typedef struct tile_t {
  int x;
  int y;
  int r;
} tile_t;
void sort(tile_t[], int);
int isOverlap(tile_t t1, tile_t t2) {
  int x = t1.x - t2.x;
  int y = t1.y - t2.y;
  int r = t1.r + t2.r;
  return r*r > x*x + y*y;
}

int main() {
  int N;
  scanf("%d\n", &N);
  tile_t tiles[N];
  int max_r = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d\n", &tiles[i].x, &tiles[i].y, &tiles[i].r);
    if (tiles[i].r > max_r) max_r = tiles[i].r;
  }
  max_r *= 2;
  sort(tiles, N);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (tiles[j].x - tiles[i].x >= max_r) break;
      if (isOverlap(tiles[i], tiles[j])) {
        ++cnt;
      }
    }
  }
  printf("%d\n", cnt);
}

//qsort
int compare (tile_t t1, tile_t t2) {
  if (t1.x > t2.x) return 1;
  if (t1.x < t2.x) return 0;
  return t1.y > t2.y;
}
void swap(tile_t *a, tile_t *b) {
  if (a == b) return;
  tile_t t;
  t = *a;
  *a = *b;
  *b = t;
}
int partition(tile_t a[], int l, int h) {
  for (int i = l; i < h; i++) {
    if (compare(a[h], a[i])) {
      swap(a + i, a + l);
      ++l;
    }
  }
  swap(a+h, a+l);
  return l;
}
void qsort(tile_t a[], int l, int h) {
  if (l < h) {
    int p = partition(a, l, h);
    qsort(a, l, p-1);
    qsort(a, p+1, h);
  }
}
void sort(tile_t a[], int n) {
  qsort(a, 0, n - 1);
}
