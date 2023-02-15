/* 
Programming Project 5: Arrays
Jane McPheron
03/23/2023
*/

 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//class to create objecs out of each data row
class HeightData {       
  public:             // Access specifier
    string myName;        
    string myCity; 
    int myHeight;
};

//function for comparing height values
bool compareNum(const HeightData& a, const HeightData& b) {
    return a.myHeight > b.myHeight;
}

int main(){

    //declaring vector that will contain all data
    vector<HeightData> allData;


    ifstream inputFile;

    //accessing the CSV data file
    inputFile.open("people-data.csv");

    //creating a clear line variable
    string line = "";

    //reading csv
    while (getline(inputFile, line)){
        
        //variables to parse out line
        string name;
        string city;
        int height;
        string tempString;

        //creating a string out of the line
        stringstream inputString(line);


        getline(inputString, name, ',');
        getline(inputString, city, ',');
        getline(inputString, tempString, ',');

        //making string value into integer value
        height = atoi(tempString.c_str());

        //placing data into object
        HeightData dataEntry;
        dataEntry.myName = name;
        dataEntry.myCity = city;
        dataEntry.myHeight = height;

        //putting object into a vector
        allData.push_back(dataEntry);

    }

    //sorting the vector
    sort(allData.begin(), allData.end(), compareNum);


    //declaring arrays
    string nameA[allData.size()];
    string cityA[allData.size()];
    int heightA[allData.size()];


    //looping through main vector to separate data into 3 arrays
    for(int i = 0; i < allData.size(); i++) {

        nameA[i]= allData[i].myName;
        cityA[i]= allData[i].myCity;
        heightA[i] = allData[i].myHeight;

        // cout << nameA[i] << " " << cityA[i] << " "
        // << heightA[i] << endl;
    }


    string keepGoing = "y";

    while (keepGoing == "y"){

    
        //getting user input for search
        string search;
        bool success = false;
        cout << "What city would you like to know about?";
        cin >> search;

        //for loop searching array for info
        for(int i = 0; i < allData.size(); i++) {
            if (cityA[i] == search){
                cout<< "The tallest person in " << cityA[i] << " is " 
                << nameA[i] << " at " << heightA[i] << " inches." << endl;

                //telling computer that the search was successful
                success = true;
                break;
            }

        }

        //telling user computer did not find their search
        if (success == false){
            cout << "Sorry, that information is unavailable." << endl;
        }


        //updating while loop variable
        cout << "Would you like to search for something else? (y/n)";
        cin >> keepGoing;

    }

}