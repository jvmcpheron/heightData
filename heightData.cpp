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

//function for grabbing and outputting data from csv file
void printData(){

string fname;
cout<<"Enter the file name: ";
cin>>fname;
 
vector<vector<string > > content;
vector<string> row;
string line, word;
 
fstream file (fname, ios::in);
if(file.is_open())
{
while(getline(file, line))
{
row.clear();
 
stringstream str(line);
 
while(getline(str, word, ','))
row.push_back(word);
content.push_back(row);
}
}
else
cout<<"Could not open the file\n";
 
for(int i=0;i<content.size();i++)
{
for(int j=0;j<content[i].size();j++)
{
cout<<content[i][j] << " ";
}
cout<<"\n";
}


}


//function testing out how to work with data in different ways
void dataTest(){

string dataName = "people-data.csv";



}


int main(){

    vector<string> names;
    vector<string> cities;
    vector<int> heights;


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

        //placing info into vectors
        names.push_back(name);
        cities.push_back(city);
        heights.push_back(height);


    }

    for(int i = 1; i < names.size(); i++) {
        cout << " " << names[i];
    }



}