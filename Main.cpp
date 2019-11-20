#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#include <cstdlib>
using namespace std;

#include "arrays.h"

int main()
{

    /* Read from file
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";
    */

    string progNum;
    int input;

    while(true)
    {

        cout << "\nChoose a program \n" << endl;

        cout << "(1) Calculate square\n(2) Gym age calculator\n(3) Load apples in boxes\n(4) Find the average and the sum of an array" << endl;
        cout << "(5) Sum of all the odds in the array\n(6) Pyramid builder\n(7) Multiplication table test\n(8) Find numbers smaller than average" << endl;
        cout << "(9) Find the smallest element of an array\n(10) Bubble sorter\n(11) Find most frequent element" << endl;

        cout << "\nEnter program number: " << endl;
        cin >> progNum;

        int num = std::atoi(progNum.c_str());
        switch(num)
        {
        case 1:
            SquareFinder();
            break;

        case 2 :
            GymCalc();
            break;

        case 3 :
            AppleCounter();
            break;

        case 4 :
            SumAndAvrg();
            break;

        case 5 :
            SumOfOds();
            break;

        case 6 :
            PyramidBuilder();
            break;

        case 7 :
            MultipTest();
            break;

        case 8 :
            SmallerThanAvrg();
            break;

        case 9 :
            MinFinder();
            break;

        case 10 :
            BubbleSort();
            break;

        case 11 :
            int arr[] = { 88, 5, 2, 88, 2, 65, 88 };
            int n = sizeof(arr) / sizeof(arr[0]);
            cout << mostFrequent(arr, n);
            break;
        }
    }
}
