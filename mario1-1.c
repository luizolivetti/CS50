#include <cs50.h>
#include <stdio.h>

//main program
int main(void)
{
     // global
     int height=5;

     // whats size?
     do
     {
          height = get_int("Height: ");
     }
     while (height<=0 || height>=5); // height <= 0 OU height > 8 ( intervalo permitido é de 1 a 8)

     // intialization
     int right=5;
     int left=1;
     int mid=5;
     char blocks[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; // string blocks[0]

     // loop
     for(int row=1; row<=height; row++)
     {
          left = mid-row;
          blocks[left]='#';

          right = 5+row;
          blocks[right]='#';
          printf("%s\n", blocks);
     }
}
