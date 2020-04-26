import time

h = int((time.time()/3600)%24)
t = int((time.time()/60)%60)

print("그리니치 표준시\n"+str(h)+"시 "+str(t)+"분")
