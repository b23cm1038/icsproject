#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void find(char a[],int n,int x[],int m)
{
    char b[10] ="1234567890";
    char b2[4]="?+=-";
    char b3[4]="!@#$";
    for(int i=0;i<10;i++)
    {
        
        for(int j=0;j<10;j++)
        {
          if(b[j]==a[i])  
          {
              x[0]++;
          }
        }
    }
    for(int i=0;i<10;i++)
    {
        if(a[i]>='a'&& a[i]<='z')
        {
            x[1]++;
        }
        if(a[i]>='A'&& a[i]<='Z')
        {
            x[2]++;
        }
    }
    for(int i=0;i<10;i++)
    {
        
        for(int j=0;j<4;j++)
        {
          if(b2[j]==a[i])  
          {
              x[3]++;
          }
        }
    }
    for(int i=0;i<10;i++)
    {
        
        for(int j=0;j<4;j++)
        {
          if(b3[j]==a[i])  
          {
              x[4]++;
          }
        }
    }
    
}

char Random(char *a, int n) {
    return a[rand() % n];
}


void generate(int strength) {
    char *numbers = "0123456789";
    char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *specialChars = "?+=-";
    char *specialChar2 = "!@#$";
    
    char password[11];  

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            password[i] = Random(numbers, 10);
            } 
        else if (i == 1) {
            password[i] = Random(lowercase, 26);
            } 
        else if (i == 2) {
            password[i] = Random(uppercase, 26);
            } 
        else if (i == 3) {
            password[i] = Random(specialChars, 4);
            } 
        else if (i == 4) {
            password[i] = Random(specialChar2, 4);
            } 
        else if (i == 5) {
            password[i] = Random(lowercase, 26);
            }
        else if (i == 6) {
            password[i] = Random(uppercase, 26);
                } 
        else if (i == 7) {
            password[i] = Random(specialChars, 4);
                } 
        else if (i == 8) {
                    password[i] = Random(specialChar2, 4);
                } 
        else if (i == 9) {
                    password[i] = Random(numbers, 10);
                }
                
        
    }
    password[10] = '\0';
    printf("\nGenerated Password:%s", password);
}

int main()
{
    char a[11];
    scanf("%s",a);
    

    char c[11];  
    int nos = 0;

    FILE* fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int h = 0;

    while (fgets(c, 11, fp) != NULL && nos < 64) {
        nos++;
        c[strcspn(c, "\n")] = '\0';  
        if (strcmp(a, c) == 0) {
            h=1;
            break;
        }
    }

    fclose(fp);

    int x[5];
    for(int i=0;i<5;i++)
    {
        x[i]=0;
    }
    find(a,10,x,5);
    int strength;
    if(h==1)
    {
        printf("50%% strength");
    }
    else
    { 
    if(x[1]==x[2]&&x[3]==x[4]&&x[2]==x[3]&&x[4]==0)
    {
        printf("50%% strength");
        strength = 50;
        
    }
    else if(x[2]==x[3]&&x[4]==x[3]&&x[2]==0)
    {
        printf("65%% strength");
        strength = 65;
    }
    else if(x[3]==x[4]&&x[4]==0)
    {
        printf("75%% strength");
        strength = 75;
    }
    else if(x[4]==0)
    {
        printf("85%% strength");
        strength = 85;
    }
    else if(x[1]==x[2]&&x[3]==x[4]&&x[2]==x[3]&&x[4]==2&&x[1]==x[0])
    {
        printf("100%% strength");
        strength = 100;
    }
    else
    {
        printf("Invalid Input");
    }
    }
    generate(strength);
}