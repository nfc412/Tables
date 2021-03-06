// Tables_Cosentino_Nicholas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

fstream fileWriter;
fstream inputValues;

int main() {

	const double gravitationalConstant = -9.81;

	int onGround;
	double launchVelocity, time, distance, launchVelocityFinal;

	ofstream fileWriter;
	fileWriter.open("C:\\Users\\Nicholas\\source\\repos\\Tables.txt", ios::out);
	if (!fileWriter) {
		cout << "File open failure";
	}
	
	ifstream inputValues;
	inputValues.open("C:\\Users\\Nicholas\\source\\repos\\inputValues.txt", ios::in);
	if (!inputValues) {
		cout << "File not found";
	}

	cout << "Time (seconds)" << setw(12) << " " << "Height (meters)\n";

	
	inputValues >> launchVelocity;

	while (!inputValues.eof()) {
		time = 0;
		
		onGround = 0;

		while (onGround < 2) {


			distance = (launchVelocity * time) + ((1 / 2) * (gravitationalConstant) * (pow(time, 2)));
			launchVelocityFinal = launchVelocity + (gravitationalConstant * time);
			launchVelocity = launchVelocityFinal;


			if (distance <= 0) {
				onGround++;
			}

			cout << setw(5) << " " << time << setw(20) << " " << distance << '\n';

			time++ ;

		
		}
		cout << '\n';
		inputValues >> launchVelocity;
	}
	inputValues.close();
	fileWriter.close();
}

