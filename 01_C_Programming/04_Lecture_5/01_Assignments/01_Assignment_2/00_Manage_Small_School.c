
#include <stdio.h>

void bubbleSorting(int arr[] , int size);
void swap(int arr[] , int index1 , int index2);
void getStudentsState(int arr [] , int size);
void getHighestGrade(int arr [] , int size);
void getLowestGrade(int arr [] , int size);
void getAverageGrades(int numberOfStudents);
void getSumOfGrades(int arr [] , int size);


int passedStudentsNumber = 0;
int failedStudentsNumber = 0;
int highestGrade = 0;
int lowestGrade = 100;
float averageOfGrades = 0.0;
int sumOfGrades = 0;

void main(void)
{
   int classOneArr[10] =   {60,40,70,80,22,36,94,64,59,34};
   int classTwoArr[10] =   {66,4,77,21,35,98,64,21,74,66};
   int classThreeArr[10] = {62,47,56,77,84,95,61,42,35,89};
   int classOneArrSize = sizeof(classOneArr) / sizeof(classOneArr[0]);
   int classTwoArrSize = sizeof(classTwoArr) / sizeof(classTwoArr[0]);
   int classThreeArrSize = sizeof(classThreeArr) / sizeof(classThreeArr[0]);


   printf("\n\n");

   bubbleSorting(classOneArr , classOneArrSize);
   bubbleSorting(classTwoArr , classTwoArrSize);
   bubbleSorting(classThreeArr , classThreeArrSize);

   getStudentsState(classOneArr , classOneArrSize);
   getStudentsState(classTwoArr , classTwoArrSize);
   getStudentsState(classThreeArr , classThreeArrSize);

   getHighestGrade(classOneArr , classOneArrSize);
   getHighestGrade(classTwoArr , classTwoArrSize);
   getHighestGrade(classThreeArr , classThreeArrSize);

   getLowestGrade(classOneArr , classOneArrSize);
   getLowestGrade(classTwoArr , classTwoArrSize);
   getLowestGrade(classThreeArr , classThreeArrSize);

   getSumOfGrades(classOneArr , classOneArrSize);
   getSumOfGrades(classTwoArr , classTwoArrSize);
   getSumOfGrades(classThreeArr , classThreeArrSize);

   getAverageGrades(passedStudentsNumber + failedStudentsNumber);

   printf("Number Of Passed Students : %d \n",passedStudentsNumber);
   printf("Number Of Failed Students : %d \n",failedStudentsNumber);
   printf("Highest Grade : %d \n",highestGrade);
   printf("Lowest Grade : %d \n",lowestGrade);
   printf("Average Grade : %0.2f \n",averageOfGrades);


   printf("\n\n");
}

void swap(int arr[] , int index1 , int index2)
{
   arr[index1] = arr[index1] ^ arr[index2];
   arr[index2] = arr[index1] ^ arr[index2];
   arr[index1] = arr[index1] ^ arr[index2];
}

void bubbleSorting(int arr[] , int size)
{
   int i;
   int j;
   for(i = 0 ; i < size - 1 ; i++)
   {
      for(j = 0 ; j < size - i - 1 ; j++)
      {
         if(arr[j] > arr[j + 1])
         {
            swap(arr ,j , j + 1);  
         }
         
      }
   }
}

void getStudentsState(int arr [] , int size)
{
   int i;
   for(i = 0 ; i < size ; i++)
   {
      if(arr[i] >= 50)
      {
         passedStudentsNumber++;
      }
      else
      {
         failedStudentsNumber++;
      }
   }
}

void getHighestGrade(int arr [] , int size)
{
   int i;
   for(i = 0 ; i < size ; i++)
   {
      if(arr[i] > highestGrade)
      {
         highestGrade = arr[i];
      }
      else
      {
         /* Do Nothing */
      }
   }   
}

void getLowestGrade(int arr [] , int size)
{
   int i;
   for(i = 0 ; i < size ; i++)
   {
      if(arr[i] < lowestGrade)
      {
         lowestGrade = arr[i];
      }
      else
      {
         /* Do Nothing */
      }
   }    
}

void getAverageGrades(int numberOfStudents)
{
   averageOfGrades = sumOfGrades / (float)numberOfStudents;
}

void getSumOfGrades(int arr [] , int size)
{
   int i;
   for(i = 0 ; i < size ; i++)
   {
       sumOfGrades += arr[i];
   }  
}