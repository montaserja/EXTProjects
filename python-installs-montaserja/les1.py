from sys import argv
import random

ops = {"+": (lambda x, y: x + y), "-": (lambda x, y: x - y), "*": (lambda x, y: x * y), "/": (lambda x, y: x / y)}

gameList = ["rock", "paper", "scissors"]


def game():
    while (True):
        choise = input("Enter your name : ")
        com_choise = random.randrange(3)
        print("computer choise " + gameList[com_choise])
        if choise.lower() == gameList[com_choise + 1]:
            print("you win")
            break
        elif choise.lower() == gameList[com_choise]:
            print("no body win")
        else:
            print("you loose")
            break


def greeting(name, age):
    if int(age) < 20:
        print("HI BRO ")
    elif int(age) < 40:
        print("HI " + name)
    elif int(age) < 60:
        print("HELLO " + name)
    else:
        print("“Hello " + name + " ,call your grandson for help")


def print_info(list):
    print(list)
    splited_path = list[0].split('/')
    print("amount of args is : " + str(len(list)))
    print("script name is : " + splited_path[-1])
    count = 0
    for num in list:
        print(type(num))
        try:
            int(num)
            count += 1
        except:
            continue
    print("args can be converted to numbers is : " + str(count))

    for item in list:
        print(item)


def calc(num1, operator, num2):
    try:
        print(ops[operator](num1, num2))
    except:
        print("calc error")


def challenge1(text):
    table = str.maketrans(
        "abcdefghijklmnopqrstuvwxyz", "cdefghijklmnopqrstuvwxyzab"
    )

    print(text.translate(table))


greeting(argv[1], argv[2])
print_info(argv)
calc(2, 's', 2)

text = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle grgl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."

challenge1(text)
game()
