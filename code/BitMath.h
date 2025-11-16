#ifndef BIT_MATH_H
#define BIT_MATH_H

/* 
   Simple macros to make bit work easy to read.
   - SET_BIT(REG, BIT):   make one bit = 1
   - CLR_BIT(REG, BIT):   make one bit = 0
   - TOG_BIT(REG, BIT):   flip one bit (1->0 or 0->1)
   - READ_BIT(REG, BIT):  get the bit value (0 or 1)
   - SET_MASK(REG, MASK): set all bits that are 1 in MASK
   - CLR_MASK(REG, MASK): clear all bits that are 1 in MASK
   - WRITE_MASK(REG, MASK, VAL): replace the bits chosen by MASK
     with VAL (VAL should already be aligned to those bit positions)
*/

#define SET_BIT(REG, BIT)        ((REG) |=  (1 << (BIT)))
#define CLR_BIT(REG, BIT)        ((REG) &= ~(1 << (BIT)))
#define TOG_BIT(REG, BIT)        ((REG) ^=  (1 << (BIT)))
#define READ_BIT(REG, BIT)       (((REG) >> (BIT)) & 0x01)

#define SET_MASK(REG, MASK)      ((REG) |=  (MASK))
#define CLR_MASK(REG, MASK)      ((REG) &= ~(MASK))

/* Example:
   WRITE_MASK(PORTD, 0xF0, (x << 4))  // write x into the upper 4 bits
*/
#define WRITE_MASK(REG, MASK, VAL) \
  do {                              \
    (REG) = (REG) & ~(MASK);        \
    (REG) = (REG) | ((VAL) & (MASK)); \
  } while (0)

#endif
