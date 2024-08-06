from pydbus import SystemBus
from gi.repository import GLib
import sys

def pair_device(device_address):
    bus = SystemBus()
    adapter = bus.get('org.bluez', '/org/bluez/hci0')

    device_path = f'/org/bluez/hci0/dev_{device_address.replace(":", "_")}'
    device = bus.get('org.bluez', device_path)

    try:
        device.Pair()
        print("Pairing successful")
    except Exception as e:
        print(f"Pairing failed: {e}")

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: pair_device.py <device_address>")
        sys.exit(1)
    pair_device(sys.argv[1])
