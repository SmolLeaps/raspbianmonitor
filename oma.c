#include <stdio.h>
#include <stdlib.h>
#include <libusb-1.0/libusb.h>
#define MOD_CTRL_LEFT  0x01
#define MOD_SHIFT_LEFT 0x02
#define MOD_ALT_LEFT   0x04
#define MOD_GUI_LEFT   0x08
#define MOD_CTRL_RIGHT 0x10
#define MOD_SHIFT_RIGHT 0x20
#define MOD_ALT_RIGHT  0x40
#define MOD_GUI_RIGHT  0x80

void print_key(uint8_t modifier, uint8_t keycode) {

    int shiftPressed = (modifier & MOD_SHIFT_LEFT) || (modifier & MOD_SHIFT_RIGHT);
    int ctrlPressed = (modifier & MOD_CTRL_LEFT) || (modifier & MOD_CTRL_RIGHT);
    int altPressed = (modifier & MOD_ALT_LEFT) || (modifier & MOD_ALT_RIGHT);
    int guiPressed = (modifier & MOD_GUI_LEFT) || (modifier & MOD_GUI_RIGHT);

    // This is a simplified example; you may need to handle more keycodes and modifiers
    if (ctrlPressed) {
        switch (keycode) {
            case 4: printf("CTRL+A\n"); break;
            case 5: printf("CTRL+B\n"); break;
            case 6: printf("CTRL+C\n"); break;
            case 7: printf("CTRL+D\n"); break;
            case 8: printf("CTRL+E\n"); break;
            case 9: printf("CTRL+F\n"); break;
            case 10: printf("CTRL+G\n"); break;
            case 11: printf("CTRL+H\n"); break;
            case 12: printf("CTRL+I\n"); break;
            case 13: printf("CTRL+J\n"); break;
            case 14: printf("CTRL+K\n"); break;
            case 15: printf("CTRL+L\n"); break;
            case 16: printf("CTRL+M\n"); break;
            case 17: printf("CTRL+N\n"); break;
            case 18: printf("CTRL+O\n"); break;
            case 19: printf("CTRL+P\n"); break;
            case 20: printf("CTRL+Q\n"); break;
            case 21: printf("CTRL+R\n"); break;
            case 22: printf("CTRL+S\n"); break;
            case 23: printf("CTRL+T\n"); break;
            case 24: printf("CTRL+U\n"); break;
            case 25: printf("CTRL+V\n"); break;
            case 26: printf("CTRL+W\n"); break;
            case 27: printf("CTRL+X\n"); break;
            case 28: printf("CTRL+Y\n"); break;
            case 29: printf("CTRL+Z\n"); break;
            default: printf("Invalid keycode with Ctrl\n");
        }
    } else if (altPressed) {
        switch(keycode) {
            case 4: printf("ALT+a\n"); break;
            case 5: printf("ALT+b\n"); break;
            case 6: printf("ALT+c\n"); break;
            case 7: printf("ALT+d\n"); break;
            case 8: printf("ALT+e\n"); break;
            case 9: printf("ALT+f\n"); break;
            case 10: printf("ALT+g\n"); break;
            case 11: printf("ALT+h\n"); break;
            case 12: printf("ALT+i\n"); break;
            case 13: printf("ALT+j\n"); break;
            case 14: printf("ALT+k\n"); break;
            case 15: printf("ALT+l\n"); break;
            case 16: printf("ALT+m\n"); break;
            case 17: printf("ALT+n\n"); break;
            case 18: printf("ALT+o\n"); break;
            case 19: printf("ALT+p\n"); break;
            case 20: printf("ALT+q\n"); break;
            case 21: printf("ALT+r\n"); break;
            case 22: printf("ALT+s\n"); break;
            case 23: printf("ALT+t\n"); break;
            case 24: printf("ALT+u\n"); break;
            case 25: printf("ALT+v\n"); break;
            case 26: printf("ALT+w\n"); break;
            case 27: printf("ALT+x\n"); break;
            case 28: printf("ALT+y\n"); break;
            case 29: printf("ALT+z\n"); break;
            case 30: printf("ALT+1\n"); break;
            case 31: printf("ALT+2\n"); break;
            case 32: printf("ALT+3\n"); break;
            case 33: printf("ALT+4\n"); break;
            case 34: printf("ALT+5\n"); break;
            case 35: printf("ALT+6\n"); break;
            case 36: printf("ALT+7\n"); break;
            case 37: printf("ALT+8\n"); break;
            case 38: printf("ALT+9\n"); break;
            case 39: printf("ALT+0\n"); break;
            case 45: printf("ALT+-\n"); break;
            case 46: printf("ALT+=\n"); break;
            case 47: printf("ALT+[\n"); break;
            case 48: printf("ALT+]\n"); break;
            case 49: printf("ALT+\\\n"); break;
            case 51: printf("ALT+;\n"); break;
            case 52: printf("ALT+'\n"); break;
            case 54: printf("ALT+,\n"); break;
            case 55: printf("ALT+.\n"); break;
            case 56: printf("ALT+/\n"); break;
            case 40: printf("ALT+Enter\n"); break;
            case 41: printf("ALT+Escape\n"); break;
            case 42: printf("ALT+Backspace\n"); break;
            case 43: printf("ALT+Tab\n"); break;
            case 44: printf("ALT+Space\n"); break;
            case 57: printf("ALT+Caps Lock\n"); break;
            case 58: printf("ALT+F1\n"); break;
            case 59: printf("ALT+F2\n"); break;
            case 60: printf("ALT+F3\n"); break;
            case 61: printf("ALT+F4\n"); break;
            case 62: printf("ALT+F5\n"); break;
            case 63: printf("ALT+F6\n"); break;
            case 64: printf("ALT+F7\n"); break;
            case 65: printf("ALT+F8\n"); break;
            case 66: printf("ALT+F9\n"); break;
            case 67: printf("ALT+F10\n"); break;
            case 68: printf("ALT+F11\n"); break;
            case 69: printf("ALT+F12\n"); break;
            case 70: printf("ALT+Print Screen\n"); break;
            case 71: printf("ALT+Scroll Lock\n"); break;
            case 72: printf("ALT+Pause\n"); break;
            case 73: printf("ALT+Insert\n"); break;
            case 74: printf("ALT+Home\n"); break;
            case 75: printf("ALT+Page Up\n"); break;
            case 76: printf("ALT+Delete\n"); break;
            case 77: printf("ALT+End\n"); break;
            case 78: printf("ALT+Page Down\n"); break;
            case 79: printf("ALT+Right Arrow\n"); break;
            case 80: printf("ALT+Left Arrow\n"); break;
            case 81: printf("ALT+Down Arrow\n"); break;
            case 82: printf("ALT+Up Arrow\n"); break;
            default: printf("ALT\n");
        }
    } 
    else if (shiftPressed) {
        switch (keycode) {
            case 4: printf("A\n"); break;
            case 5: printf("B\n"); break;
            case 6: printf("C\n"); break;
            case 7: printf("D\n"); break;
            case 8: printf("E\n"); break;
            case 9: printf("F\n"); break;
            case 10: printf("G\n"); break;
            case 11: printf("H\n"); break;
            case 12: printf("I\n"); break;
            case 13: printf("J\n"); break;
            case 14: printf("K\n"); break;
            case 15: printf("L\n"); break;
            case 16: printf("M\n"); break;
            case 17: printf("N\n"); break;
            case 18: printf("O\n"); break;
            case 19: printf("P\n"); break;
            case 20: printf("Q\n"); break;
            case 21: printf("R\n"); break;
            case 22: printf("S\n"); break;
            case 23: printf("T\n"); break;
            case 24: printf("U\n"); break;
            case 25: printf("V\n"); break;
            case 26: printf("W\n"); break;
            case 27: printf("X\n"); break;
            case 28: printf("Y\n"); break;
            case 29: printf("Z\n"); break;
            case 30: printf("!\n"); break;
            case 31: printf("@\n"); break;
            case 32: printf("#\n"); break;
            case 33: printf("$\n"); break;
            case 34: printf("%%\n"); break; // %% to escape %
            case 35: printf("^\n"); break;
            case 36: printf("&\n"); break;
            case 37: printf("*\n"); break;
            case 38: printf("(\n"); break;
            case 39: printf(")\n"); break;
            case 45: printf("_\n"); break;
            case 46: printf("+\n"); break;
            case 47: printf("{\n"); break;
            case 48: printf("}\n"); break;
            case 49: printf("|\n"); break;
            case 51: printf(":\n"); break;
            case 52: printf("\"\n"); break;
            case 54: printf("<\n"); break;
            case 55: printf(">\n"); break;
            case 56: printf("?\n"); break;
            default: printf("Shift\n");
        }
    } else if (guiPressed){
        switch(keycode){
            case 4: printf("GUI+a\n"); break;
            case 5: printf("GUI+b\n"); break;
            case 6: printf("GUI+c\n"); break;
            case 7: printf("GUI+d\n"); break;
            case 8: printf("GUI+e\n"); break;
            case 9: printf("GUI+f\n"); break;
            case 10: printf("GUI+g\n"); break;
            case 11: printf("GUI+h\n"); break;
            case 12: printf("GUI+i\n"); break;
            case 13: printf("GUI+j\n"); break;
            case 14: printf("GUI+k\n"); break;
            case 15: printf("GUI+l\n"); break;
            case 16: printf("GUI+m\n"); break;
            case 17: printf("GUI+n\n"); break;
            case 18: printf("GUI+o\n"); break;
            case 19: printf("GUI+p\n"); break;
            case 20: printf("GUI+q\n"); break;
            case 21: printf("GUI+r\n"); break;
            case 22: printf("GUI+s\n"); break;
            case 23: printf("GUI+t\n"); break;
            case 24: printf("GUI+u\n"); break;
            case 25: printf("GUI+v\n"); break;
            case 26: printf("GUI+w\n"); break;
            case 27: printf("GUI+x\n"); break;
            case 28: printf("GUI+y\n"); break;
            case 29: printf("GUI+z\n"); break;
            case 30: printf("GUI+1\n"); break;
            case 31: printf("GUI+2\n"); break;
            case 32: printf("GUI+3\n"); break;
            case 33: printf("GUI+4\n"); break;
            case 34: printf("GUI+5\n"); break;
            case 35: printf("GUI+6\n"); break;
            case 36: printf("GUI+7\n"); break;
            case 37: printf("GUI+8\n"); break;
            case 38: printf("GUI+9\n"); break;
            case 39: printf("GUI+0\n"); break;
            case 45: printf("GUI+-\n"); break;
            case 46: printf("GUI+=\n"); break;
            case 47: printf("GUI+[\n"); break;
            case 48: printf("GUI+]\n"); break;
            case 49: printf("GUI+\\\n"); break;
            case 51: printf("GUI+;\n"); break;
            case 52: printf("GUI+'\n"); break;
            case 54: printf("GUI+,\n"); break;
            case 55: printf("GUI+.\n"); break;
            case 56: printf("GUI+/\n"); break;
            case 40: printf("GUI+Enter\n"); break;
            case 41: printf("GUI+Escape\n"); break;
            case 42: printf("GUI+Backspace\n"); break;
            case 43: printf("GUI+Tab\n"); break;
            case 44: printf("GUI+Space\n"); break;
            case 57: printf("GUI+Caps Lock\n"); break;
            case 58: printf("GUI+F1\n"); break;
            case 59: printf("GUI+F2\n"); break;
            case 60: printf("GUI+F3\n"); break;
            case 61: printf("GUI+F4\n"); break;
            case 62: printf("GUI+F5\n"); break;
            case 63: printf("GUI+F6\n"); break;
            case 64: printf("GUI+F7\n"); break;
            case 65: printf("GUI+F8\n"); break;
            case 66: printf("GUI+F9\n"); break;
            case 67: printf("GUI+F10\n"); break;
            case 68: printf("GUI+F11\n"); break;
            case 69: printf("GUI+F12\n"); break;
            case 70: printf("GUI+Print Screen\n"); break;
            case 71: printf("GUI+Scroll Lock\n"); break;
            case 72: printf("GUI+Pause\n"); break;
            case 73: printf("GUI+Insert\n"); break;
            case 74: printf("GUI+Home\n"); break;
            case 75: printf("GUI+Page Up\n"); break;
            case 76: printf("GUI+Delete\n"); break;
            case 77: printf("GUI+End\n"); break;
            case 78: printf("GUI+Page Down\n"); break;
            case 79: printf("GUI+Right Arrow\n"); break;
            case 80: printf("GUI+Left Arrow\n"); break;
            case 81: printf("GUI+Down Arrow\n"); break;
            case 82: printf("GUI+Up Arrow\n"); break;
            default: printf("GUI (CMD || WIN)\n");
        }
    }
    else {
        switch (keycode) {
            case 4: printf("a\n"); break;
            case 5: printf("b\n"); break;
            case 6: printf("c\n"); break;
            case 7: printf("d\n"); break;
            case 8: printf("e\n"); break;
            case 9: printf("f\n"); break;
            case 10: printf("g\n"); break;
            case 11: printf("h\n"); break;
            case 12: printf("i\n"); break;
            case 13: printf("j\n"); break;
            case 14: printf("k\n"); break;
            case 15: printf("l\n"); break;
            case 16: printf("m\n"); break;
            case 17: printf("n\n"); break;
            case 18: printf("o\n"); break;
            case 19: printf("p\n"); break;
            case 20: printf("q\n"); break;
            case 21: printf("r\n"); break;
            case 22: printf("s\n"); break;
            case 23: printf("t\n"); break;
            case 24: printf("u\n"); break;
            case 25: printf("v\n"); break;
            case 26: printf("w\n"); break;
            case 27: printf("x\n"); break;
            case 28: printf("y\n"); break;
            case 29: printf("z\n"); break;
            case 30: printf("1\n"); break;
            case 31: printf("2\n"); break;
            case 32: printf("3\n"); break;
            case 33: printf("4\n"); break;
            case 34: printf("5\n"); break;
            case 35: printf("6\n"); break;
            case 36: printf("7\n"); break;
            case 37: printf("8\n"); break;
            case 38: printf("9\n"); break;
            case 39: printf("0\n"); break;
            case 45: printf("-\n"); break;
            case 46: printf("=\n"); break;
            case 47: printf("[\n"); break;
            case 48: printf("]\n"); break;
            case 49: printf("\\\n"); break;
            case 51: printf(";\n"); break;
            case 52: printf("'\n"); break;
            case 54: printf(",\n"); break;
            case 55: printf(".\n"); break;
            case 56: printf("/\n"); break;
            case 40: printf("Enter\n"); break;
            case 41: printf("Escape\n"); break;
            case 42: printf("Backspace\n"); break;
            case 43: printf("Tab\n"); break;
            case 44: printf("Space\n"); break;
            case 57: printf("Caps Lock\n"); break;
            case 58: printf("F1\n"); break;
            case 59: printf("F2\n"); break;
            case 60: printf("F3\n"); break;
            case 61: printf("F4\n"); break;
            case 62: printf("F5\n"); break;
            case 63: printf("F6\n"); break;
            case 64: printf("F7\n"); break;
            case 65: printf("F8\n"); break;
            case 66: printf("F9\n"); break;
            case 67: printf("F10\n"); break;
            case 68: printf("F11\n"); break;
            case 69: printf("F12\n"); break;
            case 70: printf("Print Screen\n"); break;
            case 71: printf("Scroll Lock\n"); break;
            case 72: printf("Pause\n"); break;
            case 73: printf("Insert\n"); break;
            case 74: printf("Home\n"); break;
            case 75: printf("Page Up\n"); break;
            case 76: printf("Delete\n"); break;
            case 77: printf("End\n"); break;
            case 78: printf("Page Down\n"); break;
            case 79: printf("Right Arrow\n"); break;
            case 80: printf("Left Arrow\n"); break;
            case 81: printf("Down Arrow\n"); break;
            case 82: printf("Up Arrow\n"); break;
            default: printf(" \n");
        }
    }
}

