/* ****************************************************************************** */
// Programme Banner: FileOperations.c
// Created by Shadan
// Start Date: 21/12/2019
// End Date: 03/01/2020
// Description: This file includes all the functions created and called in the main.c
/* ****************************************************************************** */

#include "FileOperations.h" // include the files used



/* ****************************************************************************** */
// Functions below are used for reading Data from sensor files. Each functions reads data from a different location.
/* ****************************************************************************** */


// function for reading  Living room data from sensor files and scanning it into House[0]
void ReadDataLiving() {

int t=0, i; // local variables

    if ((ptr = fopen(LIVING, "r")) == NULL) { // opening file at location LIVING

    printf("Error opening file"); // if NULL this will be printed out
    exit(1); // exit if NULL
   }

    for (t=0; t<24; t++) { //loop1 starts

        //read time, temperature, and humidity values
        fscanf(ptr, "%s", &House[0].Time[t]); //scan Time values

        fscanf(ptr, "%f", &House[0].temp[t][0]); //scan internal temp values

        fscanf(ptr, "%f", &House[0].temp[t][1]);// scan external temp values

        fscanf(ptr, "%f", &House[0].humidity[t]);// scan humidity values


        //read motion data
        for (i=0; i<6; i++) //loop2 for motion

            fscanf(ptr, "%f", &House[0].motion[t][i]); //scan the motion values

    } //loop1 ends

    fclose(ptr); // close the file

} //function ends

//  function for reading Kitchen Data from sensor files and scanning it into House[1]
void ReadDataKitchen() {

    int t=0, i; // local variables

    if ((ptr8 = fopen(KITCHEN, "r")) == NULL) { // opening file at location KITCHEN
        printf("Error opening file"); // if NULL this will be printed out
        exit(1); // exit if NULL
    }

    for (t=0; t<24; t++) { //loop1 starts

//read time, temperature, and humidity values
        fscanf(ptr8, "%s", &House[1].Time[t]); //scan Time values

        fscanf(ptr8, "%f", &House[1].temp[t][0]); //scan internal temp values

        fscanf(ptr8, "%f", &House[1].temp[t][1]);// scan external temp values

        fscanf(ptr8, "%f", &House[1].humidity[t]);// scan humidity values


//read motion data
        for (i=0; i<6; i++) //loop2 for motion

            fscanf(ptr8, "%f", &House[1].motion[t][i]); //scan the motion values

    } //loop1 ends

    fclose(ptr8); // close the file
}

// function for reading Bedroom Data from sensor files and scanning it into House[2]
void ReadDataBedroom() {
    int t=0, i; // local variables

    if ((ptr9 = fopen(BEDROOM, "r")) == NULL) { // opening file at location BEDROOM

        printf("Error opening file"); // if NULL this will be printed out
        exit(1); // exit if NULL
    }

    for (t=0; t<24; t++) { //loop1 starts

        //read time, temperature, and humidity values
        fscanf(ptr9, "%s", &House[2].Time[t]); //scan Time values

        fscanf(ptr9, "%f", &House[2].temp[t][0]); //scan internal temp values

        fscanf(ptr9, "%f", &House[2].temp[t][1]);// scan external temp values

        fscanf(ptr9, "%f", &House[2].humidity[t]);// scan humidity values


        //read motion data
        for (i=0; i<6; i++) //loop2 for motion

            fscanf(ptr9, "%f", &House[2].motion[t][i]); //scan the motion values

    } //loop1 ends

    fclose(ptr9); // close the file
}






/* ****************************************************************************** */
// // // Functions below are used for displaying device states in each location individually, in all locations together, and for each devices individually
/* ****************************************************************************** */

