import sys

def python_analise(path):
    res = ""

    with open(path, 'r') as file:
        for line in file:
            if "$" in line:
                res += remove_non_alpha(line[line.index('$') + 2:]) + '\n'
            elif '[' in line:
                res += remove_colors(line)
                # print(res)
            else:
                res += line
    with open("result.txt", 'w') as res_file:
        res_file.write(res)
    return res


def remove_colors(line):
    res = ""
    line = line.split('')
    for item in line:
        m = item.find('m')
        if m != -1:
            res += item[m + 1:]
        else:
            res += item
    return res


def remove_non_alpha(line):
    res = ""
    find = False
    for c in line:
        if find:
            if c == 'K':
                res = res[:-1]
            find = False
        elif c == '[':
            find = True
        elif c.isalpha() or c.isnumeric() or c in '(=+-/). ':
            res += c
    return res


if __name__ == '__main__':

    _,path = sys.argv


    res = python_analise(path)

    # print(res)
