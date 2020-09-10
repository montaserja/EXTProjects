

class Group:
    def __init__(self, name, description, parent):
        self.name = name
        self.description = description
        self.parent = parent
        self.subGroups = []
        self.workers = []
        self.arrayType = ""
        self.workersNum = 0


    def get_description(self):
        return self.description

    def get_name(self):
        return self.name

    def get_workers(self):
        if not self.subGroups:
            return self.workers
        else:
            #print(self.subGroups)
            return [sub_group.get_workers() for sub_group in self.subGroups ]

    def get_parents(self):
        list=[]
        if not self.parent:
            return list
        else:
            list.append(self.parent)
            parent_list=self.parent.get_parents()
            if parent_list:
                list.append(parent_list)
        return list

    def get_workers_num(self):
        return self.workersNum

    def add_to_list(self,item):
        if self.arrayType == "":
            if isinstance(item, Group):
                self.arrayType = "groups"
            elif isinstance(item, Worker):
                self.arrayType = "workers"
        if self.arrayType == "groups" and isinstance(item, Group):
            self.subGroups.append(item)
        elif self.arrayType == "workers" and isinstance(item, Worker):
            self.workers.append(item)
            self.workersNum+=1
            if self.parent:
                self.parent.workersNum+=1


    def print_group(self):
        print("Group name: " + self.name)
        print("Description: " + self.description)
        for i,p in enumerate(self.get_parents()):
            print("parent "+str(i+1))
            p.print_group()
        print("workers: ")
        for workerslists in self.get_workers():
            if workerslists:
                if isinstance(workerslists, Worker):
                    print(workerslists.get_person().get_full_name())
            else:
                for worker in workerslists:
                    print(worker.get_person().get_full_name())



        print()
        #print(self.get_workers())

        # print(self.get_parents())



"""----------------------------------------------------------------------------------------------------------"""


class Worker:

    def __init__(self, person, salary):
        self.person = person
        self.salary = salary

    def get_salary(self):
        return self.salary

    def get_person(self):
        return self.person


"""----------------------------------------------------------------------------------------------------------"""


class Engineer(Worker):

    def __init__(self, person, salary, bonus):
        super(Engineer, self).__init__(person, salary)
        self.bonus = bonus

    def get_salary(self):
        return self.salary + self.bonus


"""----------------------------------------------------------------------------------------------------------"""


class SalesPerson(Worker):

    def __init__(self, person, salary, commission, deals):
        super(SalesPerson, self).__init__(person, salary)
        self.commission = commission
        self.deals = deals

    def get_salary(self):
        return self.salary + (self.commission * sum(self.deals))
