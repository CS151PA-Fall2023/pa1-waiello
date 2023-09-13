#include "analytics.h"
#include <string>

void showMenu(){
    cout << "2015 National Survey of Recent College Graduate" << endl;
    cout << "1. Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2. Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3. Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4. Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5. What are the Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6. What are the Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7. What are the Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8. What are the Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9. What are the Top 5 Majors with the Highest Number of Males" << endl;
    cout << "10. What are the Top 5 Majors with the Highest Number of Females" << endl;
    cout << "11. Display Information for a Specific Major" << endl;
    cout << "12. Exit" << endl << endl;
    cout << "Select a Menu: _" << endl;
}

void makeVect(vector <GradEmploymentData> &vect)
{
    ifstream file;
    string stringDelim;
    char delim;
    file.open("graduates2015.csv");
    getline(file, stringDelim);
    for(int i = 0; i < 45; i++)
    {
        int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
        string educationMajor;     // The name of the major for these graduated students
        float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
        float medianSalary;        // The median recorded salary reported for employed people with this degree
        int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
        int demographicsMinority;  // The estimated number of people identifying as minority 
                                // (e.g., Black, African American, Native American) that were awarded degrees in this major
        int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
        int demographicsFemales;   // The estimate number of women awarded degrees in this major
        int demographicsMales;     // The estimate number of men awarded degrees in this major
        int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
        int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
        int educationMasters;      // The estimated number of Masters awarded in this for major        

        file >> demographicsTotal;
        file >> delim;
        char some = ' ';
        file >> some;
        if (some == '"')
        {
            getline(file, educationMajor, '"');
            file >> delim;
        }
        else
        {
            educationMajor+=some;
            string major;
            getline(file, major, ',');
            educationMajor+= major;
        }
        file >> meanSalary;
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
        vect.push_back(GradEmploymentData());
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


void meanSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) {
    float current = v[i].meanSalary;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].meanSalary > current) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].meanSalary = current;
  }
}



void meanSalary(vector <GradEmploymentData> v, bool high)
{
    cout << setw(36) << left << "Education Major" << right   << "Mean Salary\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)
        {
            cout << setw(35) << left << v[i].educationMajor << "$" << right << setw(11) << fixed << setprecision(2) << v[i].meanSalary << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)
        {
            cout << setw(35) << left << v[i].educationMajor  << "$" << right << setw(11) << fixed << setprecision(2) << v[i].meanSalary << endl;
        }
        cout << endl;
    }
}

void medianSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) {
    float current = v[i].medianSalary;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].medianSalary > current) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].medianSalary = current;
  }
}

void medianSalary(vector <GradEmploymentData> v, bool high)
{
    cout << setw(34) << left << "Education Major" << right   << "Median Salary\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)
        {
            cout << setw(35) << left << v[i].educationMajor << "$" << right << setw(11) << fixed << setprecision(2) << v[i].medianSalary << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)
        {
            cout << setw(35) << left << v[i].educationMajor << "$" << right << setw(11) << fixed << setprecision(2) << v[i].medianSalary << endl;
        }
        cout << endl;
    }
}
void demoAsianSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) {
    float current = v[i].demographicsAsian;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].demographicsAsian > current) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].demographicsAsian = current;
  }
}
void demoAsians(vector <GradEmploymentData> v, bool high)
{
    cout << setw(29) << left << "Education Major" << right   << "Demographics Asian\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)
        {
            cout << setw(35) << left << v[i].educationMajor << right << setw(12) << fixed << setprecision(2) << v[i].demographicsAsian << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)
        {
            cout << setw(35) << left << v[i].educationMajor << right << setw(12) << fixed << setprecision(2) << v[i].demographicsAsian << endl;
        }
        cout << endl;
    }
}
void demoMinoSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) {
    float current = v[i].demographicsMinority;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].demographicsMinority > current) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].demographicsMinority = current;
  }
}
void demoMino(vector <GradEmploymentData> v, bool high)
{
    cout << setw(26) << left << "Education Major" << right   << "Demographics Minority\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)
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
void demoMaleSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) {
    float current = v[i].demographicsMales;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].demographicsMales > current) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].demographicsMales = current;
  }
}
void demoMale(vector <GradEmploymentData> v, bool high)
{
    cout << setw(30) << left << "Education Major" << right   << "Demographics Male\n";
    cout << "----------------------------------------------------\n";
    if(high == true)
    {
        for(int i = v.size()-1; i > v.size()-11; i--)
        {
            cout << setw(36) << left << v[i].educationMajor << right << setw(11) << setfill(' ') <<  v[i].demographicsMales << endl;
        }
        cout << endl;
    } 
    else 
    {
        for(int i = 0; i < 10; i++)
        {
            
            cout << setw(36) << left << v[i].educationMajor << right << setw(11) << setfill(' ') <<  v[i].demographicsMales << endl;
        }
        cout << endl;
    }
}
void demoFemaleSort(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) {
    float current = v[i].demographicsFemales;
    GradEmploymentData temp;
    temp = v[i];
    int j = i - 1;
    while (j >= 0 && v[j].demographicsFemales > current) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
    v[j+1].demographicsFemales = current;
  }
}
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
void specMajor(vector <GradEmploymentData> v)
{
    cout << "Enter name of Major: ";
    string major;
    cin.ignore();
    getline(cin, major);
    int result = binarySearch(v, major);

    if (result != -1) {
        cout << "\nMajor: " << v[result].educationMajor << endl << endl;
        cout << "Demographics by Race: " << setw(12) << "Asian" << setw(15) << "Minority" << setw(15) << "White" << endl;
        cout << setw(34) << v[result].demographicsAsian << setw(15) << v[result].demographicsMinority << setw(15) << v[result].demographicsWhite << endl << endl;
        cout << "Demographics by Gender: " << setw(10) << "Male" << setw(15) << "Female" << endl;
        cout << setw(34) << v[result].demographicsMales << setw(15) << v[result].demographicsFemales << endl << endl;
        cout << "Education by Degree: " << setw(13) << "Bachelors" << setw(15) << "Masters" << setw(15) << "Doctorate" << setw(15) << "Total" << endl;
        cout << setw(34) << v[result].educationBachelor << setw(15) << v[result].educationMasters << setw(15) << v[result].educationDoctorate << setw(15) << v[result].demographicsTotal << endl << endl;
        cout << "Salary: " << setw(26) << "Mean" << setw(15) << "Median" << endl;
        cout << setw(24) << "$" << right << setw(10) << fixed << setprecision(2) << v[result].meanSalary << right << setw(5) << "$" << setw(10) << fixed << setprecision(2) << v[result].medianSalary << endl << endl;

    } else {
        cout << major << " not found in the list" << endl;
    }
}
void sortName(vector <GradEmploymentData> &v)
{

  for (int i = 0; i < v.size(); i++) {
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
int binarySearch(vector<GradEmploymentData>& v, string& target) 
{
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        string edMajor = v[mid].educationMajor;
        transform(edMajor.begin(), edMajor.end(), edMajor.begin(), ::tolower);
        transform(target.begin(), target.end(), target.begin(), ::tolower);
        if (edMajor.substr(0, 7) == target.substr(0, 7)) 
        {
            return mid;  // Found the target at index mid
        } 
        else if (edMajor.substr(0, 7) < target.substr(0, 7)) 
        {
            left = mid + 1;  // Search in the right half
        } 
        else 
        {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Target not found in the list
}