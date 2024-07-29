#include <stdio.h>
#include <stdlib.h>
#include <libusb-1.0/libusb.h>

void print_key(uint8_t keycode) {
    // This is a simplified example; you may need to handle more keycodes and modifiers
    switch (keycode) {
        case 4: printf("A\n"); break;
        case 5: printf("B\n"); break;
        case 6: printf("C\n"); break;
        case 7: printf("D\n"); break;
        // Add more keycodes as needed
        default: printf("Unknown keycode: %d\n", keycode);
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
            }
        }

        libusb_free_config_descriptor(config);
    }
}

int main() {
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

    libusb_device *keyboard = NULL;
    struct libusb_device_descriptor desc;
    
    // code to check for specific keyboards connected
    // for (ssize_t i = 0; i < cnt; i++) {
    //     libusb_get_device_descriptor(devs[i], &desc);
    //     if (desc.idVendor == 0x046d && desc.idProduct == 0xc31c) { // Example VendorID and ProductID for a Logitech keyboard
            
    //         keyboard = devs[i];
    //         break;
    //     }
    //     printf("vendor id: %d\n", desc.idVendor);
    //     printf("product id: %d\n", desc.idProduct);
    // }

    // if (keyboard == NULL) {
    //     fprintf(stderr, "Keyboard not found\n");
    //     libusb_free_device_list(devs, 1);
    //     libusb_exit(ctx);
    //     return 1;
    // }

    libusb_device_handle *handle;
    r = libusb_open(keyboard, &handle);
    if (r != 0) {
        fprintf(stderr, "Cannot open device\n");
        libusb_free_device_list(devs, 1);
        libusb_exit(ctx);
        return 1;
    }

    libusb_free_device_list(devs, 1);

    r = libusb_claim_interface(handle, 0);
    if (r != 0) {
        fprintf(stderr, "Cannot claim interface\n");
        libusb_close(handle);
        libusb_exit(ctx);
        return 1;
    }

    uint8_t data[8];
    int actual_length;
    while (1) {
        r = libusb_interrupt_transfer(handle, 0x81, data, sizeof(data), &actual_length, 0);
        if (r == 0 && actual_length > 0) {
            for (int i = 2; i < actual_length; i++) {
                if (data[i] != 0) {
                    print_key(data[i]);
                }
            }
        }
    }

    libusb_release_interface(handle, 0);
    libusb_close(handle);
    libusb_exit(ctx);

    return 0;
}