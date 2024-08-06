# raspbianmonitor
command line monitoring for primitive OS-level checks eg. network, temperature of CPU, etc 

**connection**
```
ssh -p [dynamic port no on ngrok instance running on rpi] 0.tcp.ap.ngrok.io
```

**run code**
libusb
```
g++ oma.c `pkg-config --libs --cflags libusb-1.0`
./a.out
```
**note:** `sudo ./a.out` if `LIBUSB_ERROR_ACCESS`

blueZ
```
gcc -o oma_bluetooth oma_bluetooth.c $(pkg-config --cflags --libs dbus-1)
```

**debug**
```
gdb ./a.out
run
```

**dependencies**
g++ (C compiler, preinstalled on Raspbian OS)
```
sudo apt-get install libusb (C library for writing drivers for USB devices)
sudo apt-get install bluez
sudo apt-get install libdbus-1-dev
```

**useful terminal commands**
see VID, PID and Keyboard Manufacturer Name
```
lsusb
```
bluetooth pairing
```
bluetoothctl
power on
discoverable on
scan on
exit
```