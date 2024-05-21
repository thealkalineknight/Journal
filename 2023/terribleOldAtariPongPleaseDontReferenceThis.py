import pygame

#  To Do : block types, hit angle input, user paddle length, gui for speed and length, start menu and move those to settings

pygame.init()

win = pygame.display.set_mode((800, 500))
pygame.display.set_caption('Akitsu Yuugei: Pin Pon')

#  pygame.quit()

#  Basic Items

start = True
game = False
settings = False

padx = 50
pady = 50
width = 20
height = 80
vel = 20

padx2 = 730
pady2 = 50
width2 = 20
height2 = 80
vel2 = 20

ballx = 401
bally = 250
ballw = 20
ballh = 20
ballv = 10
ballv2 = 10
user_v = 1

scoretrack = 0
score1 = 0
score2 = 0
scorefont = pygame.font.SysFont('Roboto', 50)
screenfont = pygame.font.SysFont('Roboto', 100)
setfont = pygame.font.SysFont('Roboto', 25)


# atari stuff

class BlockLogic:

    def __init__(self, blen, bwid, posx, posy):
        self.blen = blen
        self.bwid = bwid
        self.posx = posx
        self.posy = posy

    def hit(self):
        self.blen -= 20
        self.bwid -= 20


blocknormWid = 60
blockhydroWid = 60

class BlockNorm(BlockLogic):
    def __init__(self, posx=None, posy=None):
        super().__init__(blocknormWid, blocknormWid, posx, posy)
        pygame.draw.rect(win, (0, 0, 0), (self.posx, self.posy, self.blen, self.bwid))

    def draw(self, win):
        pygame.draw.rect(win, (150, 150, 150), (self.posx, self.posy, self.blen, self.bwid))

class BlockHydro(BlockLogic):
    def __init__(self, posx=None, posy=None):
        super().__init__(blockhydroWid, blockhydroWid, posx, posy)
        pygame.draw.rect(win, (0, 0, 0), (self.posx, self.posy, self.blen, self.bwid))

    def draw(self, win):
        pygame.draw.rect(win, (150, 250, 150), (self.posx, self.posy, self.blen, self.bwid))


blocknorm1posX = 500
blocknorm1posY = 200
blocknorm1 = BlockNorm(blocknorm1posX, blocknorm1posY)
blocknormWidc1 = 0
blocknorm2posX = 300
blocknorm2posY = 100
blocknorm2 = BlockNorm(blocknorm2posX, blocknorm2posY)
blocknormWidc2 = 0

# main

run = True

while run:
    pygame.time.delay(100)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False

    keys = pygame.key.get_pressed()

    if keys[pygame.K_RETURN]:
        game = True
        start = False
        settings = False

    if keys[pygame.K_o]:
        settings = True
        start = False
        game = False

    if keys[pygame.K_w]:
        pady -= vel
        if pady < 0:
            pady = 0

    if keys[pygame.K_s]:
        pady += vel
        if pady > 420:
            pady = 420

    if keys[pygame.K_UP]:
        pady2 -= vel2
        if pady2 < 0:
            pady2 = 0

    if keys[pygame.K_DOWN]:
        pady2 += vel2
        if pady2 > 420:
            pady2 = 420

    if keys[pygame.K_1]:
        user_v = 1

    if keys[pygame.K_2]:
        user_v = 2

    if keys[pygame.K_3]:
        user_v = 3

    if game:
        ballx += ballv * user_v
        bally += ballv2 * user_v

    if bally > 480:
        bally = 480
        ballv2 *= -1

    if bally < 0:
        bally = 0
        ballv2 *= -1

    if ballx < -1:
        ballx = 401
        bally = 250
        score1 -= 2

    if ballx > 781:
        ballx = 401
        bally = 250
        score2 -= 2

    if ballx > 710 and (pady2 + 80 > bally > pady2):
        ballv *= -1
        ballx = 711
        scoretrack = 2

    if ballx < 70 and (pady + 80 > bally > pady):
        ballv *= -1
        ballx = 69
        scoretrack = 1

    win.fill((0, 0, 0))

    if blocknorm1posX < ballx < (blocknorm1posX + blocknormWid) and blocknorm1posY < bally \
            < (blocknorm1posY + blocknormWid):
        ballv *= -1
        ballv2 *= -1
        blocknorm1.hit()
        blocknormWidc1 += 1
        if blocknormWidc1 > 2:
            blocknorm1posX = -100
            blocknorm1posY = -100
        if scoretrack == 1:
            score1 += 1
        if scoretrack == 2:
            score2 += 1

    if blocknorm2posX < ballx < (blocknorm2posX + blocknormWid) and blocknorm2posY < bally \
            < (blocknorm2posY + blocknormWid):
        ballv *= -1
        ballv2 *= -1
        blocknorm2.hit()
        blocknormWidc2 += 1
        if blocknormWidc2 > 2:
            blocknorm2posX = -100
            blocknorm2posY = -100
        if scoretrack == 1:
            score1 += 1
        if scoretrack == 2:
            score2 += 1

    if start:
        screen1rend = screenfont.render('Pin Pon.', True, (250, 250, 250))
        screen2rend = scorefont.render('Press ENTER', True, (250, 250, 250))
        screen3rend = setfont.render('Press "O" for Options...', True, (250, 250, 250))
        win.blit(screen1rend, (275, 200))
        win.blit(screen2rend, (290, 300))
        win.blit(screen3rend, (0, 0))

    if settings:
        settings1rend = setfont.render('Player one controls: W, S', True, (250, 250, 250))
        settings2rend = setfont.render('Player two controls: Up Arrow & Down Arrow keys', True, (250, 250, 250))
        settings3rend = setfont.render('Press 1,2,3 to switch ball speeds', True, (250, 250, 250))
        win.blit(settings1rend, (20, 0))
        win.blit(settings2rend, (20, 20))
        win.blit(settings3rend, (20, 40))

    if game:
        blocknorm1.draw(win)
        blocknorm2.draw(win)

        pygame.draw.rect(win, (250, 250, 250), (padx, pady, width, height))
        pygame.draw.rect(win, (250, 250, 250), (padx2, pady2, width2, height2))
        pygame.draw.rect(win, (250, 250, 250), (ballx, bally, ballw, ballh))
        score1rend = scorefont.render('Player 1: ' + str(score1), True, (250, 250, 250))
        score2rend = scorefont.render('Player 2: ' + str(score2), True, (250, 250, 250))
        win.blit(score1rend, (25, 0))
        win.blit(score2rend, (600, 0))
    pygame.display.update()