// function for displaying device state for only living room House[0]
void DisplayLiving() {
    int t=0, i; //declaring local variables of type int
    float avg, sum=0;  // declaring variables of type float

    ptr1 = fopen(STATE1, "w"); // creating txt file

    //printing out table headlines
    fprintf(ptr1, "\t\t******************************Living Room****************************\n");
    fprintf(ptr1, "TIME");
    fprintf(ptr1, "\t\t\tHEATER");
    fprintf(ptr1, "\t\tVENTILATOR");
    fprintf(ptr1, "\t\tLIGHT\n");

    // loop1 starts

    for (t = 0; t < 24; t++) { // for 24 hours
        fprintf(ptr1, "\n%s\t\t", House[0].Time[t]); // time is printed out
            sum = 0; // initializing value

            //
            // conditions for devices
            //

            // conditions for heater
            if (House[0].temp[t][0] <= TempThresh) { // if temp is less than or equal to 20 heater on
                fprintf(ptr1, "ON\t\t");
            } else { // else it is off
                fprintf(ptr1, "OFF\t\t");
            }

            //conditions for ventilator
            if (House[0].humidity[t] >= HumThresh) { // if humidity is greater than or equal to 65 ventilator on
                fprintf(ptr1, "ON\t\t\t");
            } else { // else it is off
                fprintf(ptr1, "OFF\t\t\t");
            }

// loop2 starts to find motion avg each hour
            for (i = 0; i < 6; i++) { // 6 different readings for motion

                sum = sum + House[0].motion[t][i]; // sum calculated for 6 readings
                avg = sum / 6; // average calculated
            } // loop2 ends

            // conditions for light
            if (avg >= MotThresh) { // if avg of motion is greater than or equal to 40 lights on
                fprintf(ptr1, "ON\t\t\t\t\t\t");
            } else { // else it is off
                fprintf(ptr1, "OFF\t\t\t\t\t\t");
            }

         // loop1 ends

    }

    fclose(ptr1); // close txt file
}


// function for displaying device state for only kitchen House[1]
void DisplayKitchen() {
    int t=0, i; //declaring local variables of type int
    float avg, sum=0;  // declaring variables of type float

    ptr6 = fopen(STATE2, "w"); // creating txt file

    //printing out table headlines
    fprintf(ptr6, "\t\t******************************KITCHEN****************************\n");
    fprintf(ptr6, "TIME");
    fprintf(ptr6, "\t\t\tHEATER");
    fprintf(ptr6, "\t\tVENTILATOR");
    fprintf(ptr6, "\t\tLIGHT\n");

    // loop1 starts

    for (t = 0; t < 24; t++) { // for 24 hours
        fprintf(ptr6, "\n%s\t\t", House[1].Time[t]); // time is printed out
        sum = 0; // initializing value

        //
        // conditions for devices
        //

        // conditions for heater
        if (House[1].temp[t][0] <= TempThresh) { // if temp is less than or equal to 20 heater on
            fprintf(ptr6, "ON\t\t");
        } else { // else it is off
            fprintf(ptr6, "OFF\t\t");
        }

        //conditions for ventilator
        if (House[1].humidity[t] >= HumThresh) { // if humidity is greater than or equal to 65 ventilator on
            fprintf(ptr6, "ON\t\t\t");
        } else { // else it is off
            fprintf(ptr6, "OFF\t\t\t");
        }

// loop2 starts to find motion avg each hour
        for (i = 0; i < 6; i++) { // 6 different readings for motion

            sum = sum + House[1].motion[t][i]; // sum calculated for 6 readings
            avg = sum / 6; // average calculated
        } // loop2 ends

        // conditions for light
        if (avg >= MotThresh) { // if avg of motion is greater than or equal to 40 lights on
            fprintf(ptr6, "ON\t\t\t\t\t\t");
        } else { // else it is off
            fprintf(ptr6, "OFF\t\t\t\t\t\t");
        }

        // loop1 ends

    }

    fclose(ptr6); // close txt file
}


