import sys
import re

def parse_h(file_path):
    str_to_write=""
    classname=""
    with open(file_path,'r') as h_file:
        for line in h_file:
            if "class" in line:
                classname=get_class_name(line)
            elif ")" in line:
                str_to_write+=func_parse(line,classname)
    return str_to_write

def get_class_name(line):
    lis=line.split()
    found=False
    for item in lis:
        if item=="class":
            found=True;
        elif found:
            return item


def find_func_name(lis):
    for i,item in enumerate(lis):
        if "(" in item:
            if item[0]=="(":
                return lis[i-1]
            else:
                return item[:item.find("(")]

def func_parse(line,class_name):
    lis=line.split()
    func_name=find_func_name(lis)
    line=line.replace(func_name,class_name + "::" + func_name)
    line=line.replace(";","{}")
    return line




def create_cpp(cpp,filename):
    with open(filename[:-1]+"cpp",'w') as file:
        file.write(cpp)


if __name__ == '__main__':
    _, file_path = sys.argv
    cpp=parse_h(file_path)
    cpp=cpp.replace("friend ","")
    cpp="#include\"" + file_path + "\"\n" +cpp
    create_cpp(cpp,file_path)
