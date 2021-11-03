#ifndef csv_Vector_h
#define csv_Vector_h

#include <Arduino.h>
#include "FS.h"

class csv_Vector
{
  public:
    csv_Vector();
  	void init(const char* = ";");
  	bool readLine (File , char* );
    std::vector<uint8_t> readVector (char* , byte , int = 1);

  private:
    const char * _separator = ";";
};

#endif