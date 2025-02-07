
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
        float User_WIRE;
        float OutputWire[4];
        void FileWire();



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
         MPL=7.2;
         MLT=6.4;
         Ac=0.761;
         Wa=1.419;
         Ap=1.0800;


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
        User_WIRE = Irms/J;
               printf("\n");
        printf("Wire needed : %f \n",User_WIRE);
               printf("\n");
           FileWire();

    }
      void Step10(){

       //WIRE TABLES
       Awb = OutputWire[1];
       Aws = OutputWire[2];
       Wr  = OutputWire[3];
    }

      void Step11(){
         Wae = Wa*0.75;
         printf("Effective window :%f \n",Wae);

    }

     void Step12(){
         N = Wae*0.6/Aws;
         printf("Turns : %f \n",N);

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
       printf("\n");

    }

int main()
{
    L=0.00016;
    Imax= 2.655;
    Idc =0;
    dI=0.2435;
    Pout = 25;
    F = 50000;
    Bm = 0.22;
    Ku = 0.4;

     DoMath();

    return 0;
}


void FileWire(){

    FILE *pF = fopen("E:\\MY CVs\\GitHub\\SMPS---IC-vs-Traditional\\Code 4 inductor Design\\DataForWires\\Wires.csv", "r");

    if (pF == NULL) {
        printf("Unable to open file!\n");

    }

//once file edited this should be changed? - NEED TO BE AUTO
    float buffer[35][4]; // 10 rows, 4 columns
    int rows = 35, cols = 4;

    // Read data from the file into the buffer
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(pF, "%f,", &buffer[i][j]) != 1) {
                printf("Error reading data at row %d, column %d\n", i, j);
                buffer[i][j] = 0; // Assign default value in case of error
            }
        }
    }

    fclose(pF);

    // Print the loaded table make sure all are good



    float FoundValue;

    for (int i = 0; i < 35; i++) {
        if (buffer[i][1] < User_WIRE) {
            FoundValue = buffer[i][1]; // Store the value as a float

            for(int j = 0 ; j<4;j++){
            OutputWire[j] = buffer[i][j];
             }

            break;                        // Exit the loop as we found the first less value
    }
    }
       printf("\n");
printf("FOUNDED : %.6f cm\n", FoundValue);
printf("Wire Name : AWG%2.0f\n", OutputWire[0]);
printf("Wire Area Bare : %.6f \n", OutputWire[1]);
printf("Wire Area w Iso : %.6f \n", OutputWire[2]);
printf("Wire Resistance : %.1f ohm\n", OutputWire[3]);
   printf("\n");
}
