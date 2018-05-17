// Created by Alex Mounsey : 17/05/2018
// Calculates the Apparent Wind, given the True Wind direction/speed & Vessel heading/speed

#include <math.h>
#include <conio.h>
#include <iostream>

using namespace std;

float calcAWindSpd(float twa, float tws, float vs);
float calcAWindAng(float twa, float tws, float vs, float aws);
float radians(float x);
float degrees(float x);

const double pi = 3.1415926535897;

// Input values
float vesselSpd = 13.00; // Vessel speed over ground (kts)
float tWindSpd = 10.00; // True wind speed (kts)
float tWindAng = 30.00; // True wind angle, relative to vessel's axis (deg) (negative = port side | positive = starboard side)

// Output values
float aWindSpd; // Apparent wind speed (kts)
float aWindAng; // Apparent wind angle, relative to vessel's axis (deg)

void main(int argc, const char* argv[]) {
	aWindSpd = calcAWindSpd(tWindAng, tWindSpd, vesselSpd);
	aWindAng = calcAWindAng(tWindAng, tWindSpd, vesselSpd, aWindSpd);

	cout << "Given that:" << endl;
	cout << "-----------" << endl;
	cout << "Vessel Speed: " << vesselSpd << endl;
	cout << "True Wind Speed: " << tWindSpd << endl;
	cout << "True Wind Angle: " << tWindAng << endl << endl;

	cout << "The following is true:" << endl;
	cout << "----------------------" << endl;
	cout << "Apparent Wind Speed: " << aWindSpd << endl;
	cout << "Apparent Wind Angle: " << aWindAng;

	_getch();
}

// Calculate apparent wind speed (twa=true wind angle, tws=true wind speed, vs=vessel speed
float calcAWindSpd(float twa, float tws, float vs) {
	return sqrt((tws*tws) + (vs*vs) + (2 * tws * vs * cos(radians(twa))));
}

// Calculate apparent wind angle (twa=true wind angle, tws=true wind speed, vs=vessel speed, aws=apparent wind speed)
float calcAWindAng(float twa, float tws, float vs, float aws) {
	return degrees(acos((tws * cos(radians(twa)) + vs) / aws));
}

// Returns x in radians
float radians(float x) { return (x * pi) / 180; }

// Returns x in degrees
float degrees(float x) { return (x / pi) * 180; }