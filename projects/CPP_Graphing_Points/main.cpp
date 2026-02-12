/***************************************************************
* Programmer: Hayden Gamble
* Date: 02-02-2024
* Name: hw1
* Description: This program reads information from a file
*   and computes the mean, standard deviation, minimum, and
*   maximum values of it. It then generates a graph to visually
*   show the data.
****************************************************************/
/* Header Files for the Program */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

/* using namespace "std" */
using namespace std;

/*************************************************************************
 * Description: getMean function calculates the mean of the data in the file.
 * Inputs: The vector of all the data values.
 * Outputs: Returns the mean of the data in the file as a double.
 *************************************************************************/
double getMean(const vector<double>& data){
    double sum = 0.0; // Has the total sum start at 0
    for(double num : data){ // Loop through each value from the data
        sum += num; // Adds current number to the sum
    }
    return sum/data.size(); // Calculates and returns the mean of the data in the file
}

/*************************************************************************
 * Description: getStanDev function calculates the standard deviation of the data in the file.
 * Inputs: The vector of all the data values and the mean as a double.
 * Outputs: Returns the standard deviation of the data in the file as a double.
 *************************************************************************/
double getStanDev(const vector<double>& data, double meanVar) {
    double squareDifferences = 0.0; // Creates variable that stores the sum of squared differences
    for(double value : data){ // Loop through each value from the data
        double distance = value - meanVar; // Calculates the distance from the mean
        squareDifferences += distance * distance; // Adds the squared distance to the running total of squared differences
    }
    return sqrt(squareDifferences/data.size()); // Returns the standard deviation of the data in the file
}

/*************************************************************************
 * Description: getMin function finds the minimum value of the data in the file.
 * Inputs: The vector of all the data values.
 * Outputs: Returns the minimum value as a double from the data in the file.
 *************************************************************************/
double getMin(const vector<double>& data){
    double start = data[0]; // Initializes the start to the first element of the data
    for (int i = 0; i < data.size(); i++){ // Loops through the data
        if (data[i]<start){ // If the current element is less than the start element
            start = data[i]; // Updates the start to the current element
        }
    }
    return start; // Return the minimum value of the data from the file
}

/*************************************************************************
 * Description: getMax function finds the maximum value of the data in the file.
 * Inputs: The vector of all the data values.
 * Outputs: Returns the minimum value as a double from the data in the file.
 *************************************************************************/
double getMax(const vector<double> & data){
    double start = data[0]; // Initializes the start to the first element of the data
    for(int i = 0; i < data.size(); i++) { // Loops through the data
        if(data[i]>start){ // If the current element is greater than the start element
            start = data[i]; // Updates the start to the current element
        }
    }
    return start; // Return the maximum value of the data from the file
}

