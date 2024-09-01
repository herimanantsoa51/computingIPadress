#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum classe classe;
typedef enum bool bool;
enum classe
{
    A,B,C,D,E,StrError,Invalid
};
enum bool
{
    false,true
};
int* getValIP();
classe whatClassHas(int *IP);
int *getMSRbyDefault(classe c);
int* computeIPReseau(char* binIP,char* binMSR);
int* computeIPBroadcast(char *IPbin,char* MSRbin);
int computeNbrAdressMachine(int* IPRes,int* IPBrod);
void printAdress(int *IP,char *label);
void printClass(classe c);
void finalDisplay(int*IP,int *MSR,int *IPRes,int *IPBrod,int nmachine,classe c);
void getValIPnbitSR(int *IP,int* nbitSR);
int computePow2(int n);
char *computebinMSR(int nbitR);
void errorDisplay(int * MSR,char *MSRbin);
char* changeIPTobinary(int * IP);
char* boolean(char* IP1,char* IP2);
int *binaryToIP(char* bin);
int* getValMSR();
int mainDisplay();
bool isMSRright(char* binmsr);
void mainFree(int* IP, int *MSR,int* Res,int* Brod,char* IPbin,char*MSRbin);
