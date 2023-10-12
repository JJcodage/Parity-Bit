#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LF 10

int main()

{
    char nmbr1;
    int base, nmbr2,nmbr3, tmp1, tmp2,counter,flag,odd,parity;
    
   
    
    while(1)
    {
    nmbr2=0;
    nmbr3=0;
    tmp2=0;
    parity=0;
    counter=0;
    
    top:
       
    fflush(stdin);    
    printf("Enter the base of your number (2,10,16): ");
    scanf("%d", &base);
    
    
    while(base!=2 && base!=10 && base!=16)
    {
     printf("WRONG! Enter the base again (2, 10, 16): ");
     fflush(stdin);
     scanf("%d", &base);
    }
       
    fflush(stdin);
    printf("Enter the number you are going to do base change: ");
    scanf("%c", &nmbr1);
    
    
    

    if (base==2 && !(nmbr1>='0' || nmbr1<='1'))
    {
                printf("WARNING: Your number is not valid in base 2!!!\n");
                
                goto top;
               }
                
     else if (base==10 && !(nmbr1>='0' || nmbr1<='9'))
     {
            printf("WARNING: Your number is not valid in base 10!!!\n");
           ;
            goto top;
                }
            
       else if (base==16 && !((nmbr1>='0' && nmbr1<='9') || (nmbr1>='A' && nmbr1<='F')))
     {
            printf("WARNING: Your number is not valid in base 16!!!\n");
               
                goto top;
                }
                
                
    


   
   
    while(nmbr1!=LF)
    {
    
    if(nmbr1>='0' && nmbr1<='9')
    
    {nmbr2=nmbr2*base+(nmbr1-48);
   
}
    else if(nmbr1>='A' && nmbr1<='F')
    
    {nmbr2=nmbr2*base+(nmbr1-55);
    
}
    else
    {
        printf("%d", nmbr2);
        
        printf("You have entered a non valid number for your defined base!");
        system("pause");
        return 0;
    }

    ;
    
    scanf("%c", &nmbr1);
    }
    
  
    
    for(counter=0, tmp1=nmbr2; tmp1>0;counter++)
    {
             tmp1=tmp1/2;
             }

    flag=0;
    
    for(tmp1=nmbr2;tmp1%2==0;tmp1=tmp1/2)
    flag++;
    for(tmp1=nmbr2; tmp1>0;)
    {
             tmp2=tmp2*10+tmp1%2;
             tmp1=tmp1/2;
             }
    
    
    for(tmp1=0;tmp2>0;tmp2=tmp2/10)
    {tmp1=tmp1*10+tmp2%10;
    }
    for(;flag>0;flag--)
    tmp1=tmp1*10;
    

    
    printf("State the code to calculate even or odd parity of the number (0 for even/ 1 for odd): ");
    scanf("%d", &odd);
    while(odd!=1 && odd!=0)
    {
                 printf("WRONG! Please check your even or odd parity code (0 for even/ 1 for odd): ");
                 scanf("%d", &odd);
    }
    counter=0;
    if(odd==1)
    {
              for(tmp2=tmp1;tmp2>0;)
              {
               if(tmp2%10==1)
               counter++;
               tmp2=tmp2/10;
               
              }
              if(counter%2==0)
              tmp1=tmp1*10+1;
              else
              tmp1=tmp1*10;
               }
               
    else
    {
              for(tmp2=tmp1;tmp2>0;)
              {
               if(tmp2%10==1)
               counter++;
               tmp2=tmp2/10;
               
              }
              if(counter%2==1)
              tmp1=tmp1*10+1;
              else
              tmp1=tmp1*10;
              
               }

nmbr3=tmp1;
printf("The number according to your parity bit is equal to: %d\n", nmbr3);

              
}
    system("pause");
    return 0;
}
