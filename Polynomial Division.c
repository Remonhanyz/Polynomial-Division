#include "stdio.h"

void main()
{
	// taking the input from the user
	int nom_deg, den_deg, i;
	printf("Please enter the degree of the numerator equation: ");
	scanf("%d", &nom_deg);
	printf("Please enter the degree of the denominator equation: ");
	scanf("%d", &den_deg);
	float nom_coef[nom_deg + 1];
	float den_coef[den_deg + 1];
	printf("\nPlease enter the coefficients of the numerator equation (if the coefficient is zero you have to type 0)\n");
	for (i = 0; i <= nom_deg; i++)
	{
		printf("Please write the coefficient of x^%d: ", i);
		scanf("%f", &nom_coef[i]);
	}
	printf("\nPlease enter the coefficients of the denominator equation (if the coefficient is zero you have to type 0)\n");
	for (i = 0; i <= den_deg; i++)
	{
		printf("Please write the coefficient of x^%d: ", i);
		scanf("%f", &den_coef[i]);
	}

	// doing long division
	float total_coef[nom_deg - den_deg + 1];
	int j;
	float temp_coef[den_deg+1];

	for (i = 0; i < nom_deg - den_deg + 1; i++)
	{
		//divide
		//----------
		total_coef[i] = nom_coef[nom_deg - i] / den_coef[den_deg];
		//multiply
		//-----------
		for (j = 0; j < den_deg + 1; j++)
		{
			temp_coef[den_deg - j] = total_coef[i] * den_coef[den_deg - j];
		}
		//subtract
		//-----------
		for (j = 0; j <den_deg + 1; j++)
		{
			nom_coef[nom_deg - j - i] = nom_coef[nom_deg - j - i] - temp_coef[den_deg - j];
		}
	}
	printf("\nthe solution is:\n");
	for (i = 0; i < nom_deg - den_deg + 1; i++)
	{
		printf("(%0.2f)X^%d+", total_coef[i], nom_deg - den_deg - i);
	}

	// dealing with reminder
	//------------------------
	printf("[");
	for (i = 0; i < nom_deg + 1; i++)
	{

		if (nom_coef[nom_deg - i] != 0.0 && nom_deg - i != 0)
		{
			printf("(%0.2f)X^%d+", nom_coef[nom_deg - i], nom_deg - i);
		}
		else if (nom_coef[nom_deg - i] != 0.0 && nom_deg - i == 0)
		{
			printf("(%0.2f)X^%d", nom_coef[nom_deg - i], nom_deg - i);
			printf("]/[");
			for (j = 0; j < den_deg + 1; j++)
			{
				printf("(%0.2f)X^%d+", den_coef[den_deg - j], den_deg - j);
			}
		}
	}

	printf("0]");
}