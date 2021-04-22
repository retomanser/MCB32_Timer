//-------------------------------------------------------------------------------------------------
// FILE NAME    TypeDef.h
// LANGUAGE     C
//
// DESCRIPTION  Definition for unmistakable types
//
//-------------------------------------------------------------------------------------------------

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#define False   0
#define True    (!False)

#define Null    ((void*)0)

typedef signed char     Int8;       // signed integer 8 bit
typedef signed short    Int16;      // signed integer 16 bit
typedef signed long     Int32;      // signed long/integer 32 bit
typedef unsigned char   UInt8;      // unsigned integer 8 bit
typedef unsigned short  UInt16;     // unsigned integer 16 bit
typedef unsigned int    UInt32;     // unsigned long/integer 32 bit
typedef unsigned char   Bool;       // boolean, True or False
typedef char            Char;       // unsigned char/integer 8 bit

#endif  // _TYPEDEF_H_

//-------------------------------------------------------------------------------------------------
// EOF TypeDef.h
//-------------------------------------------------------------------------------------------------
