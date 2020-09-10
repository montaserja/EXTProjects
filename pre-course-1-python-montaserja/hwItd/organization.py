from workers.structure import Group,Worker,Engineer,SalesPerson
from workers.person import Person,PobAddrees,StreetAddress


class Employees:
    def __init__(self):
        self.EmployeesNames={}

    def add_employee(self, email, name):
        self.EmployeesNames[email] = name


class HelloWorld:

    def __init__(self,path):
        self.path=path
        self.structure = {}
        self.build_structure("structure.txt")
        self.employees = Employees()
        self.analyse_workers_data(path)

    def get_structure(self):
        return self.structure

    """def open_file(self,path):
        with"""
    """function that bulds hellow world structure"""
    def build_structure(self,structure_file_path):
        with open(structure_file_path,'r')as file:
            for line in file:
                if "Department" in line:
                    description=line[:-1]
                elif "Group" in line:
                    parent=self.add_group(line[:-1],description,None)
                elif "Team" in line:
                    team=self.add_group(line[:-1], description, parent)
                    self.structure[parent.name].add_to_list(team)



    def add_group(self, group, des, parent):
        str=group.lower()
        self.structure[str]=Group(str, des, parent)
        return self.structure[str]

    def print_structer(self):
        for group in self.structure:
            self.structure[group].print_group()

    """***************************************************************************************************"""
    def analyse_workers_data(self,workers_file_path):
        with open(workers_file_path, 'r')as file:
            for i,line in enumerate(file):
                if line[0]=='#':
                    continue
                else:
                    line = line.replace(" ", "")
                    worker_array=line.split(',')
                    if len(worker_array)==9:
                        try:
                            person=self.create_person(worker_array[1],worker_array[0],worker_array[2],worker_array[3],worker_array[4],worker_array[5])
                            worker=self.create_worker(person,worker_array[7],worker_array[8])
                            self.employees.add_employee(worker.get_person().get_email(),worker.get_person().get_full_name())
                            self.add_worker_to_team(worker_array[6],worker)
                        except:
                            print("line " + str(i) + " not added")


    def create_person(self, firstName, lastName, birthYear, email, phonesNum, adrress):
        person_address=adrress.split(';')
        if len(person_address)==3:
            address_to_add=PobAddrees(person_address[0],person_address[1],person_address[2])
        elif len(person_address)==4:
            address_to_add = StreetAddress(person_address[0], person_address[1], person_address[2],person_address[3])
        person=Person(firstName, lastName, int(birthYear), email, "", address_to_add)

        numbers=phonesNum.split(';')
        for i,num in enumerate(numbers):
            person.add_phone(num)
        return person

    def create_worker(self,person,role,data):
        data_arr = data.split(';')
        if role == "staff":
            worker=Worker(person,int(data[:-1]))
        elif role=="engineer":
            try:
                if len(data_arr)==2:
                    worker=Engineer(person,int(data_arr[0]),int(data_arr[1][:-1]))
                else:
                    worker=Engineer(person,int(data_arr[0]),0)
            except:
                print(role)
                print(data_arr)


        else:
            deals=[]
            for i,item in enumerate(data_arr[2:]):
                if i==len(data_arr)-1:
                    deals.append(int(item[:-1]))
                else:
                    deals.append(int(item))

            worker = SalesPerson(person, int(data_arr[0]), float(data_arr[1]),deals)

        return worker

    def add_worker_to_team(self,team,worker):
        try:
            self.structure[team+" team"].add_to_list(worker)
        except :
            print("add worker to team func error")



#h=HelloWorld("prework-python-data.txt")
#h.print_structer()
# for group in h.structure:
#     if h.structure[group].parent:
#         print(h.structure[group].parent.get_name())