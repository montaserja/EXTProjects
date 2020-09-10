import operator


def my_reduce(func, seq):
    first = seq[0]
    for i in seq[1:]:
        first = func(first, i)
    return first


def my_accumulate(iterable, func=operator.add):
    it = iter(iterable)
    try:
        total = next(it)
    except StopIteration:
        return
    yield total
    for element in it:
        total = func(total, element)
        yield total


if __name__ == '__main__':
    lis = [1, 3, 5, 6, 2]
    print("The sum of the list elements is : ", end="")
    print(my_reduce(lambda a, b: a + b, lis))

    print(list(my_accumulate(lis, operator.mul)))
