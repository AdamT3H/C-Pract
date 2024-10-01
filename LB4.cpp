#include <iostream>
#include <string>

const int number = 20;
const int curYear = 2024;

struct PIB {
    std::string SurName;
    std::string FirstName;
    std::string SecondName;
};

struct nameOfGarageOwner {
    PIB name;
    std::string carBrand;
    std::string carPlate;
    int year;
};

nameOfGarageOwner list[number] = {
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2017},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2018},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2011},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2020},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2010},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2021},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2022},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2004},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2016},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2009},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2005},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2007},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2023},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2015},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2008},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2024},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2012},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2006},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2013},
    {{"Mikolchenko", "Petro", "Adamovich"}, "Toyota", "BC1111IT", 2014}
};

int main() {
    std::cout << "Before sorting:\n";
    for (int i = 0; i < number; i++) {
        std::cout << list[i].name.SurName << "\t" << list[i].name.FirstName << "\t" << list[i].name.SecondName << "\t" << list[i].carBrand << "\t" << list[i].carPlate << "\t" << list[i].year << std::endl;
    }

    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (list[j].year > list[j + 1].year) {
                nameOfGarageOwner temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    std::cout << "\nCars older than 10 years:\n";
    for (int i = 0; i < number; i++) {
        if(curYear - list[i].year >= 10){
        std::cout << list[i].name.SurName << "\t" << list[i].name.FirstName << "\t" << list[i].name.SecondName << "\t" << list[i].carBrand << "\t" << list[i].carPlate << "\t" << list[i].year << std::endl;
        }
    }

    return 0;
}