// function for displaying device state for only bedroom House[2]
void DisplayBedroom() {
    int t=0, i; //declaring local variables of type int
    float avg, sum=0;  // declaring variables of type float

    ptr0 = fopen(STATE3, "w"); // creating txt file

    //printing out table headlines
    fprintf(ptr0, "\t\t******************************BEDROOM****************************\n");
    fprintf(ptr0, "TIME");
    fprintf(ptr0, "\t\t\tHEATER");
    fprintf(ptr0, "\t\tVENTILATOR");
    fprintf(ptr0, "\t\tLIGHT\n");

    // loop1 starts

    for (t = 0; t < 24; t++) { // for 24 hours
        fprintf(ptr0, "\n%s\t\t", House[2].Time[t]); // time is printed out
        sum = 0; // initializing value

        //
        // conditions for devices
        //

        // conditions for heater
        if (House[2].temp[t][0] <= TempThresh) { // if temp is less than or equal to 20 heater on
            fprintf(ptr0, "ON\t\t");
        } else { // else it is off
            fprintf(ptr0, "OFF\t\t");
        }

        //conditions for ventilator
        if (House[2].humidity[t] >= HumThresh) { // if humidity is greater than or equal to 65 ventilator on
            fprintf(ptr0, "ON\t\t\t");
        } else { // else it is off
            fprintf(ptr0, "OFF\t\t\t");
        }

// loop2 starts to find motion avg each hour
        for (i = 0; i < 6; i++) { // 6 different readings for motion

            sum = sum + House[2].motion[t][i]; // sum calculated for 6 readings
            avg = sum / 6; // average calculated
        } // loop2 ends

        // conditions for light
        if (avg >= MotThresh) { // if avg of motion is greater than or equal to 40 lights on
            fprintf(ptr0, "ON\t\t\t\t\t\t");
        } else { // else it is off
            fprintf(ptr0, "OFF\t\t\t\t\t\t");
        }

        // loop1 ends

    }

    fclose(ptr0); // close txt file
}


// function for displaying device state for all rooms House[0], House[1] & House[2]
void DisplayAllData() {

    int t=0, i; //declaring local variables of type int
    float avg, sum=0;  // declaring variables of type float

    ptr4 = fopen(STATE, "w"); // creating txt file

    //printing out table headlines
    fprintf(ptr4, "\t\t******************************Living Room****************************\t\t\t");
    fprintf(ptr4, "************************Kitchen**********************\t\t\t");
    fprintf(ptr4, "\t\t************************BedRoom**********************\n");
    fprintf(ptr4, "TIME");
    fprintf(ptr4, "\t\t\tHEATER");
    fprintf(ptr4, "\t\tVENTILATOR");
    fprintf(ptr4, "\t\tLIGHT\t\t\t");
    fprintf(ptr4, "\t\t\tHEATER");
    fprintf(ptr4, "\t\tVENTILATOR");
    fprintf(ptr4, "\t\tLIGHT\t\t\t");
    fprintf(ptr4, "\t\t\tHEATER");
    fprintf(ptr4, "\t\tVENTILATOR");
    fprintf(ptr4, "\t\tLIGHT\n");



    // loop1 starts

        for (t = 0; t < 24; t++) { // for 24 hours
            fprintf(ptr4, "\n%s\t\t", House[1].Time[t]); // time is printed out
            for (d=0; d<3; d++) { // loop for the three different rooms in which 0 is living, 1 is kitchen, and 2 is bedroom
            sum = 0; // initializing value



            //
            // conditions for devices
            //

            // conditions for heater
            if (House[d].temp[t][0] <= TempThresh) { // if temp is less than or equal to 20 heater on
                fprintf(ptr4, "ON\t\t");
            } else { // else it is off
                fprintf(ptr4, "OFF\t\t");
            }

            //conditions for ventilator
            if (House[d].humidity[t] >= HumThresh) { // if humidity is greater than or equal to 65 ventilator on
                fprintf(ptr4, "ON\t\t\t");
            } else { // else it is off
                fprintf(ptr4, "OFF\t\t\t");
            }

// loop2 starts to find motion avg each hour
            for (i = 0; i < 6; i++) { // 6 different readings for motion

                sum = sum + House[d].motion[t][i]; // sum calculated for 6 readings
                avg = sum / 6; // average calculated
            } // loop2 ends

            // conditions for light
            if (avg >= MotThresh) { // if avg of motion is greater than or equal to 40 lights on
                fprintf(ptr4, "ON\t\t\t\t\t\t");
            } else { // else it is off
                fprintf(ptr4, "OFF\t\t\t\t\t\t");
            }

        } // loop1 ends
        printf("\n");
    }

    fclose(ptr4); // close txt file
}