void check_device(libusb_device *device) {

    printf("\n ---entered check_device() --- \n");
    struct libusb_device_descriptor desc;
    int r = libusb_get_device_descriptor(device, &desc);
    if (r < 0) {
        fprintf(stderr, "Failed to get device descriptor: %s\n", libusb_error_name(r));
        return;
    }

    if (desc.bDeviceClass == LIBUSB_CLASS_PER_INTERFACE) {
        libusb_config_descriptor *config;
        r = libusb_get_config_descriptor(device, 0, &config);
        if (r < 0) {
            fprintf(stderr, "Failed to get config descriptor: %s\n", libusb_error_name(r));
            return;
        }

        const libusb_interface *inter;
        const libusb_interface_descriptor *interdesc;
        for (int i = 0; i < config->bNumInterfaces; i++) {
            inter = &config->interface[i];
            for (int j = 0; j < inter->num_altsetting; j++) {
                interdesc = &inter->altsetting[j];
                if (interdesc->bInterfaceClass == LIBUSB_CLASS_HID &&
                    interdesc->bInterfaceSubClass == 1 && // Boot Interface Subclass
                    interdesc->bInterfaceProtocol == 1) { // Keyboard
                    printf("Keyboard found: VID=0x%04x, PID=0x%04x\n", desc.idVendor, desc.idProduct);
                }
                for (int k = 0; k < interdesc->bNumEndpoints; k++) {
                    const libusb_endpoint_descriptor *epdesc = &interdesc->endpoint[k];
                    printf("Endpoint address: 0x%02x\n", epdesc->bEndpointAddress);
                }
            }
        }

        libusb_free_config_descriptor(config);
    }
        printf("\n --- exit check_device() --- \n");
}

