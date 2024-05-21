from settings import *
from paddle import *
import pygame as pg
import math


class Player:
    def __init__(self, game):
        self.game = game
        self.x, self.y = PLAYER_POS
        self.angle = PLAYER_ANGLE  # c
        self.collide = False

    def movement(self):
        sin_a = math.sin(self.angle)
        cos_a = math.cos(self.angle)
        dx, dy = 0, 0
        speed = PLAYER_SPEED * self.game.delta_time
        speed_sin = speed * sin_a
        speed_cos = speed * cos_a

        keys = pg.key.get_pressed()
        if keys[pg.K_w]:
            dx += speed_cos
            dy += speed_sin
        if keys[pg.K_s]:
            dx += -speed_cos
            dy += -speed_sin
        if keys[pg.K_a]:
            dx += speed_sin
            dy += -speed_cos
        if keys[pg.K_d]:
            dx += -speed_sin
            dy += speed_cos

        self.check_wall_collision(dx, dy)
        # self.angle %= math.tau

    def check_wall(self, x, y):
        return (x, y) not in self.game.map.world_map

    def check_wall_collision(self, dx, dy):
        scale = PLAYER_SIZE_SCALE / self.game.delta_time
        if self.check_wall(int(self.x + dx * scale), int(self.y)) or self.x % 1 < 1 - self.game.map.colvar:
            self.x += dx
        else:
            self.collide = True
        if self.check_wall(int(self.x), int(self.y + dy * scale)) or self.y % 1 < 1 - self.game.map.colvar:
            self.y += dy
        else:
            self.collide = True  # caution

        if self.y < -1 or HEIGHT < self.y:
            dx *= -1
            dy *= -1
        if self.x < -1 or WIDTH < self.x:
            self.x, self.y = WIDTH / 2, HEIGHT / 2

    # def check_paddle_collision(self):
        # if self.x > 3 and self.game.paddle.x1 + 2 > self.y > self.game.paddle.y1:
            # self.x *= -1
            # self.y *= -1
# tune nums, fundamentally change so constantly times player by velocity like ball_v

    def draw(self):
        pg.draw.line(self.game.screen, 'yellow', (self.x * 100, self.y * 100),
                     (self.x * 100 + WIDTH * math.cos(self.angle),
                      self.y * 100 + WIDTH * math.sin(self.angle)), 2)
        pg.draw.circle(self.game.screen, 'green', (self.x * 100, self.y * 100), 15)

    def update(self):
        self.movement()

    @property
    def pos(self):
        return self.x, self.y

    @property
    def map_pos(self):
        return int(self.x), int(self.y)
