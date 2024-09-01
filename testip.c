#include "testip.h"

int mainDisplay()
{   
    int c;
    
    while (1)
    {   
        printf("1-Donner un adresse IP et le Masque de sous Reseau\n");
        printf("2-Notation CIDR\n");
        if (fscanf(stdin,"%d",&c)==1)   
        {   
            if (c ==1 || c==2 || c==3)
            {
                return (c);
            }  
        }
        else
        {
            printf("Veuillez Reesayer\n");
        } 
    }
}
int* getValIP()
{
    int i,a=0,*IP=(int*)malloc(4*sizeof(int));
    int* index=(int*)malloc(4*sizeof(int));
    while (1)
    {
        printf("Entrer un adresse IP a tester:");
        a=0;
        if (fscanf(stdin,"%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3])==4)
        {   
            for ( i = 0; i < 4; i++)
            {
                if (IP[i]>=0 && IP[i]<=255)
                {
                    index[i]=1;
                    a++;
                }   
                else
                {
                    index[i]=0;
                }
            }
            if (a==4 )
            {   
                free(index);
                return(IP);
            }
            else
            {   
                printf("Erreur:\n");
                for ( i = 0;i <4; i++)
                {   
                    if (index[i]==0)
                    {
                        printf("le %d em n'est pas un octet:%d\n",i+1,IP[i]);
                    }
                }
            }      
        }
        else
        {
            printf("IP adress not valid try for example(123.123.123.123)\n");
        }
        for ( i = 0; i < 4; i++)
        {
            index[i]=0;
        }
    }
}
void mainFree(int* IP, int *MSR,int* Res,int* Brod,char* IPbin,char*MSRbin)
{
    free(IP);
    free(MSR);
    free(Res);
    free(Brod);
    free(IPbin);
    free(MSRbin);
}
int* getValMSR()
{
    int i,a=0,j,*MSR=(int*)malloc(4*sizeof(int));
    int* index=(int*)malloc(4*sizeof(int));
    while (1)
    {
        printf("Entrer le MASQUE de SOUS RESEAU:");
        a=0;
        if (fscanf(stdin,"%d.%d.%d.%d",&MSR[0],&MSR[1],&MSR[2],&MSR[3])==4)
        {   
            for ( i = 0; i < 4; i++)
            {
                if (MSR[i]>=0 && MSR[i]<=255)
                {
                    index[i]=1;
                    a++;
                }   
                else
                {
                    index[i]=0;
                }
            }
            if (a==4)
            {   
                free(index);
                return(MSR);
            }
            else
            {   
                printf("Erreur:\n");
                for ( i = 0;i <4; i++)
                {   
                    if (index[i]==0)
                    {
                        printf("le %d em n'est pas un octet:%d\n",i+1,MSR[i]);
                    }
                }
            }      
        }
        else
        {
            printf("IP adress not valid try for example(255.255.255.255\n");
        }
        for ( i = 0; i < 4; i++)
        {
            index[i]=0;
        }
    }
}
void getValIPnbitSR(int *IP,int* nbitSR)
{
    int i,a=0,*index=(int*)malloc(4*sizeof(int));
    while (1)
    {
        printf("Entrer la CIDR:");
        a=0;
        if (fscanf(stdin,"%d.%d.%d.%d/%d",&IP[0],&IP[1],&IP[2],&IP[3],nbitSR)==5)
        {   
           for ( i = 0; i < 4; i++)
            {
                if (IP[i]>=0 && IP[i]<=255)
                {
                    index[i]=1;
                    a++;
                }   
                else
                {
                    index[i]=0;
                }
            }
            if (a==4 && *nbitSR<33 && *nbitSR>=0)
            {   
                free(index);
                break;
            }
            else if(*nbitSR>32 && *nbitSR<0)
            {
                printf("Nombre de bit invalid:%d, ça doit etre un entier positif inferieur ou egal a 32\n",*nbitSR);
            }
            else
            {   
                printf("Erreur:\n");
                for ( i = 0;i <4; i++)
                {   
                    if (index[i]==0)
                    {
                        printf("le %d em n'est pas un octet:%d\n",i+1,IP[i]);
                    }
                }
            }      
        }
        else
        {
            printf("Notation CIDR non valide (123.123.123.123/16)\n");
        }
        for ( i = 0; i < 4; i++)
        {
            index[i]=0;
        }
    }
}
int* computeIPReseau(char* binIP,char* binMSR)
{
    char* binRes=(char*)malloc(36*sizeof(char) +1);
    int *IPR;
    binRes=boolean(binIP,binMSR);
    IPR=binaryToIP(binRes);
    return(IPR);
}
char *computebinMSR(int nbitR)
{
    char *MSR=(char*)malloc(36*sizeof(char) +1);
    int i,p=0,k=0;
    MSR[36]='\0';
    for ( i = 0; i < 4; i++)
    {
       for ( p = 0; p < 8; p++)
       {
            if (nbitR>0)
            {
                MSR[k]='1';
                nbitR--;
            }  
            else
            {
                MSR[k]='0';
            }
            k++;
       }
       if (i<3)
       {
        MSR[k++]='.';
       }
    }
    return(MSR);   
}
classe whatClassHas(int *IP)
{   
    int i,a=0;
    if (IP[0]==10)
    {      
        return(A);
    }
    else if (IP[0]==172 && IP[1]>=16 && IP[1]<=31)
    {
        return (B);
    }
    else if (IP[0]==192 && IP[1]==168)
    {
        return(C);
    }
    else
    {
        return(Invalid);
    }
}
int *getMSRbyDefault(classe c)
{   
    int *MSR=(int*)malloc(4*sizeof(int));
    switch (c)
    {
    case C:
        MSR[0]=255;MSR[1]=255;MSR[2]=255;MSR[3]=0;
        break;
    case B:
        MSR[0]=255;MSR[1]=255;MSR[2]=0;MSR[3]=0;
        break;
    case A:
        MSR[0]=255;MSR[1]=0;MSR[2]=0;MSR[3]=0;
        break;
    }
    return(MSR);
}
void errorDisplay(int * MSR,char *MSRbin)
{
    printAdress(MSR,"Erreur Masque de sous Reseau:");
    printf("En binaire : %s\n Veuillez Reessayer\n",MSRbin);
}
int* computeIPBroadcast(char *IPbin,char* MSRbin)
{   
    int i,*IPBroad;
    char *Brodbin;
    Brodbin=(char*)malloc(36*sizeof(char)+1);
    Brodbin[36]='\0';
    for ( i = 0; i < 35; i++)
    {
        switch (IPbin[i])
        {
        case '0':
            if (MSRbin[i]=='0')  // 0 ou 1 = 1
                    Brodbin[i] = '1'; 
            else                 // 0 ou 0 = 0
                    Brodbin[i]= '0';
            break;
        case '1':
            Brodbin[i]='1';  // 1 ou 0=1, 1 ou 1 =1 
            break;
        case ';':
            Brodbin[i]='.';
            break;
        } 
    }
    return(binaryToIP(Brodbin));
}
int computeNbrAdressMachine(int* IPRes,int* IPBrod)
{
    int n=1,i,a;
    for ( i = 0; i < 4; i++)
    {
        a=IPBrod[i]-IPRes[i]+1;
        if (a!=0)
        {
            n *= a;
        }
    }
    return(n-2); 
}
void finalDisplay(int*IP,int *MSR,int *IPRes,int *IPBrod,int nmachine,classe c)
{  
    printf("Info sur:");
    printAdress(IP,"");
    printClass(c);
    printAdress(MSR,"Masque de sous Reseau:");
    printAdress(IPRes,"IP Reseau:");
    printAdress(IPBrod,"IP Broadcast:");
    printf("Nombre d'adresse possible:%d\n",nmachine);
}

void printAdress(int *IP,char *label)
{   
    int i;
    printf("%s>",label);
    for ( i = 0; i < 3; i++)
    {
        printf("%d.",IP[i]);
    }
    printf("%d\n",IP[3]); 
}
void printClass(classe c)
{
    switch (c)
    {
    case A:
         printf("l'adresse est de classe A\n");
        break;
    case B:
         printf("l'adresse est de classe B\n");
        break;
    case C:
        printf("l'adresse est de classe C\n");
        break;
    case Invalid:
        printf("Not among A B C\n");
        break;
    }
}
int computePow2(int n)
{
    int i,r=1;
    for ( i = 0; i < n; i++)
    {
        r *= 2;
    }
    return(r);  
}
char* changeIPTobinary(int *IP)
{
    int i, q, r, j, t, k = 0;
    char* result = (char*)malloc(36 * sizeof(char) + 1);
    result[36] = '\0'; 

    for (i = 0; i < 4; i++)
    {
        char tmp[9]; 
        q = IP[i];
        tmp[8] = '\0'; 

        for (j = 7; j >= 0; j--)
        {
            r = q % 2;
            tmp[j] = r + '0'; 
            q = q / 2;
        }
        for (t = 0; t < 8; t++)
        {
            result[k++] = tmp[t];
        }
        if (i < 3) 
        {
            result[k++] = '.';
        }
    }

    return (result);
}
char* boolean(char* IP1,char* IP2)
{
    char* result=(char*)malloc(36*sizeof(char) +1);
    result[36]='\0';
    char a,b;
    int i;
    for ( i = 0; i < 35 ; i++)
    {
       a=IP1[i];b=IP2[i];
       if (a==b)
       {
            if (a=='0')
            {
                result[i]='0';
            }
            else if (a=='.')
            {
                result[i]='.';
            }
            else
            {
                result[i]='1';
            }       
       }
       else
       {
            result[i]='0';
       }     
    }
    return(result);
}
int *binaryToIP(char* bin)
{
    int *IP=(int*)malloc(4*sizeof(int));
    int i,j,k=0;
    for ( i = 0; i < 4 ; i++)
    {   
        IP[i]=0;
        for ( j = 7 ; j >= 0; j--)
        {   
            if (bin[k]=='1')
            {
                IP[i] += computePow2(j);
            }  
            k++;
        }
        k++;
    }
    return(IP);
    
}
bool isMSRright(char* binmsr)
{   
    int i;
    for ( i = 0; i < 35; i++)
    {
        if (binmsr[i]=='0' && binmsr[i+1]=='1')
        {
            return(false);
        } 
    }
    return(true); 
}