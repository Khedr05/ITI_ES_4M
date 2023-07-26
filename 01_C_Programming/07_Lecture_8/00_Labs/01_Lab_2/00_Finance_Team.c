
#include <stdio.h>

typedef float   float32_t;

typedef struct 
{
	float32_t salary;
	float32_t bonus;
	float32_t deduction;
}ST_employee;

void main(void)
{
    ST_employee ahmed,amr,waleed;
	float32_t total = 0.0; 
    float32_t salary = 0.0;
    float32_t bonus = 0.0;
    float32_t deduction = 0.0;
    printf("\n\n");
	printf("Please Enter Ahmed Salary : ");
	scanf ("%f",&ahmed.salary);
	printf("Please Enter Ahmed Bonus : ");
	scanf ("%f",&ahmed.bonus);
	printf("Please Enter Ahmed Deduction : ");
	scanf ("%f",&ahmed.deduction);
	printf("\n");
	printf("Please Enter Amr Salary : ");
	scanf ("%f",&amr.salary);
	printf("Please Enter Amr Bonus : ");
	scanf ("%f",&amr.bonus);
	printf("Please Enter Amr Deduction : ");
	scanf ("%f",&amr.deduction);
	printf("\n");
	printf("Please Enter Waleed Salary : ");
	scanf ("%f",&waleed.salary);
	printf("Please Enter Waleed Bonus : ");
	scanf ("%f",&waleed.bonus);
	printf("Please Enter Waleed Deduction : ");
	scanf ("%f",&waleed.deduction);
	printf("\n\n");

    salary = ahmed.salary + amr.salary + waleed .salary;
    bonus = ahmed.bonus + amr.bonus + waleed.bonus;
    deduction = ahmed.deduction + amr.deduction + waleed.deduction;
	total = (salary + bonus) - deduction;
	
	printf("Total Value Needed is : %0.2f",total);
}