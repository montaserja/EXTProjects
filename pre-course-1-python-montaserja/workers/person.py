import re




class Person:
    ID = 1
    def __init__(self, firstName, lastName, birthYear, email, phonesNum, adrress):
        if not firstName or not lastName:
            raise ValueError("The first or last name is empty!!")
        elif not isinstance(firstName, str) or not isinstance(lastName, str):
            raise ValueError("The first or last name is not string!!")
        else:
            self.firstName = firstName
            self.lastName = lastName
        if self.check_the_email(email):
            self.email = email
        else:
            raise ValueError("The email is not valid!!")

        if isinstance(birthYear, int):
            self.birthYear = birthYear
        else:
            print("birth year is not int")
        self.phones = []
        self.add_phone(phonesNum)

        self.address = adrress
        self.id = Person.ID
        self.inc_id()

    @classmethod
    def inc_id(cls):
        cls.ID += 1

    @staticmethod
    def check_the_email(email):
        match = re.match('^[a-z0-9-]+(\.[a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.hwltd.com)$', email)
        return not match == None

    def get_email(self):
        return self.email

    def get_phones(self):
        return self.phones

    def get_first_name(self):
        return self.firstName

    def get_last_name(self):
        return self.lastName

    def get_full_name(self):
        return self.firstName+self.lastName

    def get_id(self):
        return self.id

    def add_phone(self, phone_num):
        phoneNum = Phone(phone_num)
        if phoneNum.get_isValid():
            self.phones.append(phoneNum)
        else:
            del phoneNum

    def remove_phone_num(self, phone_num):
        for phone in self.phones:
            if phone.get_phone_num() == phone_num:
                self.phones.remove(phone)
                print("phone " + phone_num + " was removed successfully")
                return
        print("phone " + phone_num + " was not found")

    def print_phones(self):
        for phone in self.phones:
            print(phone.get_phone_num())


"""-----------------------------------------------------------------------------------------------------------------"""


class Phone:
    def __init__(self, phoneNum):
        try:
            match = re.match('^[+0-9][0-9-]*$', phoneNum)
            if match == None:
                self.isValid = False
                #print("invalid phone num")
                del match
                return
            else:
                self.isValid = True
                self.phoneNum = phoneNum
            del match
        except:
            raise ValueError("phone num is not string!!")

    def get_phone_num(self):
        return self.phoneNum

    def get_isValid(self):
        return self.isValid


"""------------------------------------------------------------------------------------------"""


class Address:

    def __init__(self, country, city):
        if not country or not city:
            print("country or the city is empty")
        else:
            self.country = country
            self.city = city

    def get_adress(self):
        try:
            return "Address: " + self.country + ", " + self.city + ", " + self._other_detailed()
        except NotImplementedError:
            return "Address: " + self.country + ", " + self.city

    def _other_detailed(self):
        raise NotImplementedError


"""------------------------------------------------------------------------------------------"""


class StreetAddress(Address):
    def __init__(self, country, city, street_name, house_num):
        super().__init__(country, city)
        self.streetName = street_name
        self.houseNum = house_num

    def _other_detailed(self):
        return self.streetName + ", " + self.houseNum


"""------------------------------------------------------------------------------------------"""


class PobAddrees(Address):

    def __init__(self, country, city, post_office_box):
        super().__init__(country, city)
        self.postOfficeBox = post_office_box

    def _other_detailed(self):
        return self.postOfficeBox


"""
person = Person("montaser","jafrah",1995,"jake@s.hwltd.com","0509382929","israel,jerusalem")
print(person.get_email())   
print(person.get_first_name())
person.add_phone("+6656556")
person.print_phones()
person.add_phone("+6656556")
person.print_phones()
person.remove_phone_num("+6656555556")
person.print_phones()
address =PobAddrees("Israel","Jerusalem","sdd")
print(address.get_adress())
"""
