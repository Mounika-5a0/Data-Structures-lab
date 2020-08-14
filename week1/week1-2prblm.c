#include <stdio.h>
struct student
{
	char Name[50];
	char roll[15];
    	float m1, m2, m3, m4;
} s[10];

int main()
 {
	int i;
    	printf("Enter information of students:\n");
	for (i = 0; i < 1; ++i)
	{
         		printf("\nRoll number:");
		scanf("%s",s[i].roll);
        		printf("Name: ");
        		scanf("%s", s[i].Name);
        		printf("Marks:\n ");
        		scanf("%f", &s[i].m1);
		scanf("%f", &s[i].m2);
		scanf("%f", &s[i].m3);
		scanf("%f", &s[i].m4);
    	}
    	printf("Students Information:\n\n");
	for (i = 0; i < 1; ++i)
 	{
        		printf("\nRoll number: ");
		puts(s[i].roll);
        		printf("Name: ");
        		puts(s[i].Name);
		float sum = s[i].m1 + s[i].m2 + s[i].m3 + s[i].m4;
		float avg = sum / 4; 
        		printf("Average: %.2f", avg);
       		printf("\n");
    	}
    	return 0;
}