from PIL import ImageGrab
import time

time.sleep(1)
img = ImageGrab.grab()
img.save('origin.jpg')

