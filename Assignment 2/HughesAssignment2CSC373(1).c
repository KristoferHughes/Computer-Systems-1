
#include	<stdlib.h>
#include	<stdio.h>
#include	<float.h>

const int	SIGN_MASK	= 0x80000000;

const int	EXPONENT_MASK	= 0x7F800000;

const int	MANTISSA_MASK	= 0x007FFFFF;


//  PURPOSE:  To use the masks and 'u' to determine if 'f' is zero.  Returns
//  	'1' if 'f' is '+0.0' or '-0.0', or returns '0' otherwise.
int		isZero		(float		f
				)
{
  unsigned int	u	= *(unsigned int*)&f;

  if  ((u & (EXPONENT_MASK | MANTISSA_MASK) ) == 0x0 )
    return(1);

  return(0);
}


//  PURPOSE:  To use the masks and 'u' to determine if 'f' is zero.  Returns
//  	'1' if 'f' is '+0.0' or '-0.0', or returns '0' otherwise.
int		isPositive	(float		f
				)
{
  unsigned int	u	= *(unsigned int*)&f;

  
	if ((u & (EXPONENT_MASK | MANTISSA_MASK) ) == 0x0 )
	return(1);

  return(0);
}



//  PURPOSE:  To use the masks to determine if &lhs& is less than &rhs&.
//	Assumes both are positive.  Returns &1& if it is or &0& otherwise.
int		isLessThanForPositives
				(float		lhs,
				 float		rhs
				)
{
  unsigned int	lhsAsInt	= *(unsigned int*)&lhs;
  unsigned int	rhsAsInt	= *(unsigned int*)&rhs;

  //  If the exponent of LHS is less than that of RHS, return 1

if(lhsAsInt&(EXPONENT_MASK | MANTISSA_MASK) < rhsAsInt&(EXPONENT_MASK | MANTISSA_MASK) )
return(1);
  //  If the exponent of LHS is greater than that of RHS, return 1
else if(lhsAsInt&(EXPONENT_MASK | MANTISSA_MASK) > rhsAsInt&(EXPONENT_MASK | MANTISSA_MASK) )
return(1);
  //  If you get here the exponents are equal, how would you use the mantissa?
else if(lhsAsInt&(EXPONENT_MASK | MANTISSA_MASK) == rhsAsInt&(EXPONENT_MASK | MANTISSA_MASK) )
return(0);
}



//  PURPOSE:  To use the masks to determine if &lhs& is less than &rhs&.
//	Returns &1& if it is or &0& otherwise.
//	May only use isPositive() and isLessThanForPositives()
int		isLessThan	(float		lhs,
				 float		rhs
				)
{
 unsigned int	lhX	= *(unsigned int*)&lhs;
  unsigned int	rhX	= *(unsigned int*)&rhs;
  //  Suggestion:
  
  //  (1) Handle when either is zero
  
  
if(isZero(lhs)||isZero(rhs))
return(1);

  //  (2) Handle when they have different signs
  
else if ((lhX & SIGN_MASK) != (rhX & SIGN_MASK) )
if(lhX&(EXPONENT_MASK | MANTISSA_MASK) < rhX&(EXPONENT_MASK | MANTISSA_MASK) )
return(1);

  //  (3) Handle when they have the same sign
  
  else if(lhX&(EXPONENT_MASK | MANTISSA_MASK) > rhX&(EXPONENT_MASK | MANTISSA_MASK) )
  return(1);
  


}



//  PURPOSE:  To run the less-than comparison program.  Ignores parameters.
//	Returns &EXIT_SUCCESS& to OS.
int		main		()
{
  float		TEST_ARRAY[]	= { -FLT_MAX,
				    -1e+10
				    -1.0
				    -1e-10,
				    -FLT_MIN,
				    -0.0,
				    +0.0,
				    +FLT_MIN,
				    +1e-10,
				    +1.0,
				    +1e+10,
				    +FLT_MAX
				  };
  const int	TEST_ARRAY_LEN	= sizeof(TEST_ARRAY) / sizeof(float);
  int		i;
  int		j;

  for  (i = 0;  i < TEST_ARRAY_LEN;  i++)
  {
    float	lhs	= TEST_ARRAY[i];

    for  (j = 0;  j < TEST_ARRAY_LEN;  j++)
    {
      float	rhs	= TEST_ARRAY[j];
      int	you	= isLessThan(lhs,rhs);
      int	hardware= (lhs < rhs);
      printf("%+12g < %+12g?\tYou: %5s\tHardware: %5s\t%s\n",
	     lhs,rhs,
	     (you ? "true" : "false"),
	     (hardware ? "true" : "false"),
	     ( (you == hardware) ? "yay!" : "Ruh-roh!" )
	    );
    }

  }

  return(EXIT_SUCCESS);
}
