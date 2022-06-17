#include <cs50.h>
#include <math.h>
#include <stdio.h>

// clear screen
void clrScr(void){
    printf("\e[H\e[2J");
}

// get value
long getValue(void){
    long value=0;
    clrScr();
    do
    {
        value = get_long("Qual o número do cartão? ");
    }
    while(value<=0);
    return value;
}

// sum digits in number
long sumDigits(long number){
    long t, sum = 0, remainder;
    t = number;
    while (t != 0)
    {
        remainder = t % 10;
        sum       = sum + remainder;
        t         = t / 10;
    }
    return sum;
}


//main program
int main(void)
{
    //
    long cc=getValue();
    long reminder= 0;
    long multiples=0;
    long sumMultiples=0;
    long sumOthers=0;
    long checksum=0;
    long count=0;

    // process - 4003600000000014
    // checksum
    while(cc!=0)
    {
        // digit at digit
        reminder=cc%10;
        cc=cc/10;

        // calculating
        multiples = (count%2!=0)?reminder*2:0;
        sumMultiples = (count%2!=0)?sumMultiples+sumDigits(multiples):sumMultiples;
        sumOthers = (count%2==0)?sumOthers+reminder:sumOthers;
        checksum=sumOthers+sumMultiples;

        count++;
    }
    // validate
    int valid = checksum%10;
    if(valid!=0){
        printf("%s\n", "Cartão inválido");
    }else{
        if(reminder==3 && count==15)
            printf("%s\n", "AMEX");
        else if(reminder==4 && count>=13)
                printf("%s\n", "VISA");
        else if(reminder==5 && count==15)
                printf("%s\n", "MASTER");
        else
            printf("%s\n", "Cartão não identificado");
    }

}
