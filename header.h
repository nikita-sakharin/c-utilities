#ifndef HEADER_H
#define HEADER_H

typedef signed char schar;
typedef unsigned char uchar;
typedef short shrt;
typedef unsigned short ushrt;
typedef unsigned uint;
typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;
typedef float flt;
typedef double dbl;
typedef long double ldbl;

#define err_if(cnd_value, label) \
    do { \
        if (cnd_value) { \
            goto label; \
        } \
    } while (0);

#define max(first, second) ((first) > (second) ? (first) : (second))
#define min(first, second) ((first) < (second) ? (first) : (second))

#endif
