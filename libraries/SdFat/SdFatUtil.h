#ifndef SdFatUtil_h
#define SdFatUtil_h
/**
 * \file
 * Useful utility functions.
 */
#include "WProgram.h"
#include "Sd2Card.h"
#include <string.h>
#ifndef PSTR
#define PSTR(x) (x)
#endif
#ifndef PROGMEM
#define PROGMEM         // N/A
#endif
#ifndef PGM_P
#define PGM_P const char*
#endif
#ifndef prog_uchar
typedef const unsigned char  prog_uchar;
#endif
#ifndef prog_short
typedef const unsigned short prog_short;
#endif
#ifndef pgm_read_byte_near
#define pgm_read_byte_near(x) (*(prog_uchar*)x)
#endif
#ifndef pgm_read_byte
#define pgm_read_byte(x)      (*(prog_uchar*)x)
#endif
#ifndef pgm_read_word
#define pgm_read_word(x)      (*(prog_short*)x)
#endif
#ifndef strcpy_P
#define strcpy_P strcpy
#endif
#ifndef strncpy_P
#define strncpy_P strncpy
#endif

/** Store and print a string in flash memory.*/
#ifndef PgmPrint
#define PgmPrint(x) Serial.print(PSTR(x))
#endif
/** Store and print a string in flash memory followed by a CR/LF.*/
#ifndef PgmPrintln
#define PgmPrintln(x) Serial.println(PSTR(x))
#endif
/** Defined so doxygen works for function definitions. */
#define NOINLINE __attribute__((noinline))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/**
 * %Print a string in flash memory to the serial port.
 *
 * \param[in] str Pointer to string stored in flash memory.
*/ 
#ifndef SerialPrint_P
#define SerialPrint_P(str) { \
	const char *p=str; \
  for (uint8_t c; (c = pgm_read_byte(p)); p++) Serial.print((char)c); \
}
#endif
//------------------------------------------------------------------------------
/**
 * %Print a string in flash memory followed by a CR/LF.
 *
 * \param[in] str Pointer to string stored in flash memory.
*/ 
#ifndef SerialPrintln_P
#define SerialPrintln_P(str) { \
  SerialPrint_P(str); \
  Serial.println();   \
}
#endif

#endif  // #define SdFatUtil_h
