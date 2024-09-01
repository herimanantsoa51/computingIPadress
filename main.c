#include "testip.h"

int main ()
{
    int *IP=NULL,*MSR=NULL,*IPRes=NULL,*IPBrod=NULL,i,n_IPMachine,nbitR,choice;
    char *MSRbinary,*IPbinary;
    while (1)
    {
       choice=mainDisplay();
        switch (choice)
        {
        case 1:
            IP=getValIP();
            MSR=getValMSR();
            MSRbinary=changeIPTobinary(MSR);
            if (isMSRright(MSRbinary)==true)
            {
                IPbinary=changeIPTobinary(IP);
                IPRes=computeIPReseau(IPbinary,MSRbinary);
                IPBrod=computeIPBroadcast(IPbinary,MSRbinary);
                n_IPMachine=computeNbrAdressMachine(IPRes,IPBrod);
                finalDisplay(IP,MSR,IPRes,IPBrod,n_IPMachine,whatClassHas(IP));
            }
            else
            {
                errorDisplay(MSR,MSRbinary);
            }  
            break;
        case 2:
            getValIPnbitSR(IP,&nbitR);
            MSRbinary=computebinMSR(nbitR);
            MSR=binaryToIP(MSRbinary);
            IPbinary=changeIPTobinary(IP);
            IPRes=computeIPReseau(IPbinary,MSRbinary);
            IPBrod=computeIPBroadcast(IPbinary,MSRbinary);
            n_IPMachine=computeNbrAdressMachine(IPRes,IPBrod);
            finalDisplay(IP,MSR,IPRes,IPBrod,n_IPMachine,whatClassHas(IP));
            break;
        case 3:
            return(0);
            break;
        }
        mainFree(IP,MSR,IPRes,IPBrod,IPbinary,MSRbinary);
    }
     
    
}