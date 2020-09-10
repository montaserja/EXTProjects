from fractions import Fraction

from my_class import calc

def fraccalc( num1, op, num2):
    return Fraction(str(calc(float(num1),op,float(num2))))
