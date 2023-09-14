/**
 * @file analytics.cpp
 * @author Wade Aiello (waiello@nic.edu)
 * @brief Function file.
 * @version 0.1
 * @date 2023-09-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"

/**
 * @brief displays menu options
 * 
 */
void showMenu()
{                                                                           //Author's note: I started making a new line for my curly brackets because I saw it in a youtube video by a professional coder
    cout << "2015 National Survey of Recent College Graduate" << endl;      //I don't know about you, but it feels pretty nice to me...
    cout << "1. Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2. Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3. Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4. Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5. What are the Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6. What are the Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7. What are the Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8. What are the Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9. What are the Top 5 Majors with the Highest Number of Males" << endl;
    cout << "10. What are the Top 5 Majors with the Lowest Number of Males" << endl;
    cout << "11. What are the Top 5 Majors with the Highest Number of Females" << endl;
    cout << "12. What are the Top 5 Majors with the Lowest Number of Females" << endl;
    cout << "13. Display Information for a Specific Major" << endl;
    cout << "14. Exit" << endl << endl;
    cout << "Select a Menu: _" << endl;
}

/**
 * @brief builds vector
 * 
 * @param vect vector is created in main and called here to be built
 */
void makeVect(vector <GradEmploymentData> &vect)
{
    ifstream file;
    string stringDelim;
    char delim;
    file.open("graduates2015.csv");
    getline(file, stringDelim);    //scrubs first line of file
    for(int i = 0; i < 45; i++)    //repeats 45 times to register
    {
        int demographicsTotal;      // The estimated total of people awarded degrees in this major during 2005
        string educationMajor;      // The name of the major for these graduated students
        float meanSalary;           // The average (mean) recorded salary reported for employed people with this degree
        float medianSalary;         // The median recorded salary reported for employed people with this degree
        int demographicsAsian;      // The estimated number of people identifying as Asian that were awarded degrees in this major
        int demographicsMinority;   // The estimated number of people identifying as minority 
                                    // (e.g., Black, African American, Native American) that were awarded degrees in this major
        int demographicsWhite;      // The estimated number of people identifying as White that were awarded degrees in this major
        int demographicsFemales;    // The estimate number of women awarded degrees in this major
        int demographicsMales;      // The estimate number of men awarded degrees in this major
        int educationBachelor;      // The estimated number of bachelor degrees awarded in this for major
        int educationDoctorate;     // The estimated number of doctoral degrees awarded in this for major
        int educationMasters;       // The estimated number of Masters awarded in this for major        

        file >> demographicsTotal;
        file >> delim;
        char some = ' ';
        file >> some;
        if (some == '"')            //checks to see if quotes are used in-file for the majors (the majors that include commas in them)
        {
            getline(file, educationMajor, '"');
            file >> delim;
        }
        else                        //records data on major until a comma occurs
        {
            educationMajor+=some;
            string major;
            getline(file, major, ',');
            educationMajor+= major;
        }
        file >> meanSalary;         //goes down the list of the file, delims denote commas in between the numbers
        file >> delim;
        file >> medianSalary;
        file >> delim;
        file >> demographicsAsian;
        file >> delim;
        file >> demographicsMinority;
        file >> delim;
        file >> demographicsWhite;
        file >> delim;
        file >> demographicsFemales;
        file >> delim;
        file >> demographicsMales;
        file >> delim;
        file >> educationBachelor;
        file >> delim;
        file >> educationDoctorate;
        file >> delim;
        file >> educationMasters;
        vect.push_back(GradEmploymentData());   //makes new vector element, coming lines record from file into vector
        vect[i].demographicsAsian = demographicsAsian;
        vect[i].demographicsFemales = demographicsFemales;
        vect[i].demographicsMales = demographicsMales;
        vect[i].demographicsMinority = demographicsMinority;
        vect[i].demographicsTotal = demographicsTotal;
        vect[i].demographicsWhite = demographicsWhite;
        vect[i].educationBachelor = educationBachelor;
        vect[i].educationDoctorate = educationDoctorate;
        vect[i].educationMajor = educationMajor;
        vect[i].educationMasters = educationMasters;
        vect[i].meanSalary = meanSalary;
        vect[i].medianSalary = medianSalary;
    }
    file.close();
}

/**
 * @brief resorts vector with insertion sort by mean salary, ascending
 * 
 * @param v unsorted vector
 */
void meanSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++)                //insertion sort
  {  
    float current = v[i].meanSalary;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].meanSalary > current) 
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].meanSalary = current;
  }
}


/**
 * @brief displays mean salary, if bool param is true, in descending order, and in ascending order otherwise
 * 
 * @param v sorted vector
 * @param high parameter determining what order the vector is displayed
 */
