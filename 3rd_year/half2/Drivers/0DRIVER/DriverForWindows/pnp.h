#ifndef PNP_H
#define PNP_H
NTSTATUS EmuDispatchPnp(
					IN PDEVICE_OBJECT DeviceObject,
					IN PIRP Irp
);
NTSTATUS StartDevice(
				IN PDEVICE_OBJECT DeviceObject,
				IN PIRP Irp
);
NTSTATUS StopDevice(
				IN PDEVICE_OBJECT DeviceObject,
				IN PIRP Irp
);
NTSTATUS RemoveDevice(
				IN PDEVICE_OBJECT DeviceObject,
				IN PIRP Irp
);
NTSTATUS QueryCapability(
				IN PDEVICE_OBJECT DeviceObject,
				IN PIRP Irp
);
NTSTATUS CompletionQueryCapability(
				IN PDEVICE_OBJECT DeviceObject,
				IN PIRP Irp,
				IN PVOID Conntext	
);
#endif


