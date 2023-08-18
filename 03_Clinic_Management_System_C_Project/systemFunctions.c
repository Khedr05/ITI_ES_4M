/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Clinic_Management_System
// File          : systemFunctions.c
// Date          : 5 Jan 2022
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include"systemFunctions.h"



//======================================== patient functions implemantation ==================================


typedef struct p // define struct for patinet data
{
	u8 name[NAME_BUFFER_MAX_SIZE];
	u16 age;
	u8 gender[GENDER_BUFFER_MAX_SIZE];
	u16 id;
	u16 reserveSlotNo;
	u8 deletePatientFlag;
	struct p *next;
	
}patient;

patient *HEAD = NULL; // define a pointer with null from type of patient 


u16 login(void) // login function to check admin password is true or wrong
{
	u16 defaultPassword = 1234; // default password for admin role
	u16 inputPassword;
	u8 counter = 0;
	u8 flag = 0;

	printf("Enter Password \n");
	scanf("%d",&inputPassword);

	for(u8 i=0;i<2;i++) // user have 3 times to input wrong password after that the program will termnat
	{
		if(defaultPassword == inputPassword)
		{
			flag = 1;
			break;
		}
		else
		{
			printf("Invalid Password Please Try Again \n");
			scanf("%d",&inputPassword);
			system("cls");
		}
	}
	return flag;
}





u16 idExist(u16 idCheck) // functin use to check if patient id is taken or not
{
	u16 checkFlag = 1;
	patient *check = HEAD; // define pointer from type patient and its value equal HEAD

	while(check!=NULL) // loop on all patient in the linkedlist to check thir id
	{
		if(check->id == idCheck) 
		{
			checkFlag = 0; // if any patient has the same id then turn off the flag
		}
	 
	 check = check->next;
	}
	return checkFlag; 
}


void addNewRecord(void) // fucntion to create the linkedlist and take the first patient data
{
	patient *newPatientRecord = (patient*) malloc(sizeof(patient));
	
	printf("Add New Patient Info \n");
	printf("Enter Patient Id : ");	
	scanf("%d",&newPatientRecord->id);
	printf("Enter Patient Age : ");
	scanf("%d",&newPatientRecord->age);
	printf("Enter Patient Name : ");
	getchar();
	getString(newPatientRecord->name , NAME_BUFFER_MAX_SIZE);
	printf("Enter Patient Gender : ");
	getString(newPatientRecord->gender , GENDER_BUFFER_MAX_SIZE);

	newPatientRecord->reserveSlotNo = 0;
	newPatientRecord->deletePatientFlag = 0;
	newPatientRecord->next = HEAD;
	HEAD = newPatientRecord;
	exportData();
	printf("Press Any Key To Continue....");
	getch();
	system("cls");
}


void insertNewPatientRecord(void)// function use to insert patient and take its information
{
	if(HEAD == NULL) // if head == null it mean that the linkedlist is not create 
	{
		addNewRecord(); // call function to create it and take patient info
	}
	else
	{ // else then take the patiant info directly
	patient *insertPatientRecord = (patient*) malloc(sizeof(patient));
	printf("Add New Patient Info \n");
	printf("Enter Patient Id : ");	
	scanf("%d",&insertPatientRecord->id);
	if(!idExist(insertPatientRecord->id)) // check if the id already taken or not
	{
		printf("Id Is Taken Please Press Any Key To Continue...\n");
		free(insertPatientRecord);
		getch();
		system("cls");
		return;
	}
	printf("Enter Patient Age : ");
	scanf("%d",&insertPatientRecord->age);
	printf("Enter Patient Name : ");
	getchar();
	getString(insertPatientRecord->name , NAME_BUFFER_MAX_SIZE);
	printf("Enter Patient Gender : ");
	getString(insertPatientRecord->gender , GENDER_BUFFER_MAX_SIZE);

	insertPatientRecord->reserveSlotNo = 0;
	insertPatientRecord->deletePatientFlag = 0;
	insertPatientRecord->next = HEAD;
	HEAD = insertPatientRecord;
	exportData();
	printf("Press Any Key To Continue....");
	getch();
	}
}