void meanSalary(vector <GradEmploymentData> v, bool high)
{
    cout << setw(36) << left << "Education Major" << right   << "Mean Salary\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)       //descending order
        {
            cout << setw(35) << left << v[i].educationMajor << "$" << right << setw(11) << fixed << setprecision(2) << v[i].meanSalary << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)                         //ascending order
        {
            cout << setw(35) << left << v[i].educationMajor  << "$" << right << setw(11) << fixed << setprecision(2) << v[i].meanSalary << endl;
        }
        cout << endl;
    }
}

/**
 * @brief sorts vector by median in ascending order
 * 
 * @param v unsorted vector
 */
void medianSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++)                //insertion sort
  {
    float current = v[i].medianSalary;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].medianSalary > current) 
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].medianSalary = current;
  }
}


/**
 * @brief displays median salary, if bool param is true, in descending order, and in ascending order otherwise
 * 
 * @param v sorted vector
 * @param high parameter determining what order the vector is displayed
 */
void medianSalary(vector <GradEmploymentData> v, bool high)
{
    cout << setw(34) << left << "Education Major" << right   << "Median Salary\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)   //descending order
        {
            cout << setw(35) << left << v[i].educationMajor << "$" << right << setw(11) << fixed << setprecision(2) << v[i].medianSalary << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)                     //ascending order
        {
            cout << setw(35) << left << v[i].educationMajor << "$" << right << setw(11) << fixed << setprecision(2) << v[i].medianSalary << endl;
        }
        cout << endl;
    }
}

/**
 * @brief sorts vector by number of asians enrolled in major
 * 
 * @param v unsorted vector
 */
void demoAsianSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++)                    //insertion sort
  {
    float current = v[i].demographicsAsian;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].demographicsAsian > current) 
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].demographicsAsian = current;
  }
}

/**
 * @brief displays asian demographics, if bool param is true, in descending order, and in ascending order otherwise
 * 
 * @param v sorted vector
 * @param high parameter determining what order the vector is displayed
 */
void demoAsians(vector <GradEmploymentData> v, bool high)
{
    cout << setw(29) << left << "Education Major" << right << "Demographics Asian\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)           //descending order
        {
            cout << setw(35) << left << v[i].educationMajor << right << setw(12) << fixed << setprecision(2) << v[i].demographicsAsian << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)                             //ascending order
        {
            cout << setw(35) << left << v[i].educationMajor << right << setw(12) << fixed << setprecision(2) << v[i].demographicsAsian << endl; //I hope you noticed how all the majors are lined up with the demographics numbers
        }                                                                                                                                       //it's not easy work making the formatting look perfect
        cout << endl;
    }
}

/**
 * @brief sorts vector by number of minorities enrolled in major
 * 
 * @param v unsorted vector
 */
void demoMinoSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++)                            //insertion sort
  {                         
    float current = v[i].demographicsMinority;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].demographicsMinority > current) 
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].demographicsMinority = current;
  }
}

/**
 * @brief displays minority demographics, if bool param is true, in descending order, and in ascending order otherwise
 * 
 * @param v sorted vector
 * @param high parameter determining what order the vector is displayed
 */
void demoMino(vector <GradEmploymentData> v, bool high)
{
    cout << setw(26) << left << "Education Major" << right   << "Demographics Minority\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)           //you get the idea
        {
            cout << setw(36) << left << v[i].educationMajor << right << setw(11) << setfill(' ') <<  v[i].demographicsMinority << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)
        {
            
            cout << setw(36) << left << v[i].educationMajor << right << setw(11) << setfill(' ') <<  v[i].demographicsMinority << endl;
        }
        cout << endl;
    }
}

/**
 * @brief sorts vector by number of males enrolled in major
 * 
 * @param v unsorted vector
 */
void demoMaleSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) 
  {
    float current = v[i].demographicsMales;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].demographicsMales > current) 
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].demographicsMales = current;
  }
}

/**
 * @brief displays male demographics, if bool param is true, in descending order, and in ascending order otherwise
 * 
 * @param v sorted vector
 * @param high parameter determining what order the vector is displayed
 */
void demoMale(vector <GradEmploymentData> v, bool high)
{
    cout << setw(30) << left << "Education Major" << right   << "Demographics Male\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)
        {
            cout << setw(36) << left << v[i].educationMajor << right << setw(11) << v[i].demographicsMales << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)                                                     //I figured I might as well include lowest for male and female since I basically copied the same functions from the previous salary and demo stuff
        {
            
            cout << setw(36) << left << v[i].educationMajor << right << setw(11)  <<  v[i].demographicsMales << endl;
        }
        cout << endl;
    }
}

/**
 * @brief sorts vector by number of males enrolled in major
 * 
 * @param v unsorted vector
 */

