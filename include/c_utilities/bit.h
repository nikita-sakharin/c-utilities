#ifndef C_UTILITIES_BIT_H
#define C_UTILITIES_BIT_H

#define HAS_SINGLE_BIT(x) ((x) != 0 && ((x) & ((x) - 1)) == 0)

#endif // C_UTILITIES_BIT_H
