class my_enumerate:
    def __init__(self, my_list):
        self.index = 0;
        self.my_list = my_list
        self.my_len = len(my_list)

    def __iter__(self):
        return self

    def __next__(self):
        if self.index >= self.my_len:
            raise StopIteration
        index = self.index
        self.index += 1
        return (index, self.my_list[index])

# if __name__ == '__main__':
#     list=["sad",2,3]
#     for i,item in my_enumerate(list):
#         print(i,item)
