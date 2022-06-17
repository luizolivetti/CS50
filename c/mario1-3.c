#include <cs50.h>
#include <stdio.h>

//main program
int main(void)
{
     // global
     int height;

     // whats size?
     do
     {
          height = get_int("Height: ");
     }
     while (height<=0);

     // loop
     for(int row=1; row<=height; row++)
     {
         for(int col=1; col<=height-row; col++){
               printf("%s", " ");
         }
         for(int col=1; col<=row; col++){
               printf("%s", "#");
         }

         printf("%s", " ");

         for(int col=1; col<=row; col++){
               printf("%s", "#");
         }
         for(int col=1; col<=height-row; col++){
               printf("%s", " ");
         }

         printf("%s\n", "");
     }
}
