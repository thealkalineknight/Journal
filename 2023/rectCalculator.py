class Shape: 
    def __init__(self, w, h):
        self.width = w
        self.height = h

class Rectangle(Shape):
    def perimeter(self):
        print(self.width*2+self.height*2)
    def area(self):
        print(self.width*self.height)

w = int(input())
h = int(input())

r = Rectangle(w, h)
r.area()
r.perimeter()
