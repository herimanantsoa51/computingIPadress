#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum bool bool;
typedef enum classe classe;

enum bool
{
    TRUE,
    FALSE
};
enum classe
{
    A,B,C,D,E,StrError,Invalid
};
int * GetValofVariable();
bool IsNumberValid(int n);
classe whatClassHas(int n);
char * converVarInStr(int *var);
void printresult(classe c,int *var);
void main ()
{
    int *var;
    int i;
    bool noyes=TRUE;
    classe type;
    var=GetValofVariable();
    if (var ==NULL)
    {
        printresult(StrError,var);   
    }
    else 
    {
        for (i = 0; i < 4; i++)
        {
            noyes=IsNumberValid(var[i]);
            if (noyes==FALSE)
            {
                break;
            }
        } 
        if (noyes==FALSE)
        {
            type=Invalid;
        }
        else 
        {
            type=whatClassHas(var[0]);
        }  
        printresult(type,var);
    }
}

int *GetValofVariable()
{   
    int *tab=(int*)malloc(4*sizeof(int));
    int test=0,i;
    char * str=getenv("QUERY_STRING");
    test = sscanf(str,"IP=%d.%d.%d.%d",&tab[0],&tab[1],&tab[2],&tab[3]);
    if (test!=4)
    {
        return (NULL);
    }
    else
    {    
        return(tab);  
    }
    
}
bool IsNumberValid(int n)
{
    if (n<=255 && n>=0)
    {
        return(TRUE); 
    }
    else
    {
        return(FALSE);
    }
}
classe whatClassHas(int n)
{   
    
    if (n>=0 && n<=127)
    {
        return(A);
    }
    else if (n>127 && n<=191)
    {
        return B;
    }
    else if (n>191 && n<=224)
    {
        return(C);
    }
    else if (n>224 && n<=239)
    {
        return (D);   
    } 
    else
    {
        return(E);
    }
}
void printresult(classe c,int *var)
{   
    printf("Content-Type: text/html; charset=UTF-8\n\n");
    printf("<html lang='fr'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title >Resultat</title></head>");
    printf("<body background='img/back.jpg' style='font-family: Arial, sans-serif; background-color: #f0f0f0; margin: 0; padding: 0;'>");
    printf("<form action='cp.html' method='get'>");
    printf("<div style='width: 80%% ; margin: 0 auto; background-color: hsla(86, 25%%, 46%%, 0.541); padding: 30px; box-shadow: 1 1 10px rgba(152, 201, 113, 0.1); margin-top: 50px;margin-bottom: 50px;'>");
    switch (c)
    {
    case A:
        printf("<h1 style='text-align: center; color: #ffffff;'>l'adresse %s est de classe A</h1>",converVarInStr(var));
        break;
    case B:
        printf("<h1 style='text-align: center; color: #ffffff;'>l'adresse %s est de classe B</h1>",converVarInStr(var));
        break;
    case C:
        printf("<h1 style='text-align: center; color: #ffffff;'>l'adresse %s est de classe C</h1>",converVarInStr(var));
        break;
    case D:
        printf("<h1 style='text-align: center; color: #ffffff;'>l'adresse %s est de classe D</h1>",converVarInStr(var));
        break;
    case E:
        printf("<h1 style='text-align: center; color: #ffffff;'>l'adresse %s est de classe E</h1>",converVarInStr(var));
        break;
    case Invalid:
        printf("<h1 style='text-align: center; color: #ffffff;'>this is not a IP adress</h1>");
        break;
     case StrError:
        printf("<h1 style='text-align: center; color: #ffffff;'>INPUT INVALID try for example 000.000.000.000</h1>");
        break;
    }
    printf("<div style='text-align: center;'><input type='submit' value='Reessayer a nouveau'></div>");
    printf("</div></form></body></html>");
    
}
char * converVarInStr(int *var)
{   
    int i;
    char *result= (char*)malloc(20*sizeof(char));
    sprintf(result,"%d.%d.%d.%d",var[0],var[1],var[2],var[3]);
    return(result);
}