void displayAllRecord(void)
{
    // Function to display all patients in the system
    printf("==================================================================================================================\n");
    printf("| Patient Id | Patient Name     | Patient Gender | Patient Age | Patient Reserved Slot No |\n");
    printf("==================================================================================================================\n");

    patient *display = HEAD;

    while (display != NULL)
    {
        if (display->deletePatientFlag == 0)
        {
            printf("| %-10d | %-16s | %-14s | %-11d | %-24d |\n", display->id, display->name, display->gender, display->age, display->reserveSlotNo);
        }
        display = display->next;
    }

    printf("==================================================================================================================\n");
    printf("Press Any Key To Continue....");
    getch();
}


void editPatientName(u16 patientId)
{ // function take patient id and edit its name
	patient *editName = HEAD;
	u8 newName[NAME_BUFFER_MAX_SIZE];
	while(editName != NULL)
	{
		if(editName->id == patientId)
		{
			printf("Enter Patient New Name \n");
			getchar();
			getString(newName , NAME_BUFFER_MAX_SIZE);
			strcpy(editName->name , newName);
			break;
		}
	 editName = editName->next; 
	}	
}

void editPatientGender(u16 patientId)
{// function take patient id and edit its gender
	patient *editGender = HEAD;
	u8 newGender[GENDER_BUFFER_MAX_SIZE];
	while(editGender != NULL)
	{
		if(editGender->id == patientId)
		{
			printf("Enter Patient New Gender \n");
			getchar();
			getString(newGender, GENDER_BUFFER_MAX_SIZE);
			strcpy(editGender->gender , newGender);
			break;
		}
	 editGender = editGender->next; 
	}	
}

void editPatientAge(u16 patientId)
{// function take patient id and edit its age
	patient *editAge = HEAD;
	u8 newAge[AGE_BUFFER_MAX_SIZE];
	while(editAge != NULL)
	{
		if(editAge->id == patientId)
		{
			printf("Enter Patient New Age \n");
			getchar();
			getString(newAge,4);
			editAge->age = atoi(newAge);
			break;
		}
	 editAge = editAge->next; 
	}	
}


void editPatientRecord(void)
{// function to know from user which is patient id to edit and what to edit then call its function
	static u16 patientId;
	u16 editChoice;
	u16 notFoundFlag = 1;
	printf("Enter Patient Id \n");
	scanf("%d",&patientId);
	patient *edit = HEAD;
	while(edit != NULL)
	{	
		if(edit->id == patientId)
		{
			if(edit->deletePatientFlag == 0)
			{
				notFoundFlag = 0;
				printf("============================================== Patient Data ======================================================\n");
				printf("==================================================================================================================\n");
			    printf("| Patient Id | Patient Name     | Patient Gender | Patient Age | Patient Reserved Slot No |\n");
			    printf("==================================================================================================================\n");

			    printf("| %-10d | %-16s | %-14s | %-11d | %-24d |\n", edit->id, edit->name, edit->gender, edit->age, edit->reserveSlotNo);

			    printf("==================================================================================================================\n");
				printf("=========================================================== \n");
				printf("Choose What Do You Want To Edit \n");
				printf("1 - Patient Name \n");
				printf("2 - Patient Gender \n");
				printf("3 - Patient Age \n");
				printf("=========================================================== \n");
				printf("Enter Your Choice \n");
				scanf("%d",&editChoice);
				system("cls");

				switch(editChoice)
				{
					case 1:
						{
							editPatientName(patientId);
							break;
						}
					case 2:
						{
							editPatientGender(patientId);
							break;
						}
					case 3:
						{
							editPatientAge(patientId);
							break;	
						}
					default:
						{
							printf("Invalid Choice Please press Any Key To Continue... \n");
							getch();
							system("cls");
							break;
						}
				}
				printf("Record Updated Successfully \n");
				printf("=========================================================== \n");
				printf("Press Any Key To Continue\n");
				getch();
				exportData();
				system("cls");
			}
			break;	
		}
		
		edit = edit->next;
	}

		if(notFoundFlag)
		{
			printf("Invalid Id Please Press Any Key To Continue...\n");
			getch();
			system("cls");
		}
}