// function for displaying heaters state for different locations
void DisplayHeater () {
    int t, d;


    ptr5 = fopen(HEATER, "w");
    fprintf(ptr5, "*****HEATER STATE AT THREE DIFFERENT LOCATIONS******\n\n\n");
    fprintf(ptr5, "TIME\t\t");
    fprintf(ptr5, "LIVING ROOM\t\t");
    fprintf(ptr5, "KITCHEN\t\t\t");
    fprintf(ptr5, "BEDROOM\n");

    for (t=0; t<24; t++) {
        fprintf(ptr5, "\n%s\t", House[0].Time[t]);
        for (d=0; d<3; d++) { // loop for the three different rooms in which 0 is living, 1 is kitchen, and 2 is bedroom
            if (House[d].temp[t][0] <= TempThresh) { // if temp is less than or equal to 20 heater on
                fprintf(ptr5, "ON\t\t\t");
            } else { // else it is off
                fprintf(ptr5, "OFF\t\t\t");
            }

        }
    }
    fclose(ptr5);
}

// function for displaying ventilator state for different locations
void DisplayVentilator () {
    int t, d;

    ptr10 = fopen(VENTILATOR, "w");
    fprintf(ptr10, "******VENTILATOR STATE AT THREE DIFFERENT LOCATIONS******\n\n\n");
    fprintf(ptr10, "TIME\t\t");
    fprintf(ptr10, "LIVING ROOM\t\t");
    fprintf(ptr10, "KITCHEN\t\t\t");
    fprintf(ptr10, "BEDROOM\n");

    for (t=0; t<24; t++) {
        fprintf(ptr10, "\n%s\t", House[0].Time[t]);
        for (d=0; d<3; d++) { // loop for the three different rooms in which 0 is living, 1 is kitchen, and 2 is bedroom
            //conditions for ventilator
            if (House[d].humidity[t] >= HumThresh) { // if humidity is greater than or equal to 65 ventilator on
                fprintf(ptr10, "ON\t\t\t");
            } else { // else it is off
                fprintf(ptr10, "OFF\t\t\t");
            }

        }
    }
    fclose(ptr10);

}


// function for displaying lights state for different locations
void DisplayLights () {
    int t, d, i, sum=0, avg;

    ptr7 = fopen(LIGHTS, "w");
    fprintf(ptr7, "******LIGHTS STATE AT THREE DIFFERENT LOCATIONS******\n\n\n");
    fprintf(ptr7, "TIME\t\t");
    fprintf(ptr7, "LIVING ROOM\t\t");
    fprintf(ptr7, "KITCHEN\t\t\t");
    fprintf(ptr7, "BEDROOM\n");

    for (t=0; t<24; t++) {
        fprintf(ptr7, "\n%s\t", House[0].Time[t]);
        for (d=0; d<3; d++) {  // loop for the three different rooms in which 0 is living, 1 is kitchen, and 2 is bedroom
            //conditions for ventilator
            for (i = 0; i < 6; i++) { // 6 different readings for motion

                sum = sum + House[d].motion[t][i]; // sum calculated for 6 readings
                avg = sum / 6; // average calculated
            } // loop2 ends

            // conditions for light
            if (avg >= MotThresh) { // if avg of motion is greater than or equal to 40 lights on
                fprintf(ptr7, "ON\t\t\t");
            } else { // else it is off
                fprintf(ptr7, "OFF\t\t\t");
            }

        }
    }
    fclose(ptr7);

}




/* ****************************************************************************** */
// Function below is used for calculating total energy consumption for all devices in all locations.
/* ****************************************************************************** */

