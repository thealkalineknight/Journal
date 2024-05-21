from tkinter import *

root = Tk()


def myClick():
    labels = Label(root, text='qiqi')
    labels.pack()


buttons = Button(root, text='play jesihn imapce', command=myClick, fg='blue', bg='purple')
buttons.pack()

root.mainloop()
