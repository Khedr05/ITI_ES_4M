
#include <stdio.h>

#define STUDENT_MAX_SIZE_ARR        10

typedef unsigned char uint8_t;

typedef struct
{
	uint8_t math;
	uint8_t language;
	uint8_t physics;
	uint8_t chemistry;
}ST_student_t;

void main(void)
{
	uint8_t id;
	ST_student_t class[STUDENT_MAX_SIZE_ARR] = 
    {
        {55,44,60,78},
        {90,45,63,12},
        {78,96,45,32},
        {100,98,34,77},
        {66,23,94,51},
        {55,44,60,78},
        {90,45,63,12},
        {78,96,45,32},
        {100,98,34,77},
        {66,23,94,51}
	};

    printf("\n\n");
	printf("Please Enter Student ID : ");
	scanf ("%d",&id);

	if (id < STUDENT_MAX_SIZE_ARR)
	{
		printf("Math Grade : %d\n",class[id].math);
		printf("Language Grade : %d\n",class[id].language);
		printf("Physics Grade : %d\n",class[id].physics);
		printf("Chemistry Grade : %d",class[id].chemistry);
        printf("\n\n");
	}
	else
	{
		printf("Student Id Is Not Correct");
        printf("\n\n");
	}
}