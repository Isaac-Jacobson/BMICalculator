/*****************************************************************************
* Programmer: Isaac Jacobson
* Class: ECE 251; Lab Section 7
* Programming Assignment: Lab 3a - BMI Calculator w/ Functions!
*
* Date: 9/8/20
*
* Description: This program calculates the BMI of a person given their height
*			in feet+inches and weight in pounds.
*
* Relevant Formulas: BMI = ((weight in pounds)/(height in inches)^2)*703
*****************************************************************************/

#include "prob3a.h"
#include <stdint.h>
#include <stdio.h>
#include "utils/uartstdio.h"


/*************************************************************
* Function: get_height()				                            *
* Date Created: 9/8/20                                      *
* Date Last Modified: 9/29/20                               *
* Description: Asks the user for their height in feet and   *
*  inches    																								* 
* Input parameters: Pointers to height variables            *
* Returns: None												                      *
* Preconditions: height in feet and inches variables				*
*  initialized																							*
* Postconditions: height_feet and height_incehs found       *
*************************************************************/
void get_height(int *height_feet,int *height_inches){
char inputHeightFeet = '\0';
	char inputHeightInches = '\0';
	do{
UARTprintf("\nHeight (Feet):");
	inputHeightFeet = UARTgetc();
	*height_feet = char2int(inputHeightFeet);
	}while(*height_feet > 7 || *height_feet < 3);
	do{
	UARTprintf("\nHeight (Inches):");
	inputHeightInches = UARTgetc();
	*height_inches = char2int(inputHeightInches);
	}while(*height_inches > 12);
}
/*************************************************************
* Function: get_weight()				                            *
* Date Created: 9/8/20                                      *
* Date Last Modified: 9/8/20                                *
* Description: Asks the user for their weight in pounds     *
* Input parameters: None						                        *
* Returns: weight_in_poundss as an int                      *
* Preconditions: None																		    *
* Postconditions: weight_in_pounds found                    *
*************************************************************/
int get_weight(){
char inputWeight100 = '\0';
	char inputWeight10 = '\0';
	char inputWeight1 = '\0';
	int weight = 0;
	do{
UARTprintf("\nWeight (Pounds):");
	inputWeight100 = UARTgetc();
	inputWeight10 = UARTgetc();
	inputWeight1 = UARTgetc();
		weight = char2int(inputWeight100)*100 + char2int(inputWeight10)*10 + char2int(inputWeight1);
	}while(weight > 400 || weight < 100);
	return weight;
}

/*************************************************************
* Function: get_height_feet ()                              *
* Date Created: 9/8/20                                      *
* Date Last Modified: 9/8/20                                *
* Description: Asks the user for their height in feet       *
* Input parameters: None						                        *
* Returns: height_in_feet as an int                         *
* Preconditions: None																		    *
* Postconditions: height_in_feet found                      *
*************************************************************/
int get_height_feet(){
	char inputHeightFeet = '\0';
UARTprintf("\nHeight (Feet):");
	inputHeightFeet = UARTgetc();
	return char2int(inputHeightFeet);
}

/*************************************************************
* Function: get_height_inches ()                            *
* Date Created: 9/8/20                                      *
* Date Last Modified: 9/8/20                                *
* Description: Asks the user for their height in inches     *
* Input parameters: None						                        *
* Returns: height_in_inches as an int                       *
* Preconditions: None																		    *
* Postconditions: height_in_inches found                    *
*************************************************************/
int get_height_inches(){
char inputHeightInches = '\0';
UARTprintf("\nHeight (Inches):");
	inputHeightInches = UARTgetc();
	return char2int(inputHeightInches);
}

/*************************************************************
* Function: convert_height_to_inches ()                     *
* Date Created: 9/8/20                                      *
* Date Last Modified: 9/8/20                                *
* Description: converts the height to inches                *
* Input parameters: height_in_inches and height_in_feet 		*
* as ints																										*
* Returns: height_in_inches as an int                       *
* Preconditions: height found in inches and feet				    *
* Postconditions: height entirely in inches                 *
*************************************************************/
int convert_height_to_inches(int height_in_feet, int height_in_inches){
return (height_in_feet * 12) + height_in_inches;
}

/*************************************************************
* Function: calculate_bmi ()                                *
* Date Created: 9/8/20                                      *
* Date Last Modified:9/8/20                                 *
* Description: Take the height and weight as inputs and     *
* returns the BMI                  										      *
* Input parameters: height_in_feet as an int,   						*
* height_in_inches as an int, weight_in_pounds as an int    *
* Returns: BMI as a double                                  *
* Preconditions: Height and weight must be calculated       *
* Postconditions: BMI calculated				                    *
*************************************************************/
double calculate_bmi(int weight_in_pounds, int height){
double numerator = (double) weight_in_pounds * 703;
double denomerator = (double) height*height;
	return numerator/denomerator;
}

/************************************************************
* Function: char2int ()                                     *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: Converts an char digit to it's integer value *
* Input parameters: The character digit                     *
* Returns: The integer value of the character digit         *
* Preconditions: None (other functions to be run first)     *
* Postconditions: The integer value of the character        *
*             digit is returned                             *
************************************************************/
int char2int (char digit)
{
		return (digit - 48);
}

/*************************************************************
* Function: display_bmi ()                                  *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: Takes the bmi value as input and print       *
*		the value out to Termite over UART                      *
* Input parameters: BMI as a double                         *
* Returns: None                                             *
* Preconditions: BMI must be calculated, UART initialized   *
* Postconditions: BMI printed to Termite                    *
*************************************************************/
void display_bmi (double bmi)
{
		char buffer[20]; // buffer to hold converted bmi to string
		sprintf(buffer, "%f", bmi); // convert from double to string
		UARTprintf("BMI: %s\n", buffer); // print out BMI over UART
}
