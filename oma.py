'''
sudo apt-get install bluez python3-bluez python3-evdev
pip install pybluez evdev
'''
import bluetooth
from evdev import UInput, ecodes as e

def create_virtual_keyboard():
    capabilities = {
        e.EV_KEY: [
            e.KEY_A, e.KEY_B, e.KEY_C, e.KEY_D, e.KEY_E, e.KEY_F, e.KEY_G,
            e.KEY_H, e.KEY_I, e.KEY_J, e.KEY_K, e.KEY_L, e.KEY_M, e.KEY_N,
            e.KEY_O, e.KEY_P, e.KEY_Q, e.KEY_R, e.KEY_S, e.KEY_T, e.KEY_U,
            e.KEY_V, e.KEY_W, e.KEY_X, e.KEY_Y, e.KEY_Z,
            e.KEY_1, e.KEY_2, e.KEY_3, e.KEY_4, e.KEY_5, e.KEY_6, e.KEY_7,
            e.KEY_8, e.KEY_9, e.KEY_0, e.KEY_ENTER, e.KEY_ESC, e.KEY_BACKSPACE,
            e.KEY_TAB, e.KEY_SPACE, e.KEY_MINUS, e.KEY_EQUAL, e.KEY_LEFTBRACE,
            e.KEY_RIGHTBRACE, e.KEY_BACKSLASH, e.KEY_SEMICOLON, e.KEY_APOSTROPHE,
            e.KEY_GRAVE, e.KEY_COMMA, e.KEY_DOT, e.KEY_SLASH
        ]
    }
    return UInput(capabilities)

def send_key(ui, keycode):
    ui.write(e.EV_KEY, keycode, 1)
    ui.write(e.EV_KEY, keycode, 0)
    ui.syn()

def find_bluetooth_device(name):
    nearby_devices = bluetooth.discover_devices(lookup_names=True)
    for addr, dev_name in nearby_devices:
        if dev_name == name:
            return addr
    return None

def connect_to_device(addr):
    sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    sock.connect((addr, 1))
    return sock

if __name__ == "__main__":
    device_name = "Carey's iPhone"  # Replace with the Bluetooth device name you want to connect to
    addr = find_bluetooth_device(device_name)

    if addr is None:
        print(f"Could not find device {device_name}")
        exit(1)

    print(f"Found device {device_name} with address {addr}")
    sock = connect_to_device(addr)
    print(f"Connected to {device_name}")

    ui = create_virtual_keyboard()

    try:
        while True:
            data = sock.recv(1024)
            if data:
                for byte in data:
                    # Example: Convert received byte to keycode (this is just an example, adapt as needed)
                    if byte == b'a'[0]:
                        send_key(ui, e.KEY_A)
                    elif byte == b'b'[0]:
                        send_key(ui, e.KEY_B)
                    # Add more key mappings as needed

    except KeyboardInterrupt:
        print("Disconnected")
    finally:
        sock.close()
        ui.close()