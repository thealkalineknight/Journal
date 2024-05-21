from settings import *
import pygame as pg


class Paddle:
    def __init__(self, game):
        self.game = game
        self.x1, self.y1 = 2.2, 4
        self.x2, self.y2 = 13.5, 4
        self.speed = 0.004  # not final
        self.width = 30
        self.height = 130

    def movement(self):
        dy1 = 0
        dy2 = 0

        speed = self.speed * self.game.delta_time
        keys = pg.key.get_pressed()

        if keys[pg.K_w] and 1 < self.y1:
            dy1 -= speed
        if keys[pg.K_s] and self.y1 < 6.7:
            dy1 += speed
        self.y1 += dy1

        if keys[pg.K_UP] and 1 < self.y2:
            dy2 -= speed
        if keys[pg.K_DOWN] and self.y2 < 6.7:
            dy2 += speed
        self.y2 += dy2

    def draw(self):
        pg.draw.rect(self.game.screen, 'blue',
                     (self.x1 * 100, self.y1 * 100, self.width, self.height))

        pg.draw.rect(self.game.screen, 'red',
                     (self.x2 * 100, self.y2 * 100, self.width, self.height))

    def update(self):
        self.movement()

    @property
    def pos1(self):
        return self.x1, self.y1

    @property
    def pos2(self):
        return self.x2, self.y2
