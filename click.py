from ctypes import *
user32 = windll.user32
import time
import sys
from PIL import ImageGrab
from PIL import Image
 
if __name__ == "__main__":
    x = int(input())
    y = int(input())
    if x == -1:
        sys.exit()
    y = ((380/8)-1)*y+(380/8-1)/2
    x = ((380/8)-2)*x+(380/8-1)/2
    y += 117
    x += 132
    user32.SetCursorPos(x,y)
    user32.mouse_event(0x2,0,0,0,0)
    time.sleep(0.2)
    user32.mouse_event(0x4,0,0,0,0)
