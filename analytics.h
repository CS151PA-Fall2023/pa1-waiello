#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct GradEmploymentData
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
};
void showMenu();
void makeVect(vector <GradEmploymentData> &vect);
void meanSalary(vector <GradEmploymentData> v, bool high);
void meanSort(vector <GradEmploymentData> &v);
void medianSort(vector <GradEmploymentData> &v);
void medianSalary(vector <GradEmploymentData> v, bool high);
void demoAsianSort(vector <GradEmploymentData> &v);
void demoAsians(vector <GradEmploymentData> v, bool high);
void demoMinoSort(vector <GradEmploymentData> &v);
void demoMino(vector <GradEmploymentData> v, bool high);
void demoMaleSort(vector <GradEmploymentData> &v);
void demoMale(vector <GradEmploymentData> v, bool high);
void demoFemaleSort(vector <GradEmploymentData> &v);
void demoFemale(vector <GradEmploymentData> v, bool high);
void sortName(vector <GradEmploymentData> &v);
void specMajor(vector <GradEmploymentData> v);
int binarySearch(vector<GradEmploymentData>& v, string& target);

#endif