void demoFemaleSort(vector <GradEmploymentData> &v)
{

    for (int i = 0; i < v.size(); i++) 
    {
        float current = v[i].demographicsFemales;
        GradEmploymentData temp;
        temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].demographicsFemales > current) 
        {
        v[j + 1] = v[j];
        j--;
        }
        v[j + 1] = temp;
        v[j+1].demographicsFemales = current;
    }
}

/**
 * @brief displays female demographics, if bool param is true, in descending order, and in ascending order otherwise
 * 
 * @param v sorted vector
 * @param high parameter determining what order the vector is displayed
 */
void demoFemale(vector <GradEmploymentData> v, bool high)
{
    cout << setw(28) << left << "Education Major" << right   << "Demographics Female\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)
        {
            cout << setw(36) << left << v[i].educationMajor << right << setw(11) << setfill(' ') <<  v[i].demographicsFemales << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)
        {
            cout << setw(36) << left << v[i].educationMajor << right << setw(11) << setfill(' ') <<  v[i].demographicsFemales << endl;
        }
        cout << endl;
    }
}

/**
 * @brief This function displays major information based on user input
 * 
 * @param v sorted vector
 */
void specMajor(vector <GradEmploymentData> v)
{
    cout << "Enter name of Major: ";
    string major;
    cin.ignore();                           //here bc of previous cin data
    getline(cin, major);
    int result = binarySearch(v, major);    //runs binarySearch, which finds the index of the major and uses that in displayed information

    if (result != -1) 
    {
        cout << "\nMajor: " << v[result].educationMajor << endl << endl;                                                                                            //I'm particularly proud of the formatting here. I imagine I spent at least 20 minutes getting this to look just right
        cout << "Demographics by Race: " << setw(12) << "Asian" << setw(15) << "Minority" << setw(15) << "White" << endl;
        cout << setw(34) << v[result].demographicsAsian << setw(15) << v[result].demographicsMinority << setw(15) << v[result].demographicsWhite << endl << endl;
        cout << "Demographics by Gender: " << setw(10) << "Male" << setw(15) << "Female" << endl;
        cout << setw(34) << v[result].demographicsMales << setw(15) << v[result].demographicsFemales << endl << endl;
        cout << "Education by Degree: " << setw(13) << "Bachelors" << setw(15) << "Masters" << setw(15) << "Doctorate" << setw(15) << "Total" << endl;                                                      //I wasn't sure which line to put the demographc totals on. On the one hand, the formatting would probably look best,
        cout << setw(34) << v[result].educationBachelor << setw(15) << v[result].educationMasters << setw(15) << v[result].educationDoctorate << setw(15) << v[result].demographicsTotal << endl << endl;   //but I felt like I was making a political statement with that. Gender is not the all-encompassing demographic category
        cout << "Salary: " << setw(26) << "Mean" << setw(15) << "Median" << endl;                                                                                                                           //I want to associate the "total" number with; the degree category is much less politically motivated.
        cout << setw(24) << "$" << right << setw(10) << fixed << setprecision(2) << v[result].meanSalary << right << setw(5) << "$" << setw(10) << fixed << setprecision(2) << v[result].medianSalary << endl << endl;  

    } 
    else 
    {
        cout << major << " not found in the list" << endl;
    }
}
/**
 * @brief sorts by name in ascending order
 * 
 * @param v unsorted vector
 */
void sortName(vector <GradEmploymentData> &v)
{
    for (int i = 0; i < v.size(); i++)                        //still insertion sort
    {
        string current = v[i].educationMajor;
        GradEmploymentData temp;
        temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].educationMajor > current) 
        {
        v[j + 1] = v[j];
        j--;
        }
        v[j + 1] = temp;
        v[j+1].educationMajor = current;
    }
}
/**
 * @brief Turns strings lowecase and compares them using binary search
 * 
 * @param v sorted vector
 * @param target user input
 * @return int returns index of major
 */
int binarySearch(vector<GradEmploymentData>& v, string& target) 
{
    int left = 0;
    int right = v.size() - 1;

    while (left <= right)                                           //binary search
    {                                                         
        int mid = left + (right - left) / 2;

        string edMajor = v[mid].educationMajor;
        transform(edMajor.begin(), edMajor.end(), edMajor.begin(), ::tolower);      //converts both strings to lowercase, so case doesn't matter. Extra credit...?
        transform(target.begin(), target.end(), target.begin(), ::tolower);
        if (edMajor.substr(0, 7) == target.substr(0, 7))                            //I honestly didn't know the <string> library included such beautiful functions as substr...
        {                                                                           //Here I decided to just compare the first 7 digits, because people make mistakes and the onlyreal repeats are the
            return mid;                                                             //"other" categories, which means you've gotta search the 5 digits in other plus the space and the first digit of the next word.
        }                                                                           //If you want, you can try it out! I personally did "computeoadjfposijfnlasdjfaj" and it returned the computer science major information.
        else if (edMajor.substr(0, 7) < target.substr(0, 7)) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }

    return -1;
}