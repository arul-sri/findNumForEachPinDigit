/*********************************
* Author: Arul Srivastava        *
* Class: CSCI121-00N, Summer 2021*
* Assignment: Assignment 4       *
* Due Date: June 28, 2021        *
* Last Modified: June 28, 2021   *
*********************************/

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;


int matrix[10][2];

int randomNumberZeroOne();
void generateChallenge();
void displayPinNumTable();
int findNumForPin(int pin);
int findNumForEachPinDigit(int pinDigit);

/************************************************
 * Function: main                               *
 * Purpose: shows user the pin challenge table  *
 * and asks for pin from user. It also checks   *
 * if the pin entered by user matches the       *
 * challenge                                    *
 * Last Modified: June 28, 2021                 *
 ************************************************/

int main(){
    int actualPin = 2468;
    int enteredPin;
    generateChallenge();
    displayPinNumTable();
    cout << "Enter your 4 digit PIN: ";
    cin >> enteredPin;
    if (enteredPin<1000 || enteredPin > 9999){
      cout<<"Please enter valid PIN"<<endl;
      return -1;
    }
    int numOfActualPin = findNumForPin(actualPin);
    if (numOfActualPin == enteredPin){
      cout << "Your PIN has matched successfully!" << endl;
    }
    else
      cout << "Sorry your PIN has not matched!" << endl;

    return 0;
}

/************************************************
 * Function: generateChallenge                  *
 * Purpose: creates the challenge table of pin  *
 *   and nums                                   *
 * Return Value: void function so no return     *
 * Last Modified: June 28, 2021                 *
 ************************************************/

void generateChallenge(){
  srand(time(NULL));
  for (int a=0; a<10; a++)
    {
        matrix[a][0] = a; 
        matrix[a][1] = rand()%2;
    }
}

/************************************************
 * Function: displayPinNumTable                 *
 * Purpose: Displays the pin and num table in   *    
 *  given format                                *
 * Return Value: void function so no return     *
 * Last Modified: June 28, 2021                 *
 ************************************************/

void displayPinNumTable(){
  cout << "PIN ";
  for (int a=0; a<10; a++){
    cout<< matrix[a][0] << " ";
  }
  cout << endl << "NUM ";
  for (int a=0; a<10; a++){
    cout << matrix[a][1] << " ";
  }
  cout << endl;
}

/************************************************
 * Function: findNumForPin                      *
 * Purpose: Finds the corresponding num from pin*
 * Parameters: pin                              *
 * Return Value: num of actual pin in terms of  *
 *   0 and 1                                    *
 * Last Modified: June 28, 2021                 *
 ************************************************/

int findNumForPin(int pin){
    int numOfActualPin;
    int digitOfNum;
    
    int digitOfPin = pin/1000;
    digitOfNum = findNumForEachPinDigit(digitOfPin);
    numOfActualPin = (1000*digitOfNum);
    
    digitOfPin = (pin%1000)/100;
    digitOfNum = findNumForEachPinDigit(digitOfPin);
    numOfActualPin+=(100*digitOfNum);

    digitOfPin = (pin%100)/10;
    digitOfNum = findNumForEachPinDigit(digitOfPin);
    numOfActualPin += (10*digitOfNum);

    digitOfPin = pin%10;
    digitOfNum = findNumForEachPinDigit(digitOfPin);
    numOfActualPin +=  digitOfNum;
    return numOfActualPin;
}

/************************************************
 * Function: findNumForEachPinDigit             *
 * Purpose: Finds the corresponding num from the*
 *   pin individually given by user             *
 * Parameters: pinDigit                         *
 * Return Value: returns the corresponding num  *
 *   (0 or 1) of pin individually               *
 * Last Modified: June 28, 2021                 *
 ************************************************/

int findNumForEachPinDigit(int pinDigit){
  for (int i = 0; i < 10; i++)
    {
      if (matrix[i][0] == pinDigit){
        return matrix[i][1];
      }
    }
  return -1;
}