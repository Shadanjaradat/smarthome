/* ****************************************************************************** */
// Programme Banner: FileOperations.h
// Created by Shadan
// Start Date: 21/12/2019
// End Date: 25/01/2020
// Description: This file includes all the headers, definitions, and global variables used in FileOperations.c and main.c
/* ****************************************************************************** */

#ifndef FILEPROCESSING_FILEOPERATIONS_H
#define FILEPROCESSING_FILEOPERATIONS_H

//header files
#include <stdio.h> // for basic operations such as printing and scanning
#include <stdlib.h> // for memory
#include <time.h> // for recording of date and time
#include <string.h> // for use of string
#include <unistd.h>



//definitions
#define MotThresh 40 // these definitions are for threshold values
#define TempThresh 20
#define HumThresh 65

// the definitions shown below are the location of the files read, and created
#define HEATER "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\Output\\heater.txt"
#define VENTILATOR "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\Output\\ventilator.txt"
#define LIGHTS "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\Output\\lights.txt"
#define LIVING "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\living.txt"
#define KITCHEN "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\kitchen.txt"
#define BEDROOM "C:\\Users\\Shadan\\Desktop\\zzzPROJECT-JAN\\bedroom.txt"
#define STATE1 "C:\\Users\\Shadan\\Desktop\\Project-JAN\\Output\\living-device-state.txt"
#define STATE2 "C:\\Users\\Shadan\\Desktop\\Project-JAN\\Output\\kitchen-device-state.txt"
#define STATE3 "C:\\Users\\Shadan\\Desktop\\Project-JAN\\Output\\bedroom-device-state.txt"
#define STATE "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\Output\\all-device-state.txt"
#define ENERGY "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\Output\\energy.txt"
#define HOUR "C:\\Users\\Shadan\\Desktop\\PROJECT-JAN\\output\\hour.txt"



// Global Variables
// a new file pointer is used for each txt file
FILE *ptr;// declaring the file pointer
FILE *ptr1;
FILE *ptr2;
FILE *ptr3;
FILE *ptr5;
FILE *ptr8;
FILE *ptr9;
FILE *ptr6;
FILE *ptr0;
FILE *ptr4;
FILE *ptr7;
FILE *ptr10;


// struct is used to store values of time, temp, humidity, and motion for 3 different rooms
struct Location {
    char Time[24][25];
    float temp[24][2];
    float humidity[24];
    float motion[24][6];
}; struct Location House[3]; // [3] shows that three of this struct are used


int t1, t2, t3, he, le, ve, d; // global variables to make calculations easier and more accessible




// prototypes
// functions created and used
void ReadDataLiving();
void ReadDataKitchen();
void ReadDataBedroom();
void DisplayHeater();
void DisplayVentilator();
void DisplayLights();
void DisplayAllData();
void DisplayLiving();
void DisplayKitchen();
void DisplayBedroom();
void DisplayEnergy();
void HourUsage();


#endif // FILEPROCESSING_FILEOPERATIONS_H