from hwItd.organization import HelloWorld

class reports:
    def __init__(self):
        self.hello_world = HelloWorld("prework-python-data.txt")
        self.dcit={}

    def get_num_employees(self,department, depth):
        structure=self.hello_world.get_structure()
        if 0<depth<4:
            string_to_print = self.team_workers(structure, department,depth)
        else:
            raise ValueError("department not valid")

        print(string_to_print)

    def team_workers(self,structure,department,depth):
        department_workers=0
        result=""
        for i,group in enumerate(structure):
            if department.lower() in structure[group].get_description().lower():
                if "group" in group:
                    result+="\t"
                    department_workers+=structure[group].get_workers_num()
                    result += structure[group].get_name().upper() + " - " + str(structure[group].get_workers_num()) + " workers\n"
                elif "team" in group and depth==3:
                    result += "\t\t"
                    result += structure[group].get_name().upper() + " - " + str(structure[group].get_workers_num()) + " workers\n"
        if depth==1:
            result = department.upper() + " - " + str(department_workers)
        else:
            result=department.upper()+" - "+str(department_workers) +"\n"+ result

        return result

# reports=reports()
# reports.get_num_employees("engineering",1)