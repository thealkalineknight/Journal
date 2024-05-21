import pygame as pg

_ = False

mini_map = [
    [_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, 1, 1, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, 1, _, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, _, _, 2, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _],
    [_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _],
]


class Map:
    def __init__(self, game):
        self.game = game
        self.mini_map = mini_map
        self.unbroken_map = {}
        self.broken_map = {}
        self.world_map = {}
        self.get_map()
        self.colvar = 1

    def get_map(self):
        for j, row in enumerate(self.mini_map):
            for i, value in enumerate(row):
                if value == 1:
                    self.unbroken_map[(i, j)] = value
                    self.world_map[(i, j)] = value
                if value == 2:
                    self.broken_map[(i, j)] = value
                    self.world_map[(i, j)] = value

    def draw(self):
        for pos in self.unbroken_map:
            if self.game.player.collide:
                self.colvar *= 0.5
            pg.draw.rect(self.game.screen, 'white', (pos[0] * 100, pos[1] * 100, 100 * self.colvar, 100 * self.colvar))

        [pg.draw.rect(self.game.screen, 'white', (pos[0] * 100, pos[1] * 100, 100, 100), 2)
         for pos in self.broken_map]

