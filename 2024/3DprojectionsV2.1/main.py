import sys
from settings import *
from cubeOld import *
from cube import *


# TODO:
# I will clean this up next week and add more stuff then move it to C++ (moai emoji)


class Game:
    def __init__(self):
        pg.init()
        pg.mouse.set_visible(False)
        self.screen = pg.display.set_mode(RES)
        self.clock = pg.time.Clock()
        self.dtime = 1
        self.new_game()

    def new_game(self):  # if calls property from other class, list after
        self.cubeOld = CubeOld(self)
        self.cube = Cube(self)

    def run(self):
        while True:
            self.update()
            self.draw()
            self.check_events()

    def update(self):
        # self.cubeOld.update()
        self.dtime = self.clock.tick(FPS)
        pg.display.set_caption(f'{self.clock.get_fps():.1f}')

    def draw(self):
        pg.display.flip()
        self.screen.fill('black')
        # self.cubeOld.draw()
        self.cube.draw2()

    def check_events(self):
        for event in pg.event.get():
            if event.type == pg.QUIT or (event.type == pg.KEYDOWN and event.key == pg.K_ESCAPE):
                pg.quit()
                sys.exit()


if __name__ == '__main__':
    game = Game()
    game.run()
