#pragma once

#include <ntddk.h>

#ifndef IO_HANDLERS
#define IO_HANDLERS


NTSTATUS DefaultDispatchHandler(IN PDEVICE_OBJECT fdo, IN PIRP Irp);

NTSTATUS DeviceControlHandler(IN PDEVICE_OBJECT fdo, IN PIRP Irp);


#endif // !IO_HANDLERS