void deletePatientRecord(void)
{// this funcion remove the patient from the system 
	u8 flag = 0;
	u8 idflag = 0,reverseFlag = 0;
	u16 patientId;
	printf("Enter Patient Id :");
	scanf("%d",&patientId);
	patient *del = HEAD;

	while(del != NULL)
	{
		if(del->id == patientId)
		{
			idflag = 1;
			if(del->reserveSlotNo == 0)
			{	
				reverseFlag = 1;
				if(del->deletePatientFlag == 0)
				{
					flag = 1;
					del->deletePatientFlag = 1;
				}
			}
		}
		del = del->next;	
	}
	if(flag == 1)
	{
		printf("Patient Deleted Succes\n");
	}
	if(idflag == 1 && reverseFlag == 0)
	{
		printf("Cant Delete patient Have Reserved Slot Cancel It First\n");
	}

	if(idflag == 0)
	{
		printf("Invalid Patient Id Please Try Again\n");
	}
	exportData();
	printf("Press Any Key To Continue....");
	getch();
	system("cls");
}

void restorePatientRecord(void)
{// this function restore the patient that we delete from system
	u8 flag = 0;
	u8 idflag = 0;
	u16 patientId;
	printf("Enter Patient Id :");
	scanf("%d",&patientId);
	patient *restore = HEAD;

	while(restore != NULL)
	{
		if(restore->id == patientId)
		{
			idflag = 1;
			if(restore->deletePatientFlag == 1)
			{
				flag = 1;
				restore->deletePatientFlag = 0;
			}
		}
		restore = restore->next;	
	}
	if(flag == 1)
	{
		printf("Patient Restored Succes\n");
	}
	else
	{
		printf("Patient Already Not Deleted Yet\n");
	}

	if(idflag == 0)
	{
		printf("Invalid Patient Id Please Try Again\n");
	}
	exportData();
	printf("Press Any Key To Continue....");
	getch();
	system("cls");

}

//========================================== slots functions implemntation =======================================


typedef struct r  // struct to save slot data
{
	u16 slotId;
	u16 slotAvalibleFlag;
	u16 patientId;
	u8 startTime[SLOT_TIME_BUFFER_MAX_SIZE];
	u8 endTime[SLOT_TIME_BUFFER_MAX_SIZE];
	struct r *next;
}slot;

slot *SHEAD = NULL;


u16 slotIdExist(u16 idSlotCheck)
{// function check if slot id is taken or not
	u16 checkFlag = 1;
	slot *check = SHEAD;

	while(check!=NULL)
	{
		if(check->slotId == idSlotCheck)
		{
			checkFlag = 0;
		}
	 
	 check = check->next;
	}
	return checkFlag;
}



void addNewReverseSlot(void)
{// function to create linkedlist for the slots data and take slot info
	slot *newSlot = (slot*) malloc(sizeof(slot));
	printf("Add New Reverse Slot Info \n");
	printf("Enter Slot Id : ");	
	scanf("%d",&newSlot->slotId);
	printf("Enter Slot Start Time : ");
	getchar();
	getString(newSlot->startTime , SLOT_TIME_BUFFER_MAX_SIZE);
	printf("Enter Slot End Time : ");
	getchar();
	getString(newSlot->endTime , SLOT_TIME_BUFFER_MAX_SIZE);
	newSlot->slotAvalibleFlag = 0;
	newSlot->patientId = 0;
	newSlot->next = SHEAD;
	SHEAD = newSlot;
	exportSlotsData();
	printf("Press Any Key To Continue....");
	getch();
}