// function for calculating energy consumption for all devices at three different locations
 void DisplayEnergy() {

int le=0, he=0, ve=0, energy, t=0, i=0, total[24];
float sum=0, avg;


    ptr2 = fopen(ENERGY, "w"); // creating txt file

    fprintf(ptr2, "\t\t\t\t\t\t\t\t\t\t\t******************************** DAILY ENERGY CONSUMPTION *******************************\n\n\n\n\n\n"); //printing out the titles of the table
    fprintf(ptr2, "\t\t******************************Living Room****************************\t\t\t");
    fprintf(ptr2, "************************Kitchen**********************\t\t\t");
    fprintf(ptr2, "\t\t************************BedRoom**********************\n");
    fprintf(ptr2, "TIME");
    fprintf(ptr2, "\t\t\tHEATER");
    fprintf(ptr2, "\t\tVENTILATOR");
    fprintf(ptr2, "\t\tLIGHT\t\t\t");
    fprintf(ptr2, "\t\t\tHEATER");
    fprintf(ptr2, "\t\tVENTILATOR");
    fprintf(ptr2, "\t\tLIGHT\t\t\t");
    fprintf(ptr2, "\t\t\tHEATER");
    fprintf(ptr2, "\t\tVENTILATOR");
    fprintf(ptr2, "\t\tLIGHT\n");



for (t=0; t<24; t++) { // main loop for 24 hrs

    fprintf(ptr2, "\n%s\t\t", House[0].Time[t]); // time is printed out
    for (d = 0; d < 3; d++) { // loop for the three different rooms in which 0 is living, 1 is kitchen, and 2 is bedroom
        // heater energy consumption
        if (House[d].temp[t][0] <= TempThresh) { // if temp is less than or equal to 20
            fprintf(ptr2, "300 KJ\t\t");
            t1 = t1 + 1; // hour usage

        } else {
            fprintf(ptr2, "0 KJ\t\t");
        }

        // ventilator energy consumption
        if (House[d].humidity[t] >= HumThresh) { // if humidity is greater than or equal to 65
            fprintf(ptr2, "250 KJ\t\t\t");
            t2 = t2 + 1; // hour usage
        } else {
            fprintf(ptr2, "0 KJ\t\t\t");
        }

        // lights energy consumption
        for (i = 0; i < 6; i++) { //loop for calculation avg again
            sum = sum + House[d].motion[t][i]; // sum calculated for 6 readings
            avg = (sum / 6); // average calculated
        }
        if (avg >= MotThresh) { // if avg of motion is greater than or equal to 40
            fprintf(ptr2, "100 KJ\t\t\t\t\t\t");
            t3 = t3 + 1; // hour usage
        } else {
            fprintf(ptr2, "0 KJ\t\t\t\t\t\t");
        }

        sum = 0; // clearing the sum to be used later again

    }
    printf("\n");
}

// hour usage used to calculate energy consumption
he = t1 * 300;
ve = t2 * 250;
le = t3 * 100;

    energy = le + he + ve; // calculating daily energy consumption of all devices

    fprintf(ptr2, "\n\n\n\nDaily energy for heater: %d\n", he);
    fprintf(ptr2, "Daily energy for ventilation: %d\n", ve);
    fprintf(ptr2, "Daily energy for lights: %d", le);
    fprintf(ptr2, "\n\nTotal Daily Energy Consumption = %d KJ", energy);


fclose(ptr2); // file closed

} // end of function




/* ****************************************************************************** */
// Functions below is used to calculate the number of hours each device was on for for all locations.
/* ****************************************************************************** */

//function for printing out hour usage and energy consumption values of the three devices
void HourUsage () {

    ptr3 = fopen(HOUR, "w"); // creating txt file

    // calculating energy consumption using working hours of devices

    he = t1 * 300;
    ve = t2 * 250;
    le = t3 * 100;


    // printing out the results
    fprintf(ptr3, "\t****** HOURLY USAGE OF DEVICES ******\n\n"); // header

    fprintf(ptr3, "HEATER\t\t %d HOURS\t\t %d KJ\n", t1, he); // HEATER VALUES

    fprintf(ptr3, "VENTILATOR\t %d HOURS\t\t %d KJ\n", t2, ve); //VENTILATOR VALUES

    fprintf(ptr3, "LIGHTS\t\t %d HOURS\t\t %d KJ\n", t3, le); //LIGHTS VALUES

    fclose(ptr3); // file closed

}; // end of function





