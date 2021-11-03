#include "csv_Vector.h"

// Constructor
csv_Vector::csv_Vector()
{

}

/*	Argument:
		separator	to specify the separator between each data ";" by default
*/
void csv_Vector::init(const char* separator)
{
_separator = separator;

}

/*  Read a line in the csv file
	Returns true if ok, false if end of file reached
*/
bool csv_Vector::readLine (File file, char* buffer)
{
	if (!file.available()) return false;

	int i = 0;
	char c = file.read();
	while (c != '\n') {
		buffer[i++] = c;
		c = file.read();
	}
	buffer[i] = NULL;

	return true;
}
/*  Read the data in a line and returns a vector of bytes
	Arguments:
		buffer		the array of chars containing the line
		nFeatures	number of data in each line (the last data is the class)
		norm		normalizing factor to get numbers in [0 - 255], equal to 1 by default
*/
std::vector<uint8_t> csv_Vector::readVector (char *buffer, byte nFeatures, int norm)
{
	std::vector<uint8_t> x;
	char * pch = strtok(buffer, _separator);
	int k = 0;
	uint8_t y = 0;
	while (pch != NULL)
	{
	if (k == 0) y = atoi(pch);
	else {
		int u;
		if (k < nFeatures) u  = atoi(pch);
		else {
			u  = atof(pch) / norm;
			if (u > 255) u = 255;
		}
		x.push_back(u);
	}
	k++;
	pch = strtok(NULL, _separator);
	}
	x.push_back(y);
	return x;
}