/* Main Function: */
int main() {
    ////////////////////////////////////////////////////////////////////////
    // accessing the data file
    ///////////////////////////
    ifstream fin("exampleInput.txt");
    // ifstream fin("exampleInput2.txt");
    // ifstream fin("exampleInput3.txt");
    // ifstream fin("exampleInput4.txt");
    // ifstream fin("exampleInput5.txt");
    ////////////////////////////////////////////////////////////////////////
    
    /* If reading the file fails, print "Error: could not open data.txt". */
    if (fin.fail()){
        cout << "Error: could not open the file";
        return -1;
    } else {
        cout << "Opened the file successfully\n";
    }

    /* Reading the data from the file into the vector. */
    vector<double> data = {}; // Vector to store the data from the file
    int num, sum=0, count=0;
    string tmp;
    getline(fin,tmp,'[');
    getline(fin,tmp,'[');
    char str = ',';
    while (fin.good() && str != ']') {
//        cout << "adding data values to vector: " << count << endl;
        fin >> num >> str;
        data.push_back(num);
        count++;
//        cout << num << endl;
    }

    /* Printing out the mean, standard deviation, minimum, and maximum values of the 
     * data into the terminal. */
    cout << "The mean is: " << getMean(data) << endl;
    cout << "The s.d. is: " << getStanDev(data, getMin(data)) << endl;
    cout << "The min is: " << getMin(data) << endl;
    cout << "The max is: " << getMax(data) << endl;
    fin.close();

    /*************************************************************************
     * Outputting Into SVG
     *************************************************************************/
    ofstream fout("outputGraphs.svg");
    
    // Creating variables for the outputted graph.
    double topMargin = 70;
    double bottomMargin = 70;
    double leftMargin = 70;
    double rightMargin = 70;
    double xAxisSize = getMax(data) - getMin(data);
    // cout << "xAxisSize: " << xAxisSize << endl;
    double yAxisSize = data.size() + 1;
    // cout << "yAxisSize: " << yAxisSize << endl;
    double origin = yAxisSize+topMargin;
    // cout << "the origin: " << origin << endl;
    double height = 500;
    // cout << "graph height: " << height << endl;
    double width = 1000;
    double xScale = (width - leftMargin - rightMargin)/(data.size());
    // cout << "xScale is: " << xScale << endl;
    double yScale = (height - bottomMargin - topMargin)/(getMax(data)- getMin(data));
    // cout << "yScale is: " << yScale << endl;
    // cout << "xScale on data is: " << xScale * (width - leftMargin - rightMargin) << endl;
    // cout << "yScale on difference of max and min is: " << yScale*(getMax(data)-getMin(data)) << endl;

    // Writing the SVG file in C++ for it to be transfered over to the .svg file.
    fout << R"(<svg version="1.1" width=")" << width << R"(" height=")" << height << R"(" )";
    fout << R"(xmlns="http://www.w3.org/2000/svg">)" << endl;
    fout << R"(<polyline fill="none" stroke="#0074d9" stroke-width="3")" << endl;
    fout << R"(points=")";
    for (int i = 0; i < data.size(); ++i) {
        cout << "starting data for loop for output" << endl;
        fout << (i * xScale) + leftMargin << ", " << height - bottomMargin - ((data[i]-getMin(data))*yScale) << endl;
        cout << i << ", " << data[i] << endl;
    }
    cout << "The size of the 'data' vector is " << data.size() << endl;
    fout << R"("/>)" << endl;
    double fontSize = 12;
    fout << R"(<text x="10" y="20" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">Mean: )" << getMean(data) << R"(</text>)" << endl;
    fout << R"(<text x="10" y="32" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">Standard Deviation: )" << getStanDev(data, getMean(data)) << R"(</text>)" << endl;
    fout << R"(<text x="10" y="44" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">Minimum: )" << getMin(data) << R"(</text>)" << endl;
    fout << R"(<text x="10" y="56" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">Maximum: )" << getMax(data) << R"(</text>)" << endl;
    fout << R"(<polyline fill="none" stroke="#0074d9" stroke-width="3" points=")" << leftMargin << R"(,)" << (height - bottomMargin) << R"( )" << (width - rightMargin) << R"(,)" << (height - bottomMargin) << R"("/>)" << endl;
    fout << R"(<polyline fill="none" stroke="#0074d9" stroke-width="3" points=")" << (leftMargin) << R"(,)" << (height - bottomMargin) << R"( )" << (leftMargin) << R"(,)" << (topMargin) << R"("/>)" << endl;
    fout << R"(<text x=")" << (width - rightMargin - 20) << R"(" y=")" << (height - bottomMargin + 20) << R"(" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">)"<<  data.size() << R"(</text>)" << endl;
    fout << R"(<text x=")" << leftMargin << R"(" y=")" << (height - bottomMargin + 20) << R"(" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">0</text>)" << endl;
    fout << R"(<text x=")" << (leftMargin - 25) << R"(" y=")" << (height - bottomMargin) << R"(" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">)"<<  getMin(data) << R"(</text>)" << endl;
    fout << R"(<text x=")" << (leftMargin - 30) << R"(" y=")" << (topMargin + 10) << R"(" font-family="Verdana" font-size=")" << fontSize << R"(" fill="blue">)"<<  getMax(data) << R"(</text>)" << endl;
    fout << R"(</svg>)" << endl;
    // cout << origin << endl;
    fout.close();
    // cout << "ave = " << static_cast<float>(sum)/count << endl;
    return 0;
}
