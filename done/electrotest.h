#ifndef ELECTROTEST_H_INCLUDED
#define ELECTROTEST_H_INCLUDED
char* generateMenu();
long parseMenuSelection(char* str);
int start(char* str);
long getInt(char* str);
float resCalc(char* str);
void powerCalc(char* str);
void findComp(char* str);
#endif
