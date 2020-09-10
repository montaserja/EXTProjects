def calc(num1, op, num2):
    ops = {"+": (lambda x, y: x + y), "-": (lambda x, y: x - y), "*": (lambda x, y: x * y),
           "/": (lambda x, y: x / y)}
    return ops[op](num1,num2)