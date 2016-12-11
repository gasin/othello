import cv2
import numpy as np
import math
import copy
import time
from PIL import ImageGrab

#1280*600

im = cv2.imread("origin.jpg")
sma_im = im[117:497, 132:512]
cv2.imwrite("sma.jpg",sma_im)

height = 380
width = 380

red = -1

cel_im = copy.deepcopy(sma_im)
celly = width/8-1
cellx = width/8-2

board = [[0 for i in range(8)] for j in range(8)] #0..empty, 1..black, 2..white
for i in range(8):
    for j in range(8):
        b = 0
        w = 0
        r = 0
        for k in range(i*cellx+10,(i+1)*cellx-10):
            for l in range(j*celly+10,(j+1)*celly-10):
                if sma_im[l,k,0] < 100 and sma_im[l,k,1] < 100 and sma_im[l,k,2] < 100:
                    b += 1
                if sma_im[l,k,0] > 150 and sma_im[l,k,1] > 150 and sma_im[l,k,2] > 150:
                    w += 1
                if sma_im[l,k,0] < 100 and sma_im[l,k,1] < 100 and sma_im[l,k,2] > 200:
                    r += 1
        if b < 50 and w < 50:
            board[i][j] = 0
            cv2.rectangle(cel_im, (i*cellx+10, j*celly+10), ((i+1)*cellx-10, (j+1)*celly-10), (255, 0, 0), -1)
        elif b > w:
            board[i][j] = 1
            cv2.rectangle(cel_im, (i*cellx+10, j*celly+10), ((i+1)*cellx-10, (j+1)*celly-10), (  0, 0, 0), -1)
        else:
            board[i][j] = 2
            cv2.rectangle(cel_im, (i*cellx+10, j*celly+10), ((i+1)*cellx-10, (j+1)*celly-10), (255,255,255), -1)
        if r > 10:
            red = board[i][j]
            cv2.rectangle(cel_im, (i*cellx+15, j*celly+15), ((i+1)*cellx-15, (j+1)*celly-15), (  0,  0,255), -1)
cv2.imwrite("cel.jpg",cel_im)
turn = int(input())
print turn
print red
print board

