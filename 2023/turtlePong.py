import turtle

wn = turtle.Screen()
wn.title('Stupid Pong')
wn.bgcolor('black')
wn.setup(width=800, height=600)
wn.tracer(0)  # Make so manually update so speed up game

paddle_a = turtle.Turtle()
paddle_a.speed(0)
paddle_a.shape('square')
paddle_a.color('white')
paddle_a.shapesize(stretch_wid=5, stretch_len=1)
paddle_a.penup()
paddle_a.goto(-350, 0)  # 350 and -350 max range, 0 mid

paddle_b = turtle.Turtle()
paddle_b.speed(0)
paddle_b.shape('square')
paddle_b.color('white')
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup()
paddle_b.goto(350, 0)

ball = turtle.Turtle()
ball.speed(0)
ball.shape('square')
ball.color('white')
ball.penup()
ball.goto(0, 0)
ball.dx = 0.45  # d is delta
ball.dy = -0.45

pen = turtle.Turtle()
pen.speed(0)
pen.color('white')
pen.penup()
pen.hideturtle()
pen.goto(0, 260)
pen.write('Player A: 0     Player B: 0', align='center', font=('Courier', 25, 'bold'))

score_a = 0
score_b = 0


def paddle_a_up():
    y = paddle_a.ycor()  # from turtle, returns y coordinate
    y += 30
    paddle_a.sety(y)


def paddle_a_down():
    y = paddle_a.ycor()
    y -= 30
    paddle_a.sety(y)


def paddle_b_up():
    y = paddle_b.ycor()  # from turtle, returns y coordinate
    y += 30
    paddle_b.sety(y)


def paddle_b_down():
    y = paddle_b.ycor()
    y -= 30
    paddle_b.sety(y)


wn.listen()  # listens for keyboard input
wn.onkeypress(paddle_a_up, 'w')
wn.onkeypress(paddle_a_down, 's')
wn.onkeypress(paddle_b_up, 'Up')
wn.onkeypress(paddle_b_down, 'Down')

while True:
    wn.update()
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    if ball.ycor() > 290:
        ball.sety(290)
        ball.dy *= -1  # reverses direction

    if ball.ycor() < -290:
        ball.sety(-290)
        ball.dy *= -1

    if ball.xcor() > 390:
        ball.goto(0, 0)
        ball.dx *= -1

    if ball.xcor() < -390:
        ball.goto(0, 0)
        ball.dx *= -1

    if ball.xcor() > 340 and (ball.ycor() < paddle_b.ycor() + 50 and ball.ycor() > paddle_b.ycor() - 50):
        ball.setx(340)
        ball.dx *= -1

    if ball.xcor() < -340 and (ball.ycor() < paddle_a.ycor() + 50 and ball.ycor() > paddle_a.ycor() - 50):
        ball.setx(-340)
        ball.dx *= -1
