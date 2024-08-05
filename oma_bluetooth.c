#include <stdio.h>
#include <stdlib.h>
#include <dbus/dbus.h>

DBusConnection* connect_to_system_bus() {
    DBusError err;
    DBusConnection* conn;

    dbus_error_init(&err);
    conn = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
    if (dbus_error_is_set(&err)) {
        fprintf(stderr, "Connection Error (%s)\n", err.message);
        dbus_error_free(&err);
    }
    if (!conn) {
        exit(1);
    }

    return conn;
}

void start_discovery(DBusConnection* conn) {
    DBusMessage* msg;
    DBusMessageIter args;
    DBusPendingCall* pending;

    msg = dbus_message_new_method_call("org.bluez", 
                                       "/org/bluez/hci0", 
                                       "org.bluez.Adapter", 
                                       "StartDiscovery");
    if (!msg) {
        fprintf(stderr, "Message Null\n");
        exit(1);
    }

    if (!dbus_connection_send_with_reply(conn, msg, &pending, -1)) {
        fprintf(stderr, "Out Of Memory!\n");
        exit(1);
    }
    if (!pending) {
        fprintf(stderr, "Pending Call Null\n");
        exit(1);
    }

    dbus_connection_flush(conn);
    dbus_message_unref(msg);
}

void listen_for_signals(DBusConnection* conn) {
    DBusMessage* msg;
    DBusMessageIter args;
    char* sigvalue;

    while (1) {
        dbus_connection_read_write(conn, 0);
        msg = dbus_connection_pop_message(conn);

        if (msg == NULL) {
            sleep(1);
            continue;
        }

        if (dbus_message_is_signal(msg, "org.freedesktop.DBus.Properties", "PropertiesChanged")) {
            if (!dbus_message_iter_init(msg, &args)) {
                fprintf(stderr, "Message has no arguments!\n");
            } else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
                fprintf(stderr, "Argument is not string!\n");
            } else {
                dbus_message_iter_get_basic(&args, &sigvalue);
                printf("Received Signal with value: %s\n", sigvalue);
            }
        }

        dbus_message_unref(msg);
    }
}


int main() {
    printf("---init---\n");
    DBusConnection* conn;
    printf("breakpoint 1\n");
    conn = connect_to_system_bus();
    printf("breakpoint 2\n");
    start_discovery(conn);
    printf("breakpoint 3\n");
    listen_for_signals(conn);
    printf("breakpoint 4\n");
    return 0;
}