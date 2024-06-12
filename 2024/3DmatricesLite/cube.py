from settings import *


class Cube:
    def __init__(self, game):
        self.game = game
        self.RADIUS = 5
        self.Tf = 1
        self.Sx = 1.5
        self.Sy = 1
        self.Sz = 1
        self.Sf = 1.3
        self.th = 0.43
        self.mS = [[self.Sx, 0, 0],
                   [0, self.Sy, 0],
                   [0, 0, self.Sz]]
        self.mRx = [[1, 0, 0],
                    [0, math.cos(self.th), math.sin(self.th)],
                    [0, -math.sin(self.th), math.cos(self.th)]]
        self.matrixA = [[-1, 1, -3],
                        [1, 1, -3],
                        [1, -1, -3],
                        [-1, -1, -3],  # --
                        [-1, -1, -5],
                        [1, -1, -5],
                        [1, 1, -5],
                        [-1, 1, -5]]

    def update(self):
        v = 0

    def draw(self):
        for i in range(len(self.matrixA)):
            x = self.matrixA[i][0] / -self.matrixA[i][2]
            y = self.matrixA[i][1] / -self.matrixA[i][2]
            x = self.remap(x, 0)
            y = self.remap(y, 1)

            pg.draw.circle(self.game.screen, 'green',
                           (x, y), 5)

    def remap(self, point, p):
        point = (1 + point) / 2
        if p == 0:
            point *= WIDTH
        if p == 1:
            point *= HEIGHT
        return point

    def transform(self):
        for i in range(len(self.matrixA)):
            x = self.matrixA[i][0]
            y = self.matrixA[i][1]
            z = self.matrixA[i][2]
            ms = self.mS

            self.matrixA[i][0] = x * ms[0][0] + y * ms[1][0] + z * ms[2][0]
            self.matrixA[i][1] = x * ms[0][1] + y * ms[1][1] + z * ms[2][1]
            self.matrixA[i][2] = x * ms[0][2] + y * ms[1][2] + z * ms[2][2]

