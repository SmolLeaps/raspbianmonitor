#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <stdlib.h>

#define USB_VENDOR_ID 0x11  // Replace with your keyboard's vendor ID
#define USB_PRODUCT_ID 0x12 // Replace with your keyboard's product ID

void print_endpoint_data(unsigned char *data, int length) {
    printf("Data: ");
    for (int i = 0; i < length; ++i) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

int main() {
    libusb_device_handle *handle = NULL;
    libusb_context *ctx = NULL;
    int r;
    int endpoint_address = 0x81; // Typically, keyboards use the first IN endpoint
    unsigned char data[8];
    int actual_length;

    // Initialize libusb
    r = libusb_init(&ctx);
    if (r < 0) {
        fprintf(stderr, "Failed to initialize libusb: %s\n", libusb_strerror(r));
        return EXIT_FAILURE;
    }

    // Set verbosity level to 3, as suggested in the libusb documentation
    libusb_set_option(ctx, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_DEBUG);

    // Open USB device
    handle = libusb_open_device_with_vid_pid(ctx, USB_VENDOR_ID, USB_PRODUCT_ID);
    if (!handle) {
        fprintf(stderr, "Cannot open device\n");
        libusb_exit(ctx);
        return EXIT_FAILURE;
    }

    // Detach kernel driver if necessary
    if (libusb_kernel_driver_active(handle, 0) == 1) {
        r = libusb_detach_kernel_driver(handle, 0);
        if (r != 0) {
            fprintf(stderr, "Cannot detach kernel driver: %s\n", libusb_strerror(r));
            libusb_close(handle);
            libusb_exit(ctx);
            return EXIT_FAILURE;
        }
    }

    // Claim interface 0 (usually the keyboard interface)
    r = libusb_claim_interface(handle, 0);
    if (r < 0) {
        fprintf(stderr, "Cannot claim interface: %s\n", libusb_strerror(r));
        libusb_close(handle);
        libusb_exit(ctx);
        return EXIT_FAILURE;
    }

    // Read data from the endpoint
    while (1) {
        r = libusb_interrupt_transfer(handle, endpoint_address, data, sizeof(data), &actual_length, 0);
        if (r == 0 && actual_length > 0) {
            print_endpoint_data(data, actual_length);
        } else if (r != 0) {
            fprintf(stderr, "Error in interrupt transfer: %s\n", libusb_strerror(r));
            break;
        }
    }

    // Release interface and close device
    libusb_release_interface(handle, 0);
    libusb_close(handle);
    libusb_exit(ctx);

    return EXIT_SUCCESS;
}
