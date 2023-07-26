#include<stdio.h>

int main()
{
    int userId = 12345 ;
    int userPassword = 54321 ;
    int inputId = 0 ;
    int inputPassword = 0;

    printf("\n\n");
    printf("Enter Your Id\n");
    scanf("%d",&inputId);

    if(inputId == userId)
    {
        printf("Enter Your Password\n");
        scanf("%d",&inputPassword);
        if(inputPassword == userPassword)
        {
            printf("UserName : Sherif\n");
        }
        else
        {
            printf("Invalid Password\n");
        }   
    }
    else
    {
        printf("Invalid Id\n");
    }
    printf("\n\n");
}