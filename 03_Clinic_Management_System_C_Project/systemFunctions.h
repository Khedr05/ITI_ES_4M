/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : Clinic_Management_System
// File          : systemFunctions.h
// Date          : 5 Jan 2022
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/


#include"datatypes.h"


#define NAME_BUFFER_MAX_SIZE		100
#define GENDER_BUFFER_MAX_SIZE		7
#define AGE_BUFFER_MAX_SIZE			4
#define SLOT_TIME_BUFFER_MAX_SIZE	6

//======================================== patient functions headers ==================================

u16 login(void);
void exportData(void);
void importData(void);
u16 idExist(u16 idCheck);
void addNewRecord(void);
void insertNewPatientRecord(void);
void displayAllRecord(void);
void editPatientName(u16 patientId);
void editPatientGender(u16 patientId);
void editPatientAge(u16 patientId);
void editPatientRecord(void);
void deletePatientRecord(void);
void restorePatientRecord(void);

//========================================== slots functions headers =======================================

void importSlotsData(void);
void exportSlotsData(void);
u16 slotIdExist(u16 idSlotCheck);
void addNewReverseSlot(void);
void insertNewReverseSlot(void);
void displayAllSlots(void);
void reverseAvalibleSlot(void);
void cancelReversedSlot(void);
void resetAllSlotAvilableFlag(void);

//========================================= user functions headers ===========================================

void viewPatientRecord(void);
void viewTodayReservations(void);

//========================================== file Hnadling Function Headers ==================================================


void importAllData(void);
void exportAllData(void);



//========================================== function to scan string ==================================================


void getString(u8 *str , u32 strSize);