void insertNewReverseSlot(void)
{// function to insert slots data in the linkedlist
	if(SHEAD == NULL)// if shead equal null then its mean that the linkedlist ist created 
	{
		addNewReverseSlot();// call this function to create linkedlist and take slot info
	}
	else
	{// else take slot info and insert it in the linkedlist
		slot *insertNewSlot = (slot*) malloc(sizeof(slot));
		printf("Add New Reverse Slot Info \n");
		printf("Enter Slot Id : ");	
		scanf("%d",&insertNewSlot->slotId);
		if(!slotIdExist(insertNewSlot->slotId))// check slotid
		{
		printf("Id Is Taken Please Press Any Key To Continue...\n");
		free(insertNewSlot);
		getch();
		system("cls");
		return;
		}
		printf("Enter Slot Start Time : ");
		getchar();
		getString(insertNewSlot->startTime , SLOT_TIME_BUFFER_MAX_SIZE);
		printf("Enter Slot End Time : ");
		getchar();
		getString(insertNewSlot->endTime , SLOT_TIME_BUFFER_MAX_SIZE);
		insertNewSlot->slotAvalibleFlag = 0;
		insertNewSlot->patientId = 0;

		insertNewSlot->next = SHEAD;
		SHEAD = insertNewSlot;
		exportSlotsData();
		printf("Press Any Key To Continue....");
		getch();
	}
}


void displayAllSlots(void)
{
    // Function to display all slots info
    printf("==================================================================================================================\n");
    printf("| SlotId | PatientId | Start Time | End Time   | Slot Availability |\n");
    printf("==================================================================================================================\n");

    slot *sdisplay = SHEAD;

    while (sdisplay != NULL)
    {
        printf("| %-6d | %-9d | %-10s | %-10s | %-17d |\n", sdisplay->slotId, sdisplay->patientId, sdisplay->startTime, sdisplay->endTime, sdisplay->slotAvalibleFlag);
        sdisplay = sdisplay->next;
    }

    printf("==================================================================================================================\n");
    printf("Press Any Key To Continue....");
    getch();
}


void reverseAvalibleSlot(void)
{// this function allow patient to reverse slot
	u16 flag = 0; 
	u8 reverseFlag = 0 , setFlagFlag = 0 , twiceflag = 0 , slotExitFlag = 0;
	slot *reverseSlot = SHEAD;
	printf("==================================================================================================================\n");
    printf("| SlotId | Start Time | End Time   | Slot Availability |\n");
    printf("==================================================================================================================\n");
	while(reverseSlot != NULL)
	{
		if(reverseSlot->slotAvalibleFlag == 0)
		{
			flag = 1;

       		printf("| %-6d | %-10s | %-10s | %-17d |\n", reverseSlot->slotId,reverseSlot->startTime, reverseSlot->endTime, reverseSlot->slotAvalibleFlag);
		}
		reverseSlot = reverseSlot->next;
	}
	   printf("==================================================================================================================\n");

	if(flag == 0)
	{
		printf("No Reverse Avalible \n");
	}
	else
	{
		u16 patientId,slotId;
		printf("Enter Slot Id : ");
		scanf("%d",&slotId);
		printf("Enter Patient Id : ");
		scanf("%d",&patientId);

		slot *slotidexist = SHEAD;
		while(slotidexist != NULL)
		{
			if(slotidexist->slotId == slotId)
			{
				slotExitFlag = 1;
			}
			slotidexist = slotidexist->next;
		}
		patient *reverse = HEAD;
		while(reverse != NULL)
		{
			if(reverse->id == patientId)
			{
				reverseFlag = 1;
				if(reverse->reserveSlotNo == 0 && reverse->deletePatientFlag == 0 && slotExitFlag == 1)
				{
					twiceflag = 0;
					reverse->reserveSlotNo = slotId;
				}
				else
				{
					twiceflag = 1;
				}
			}
			reverse = reverse->next;
		}
		slot *setflag = SHEAD;
		while(setflag != NULL)
		{
			if(setflag->slotId == slotId)
			{
				if(twiceflag == 0 && reverseFlag == 1)
				{
					setFlagFlag = 1;
					setflag->slotAvalibleFlag = 1;
					setflag->patientId = patientId;
				}
			}
			setflag = setflag->next;
		}
	}

	if(reverseFlag == 0)
	{
		printf("Invalid Patient Id Please Try Again...\n");
	}
	if(setFlagFlag == 0 && twiceflag == 0)
	{
		printf("Invalid Slot Id Please Try Again...\n");
	}
	if(twiceflag == 1)
	{
		printf("Cant Reverse Two Slots For The Same Patient\n");
	}
	if(reverseFlag == 1 && setFlagFlag == 1 && twiceflag == 0)
	{
		printf("Reverse Slot Succes \n");
	}
	exportSlotsData();
	exportData();
	printf("Press Any Key To Continue...\n");
	getch();
	system("cls");
}


