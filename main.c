/* ****************************************************************************** */
// Programme Banner: CProgramming Project
// Created by Shadan
// Start Date: 18/12/2019
// End Date: 06/01/2020
// Description: This file includes the main function that calls the functions created in FileOperations.c using a menu based interface.
/* ****************************************************************************** */

#include "FileOperations.h" // including the files used



// main function
int main () {
    int i, n, s; // local variables
i=0;



printf("\nWelcome TO THE PROGRAM THAT CONTROLS THE STATE OF THREE DEVICES (heater, lights, and ventilator) IN KITCHEN, BEDROOM, AND LIVING ROOM\n MENU IS SHOWN BELOW\n\n");

     while (i!=1) { // loop created so that the menu is dislplayed over and over again, unless program is ended
printf("Threshold values:\nHeater:%d\nVentilator:%d\nLights:%d\n\n", TempThresh, HumThresh, MotThresh); // displaying threshold values to the user
printf("******INSTRUCTION: TO DISPLAY ANY DATA IN TXT FILES, DATA FROM SENSORS HAS TO BE READ FIRST******\n\n\n"); // txt files would show zero if files were not scanned

// the lines displayed below show the menu created for the program
         printf("1. Read Data From Sensors\n");
         printf("2. Display Device State In Certain Location\n");
         printf("3. Display Device State Of A Certain Device\n");
         printf("4. Display Daily Energy Usage\n");
         printf("5. Display The Time The Devices Are On For\n");
         printf("6. End Program\n");

         printf("What do you want the program to do?");
         scanf("%d", &n); // users option will be scanned into n


   switch (n) { // switch n used to control what happens depending on the user's choice



      case 1: // case 1 is for reading sensor data from txt files
              printf("Which Room?\n");
              printf("1. Living.\n 2. Kitchen.\n 3.Bedroom.\n 4.All Rooms.\n");
              scanf("%d", &s);

              switch (s) { // another switch s created to read different files for different locations

                  case 1:
                  ReadDataLiving();
                  break;


                  case 2:
                  ReadDataKitchen();
                   break;


                  case 3:
                  ReadDataBedroom();
                  break;

                  case 4:
                  ReadDataLiving();
                  ReadDataKitchen();
                  ReadDataBedroom();
                  break;
                          } // switch s ends

       break; // case 1 for switch n ends



       case 2: // case 2 is displaying state of all devices in specific locations
              printf("Which Room?\n");
              printf("1. Living.\n 2. Kitchen.\n 3.Bedroom.\n 4.All Rooms.\n");
              scanf("%d", &s);

              switch (s) { // switch s created to allow the user choose the location

                  case 1:
                  DisplayLiving();
                  break;

                  case 2:
                  DisplayKitchen();
                  break;

                  case 3:
                  DisplayBedroom();
                  break;

                  case 4:
                  DisplayAllData();
                  break;
                          } // switch s ends


        break; // case 2 for switch n ends




       case 3: // case 3 is used to allow the user to examine a certain devices state in all locations
              printf("Which Device?\n");
              printf("1.Heater\n2.Ventilator\n3.Light\n");
              scanf("%d", &s);


              switch (s) { // switch s created to allow the user to choose which device wanted

                  case 1:
                      DisplayHeater();
                  break;

                  case 2:
                      DisplayVentilator();
                  break;

                  case 3:
                      DisplayLights();
                  break;
                           } // switch s ends

         break; // case 3 for switch n ends


       case 4: // case 4 is for displaying energy values for all devices in all locations
              DisplayEnergy();

        break; // case 4 for switch n ends



        case 5: // case 5 is for displaying hourly usage for all devices in all locations
              DisplayEnergy();
              HourUsage();

         break;  // case 5 for switch n ends



       case 6: // case 6 is for ending the program
              
        return (0);



      } // switch n ends

      } // while loop ends


} // main function ends