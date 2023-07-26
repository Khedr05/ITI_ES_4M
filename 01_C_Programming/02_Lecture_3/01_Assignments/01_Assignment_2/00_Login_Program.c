#include<stdio.h>

int main()
{
        int ahmedId = 1234 , ahmedPass = 7788 , amrId = 5678 , amrPass = 5566 , waelId = 9870 , waelPass = 1122 , inputId = 0 , inputPass = 0 , endFlag = 0;
        while(1)
        {
            int i = 1;
            printf("Enter Your Id \n");
            scanf("%d",&inputId);

            if((inputId == ahmedId) || (inputId == amrId) || (inputId == waelId))
            {
                do
                {
                    printf("Enter Your Password\n");
                    scanf("%d",&inputPass);
                    if((inputPass == ahmedPass))
                    {
                        printf("Welcome Ahmed\n");
                        endFlag = 1;
                        break;
                    }
                    else if((inputPass == amrPass))
                    {
                        printf("Welcome Amr\n");
                        endFlag = 1;
                        break;
                    }
                    else if((inputPass == waelPass))
                    {
                        printf("Welcome Weal\n");
                        endFlag = 1;
                        break;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                    i++;
                }
                while(i<=3);
            }
            else
            {
                printf("You Are Not Registered \n");
                break;
            }
            if(i > 3)
            {
                 printf("No More Tries \n");
                 break;
            }  
            else
            {
                /* Do Nothing */
            } 
            if(endFlag == 1)
            {
                endFlag = 0;
                break;
            }         
        }       
}