int main() {
    printf("init\n");
    libusb_device **devs;
    libusb_context *ctx = NULL;
    int r;
    ssize_t cnt;

    r = libusb_init(&ctx);
    if (r < 0) {
        fprintf(stderr, "Init Error %d\n", r);
        return 1;
    }

    cnt = libusb_get_device_list(ctx, &devs);
    if (cnt < 0) {
        fprintf(stderr, "Get Device Error\n");
        libusb_exit(ctx);
        return 1;
    }

    //logic for calling check_device()
       for (ssize_t i = 0; i < cnt; i++) {
        check_device(devs[i]);
    }
    // printf("breakpoint 1 | \n");
    libusb_device *keyboard = NULL;
    // printf("breakpoint 2 | \n");
    struct libusb_device_descriptor desc;
    // code to check for specific keyboards connected
    for (ssize_t i = 0; i < cnt; i++) {
        libusb_get_device_descriptor(devs[i], &desc);
        if ((desc.idVendor == 0x1532 && desc.idProduct == 0x0243) ) { // TODO: receive dynamic values for the found keyboard from check_device()
            // printf("breakpoint 3 | \n");
            keyboard = devs[i];
            break;
        }
    }

    if (keyboard == NULL) {
        fprintf(stderr, "Keyboard not found\n");
        libusb_free_device_list(devs, 1);
        libusb_exit(ctx);
        return 1;
    }

    // printf("breakpoint 4 | \n");
    libusb_device_handle *handle;
    // printf("breakpoint 5 | \n");
    r = libusb_open(keyboard, &handle);
    // printf("breakpoint 6 | \n");
    if (r != 0) {
        fprintf(stderr, "Cannot open device: %s\n", libusb_error_name(r));
        libusb_free_device_list(devs, 1);
        libusb_exit(ctx);
        return 1;
    }
    // printf("breakpoint 7 | \n");
    libusb_free_device_list(devs, 1);
    // Detach the kernel driver if necessary
    if (libusb_kernel_driver_active(handle, 0) == 1) {
        printf("Kernel driver active. Detaching it.\n");
        r = libusb_detach_kernel_driver(handle, 0);
        if (r != 0) {
            fprintf(stderr, "Cannot detach kernel driver: %s\n", libusb_error_name(r));
            libusb_close(handle);
            libusb_exit(ctx);
            return 1;
        }
    }
    // printf("breakpoint 8 | \n");  
    r = libusb_claim_interface(handle, 0);
    if (r != 0) {
        fprintf(stderr, "Cannot claim interface: %s\n", libusb_error_name(r));
        libusb_close(handle);
        libusb_exit(ctx);
        return 1;
    }

    uint8_t data[8];
    int actual_length;

    while (1) {
        r = libusb_interrupt_transfer(handle, 0x81, data, sizeof(data), &actual_length, 5000);
        // printf("breakpoint 9 | \n", r);
        // printf("variables in breakpoint 9: %s | %u \n", handle, data);
        // char str[20];  // Make sure the array is large enough to hold the number as a string
        // sprintf(str, "%u", handle); // Convert the unsigned int to a string
        // printf("The string representation of the unsigned integer is: %s\n", str);
        if (r == 0 && actual_length == sizeof(data)) {
            // printf("breakpoint 10  | \n");
            for (int i = 2; i < actual_length; i++) {
                // printf("breakpoint 11 | \n");
                if (data[i] != 0 && sizeof(data)<=2) {
                    // printf("breakpoint 12 | \n");
                    print_key(0, data[i]);
                }
                else {
                    print_key(data[0], data[2]);
                }
            }
        } else if (r != LIBUSB_ERROR_TIMEOUT) {
            fprintf(stderr, "Error in interrupt transfer: %s\n", libusb_error_name(r));
        }
        else {
            fprintf(stderr, "Error receiving data: %s\n", libusb_error_name(r));
        }
    }

    libusb_release_interface(handle, 0);
    libusb_close(handle);
    libusb_exit(ctx);

    return 0;
}
