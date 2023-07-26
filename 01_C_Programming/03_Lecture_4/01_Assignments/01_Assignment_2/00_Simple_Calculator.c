
#include<stdio.h>


/************************  Function Prototype ********************/

float add(float num1 , float num2);
float subtract(float num1 , float num2);
float multiply(float num1 , float num2);
float divide(float num1 , float num2);
int anding(int num1 , int num2);
int oring(int num1 , int num2);
int noting(int num1);
int xoring(int num1 , int num2);
int reminder(int num1 , int num2);
int increment(int num1);
int decrement(int num1);

/************************  Main Program ********************/

void main(void)
{
    int operation = 0;
    int userInputNum1 = 0;
    int userInputNum2 = 0;
    int resualt = 0;
    float f64UserInputNum1 = 0.0;
    float f64UserInputNum2 = 0.0;
    float f64Resualt = 0.0;
    
    printf("\n\n");

    printf("1 -  add        \n");
    printf("2 -  subtract   \n");
    printf("3 -  multiply   \n");
    printf("4 -  divide     \n");
    printf("5 -  anding     \n");
    printf("6 -  not        \n");
    printf("7 -  oring      \n");
    printf("8 -  xoring     \n");
    printf("9 -  reminder   \n");
    printf("10 - increment  \n");
    printf("11 - decrement  \n");

    printf("Enter Operation Id : ");
    scanf("%d",&operation);

    switch(operation)
    {
        case 1:
            {
                printf("Enter Number 1 : ");
                scanf("%f",&f64UserInputNum1);
                printf("Enter Number 2 : ");
                scanf("%f",&f64UserInputNum2);
                f64Resualt = add(f64UserInputNum1 , f64UserInputNum2);
                printf("Adding Of %0.2f + %0.2f = %0.2f",f64UserInputNum1 , f64UserInputNum2 , f64Resualt);
                break;
            }
        case 2:
            {
                printf("Enter Number 1 : ");
                scanf("%f",&f64UserInputNum1);
                printf("Enter Number 2 : ");
                scanf("%f",&f64UserInputNum2);            
                f64Resualt = subtract(f64UserInputNum1 , f64UserInputNum2);
                printf("Subtracting Of %0.2f - %0.2f = %0.2f",f64UserInputNum1 ,f64UserInputNum2 , f64Resualt);
                break;
            }
        case 3:
            {
                printf("Enter Number 1 : ");
                scanf("%f",&f64UserInputNum1);
                printf("Enter Number 2 : ");
                scanf("%f",&f64UserInputNum2);            
                f64Resualt = multiply(f64UserInputNum1 , f64UserInputNum2);
                printf("Multiplying Of %0.2f * %0.2f = %0.2f",f64UserInputNum1 , f64UserInputNum2 , f64Resualt);
                break;
            }
        case 4:
            {
                printf("Enter Number 1 : ");
                scanf("%f",&f64UserInputNum1);
                printf("Enter Number 2 : ");
                scanf("%f",&f64UserInputNum2);            
                f64Resualt = divide(f64UserInputNum1 , f64UserInputNum2);
                printf("Dividing Of %0.2f / %0.2f = %0.2f",f64UserInputNum1 , f64UserInputNum2 , f64Resualt);
                break;
            }
        case 5:
            {
                printf("Enter Number 1 : ");
                scanf("%d",&userInputNum1);
                printf("Enter Number 2 : ");
                scanf("%d",&userInputNum2);            
                resualt = anding(userInputNum1 , userInputNum2);
                printf("Anding Of %d & %d = %d",userInputNum1 , userInputNum2 , resualt);
                break;
            }
        case 6:
            {
                printf("Enter Number 1 : ");
                scanf("%d",&userInputNum1);
                printf("Enter Number 2 : ");
                scanf("%d",&userInputNum2);            
                resualt = oring(userInputNum1 , userInputNum2);
                printf("Oring Of %d | %d = %d",userInputNum1 , userInputNum2 , resualt);
                break;
            }
        case 7:
            {
                printf("Enter Number : ");
                scanf("%d",&userInputNum1);            
                resualt = noting(userInputNum1);
                printf("Not Of !%d = %d",userInputNum1 , resualt);
                break;
            }
        case 8:
            {
                printf("Enter Number 1 : ");
                scanf("%d",&userInputNum1);
                printf("Enter Number 2 : ");
                scanf("%d",&userInputNum2);            
                resualt = xoring(userInputNum1 , userInputNum2);
                printf("Xoring Of %d ^ %d = %d",userInputNum1 , userInputNum2 , resualt); 
                break;
            }
        case 9:
            {
                printf("Enter Number 1 : ");
                scanf("%d",&userInputNum1);
                printf("Enter Number 2 : ");
                scanf("%d",&userInputNum2);            
                resualt = reminder(userInputNum1 , userInputNum2);
                printf("Reminder Of %d %% %d = %d",userInputNum1 , userInputNum2 , resualt);
                break;
            }
        case 10:
            {
                printf("Enter Number : ");
                scanf("%d",&userInputNum1);
                resualt = increment(userInputNum1);
                printf("Increment Of %d = %d",userInputNum1,resualt);                             ;
                break;
            }
        case 11:
            {
                printf("Enter Number : ");
                scanf("%d",&userInputNum1);             
                resualt = decrement(userInputNum1);
                printf("Deccrement Of %d = %d",userInputNum1,resualt);
                break;
            }
        default :
         {
            printf("Invalid Choice \n");
         }          
    }
    printf("\n\n");
}

    


/************************  Function Implmantation ********************/

float add(float num1 , float num2)
{
    return (num1 + num2);
}

float subtract(float num1 , float num2)
{
    return (num1 - num2);
}

float multiply(float num1 , float num2)
{
    return (num1 * num2);
}

float divide(float num1 , float num2)
{
    return (num1 / num2);
}

int anding(int num1 , int num2)
{
    return num1 & num2;
}

int oring(int num1 , int num2)
{
    return num1 | num2;
}

int noting(int num1)
{
    return !num1;
}

int xoring(int num1 , int num2)
{
    return num1 ^ num2;
}

int reminder(int num1 , int num2)
{
    return num1 % num2;
}

int increment(int num1)
{
    return ++num1;
}

int decrement(int num1)
{
    return --num1;
}