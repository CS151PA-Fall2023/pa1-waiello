/**
 * @file main.cpp
 * @author Wade Aiello (waiello@nic.edu)
 * @brief Main program file. Sorts files based on user input or searches files based on user input.
 * @version 0.1
 * @date 2023-09-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"

int main()
{
    cout.imbue(locale(""));                         //sets comma for formatting large numbers. I'm shocked it was this easy. I just wanted it to look nice
    vector <GradEmploymentData> data;               //vector of GradEmploymentData
    makeVect(data);                                 //Makes vector data
    
    while(true)
    {
        showMenu();                                 //shows menu, recieves user input and outputs
        int number;
        cin >> number;
        switch(number)                              //switch statement that runs functions based on input
        {
            case 1:
            meanSort(data);
            meanSalary(data, true);
            break;

            case 2:
            meanSort(data);
            meanSalary(data, false);
            break;

            case 3:
            medianSort(data);
            medianSalary(data, true);
            break;
            
            case 4:
            medianSort(data);
            medianSalary(data, false);
            break;

            case 5:
            demoAsianSort(data);
            demoAsians(data, true);
            break;
            
            case 6:
            demoAsianSort(data);
            demoAsians(data, false);
            break;
            
            case 7:
            demoMinoSort(data);
            demoMino(data, true);
            break;
            
            case 8:
            demoMinoSort(data);
            demoMino(data, false);
            break;

            case 9:
            demoMaleSort(data);
            demoMale(data, true);
            break;

            case 10:
            demoMaleSort(data);
            demoMale(data, false);
            break;

            case 11:
            demoFemaleSort(data);
            demoFemale(data, true);
            break;

            case 12:
            demoFemaleSort(data);
            demoFemale(data, false);
            break;

            case 13:
            sortName(data);
            specMajor(data);
            break;

            case 14:
            return 0;

            default:
            cout << "Invalid Input. ";
            break;
        }
        cout << "Press enter to continue...\n";
        string any;
        if(number != 13)                            //Because number 11 includes another getline statement with the specMajor function,
        {                                           //for whatever reason you don't need the cin.ignore statement and it does it twice with the statement here
        cin.ignore();
        }
        getline(cin, any);
    }
    return 0;
}