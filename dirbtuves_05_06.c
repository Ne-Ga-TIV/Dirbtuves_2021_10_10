#include <stdio.h>
 
int main()
{
    char value;
    int numb = 1, div_coutn, size_b, size_f, numb_found;
    while(1)
    {
        numb_found = numb = div_coutn = 0;
        size_f = size_b = 1;
        while(value = getchar(), value != ' ' && value != '\n')
        {
            if(value == '-')
            {
                printf("Skaicius turi buti teigiamas!\n");
                while(value = getchar(), value != ' ' && value != '\n');
                numb = -1;
                break;
            } 
            if(value < 48 || value > 58)
            {
                printf("Tai turi buti skaiciai\n");
                while(value = getchar(), value != ' ' && value != '\n');
                numb = -1;
                break;
            }
            else
            {   
                numb_found = 1;
                numb *= 10;
                numb += value - 48;
            }
        }
        if(numb_found && numb == 0)
            return 0;
        if(!numb_found || numb == -1)
            continue;

        for(int i = 1; i <= numb / 2; i++)
            if(numb % i == 0)
                div_coutn++;
        if(div_coutn == 1)
        {
            div_coutn = 0;
            printf("Skaicius %d yra pirminis\n", numb);

            
        }
        else{
            printf("Skaicius %d ne pirminis, ", numb);
            for(;div_coutn != 1; ++size_f){
                div_coutn = 0;
                for(int j = 1; j <= (numb+size_f) / 2; j++){
                    if((numb+size_f) % j == 0)
                        div_coutn++;
                }
            }
            div_coutn = 0;

            for(;div_coutn != 1 && numb-size_b >= 1; ++size_b){
                div_coutn = 0;
                for(int j = 1; j <= (numb-size_b) / 2; j++)
                    if((numb-size_b) % j == 0)
                        div_coutn++;
            }
            size_f--,size_b--;
            if(numb-size_b == 1 || size_b == 0){
                printf("artimiausias pirminis skaicius yra %d\n", numb+size_f);
                continue;
            }
            if(size_f == size_b){
                printf("artimiausi pirmini skaiciai yra %d ir %d\n", numb-size_f, numb+size_f);
                continue;
            }
            if(size_f < size_b)
                printf("artimiausias pirminis skaicius yra %d\n", numb+size_f);
            else
                printf("artimiausias pirminis skaicius yra %d\n", numb-size_b);

        }
    }
    return 0;

}