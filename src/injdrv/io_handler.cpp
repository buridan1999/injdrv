#include "io_handler.h"

#include <ntddk.h>

NTSTATUS CompliteIrp(PIRP Irp, NTSTATUS status, ULONG info)
{
  Irp->IoStatus.Status = status;
  Irp->IoStatus.Information = info;
  IoCompleteRequest(Irp, IO_NO_INCREMENT);
  return status;
}

NTSTATUS DefaultDispatchHandler(IN PDEVICE_OBJECT fdo, IN PIRP Irp)
{
  UNREFERENCED_PARAMETER(fdo);

  return CompliteIrp(Irp, STATUS_SUCCESS, 0);
}

NTSTATUS DeviceControlHandler(IN PDEVICE_OBJECT fdo, IN PIRP Irp)
{
  UNREFERENCED_PARAMETER(fdo);

  PIO_STACK_LOCATION  currentIrpStack = IoGetCurrentIrpStackLocation(Irp);

  //PVOID               inputBuffer;
  //PVOID               outputBuffer;
  //ULONG               inputBufferLength;
  //ULONG               outputBufferLength;

  KdPrint(("DeviceControlHandler -> ioctl get: 0x%X", currentIrpStack->Parameters.DeviceIoControl.IoControlCode));

  switch (currentIrpStack->Parameters.DeviceIoControl.IoControlCode)
  {
    case (0xFF):
    {
      if (bool ok = true)
      {
        return CompliteIrp(Irp, STATUS_SUCCESS, 0);
      }
      else
      {
        return CompliteIrp(Irp, STATUS_UNSUCCESSFUL, 0);
      }
    }
  }
  return CompliteIrp(Irp, STATUS_SUCCESS, 0);
}
