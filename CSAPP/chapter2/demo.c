//数据在不同架构处理器下的表示
#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t led)
{
  size_t i;
  for (i = 0 ;i < led; i++)
  {
    printf("%.2x",start[i]);
  }
  printf("\n");
}

void show_int(int x)
{
  show_bytes((byte_pointer)&x,sizeof(int));
}

void show_float(float x)
{
  show_bytes((byte_pointer)&x,sizeof(float));
}

void show_pointer(void *x)
{
  show_bytes((byte_pointer)&x,sizeof(void *));
}

int main()
{
  int i =12345;
  show_int(i);
  return 0;
}
