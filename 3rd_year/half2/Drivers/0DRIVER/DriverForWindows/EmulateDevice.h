NTSTATUS DriverEntry(
					 IN PDRIVER_OBJECT DriverObject,
					 IN PUNICODE_STRING RegistryPath
					 );

NTSTATUS EmuAddDevice(
					 IN PDRIVER_OBJECT DriverObject,
					 IN PDEVICE_OBJECT PhysicalDeviceObject
					 );

VOID EmuDriverUnload(
					 IN PDRIVER_OBJECT DriverObject
					 );

NTSTATUS EmuDispatchCreate(
					 IN PDEVICE_OBJECT DriverObject,
					 IN PIRP Irp
					 );

NTSTATUS EmuDispatchClose(
					 IN PDEVICE_OBJECT DriverObject,
					 IN PIRP Irp
					 );

NTSTATUS EmuDispatchRead(
					 IN PDEVICE_OBJECT DriverObject,
					 IN PIRP Irp
					 );

NTSTATUS EmuDispatchWrite(
					 IN PDEVICE_OBJECT DriverObject,
					 IN PIRP Irp
					 );

NTSTATUS EmuDispatchDeviceControl(
					 IN PDEVICE_OBJECT DriverObject,
					 IN PIRP Irp
					 );