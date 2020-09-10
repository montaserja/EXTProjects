import sys
from calcnum import intcalc
from calcdec import deccalc
from calcfrac import fraccalc

if __name__ == '__main__':
    _,num1,op,num2,flag=sys.argv

    if(flag=="-f"):
        print(fraccalc(num1, op, num2))
    elif flag=="-d":
        print(deccalc(num1, op, num2))
    elif flag=="-n":
        print(intcalc(num1, op, num2))
    else:
        print("insert a flag(-n,-f,-d)")