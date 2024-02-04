// Put your name here

#include "functions.h"

#include <iostream>
#include <iomanip>

using namespace std;

// Implement the functions from functions.h here
double getInput(const string& prompt) {
  double input;
  cout << prompt;
  cin >> input;
  if (input > 0) {
	  return input;
  }else {
	return getInput(prompt);
  };
}

double convertDistance(double inches) {
  return inches * 0.0254;
}

double getSpeed(double distance, double seconds) {
  return distance / seconds;
}

double convertSpeed(double metersPerSec) {
  return metersPerSec * 2.23694;
}