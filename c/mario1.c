#include <cs50.h>
#include <stdio.h>

//main program
int main(void)
{
     // global
     int height=8;

     // whats size?
     do
     {
          height = get_int("Height: ");
     }
     while (height<=0 || height>8); // height <= 0 OU height > 8 ( intervalo permitido é de 1 a 8)

     // intialization
     int hashes=1;
     char blocks[8] = {' ',' ',' ',' ',' ',' ',' ',' '}; // string blocks[0]

     // loop
     for(int row=1; row<=height; row++)
     {
         hashes = height - row;
         blocks[hashes]='#';
         printf("%s\n", blocks);
     }
}
