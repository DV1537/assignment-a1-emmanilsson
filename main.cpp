#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, const char *argv[])
{

    std::ifstream myfile;

    myfile.open("textfile.txt");

    double *ptr; //Deklarera en pekare av typen double
    double average = 0, sum = 0;
    int numberOfElements, n;
    ptr = new double[numberOfElements]; //Pekaren pekar på en dynamiskt allokerad array som har numberOfElements antal element som användaren får mata in

    std::cout << "How many numbers did you write in the file?";
    std::cin >> numberOfElements;



    for (n = 0; n < numberOfElements; n++)
    {
        myfile >> ptr[n];                                       //Läser in alla värden från filen


        if (myfile.fail())                                      //Om det sker felinmatningar
        {
            std::cout << "Wrong input, program terminates...\n"
                      << "Press [ENTER] to close program";
            getchar();
            getchar();

            exit(EXIT_FAILURE);                                 //Skall programmet stängas ner
        }

    }



    std::cout << "You have entered: ";
    for (n = 0; n < numberOfElements; n++)
    {
        std::cout << std::fixed << std::setprecision(3) << ptr[n] << ", ";
    }



    for (n = 0; n < numberOfElements; n++)
    {
        sum += ptr[n];
    }

    getchar();
    getchar();


    myfile.close();



    average = sum / numberOfElements;

    std::cout << "The number/s greater than the average is: ";
    for (n = 0; n < numberOfElements; n++)
    {
        if (ptr[n] > average)
            std::cout << ptr[n] << " ";
    }



    getchar();
    getchar();

    return 0;
}
