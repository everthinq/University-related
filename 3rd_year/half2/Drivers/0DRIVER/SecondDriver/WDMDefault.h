#ifndef WDMDEFAULT_H
#define WDMDEFAULT_H



typedef struct tagDEVICE_EXTENSION {
PDEVICE_OBJECT DeviceObject;
PDEVICE_OBJECT NextDeviceObject;
DEVICE_CAPABILITIES pdc;
IO_REMOVE_LOCK RemoveLock;
LONG handles;
PVOID DataBuffer;
UNICODE_STRING Device_Description;
SYSTEM_POWER_STATE SysPwrState;
DEVICE_POWER_STATE DevPwrState;
PIRP PowerIrp;

LONG SourceSize;
PVOID SourcePointer;
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;


typedef struct tagDEVICE_POWER_INFORMATION{
BOOLEAN SupportQueryCapability;
ULONG DeviceD1;
ULONG DeviceD2;
ULONG WakeFromD0;
ULONG WakeFromD1;
ULONG WakeFromD2;
ULONG WakeFromD3;
SYSTEM_POWER_STATE SystemWake;
DEVICE_POWER_STATE DeviceWake;
DEVICE_POWER_STATE DeviceState[PowerSystemMaximum];
}  DEVICE_POWER_INFORMATION, *PDEVICE_POWER_INFORMATION;



#define IOCTL_READ_DEVICE_INFO              \
          CTL_CODE(                           \
                      FILE_DEVICE_UNKNOWN,    \
                      0x800,                  \
                      METHOD_BUFFERED,        \
                      FILE_ANY_ACCESS)
                      
  //Код для получения информации о питании устроиства
  #define IOCTL_READ_POWER_INFO             \
      CTL_CODE(             \
           FILE_DEVICE_UNKNOWN,     \
           0x801,           \
           METHOD_BUFFERED,     \
           FILE_ANY_ACCESS)
  
  NTSTATUS
    CompleteRequest(
          IN PIRP Irp,
          IN NTSTATUS status,
          IN ULONG_PTR info);
#endif	


      
