#include <stdio.h>

int main()
{
    float OutputWire[4];
    FILE *pF = fopen("E:\\MY CVs\\GitHub\\SMPS---IC-vs-Traditional\\Code 4 inductor Design\\DataForWires\\Wires.csv", "r");

    if (pF == NULL) {
        printf("Unable to open file!\n");
        return 1; // Exit the program if the file cannot be opened
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
    printf("Loaded Table:\n");

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            if (j==0){
                
            printf("%6.0f ", buffer[i][j]); //readings less decimal points
        }
         else if (j == 3){
                
            printf("%6.2f ", buffer[i][j]); //readings less decimal points
        }

        else{
              printf("%6.10f ", buffer[i][j]); //readings need more decimal points
        }     
    }
    printf("\n");
    }

    float User_WIRE;
      float FoundValue;
    printf("Please insert the wire area in cm: ");
    scanf("%f",&User_WIRE);
    printf("You entered: %.56f cm\n", User_WIRE);

    for (int i = 0; i < 35; i++) {
        if (buffer[i][1] < User_WIRE) {
            FoundValue = buffer[i][1]; // Store the value as a float
            for(int j = 0 ; j<4;j++){
                
            OutputWire[j] = buffer[i][j];
             }
            break;                        // Exit the loop as we found the first less value
       
    }
printf("FOUNDED : %.20f cm\n", FoundValue);
printf("OUPUT : %.20f cm\n", OutputWire[0]);
printf("OUPUT : %.20f cm\n", OutputWire[1]);
printf("OUPUT : %.20f cm\n", OutputWire[2]);
printf("OUPUT : %.20f cm\n", OutputWire[3]);
    return 0;

}
}
