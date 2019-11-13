from copy import copy

class machine:
    def __init__(self):
        self.a = ['a','b','c','d','e','f','g']
        self.b = copy(self.a)

    def reset(self):
        self.b = copy(self.a)
    
    def cal(self, a):
        a = a-1

        if a<0 or a>len(self.b):
            print("Error")
            return None

        elif a == 2:
            temp1 = 0
            temp2 = 0

            for i in range(7):

                if self.b[i] == 'c':
                    temp1 = i
                elif self.b[i] == 'f':
                    temp2 = i

            if not temp1 == 0:
                temp = self.b[temp1]
                self.b[temp1] = self.b[temp2]
                self.b[temp2] = temp

            temp1 = 0
            temp2 = 0

            for i in range(7):

                if self.b[i] == 'g':
                    temp1 = i
                elif self.b[i] == 'c':
                    temp2 = i

            if not temp1 == 0:
                temp = self.b[temp1]
                self.b[temp1] = self.b[temp2]
                self.b[temp2] = temp

            temp1 = 0
            temp2 = 0

            for i in range(7):
                if self.b[i] == 'd' or self.b[i] == 'x':
                    temp1 = i
                elif self.b[i] == 'e':
                    temp2 = i
                
            if not temp1 == 0:
                temp = self.b[temp1]
                self.b[temp1] = self.b[temp2]
                self.b[temp2] = temp
            

            print(self.b)

        elif a == 3:
            for i in range(7):
                if self.b[i] == 'd':
                    self.b[i] = 'x'

            print(self.b)

        elif a == 6:
            self.reset()
            print(self.b)

        else:
            print(self.b[a])
        return self.b[a]

if __name__ == "__main__":
    result = machine()
    result.cal(int(3))
    result.cal(int(7))
    result.cal(int(4))
    result.cal(int(3))
    result.cal(int(4))
    result.cal(int(5))
