
[![Arduino CI](https://github.com/RobTillaart/Distancetable/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/Distancetable/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/Distancetable.svg?maxAge=3600)](https://github.com/RobTillaart/Distancetable/releases)

# Distancetable

Arduino library to store a symmetrical distance table in less memory.

## Description

The DistanceTable library is a class that stores a symmetrical distance table 
which is typically N x N entries in less memory space. 
It uses (N x (N-1))/2 ("in a triangle") as an eucledian distance table is 
symmetrical around its main diagonal. 
Furthermore as the main diagonal are all zero it does not need to be stored either.

An ATMEL328 (Arduino) can store a 30 x 30 matrix = 900 floats in 1740 bytes, 
where it typically would take 900 x 4 = 3600 bytes. 

Within the 2K RAM of an Arduino one could store normally a 21 x 21 matrix (1764 bytes).

## Interface

- **explicit DistanceTable(uint8_t size)** Constructor, allocates memory
- **~DistanceTable();** Destructor

- **void clear()** sets all entries to 0.0.
- **void set(uint8_t x, uint8_t y, float value )** sets a value
- **float get(uint8_t x, uint8_t y)** gets a value
- **void dump();
- **uint16_t size()** returns memory used, not the dimension.


## Future

- dump(stream = Serial); allow other streams
- getDimension() => returns one side
- getStorage()   => returns allocated memory for the table.
- check size parameter in constructor > 1.
- count(value == 0) count # occurences
- max() maximum
- min() minimum   0 and negative values?

- size() should become obsolete.

Note: table can be used for other symmetrical 2D tables. And therefor include 
negative values.


## Operational

See examples.
