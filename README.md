# Elliptic Integrals

## Overview
This project provides classes and functions to calculate values of complete elliptic integrals of the first and the second kind,
as well as values for arithmetic geometric mean and its modified analogue. All calculations use gmp library so that you 
can specify the precision to calculate the desired value with any number of digits. There is also a function that calculates digits 
of pi with any given precision.

### Prerequisites
All calculations are made using gmp library (https://gmplib.org/) so you need it to make it work. For example, if you have brew(https://brew.sh/), you can run
```
brew install gmp
```
## Examples
All examples can be found in https://github.com/akniles/elliptic_integrals/tree/master/examples, if you didn't link gmp library, you can run
```
g++ -o test first.cpp -I/usr/local/include -L/usr/local/lib -lgmpxx -lgmp
```

```
./test
```

## Authors
Slinka Aliaksei
