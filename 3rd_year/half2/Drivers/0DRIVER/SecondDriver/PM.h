#ifndef PM_H
#define PM_H

NTSTATUS
	EmuDispatchPower(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS
	CompletionQuerySystemPower(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp, IN PVOID Context);
NTSTATUS
	CompletionQueryDevicePower(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp, IN PVOID Context);
NTSTATUS
	CompletionSetSystemPower(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp, IN PVOID Context);
NTSTATUS
	CompletionDevicePowerUp(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp, IN PVOID Context);

VOID
	CallBackForRequestPower(IN PDEVICE_OBJECT DeviceObject, IN UCHAR MinorFunction, IN POWER_STATE PowerState, IN PVOID Context, IN PIO_STATUS_BLOCK IoStatus);
VOID
	CallBackForSetPower(IN PDEVICE_OBJECT DeviceObject, IN UCHAR MinorFunction, IN POWER_STATE PowerState, IN PVOID Context, IN PIO_STATUS_BLOCK IoStatus);
#endif
