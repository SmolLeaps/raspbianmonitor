#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>

int main(int argc, char **argv) {
    unsigned char report[] = {
        0xA1, // HID message type (0xA1 for input)
        0x01, // Report ID (keyboard)
        0x00, // Modifier byte (no modifiers)
        0x00, // Reserved
        0x04, // Keycode (0x04 for 'a')
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // Remaining keycodes
    };

    // Create L2CAP socket
    int sock = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_l2 addr = { 0 };
    addr.l2_family = AF_BLUETOOTH;
    addr.l2_psm = htobs(0x0011); // HID interrupt PSM (0x0011)
    if (str2ba("78:A7:C7:B4:0F:9E", &addr.l2_bdaddr) < 0) { // Replace with the target device's Bluetooth address
        perror("Invalid Bluetooth address");
        close(sock);
        exit(1);
    }

    // Connect to the remote device
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sock);
        exit(1);
    }

    // Send the HID report
    int bytes_written = write(sock, report, sizeof(report));
    if (bytes_written < 0) {
        perror("write");
    }

    // Close the socket
    close(sock);

    return 0;
}
