#include "analytics.h"

int main()
{
    cout.imbue(std::locale("")); //sets comma for formatting. I just wanted it to look nice
    vector <GradEmploymentData> data;
    makeVect(data);    
    
    while(true){
        showMenu();
        int number;
        cin >> number;


        switch(number)
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
            demoFemaleSort(data);
            demoFemale(data, true);
            break;

            case 11:
            sortName(data);
            specMajor(data);
            break;

            //specific major

            case 12:
            return 0;

            default:
            cout << "Invalid Input. ";
            break;
            
        }
        cout << "Press enter to continue...\n";
        string any;
        if(number != 11)
        {
        cin.ignore();
        }
        getline(cin, any);
    }
/*     meanSort(data);
    meanSalary(data, true);
    meanSalary(data, false);
    medianSort(data);
    medianSalary(data, true);
    demoAsianSort(data);
    demoAsians(data, true);
    demoMinoSort(data);
    demoMino(data, true);
    demoFemaleSort(data);
    demoFemale(data, true);
    demoMaleSort(data);
    demoMale(data, true);

 */

    return 0;
}