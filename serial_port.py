# python3 -m pip install pyserial
import serial

with serial.Serial('/dev/cu.usbmodem143201', 9600, timeout=1) as ser:
	while (1):
		line = ser.readline()
		try:
			print(float(line[0:4]), "kmh")
		except:
			pass