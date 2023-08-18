/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Clinic_Management_System
// File          : main.c
// Date          : 5 Jan 2022
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/



#include<stdio.h>
#include"systemFunctions.h"
#include"datatypes.h"
#include<stdlib.h>
#include<conio.h>

u16 main(void)
{
	u8 exitFlag = 0;
	system("cls"); // bultin function to clear cmd
	importData(); // this function to import all patient data from systemdata.txt file
	importSlotsData();// this function to import all slots data from systemslotsdata.txt file
	printf("Current Date: %s\n",__DATE__);// date macro to print current date
    printf("Current Time: %s\n",__TIME__);// time macro to print current time
	printf("Welcome In Clinc Mangment System \n");
	while(1) // while one loop to make program run without stop 
	{
		u16 roleChoice;
		u16 processChoice;
		if(exitFlag == 1) break;
		printf("Chosse Your Role [1 - Admin | 2 - User | 3 - Exit From The Program] \n");
		scanf("%d",&roleChoice);
		system("cls");

		switch(roleChoice)
		{	// switch case to chosse end user role 
			case 1:
				{		// case 1 then user chosse admin role
						if(login()) // login function to take password of admin and check it
						{	
							u8 exitFlag = 0;
							while(1)
							{
								if(exitFlag == 1) break;
								processReChoiceAdmin:
								system("cls");
								printf("Chosse What Is Your Process \n");// this is admin main menu
								printf("=========================================================== \n");
								printf("1  - Add New Patient Record\n");
								printf("2  - Edit Patient Record\n");
								printf("3  - Reserve A Slot With The Doctor\n");
								printf("4  - Cancel Reservation\n");
								printf("5  - Display All Patient Record\n");
								printf("6  - Add New Reverse Slot\n");
								printf("7  - Display All Reserve Slots\n");
								printf("8  - Cancel All Reserve Slots \n");
								printf("9  - Delete Patient Record \n");
								printf("10 - Restore Patient Record \n");
								printf("11 - Import All Recorded Data\n");
								printf("12 - Export All Recorded Data\n");
								printf("13 - To Exit For Main Menu \n");
								printf("=========================================================== \n");
								printf("Enter Your Choice \n");
								scanf("%d",&processChoice);
								printf("=========================================================== \n");

								switch(processChoice)
								{  // nested switch to make user choice from the menu of admin role
									case 1:
										{
											insertNewPatientRecord();
											system("cls");
											break;
										}
									case 2:
										{
											editPatientRecord();
											system("cls");
											break;
										}
									case 3:
										{
											reverseAvalibleSlot();
											system("cls");
											break;
										}
									case 4:
										{
											cancelReversedSlot();
											system("cls");
											break;
										}
									case 5:
										{
											displayAllRecord();
											system("cls");
											break;
										}
									case 6:
										{
											insertNewReverseSlot();
											system("cls");
											break;
										}
									case 7:
										{
											displayAllSlots();
											system("cls");
											break;
										}
									case 8:
										{
											resetAllSlotAvilableFlag();
											system("cls");
											break;
										}
									case 9:
										{
											deletePatientRecord();
											system("cls");
											break;
										}
									case 10:
										{
											restorePatientRecord();
											system("cls");
											break;
										}
									case 11:
										{
											importAllData();
											system("cls");
											break;
										}
									case 12:
										{
											exportAllData();
											system("cls");
											break;
										}
									case 13:
										{
											exitFlag = 1;
											break;
										}
									default:
										{
											printf("Wrong Choice Please Try Again... \n");
											goto processReChoiceAdmin;// if the user enter wrong choice will return to the admin role menu to rechosse
											break;
										}
								}
							}
						  
						}
					  	else
						{
							printf("Too Many Wrong Attempt Program Will Termnat...\n");
							return 0;
						}
						system("cls");
						break;
					}
				case 2:
					{ // case user chosse user role

						u8 exitFlag = 0;
						while(1)
						{ 
							if(exitFlag == 1) break;
							processReChoiceUser:
							system("cls");
							printf("Chosse What Is Your Process \n"); // main menu for user role
							printf("=========================================================== \n");
							printf("1 - View Patient Record\n");
							printf("2 - View Today Reservations\n");
							printf("3 - To Exit For Main Menu\n");
							printf("=========================================================== \n");
							printf("Enter Your Choice \n");
							scanf("%d",&processChoice);
							printf("=========================================================== \n");

							switch(processChoice)
							{ // nested switch for user role to chosse from his main menu
								case 1:
									{
										viewPatientRecord();
										break;
									}
								case 2:
									{
										viewTodayReservations();
										break;
									}
								case 3:
									{
										exitFlag = 1;
										break;
									}	
								default:
									{
										printf("Wrong Choice Please Try Again... \n");
										goto processReChoiceUser;// if the user enter wrong choice will return to the admin role menu to rechosse
										break;
									}
							}
						}
						system("cls");
						break;
					}
				case 3:
					{
						exitFlag = 1;
						system("cls");
						break;
					}
		}
	}
	printf("Thanks For Using Our System ");
	exportData(); // export all new data of paitant to file before the program terminat 
	exportSlotsData();// export all new data of slots to file before the program terminat
}
