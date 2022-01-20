#! /bin/bash
# sudo chmod a+rw /dev/ttyACM0
sudo chmod a+rw /dev/ttyUSB0

port="/dev/ttyUSB0"
build_folder_name="cmake-build-debug"

current_path=$(pwd)
cd $build_folder_name

cmake $current_path
make

cd $current_path

avr-objcopy -O ihex -R .eeprom $build_folder_name/SnakeAVR $build_folder_name/SnakeAVR.hex
# avrdude -F -V -c arduino -p ATMEGA328P -P $port -b 115200 -U flash:w:SnakeAVR.hex
avrdude -v -p atmega2560 -c wiring -P $port -b 115200 -D -U flash:w:$build_folder_name/SnakeAVR.hex:i
