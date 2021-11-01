// Copyright (c) 2019 St. Mother Teresa HS All rights reserved.
//
// Created by: Seti Ngabo
// Created on: Oct 2021
// This program prints 10 random numbers with the largest number at the bottom


#include <iostream>
#include <random>
#include <array>


template<size_t N>
int largestNumber(std::array<int, N> number) {
    // This function finds the largest number
    int bigNumber = number[1];

    // process
    for (int counter = 0; counter < number.size(); counter++) {
        if (number[counter] > bigNumber) {
            bigNumber = number[counter];
        }
    }

    return bigNumber;
}

int main() {
    // This function prints the largest number

    std::array<int, 10> number;
    int randomNumber;
    int bigNumber;

    // heading
    std::cout << "Here is a list of random numbers : \n" << std::endl;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 100);

    // process
    for (int counter = 1; counter < 11; counter++) {
        randomNumber = idist(rgen);
        number[counter] = randomNumber;
        std::cout << "The random number " << counter << " is : "
        << randomNumber << std::endl;
    }

    bigNumber = largestNumber(number);
    // output
    std::cout << "\nThe largest number is " << bigNumber << std::endl;

    std::cout << "\nDone." << std::endl;
}