void cancelReversedSlot(void)
{// this function allow user to cancel his reversation
	u16 patientId,reversedSlot;
	u8 patientIdFlag = 0 , slotIdFlag = 0 ;
	printf("Enter Patient Id : ");
	scanf("%d",&patientId);

	patient *cancel = HEAD;

	while(cancel != NULL)
	{
		if(cancel->id == patientId)
		{
			patientIdFlag = 1;
			reversedSlot = cancel->reserveSlotNo;
			cancel->reserveSlotNo = 0;
		}
		cancel = cancel->next;
	}

	slot *resetSlotFlag = SHEAD;

	if(patientIdFlag == 1)
	{
		while(resetSlotFlag != NULL)
		{
			if(resetSlotFlag->slotId == reversedSlot)
			{
				slotIdFlag = 1;
				resetSlotFlag->slotAvalibleFlag = 0;
				resetSlotFlag->patientId = 0;
			}
			resetSlotFlag = resetSlotFlag->next;
		}
		printf("Cancel Reverse Succes\n");
	}
	if(patientIdFlag == 0)
	{
		printf("Invalid Patient Id Please Try Again...\n");
	}

	if(slotIdFlag == 0)
	{
		printf("Invalid Slot Id Please Try Again...\n");
	}
	exportData();
	exportSlotsData();
	printf("Press Any Key To Continue...\n");
	getch();
	system("cls");
}


void resetAllSlotAvilableFlag(void)
{// this function allow admin to cancel all reversation slots
	slot *resetAll = SHEAD;
	while(resetAll != NULL)
	{
		resetAll->slotAvalibleFlag = 0;
		resetAll->patientId = 0;
		resetAll = resetAll->next;
	}

	patient *cancelAll = HEAD;
	while(cancelAll != NULL)
	{
		cancelAll->reserveSlotNo = 0;
		cancelAll = cancelAll->next;
	}
	exportData();
	exportSlotsData();
	printf("All Reserved Slots Canclled\n");
	printf("Press Any Key To Continue...\n");
	getch();
	system("cls");
}


//========================================= user functions implemnation ===========================================


void viewPatientRecord(void)
{// function for user to show him his info and his reverse	
	u16 patientId;
	u8 flag = 0,reverseFlag = 0;
	printf("Enter Patient Id : ");
	scanf("%d",&patientId);
	patient *view = HEAD;

	while(view != NULL)
	{
		if(view->id == patientId)
		{	
			flag = 1;
				printf("============================================== Patient Data ======================================================\n");
				printf("==================================================================================================================\n");
			    printf("| Patient Id | Patient Name     | Patient Gender | Patient Age | Patient Reserved Slot No |\n");
			    printf("==================================================================================================================\n");

			    printf("| %-10d | %-16s | %-14s | %-11d | %-24d |\n", view->id, view->name, view->gender, view->age, view->reserveSlotNo);
			if(view->reserveSlotNo != 0)
			{
				reverseFlag = 1;
				slot *sview = SHEAD;
				while(sview != NULL)
				{
					if(sview->slotId == view->reserveSlotNo)
					{
						printf("==================================================================================================================\n");
						printf("=================================== Patient Have A Reverse Slot Today ============================================\n");
						printf("==================================================================================================================\n");
   					    printf("| SlotId | Start Time | End Time   |\n");
   					    printf("==================================================================================================================\n");
    					printf("| %-6d | %-10s | %-10s |\n", sview->slotId,sview->startTime,sview->endTime);
					}

					sview = sview->next;
				}
			    printf("==================================================================================================================\n");
			}
		}
		view = view->next;
	}

	if(reverseFlag == 0)
	{
		printf("Patient Have No Reverse Slot Today \n");
	}

	if(flag == 0)
	{
		printf("Invalid Patient Id \n");
	}
	printf("Press Any Key To Continue...\n");
	getch();
	system("cls");
}


