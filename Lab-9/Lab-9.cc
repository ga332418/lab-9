/*
 *        File: lab-9.cc
 *      Author: Gabriel Avink
 *        Date: 3/17/2021
 * Description: git lab 9
 */

#include <iostream>
#include <fstream>

int findLowestLow(int[]);
int findHighestLow(int[]);
float findAverageLow(int[]);
using namespace std;
int main()
{

        int dailyLow[30], lowest, highest;
        float average;

        ifstream f("athens_low_temps.txt");

        if (f.is_open())
        {

                for (int i = 0; i < 30; i++)
                {

                        f >> dailyLow[i];
                }

                lowest = findLowestLow(dailyLow);
                highest = findHighestLow(dailyLow);
                average = findAverageLow(dailyLow);

                cout << "Lowest low temperature: " << lowest << endl;
                cout << "Highest low temperature: " << highest << endl;
                cout << "Average low temperature: " << average << endl;
        }

        else
        {
                cout << "File failed to open.";
        }

        f.close();
        return 0;
}

int findLowestLow(int temp[])
{

        int lowest = temp[0];

        for (int i = 0; i < 30; i++)

                if (temp[i] < lowest)
                        lowest = temp[i];

        return lowest;
}

int findHighestLow(int temp[])
{

        int highest = temp[0];

        for (int i = 0; i < 30; i++)

                if (temp[i] > highest)
                        highest = temp[i];

        return highest;
}

float findAverageLow(int temp[])
{

        int sum = 0;
        float avg;

        for (int i = 0; i < 30; i++)

                sum = sum + temp[i];

        avg = sum / 30.0;

        return avg;
}