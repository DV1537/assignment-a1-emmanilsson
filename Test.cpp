#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */

int main(int argc, const char *argv[])
{

    std::ifstream myfile;

    myfile.open(argv[1]);

    double *ptrNumbers; //Declare a pointer of type double
    double average = 0, sum = 0;
    int numberOfElements, n;
    ptrNumbers = new double[numberOfElements]; 


    while (!myfile.eof())
    {
        float a;
        myfile >> a;
        numberOfElements++;


        if (myfile.fail()) //If the input is wrong 
        {
            std::cout << "Wrong input, program terminates...\n"
                      << "Press [ENTER] to close program";
            getchar();
            getchar();

            exit(EXIT_FAILURE); //Program shuts down
        }
    }

    myfile.close();


    myfile.open(argv[1]);
    


    for (n = 0; n < numberOfElements; n++)
    {

        myfile >> ptrNumbers[n];        //Reads all the numbers from the file
   
    }


    std::cout << "Input: ";
    for (n = 0; n < numberOfElements; n++)
    {

        ptrNumbers[n] = round(ptrNumbers[n] * 1000) / 1000;     //Print the numbers with 3 decimal digits
        
        std::cout << ptrNumbers[n] << ", ";
    
    }


    for (n = 0; n < numberOfElements; n++)
    {

        sum += ptrNumbers[n];
    
    }

    getchar();
    getchar();

    myfile.close();

    average = sum / numberOfElements;
    

    std::cout << "The number/s greater than the average is: ";
    for (n = 0; n < numberOfElements; n++)
    {
        ptrNumbers[n] = round(ptrNumbers[n] * 1000) / 1000;     //Print the numbers with 3 decimal digits

        if (ptrNumbers[n] > average)
            std::cout << ptrNumbers[n] << " ";
    }



    delete[] ptrNumbers;
    ptrNumbers = NULL;

    getchar();
    getchar();

    return 0;
}
