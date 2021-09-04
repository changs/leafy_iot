leafy_iot:
	arduino-cli compile --fqbn arduino:mbed_nano:nanorp2040connect leafy_iot
	arduino-cli upload -p /dev/cu.usbmodem14101 --fqbn arduino:mbed_nano:nanorp2040connect leafy_iot
