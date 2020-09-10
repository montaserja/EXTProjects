import os
import re
files_to_read = {"Mark_Twain__Adventures_of_Huckleberry_Finn.txt","Moses_and_the_Sages__Bible.txt","William_Shakespeare__Hamlet.txt"}
num_of_books = len(files_to_read)
class index_writer:
    def __init__(self,dir_path):
        self.words_dict = {}
        self.dir_path = dir_path

    def check_dir(self,path):
        if not os.path.exists(path):
            os.makedirs(path)

    def write(self,index_path):
        self.check_dir(index_path)
        # index_file = open(index_path+"index.txt","w")
        books_names = []
        for file_name in files_to_read:
            with open(self.dir_path+file_name,"r",encoding="utf8") as file:
                name = file_name.split(".")[0]
                books_names.append(name)
                data = file.read()
                regex = re.compile('[^a-zA-Z0-9\n ]')
                data = regex.sub(' ', data)
                for i,line in enumerate(data.split('\n')):
                    for word in line.split():
                        try:
                            self.words_dict[word][name].append(i)
                        except:
                            try:
                                self.words_dict[word][name] = [i]
                            except:
                                self.words_dict[word] = {name : [i]}
        with open(index_path + "words.txt", "w", encoding="utf8") as words_file:
            with open(index_path + "index.txt", "w", encoding="utf8") as index_file:
                for i,word in enumerate(self.words_dict):
                    words_file.write(f'{word},{num_of_books*i}\n')
                    for book in books_names:
                        index_file.write(f'{book},')
                        try:
                            for line_index in self.words_dict[word][book]:
                                index_file.write(f'{line_index},')
                        except:
                            pass
                        index_file.write('\n')

    #     # index_file.close()
    #     # print(self.words_dict)
    #
    # 
    # def find(self,seq,index_path):
    #     seq_words = seq.split()
    #     lines_to_return = []
    #     for word in seq_words:
    #         try:
    #             with open(index_path+word+".txt","r",encoding="utf8") as file:
    #                 lines = file.readlines()
    #         except:
    #             continue
    #         # lines = self.words_dict[word]
    #         for line in lines:
    #             if seq in line:
    #                 lines_to_return.append(line)
    #         return lines_to_return


if __name__ == '__main__':
    # regex = re.compile('[^a-zA-Z0-9\n ]')
    # s ="_asdf33##  d"
    # s= regex.sub('', s)
    # print(s)
    writer = index_writer("google/")
    writer.write("my_index_dir/")
    # print("now we search")
    # print(writer.find("what is y","my_index_dir/"))
