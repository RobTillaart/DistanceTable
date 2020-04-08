//
//    FILE: DistanceTable.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.4
// PURPOSE: memory efficient DistanceTable for Arduino
//     URL: 
//
// Released to the public domain
//

#ifndef DistanceTable_h
#define DistanceTable_h

#include "Arduino.h"

#define DISTANCETABLE_LIB_VERSION "0.1.4"

class DistanceTable
{
public:
    explicit DistanceTable(uint8_t);
    ~DistanceTable();

    void clear();
    void set(uint8_t x, uint8_t y, float value );
    float get(uint8_t x, uint8_t y);
    void dump();
    uint16_t size() { return _store; };

protected:
    int getIndex(uint8_t, uint8_t);

    uint8_t _size;
    uint16_t _store;
    float * _distanceTable;
};

#endif
// --- END OF FILE ---