void viewTodayReservations(void)
{// this function show to user all taken reverse and patient id 
	printf("==================================================================================================================\n");
    printf("| SlotId | PatientId | Start Time | End Time   |\n");
    printf("==================================================================================================================\n");
            
	slot *sdisplay = SHEAD;

	while(sdisplay != NULL)
	{
		if(sdisplay->slotAvalibleFlag == 1)
		{
			printf("| %-6d | %-9d | %-10s | %-10s |\n", sdisplay->slotId, sdisplay->patientId, sdisplay->startTime, sdisplay->endTime);
    		printf("==================================================================================================================\n");
		}
		sdisplay = sdisplay->next;
	}
	printf("Press Any Key To Continue....");
	getch();
}


//========================================== file Hnadling Functions ==================================================


void exportSlotsData(void) // fucntion to export slot data to file
{
	slot *swrite = SHEAD;

	FILE *swp = fopen("systemSlotsData.txt","w");

	while(swrite !=NULL)
	{
		fwrite(swrite,sizeof(slot),1,swp);
		swrite = swrite->next;
	}
	fclose(swp);
}

void importSlotsData(void) // function to import slot data from file
{
	slot *sread = SHEAD;

	slot s;

	FILE *srp = fopen("systemSlotsData.txt","r");

	while(fread(&s,sizeof(slot),1,srp))
	{
		if(SHEAD == NULL)
		{
			sread = (slot*) malloc(sizeof(slot));
			strcpy(sread->startTime,s.startTime);
			strcpy(sread->endTime,s.endTime);
			sread->slotId = s.slotId;
			sread->slotAvalibleFlag = s.slotAvalibleFlag;
			sread->patientId = s.patientId;
			sread->next = NULL;
			SHEAD = sread;
		}
		else
		{
				slot *stemp = (slot*) malloc(sizeof(slot)); //variable gdeed
				stemp->next = SHEAD;
				SHEAD = stemp;
				strcpy(stemp->startTime,s.startTime);
				strcpy(stemp->endTime,s.endTime);
				stemp->slotId = s.slotId;
				stemp->slotAvalibleFlag = s.slotAvalibleFlag;
				stemp->patientId = stemp->patientId;
		}
	}
	fclose(srp);
	printf("Slots Data imported successfully\n");
}

void exportData(void) // function use to export the paintent data to the file
{
	patient *write = HEAD;

	FILE *wp = fopen("systemData.txt","w");

	while(write !=NULL)
	{
		fwrite(write,sizeof(patient),1,wp);
		write = write->next;
	}
	fclose(wp);
}

void importData(void)// function import all data of patient from file
{
	patient *read = HEAD;

	patient p;

	FILE *rp = fopen("systemData.txt","r");

	while(fread(&p,sizeof(patient),1,rp))
	{
		if(HEAD == NULL)
		{
			read = (patient*) malloc(sizeof(patient));
			strcpy(read->name,p.name);
			strcpy(read->gender,p.gender);
			read->id = p.id;
			read->age = p.age;
			read->reserveSlotNo = p.reserveSlotNo;
			read->deletePatientFlag = p.deletePatientFlag;
			read->next = NULL;
			HEAD = read;
		}
		else
		{
				patient *temp = (patient*) malloc(sizeof(patient)); //variable gdeed
				temp->next = HEAD;
				HEAD = temp;
				strcpy(temp->name,p.name);
				strcpy(temp->gender,p.gender);
				temp->age = p.age;
				temp->id = p.id;
				temp->reserveSlotNo = p.reserveSlotNo;
				temp->deletePatientFlag = p.deletePatientFlag;
		}
	}
	fclose(rp);
	printf("Patient Data imported successfully\n");
}

void importAllData(void)
{
	importData();
	importSlotsData();
	printf("All Data Imported press Any Key To Continue...\n");
	getch();
}

void exportAllData(void)
{
	exportData();
	exportSlotsData();
	printf("All Data Exported press Any Key To Continue...\n");
	getch();
}


//========================================== function to scan string ==================================================


void getString(u8 *str, u32 strSize)
{
    u32 counter = 0;
    u8 ch;

    while (counter < strSize - 1)
    {
    	ch = getchar();
        if (ch == '\n') {
            break; // Exit the loop if newline character is encountered
        }
        str[counter] = ch;
        counter++;
    }
    str[counter] = '\0'; // Null-terminate the string
}
