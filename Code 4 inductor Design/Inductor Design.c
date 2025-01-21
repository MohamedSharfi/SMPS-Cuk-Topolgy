
#include <stdio.h>
#include <math.h>
        float MPL;
        float MLT;
        float Ac;
        float Wa;
        float Ap;
        float Awb;
        float Aws;
        float Wr;
        float Aws;
        float Wa;
        float ku;
        float J;
        float Kg;
        float Ke;
        float Irms;
        float Awbc;
        float N;
        float Wae;
        float Ipeak;
        float E;
        
        float L,Imax,Imin,Idc,dI,Pout,F,Bm,Ku;
       

        void Step1(){

       // Prompt the user to input the following values
printf("Enter the value of Inductor (L in Henry): ");
scanf("%f", &L);

printf("Enter the maximum current (Imax in Amps): ");
scanf("%f", &Imax);

printf("Enter the minimum current (Imin in Amps): ");
scanf("%f", &Imin);

printf("Enter the DC current (Idc in Amps): ");
scanf("%f", &Idc);

printf("Enter the current ripple (dI in Amps): ");
scanf("%f", &dI);

printf("Enter the output power (Pout in Watts): ");
scanf("%f", &Pout);

printf("Enter the switching frequency (F in Hz): ");
scanf("%f", &F);

printf("Enter the flux density (Bm in Tesla): ");
scanf("%f", &Bm);

printf("Enter the utilization factor (Ku): ");
scanf("%f", &Ku);
    }

    void Step2(){
        
    if(dI==0){
         dI = Imax - Imin;
    }
        
    if(Imax == 0){
            if(Idc>0){
                 Ipeak = Idc+(dI/2);
            }
            else {
                 Ipeak = Imin + dI;
            }
          
        }
        
    if(Imax > 0){
        Ipeak = Imax;
        Idc = Imax - (dI/2);
        }
        
    }
       
       
    
    
     void Step3(){
        E = (L*Ipeak*Ipeak)/2;
        printf("Energy : %f \n",E);
    }
    
     void Step4(){
        Ke = (0.145*Pout*Bm*Bm)/10000;
    }
    
     void Step5(){
        Kg = (E*E)/(Ke*1);
    }
    
      void Step6(){
          //ETD FILEs
         MPL=9.22;
         MLT=8.3;
         Ac=1.252;
         Wa=2.34;
        Ap=2.93;


    }
    
     void Step7(){
        J = (2*(E)*(10000))/((Bm*Ap*Ku));
          printf("Current Desnsity : %f \n",J);
    }
    
       void Step8(){
        Irms = sqrt((Idc*Idc) + (dI*dI));
          printf("Current RMS : %f \n",Irms);
    }
    
       void Step9(){
        Awbc = Irms/J;
          printf("Wire needed : %f \n",Awbc);
    }
      void Step10(){
        
       //WIRE TABLES
       Awb=0.00653;
       Aws = 0.00754;
       Wr = 104.3;
    }
    
      void Step11(){
         Wae = Wa*0.75;
         printf("Effective window :%f \n",Wae);
        
    }
    
     void Step12(){
         N = Wae*0.6/Aws;
         printf(" Turns : %f \n",N);
        
    }
    
     void DoMath(){
        
         Step2();
         Step3();
         Step4();
         Step5();
         Step6();
         Step7();
         Step8();
         Step9();
         Step10();
         Step11();
         Step12();
       printf("%f",N);
        
    }

int main()
{
    L=0.0025;
    Imax= 0;
    Idc = 1.5;
    dI=0.25;
    Pout = 100;
    F = 200000;
    Bm = 0.22;
    Ku = 0.4;
    
     DoMath();
     
    return 0;
}