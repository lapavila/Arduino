import serial
porta = '/dev/tty.usbmodemfa131'
baud_rate = 9600
arduino = serial.Serial(porta, baud_rate)
arduino.write('p')
arduino.close()