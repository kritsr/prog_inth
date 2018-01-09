#include<stdio.h>
#include<string.h>
int R, C, DR, DC;
char MAP[50][51];
char MAP2[50][51];
char turn(){
  memcpy(MAP2, MAP, sizeof(MAP));
  char c = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (MAP2[i][j] == '*') {
        if (i > 0 && (MAP2[i-1][j] == '.' || MAP2[i-1][j] == 'S')) c = MAP[i-1][j] = '*';
        if (j > 0 && (MAP2[i][j-1] == '.' || MAP2[i][j-1] == 'S')) c = MAP[i][j-1] = '*';
        if (i < R-1 && (MAP2[i+1][j] == '.' || MAP2[i+1][j] == 'S')) c = MAP[i+1][j] = '*';
        if (j < C-1 && (MAP2[i][j+1] == '.' || MAP2[i][j+1] == 'S')) c = MAP[i][j+1] = '*';
      } else if (MAP2[i][j] == 'S') {
        if (i > 0 && (MAP[i-1][j] == '.' || MAP[i-1][j] == 'D')) c = MAP[i-1][j] = 'S';
        if (j > 0 && (MAP[i][j-1] == '.' || MAP[i][j-1] == 'D')) c = MAP[i][j-1] = 'S';
        if (i < R-1 && (MAP[i+1][j] == '.' || MAP[i+1][j] == 'D')) c = MAP[i+1][j] = 'S';
        if (j < C-1 && (MAP[i][j+1] == '.' || MAP[i][j+1] == 'D')) c = MAP[i][j+1] = 'S';
        if (MAP[DR][DC] == 'S') return 'D';
      }
    }
  }
  return c;
}
int main(){
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; i++) {
    scanf("%s", MAP[i]);
    char *j = strchr(MAP[i], 'D');
    if (j != NULL) {
      DR = i;
      DC = j-MAP[i];
    }
  }
  int i = 0;
  while(1) {
    char c;
    c = turn();
    ++i;
    if (c == 0) printf("KAKTUS\n");
    else if (c == 'D') printf("%d\n", i);
    else continue;
    break;
  }
}
