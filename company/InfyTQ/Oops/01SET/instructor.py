import random

technology = ["javascript", "MERN", "MEAN", "cloud", "devops"]


class Instructor:
    def __init__(self):
        self.__instructor_name = None
        self.__technology_skill = []
        self.__experience = None
        self.__avg_feedback = None

    def set_name(self, name):
        self.__instructor_name = name

    def get_name(self):
        return self.__instructor_name

    def set_skill(self, skill):
        self.__technology_skill = skill

    def get_skill(self):
        return self.__technology_skill

    def set_experience(self, experience):
        self.__experience = experience

    def get_experience(self):
        return self.__experience

    def set_feedback(self, feedback):
        self.__avg_feedback = feedback

    def get_feedback(self):
        return self.__avg_feedback

    def calculate_avg_feedback(self):
        if(self.__experience > 3):
            self.__avg_feedback = random.choice([4.5, 4.6, 4.7, 4.8, 4.9, 5])
        elif(self.__experience <= 3):
            self.__avg_feedback = random.choice(
                [4, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9, 5])
        else:
            pass

        return self.__avg_feedback

    def check_eligibility(self):
        if(self.__experience >= 3):
            count = 0
            for each in self.__technology_skill:
                if each in technology:
                    count += 1
            if count > 0:
                return True
        return False

    def allocate_course(self):
        if(self.check_eligibility()):
            return True
        return False

    def allocate_course(self, tech):
        if(tech in technology) and (self.check_eligibility()):
            return True
        return False


I1 = Instructor()

I1.set_skill(["firebase", "MERN", "cloud"])
print(I1.get_skill())

I1.set_experience(3)
print("Rate: ", I1.calculate_avg_feedback())

print(I1.check_eligibility())
