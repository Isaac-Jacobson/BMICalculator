
#ifndef __PROB3A_H__
#define __PROB3A_H__

//Function Prototypes
int char2int (char digit);
int get_weight (void);
int get_height_feet (void);
int get_height_inches (void);
void get_height(int *height_feet, int *height_inches);
int convert_height_to_inches(int height_in_feet, int height_in_inches);
double calculate_bmi (int weight_in_pounds, int height);
void display_bmi (double bmi);

#endif /* __PROB3A_H__ */
