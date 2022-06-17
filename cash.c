#include <cs50.h>
#include <math.h>
#include <stdio.h>

// clear screen
void clrScr(void){
    printf("\e[H\e[2J");
}


// get value
float getValue(void){
    float cost=0;
    float paid=0;
    float value=0;

    clrScr();
    do
    {
        cost = get_float("Qual o valor da compra? ");
    }
    while(cost<=0);
    do
    {
        paid = get_float("Qual o valor recebido? ");
    }
    while(paid<=0 || paid<=cost);

    value = paid - cost;

    return value;
}

//main program
int main(void)
{
    // get value
    float payback = getValue();

    // process
    int _25c=0;
    int _10c=0;
    int _5c=0;
    int _1c=0;
    int totalCoins=0;
    float aux=payback;
    do
    {

        if(aux>=0.250000){
           aux = aux - 0.250000;
           _25c++;
        }else if(aux>=0.100000){
                 aux = aux - 0.100000;
                 _10c++;
        }else if(aux>=0.050000){
                 aux = aux - 0.050000;
                 _5c++;
        }else if(aux>=0.010000){
                 aux = aux - 0.010000;
                 _1c++;
        }else{
            break;
        }
        totalCoins++;

    }
    while(aux>0);

    // result
    clrScr();
    printf("%s","+-----------------------------------+\n");
    printf("%s","|  Troco para: ");
    printf("%0.2f", payback);
    printf("%s","                 |\n");
    printf("%s","+-----------------------------------+\n");
    printf("%s","| 25c  | 10c  | 5c  | 1c  |  Total  |\n");
    printf("%s","+-----------------------------------+\n");
    printf("%s","|");
    printf("%4d",_25c);
    printf("%3s","|");
    printf("%4d",_10c);
    printf("%3s","|");
    printf("%4d",_5c);
    printf("%2s","|");
    printf("%4d",_1c);
    printf("%2s","|");
    printf("%7d",totalCoins);
    printf("%4s","|\n");
    printf("%s","+-----------------------------------+\n");
    printf("%s","\n");
}
