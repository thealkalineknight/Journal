from settings import *

class Cube:
    def __init__(self, game):
        self.game = game
        self.prev_time = 0
        self.Tf = 1
        self.Sx = 1
        self.Sy = 1
        self.Sz = 1
        self.Sf = 1
        self.th = 0  # -0.3
        self.mS = [[self.Sx, 0, 0],
                   [0, self.Sy, 0],
                   [0, 0, self.Sz]]
        self.mRx = [[1, 0, 0],
                    [0, math.cos(self.th), math.sin(self.th)],
                    [0, -math.sin(self.th), math.cos(self.th)]]
        self.mRy = [[math.cos(self.th), 0, -math.sin(self.th)],
                    [0, 1, 0],
                    [math.sin(self.th), 0, math.cos(self.th)]]
        self.mRz = [[math.cos(self.th), math.sin(self.th), 0],
                    [-math.sin(self.th), math.cos(self.th), 0],
                    [0, 0, 1]]
        self.matrixA = [[-1, 1, -3],
                        [1, 1, -3],
                        [1, -1, -3],
                        [-1, -1, -3],  # --
                        [-1, -1, -5],
                        [1, -1, -5],
                        [1, 1, -5],
                        [-1, 1, -5]]
        self.matrixAt = [[0, 0, 0],
                         [0, 0, 0],
                         [0, 0, 0],
                         [0, 0, 0],
                         [0, 0, 0],
                         [0, 0, 0],
                         [0, 0, 0],
                         [0, 0, 0]]
        self.matrixB = [[-1, -1, 1],
                        [1, -1, 1],
                        [1, 1, 1],
                        [-1, 1, 1],
                        [-1, -1, -1],
                        [1, -1, -1],
                        [1, 1, -1],
                        [-1, 1, -1]]
        self.pjM = [[1, 0, 0],
                    [0, 1, 0],
                    [0, 0, 0]]

    def update(self):
        v = 0

    def timed_event(self):
        curr_time = pg.time.get_ticks()
        if curr_time - self.prev_time >= 200:
            self.prev_time = curr_time
            return True

    def draw2(self):
        self.th += 0.01
        mRx = [[1, 0, 0],
               [0, math.cos(self.th), math.sin(self.th)],
               [0, -math.sin(self.th), math.cos(self.th)]]
        mRy = [[math.cos(self.th), 0, -math.sin(self.th)],
               [0, 1, 0],
               [math.sin(self.th), 0, math.cos(self.th)]]
        mRz = [[math.cos(self.th), math.sin(self.th), 0],
               [-math.sin(self.th), math.cos(self.th), 0],
               [0, 0, 1]]

        for p in self.matrixB:
            RxPx = p[0] * mRx[0][0] + p[1] * mRx[1][0] + p[2] * mRx[2][0]
            RxPy = p[0] * mRx[0][1] + p[1] * mRx[1][1] + p[2] * mRx[2][1]
            RxPz = p[0] * mRx[0][2] + p[1] * mRx[1][2] + p[2] * mRx[2][2]

            RyPx = RxPx * mRy[0][0] + RxPy * mRy[1][0] + RxPz * mRy[2][0]
            RyPy = RxPx * mRy[0][1] + RxPy * mRy[1][1] + RxPz * mRy[2][1]
            RyPz = RxPx * mRy[0][2] + RxPy * mRy[1][2] + RxPz * mRy[2][2]

            RzPx = RyPx * mRz[0][0] + RyPy * mRz[1][0] + RyPz * mRz[2][0]
            RzPy = RyPx * mRz[0][1] + RyPy * mRz[1][1] + RyPz * mRz[2][1]

            x = RzPx * self.pjM[0][0] + RzPy * self.pjM[1][0]
            y = RzPx * self.pjM[0][1] + RzPy * self.pjM[1][1]
            x = int(x * 100 + HWIDTH)
            y = int(y * 100 + HHEIGHT)
            pg.draw.circle(self.game.screen, 'red', (x, y), 5)
