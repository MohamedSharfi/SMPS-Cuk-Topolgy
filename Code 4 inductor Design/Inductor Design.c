
#include <stdio.h>
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
        float Ap;
        float J;
        float Kg;
        float Ke;
        float Irms;
        float Awbc;
        float N;
        float Wae;
        float Ipeak;
        float L = 0;
        float Imax = 0;
        float Imin = 0;
        float Idc = 0;
        float dI = 0;
        float Pout = 0;
        float F = 0;
        float Bm = 0;
        float Ku = 0;
        float E;
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
        Ipeak = Imax;
        Ipeak = Idc+dI/2;
    }
    
    void dI_value(){
        dI = Imax- Imin;
    }
    
     void Step3(){
        E = (L*Ipeak*Ipeak)/2;
    }
    
     void Step4(){
        Ke = (0.145*Pout*Bm*Bm)/10000;
    }
    
     void Step5(){
        Kg = (E*E)/(Ke*1);
    }
    
      void Step6(){
          //ETD FILEs
        float MPL;
        float MLT;
        float Ac;
        float Wa;
        float Ap;
    }
    
     void Step7(){
        J = 2*(E)*(10000)/(Bm*Ap*ku);
    }
    
       void Step8(){
        Irms = sqart((Idc*Idc) + (dI*dI));
    }
    
       void Step9(){
        Awbc = Irms/J;
        
    }
      void Step10(){
       //WIRE TABLES
       float Awb;
       float Aws;
       float Wr;
    }
    
      void Step11(){
         Wae = Wa*0.75;
        
    }
    
     void Step12(){
         N = Wae*0.6/Aws;
        
    }
    
    
int main()
{
     Step1();
  
  
    return 0;
}