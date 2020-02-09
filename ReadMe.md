# rtlSdrCamera

### Dependencies

#### libusb
##### Install with package manager
	Install with: "sudo apt-get install libusb1.0-0-dev"

#### rtl-sdr

##### Clone github repository and install rtl-sdr library
	Clone github repository: "git clone https://github.com/osmocom/rtl-sdr"
	cd /path/to/rtl-sdr
	mkdir build/
	cd build/
	cmake ../ -DINSTALL_UDEV_RULES=ON -DDETACH_KERNEL_DRIVER=ON
	make
	sudo make install

##### Set rules to use rtl-sdr dongle 
	cd ~/path/to/rtl-sdr
	sudo cp rtl-sdr.rules /etc/udev/rules.d/
	sudo udevadm control --reload-rules
	sudo udevadm trigger

#### Build Project

	cd /path/to/rtlSdrCamera
	mkdir build/
	cd build/
	cmake ../ 
	make
	cd src
	./rtlSdrCamera [device_id] [frequency] [/path/to/testImage]