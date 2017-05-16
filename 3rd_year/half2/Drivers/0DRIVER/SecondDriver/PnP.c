#include <wdm.h>
#include "WDMDefault.h"
#include "PnP.h"

extern PDEVICE_POWER_INFORMATION Global_PowerInfo_Ptr;

NTSTATUS 
	EmuDispatchPnp(
		IN PDEVICE_OBJECT DeviceObject,
		IN PIRP Irp
		)
{
	PIO_STACK_LOCATION p_IO_STK;
	PDEVICE_EXTENSION p_DVCEXT;
	ULONG IRP_MN_Code;
	NTSTATUS Status = STATUS_SUCCESS;

	DbgPrint ("IRP_MJ_PNP Received : Begin\r\n");
	p_IO_STK = IoGetCurrentIrpStackLocation(Irp);
	p_DVCEXT = DeviceObject->DeviceExtension;
	IoAcquireRemoveLock(
          &p_DVCEXT->RemoveLock, 
          Irp); // блокир запрос
	IRP_MN_Code = p_IO_STK->MinorFunction ;
switch(IRP_MN_Code)
{
case IRP_MN_START_DEVICE :
	DbgPrint ("IRP_MN_START_DEVICE Received : Begin\r\n");
	Status = StartDevice(
	DeviceObject,
	Irp);
	DbgPrint ("IRP_MN_START_DEVICE Received : End\r\n");
	break;
case IRP_MN_STOP_DEVICE :
	DbgPrint ("IRP_MN_STOP_DEVICE Received : Begin\r\n");
	Status = StopDevice(
	DeviceObject,
	Irp);
	DbgPrint ("IRP_MN_STOP_DEVICE Received : End\r\n");
	break;
case IRP_MN_REMOVE_DEVICE :
	DbgPrint ("IRP_MN_REMOVE_DEVICE Received : Begin\r\n");
	Status = RemoveDevice(
	DeviceObject,
	Irp);
	DbgPrint ("IRP_MN_REMOVE_DEVICE Received : End\r\n");
	break;
case IRP_MN_QUERY_CAPABILITIES :
	DbgPrint ("IRP_MN_QUERY_CAPABILITIES Received : Begin\r\n");
	Status = QueryCapability(
	DeviceObject,
	Irp);
	DbgPrint ("IRP_MN_QUERY_CAPABILITIES Received : End\r\n");
	break;
default:
	IoReleaseRemoveLock(
	&p_DVCEXT->RemoveLock,
	Irp);
	IoSkipCurrentIrpStackLocation (Irp);
	return IoCallDriver (p_DVCEXT->NextDeviceObject,
	Irp);
}
IoReleaseRemoveLock(
	&p_DVCEXT->RemoveLock,
	Irp);
if (NT_SUCCESS (Status))
	CompleteRequest(
		Irp,
		STATUS_SUCCESS,
		0);
DbgPrint("IRP_MJ_PNP Received : End\r\n");
return Status;
}

NTSTATUS StartDevice(IN PDEVICE_OBJECT DeviceObject,IN PIRP Irp)
{
	PIO_STACK_LOCATION p_IO_STK;
	ULONG count;
	ULONG i;
	//LONG SourceSize;
    //PVOID SourcePointer;
	PDEVICE_EXTENSION p_DVCEXT;
	
	PCM_PARTIAL_RESOURCE_DESCRIPTOR pointer;
	PCM_PARTIAL_RESOURCE_DESCRIPTOR pointerTranslated;
	p_DVCEXT = DeviceObject -> DeviceExtension;
	p_IO_STK = IoGetCurrentIrpStackLocation(Irp);
	count = p_IO_STK->Parameters.StartDevice.AllocatedResources->List[0].PartialResourceList.Count;
	for( i=0; i<count; i++)
	{
		pointer = &(p_IO_STK->Parameters.StartDevice.AllocatedResources->List[0].PartialResourceList.PartialDescriptors[i]);
		pointerTranslated = &(p_IO_STK->Parameters.StartDevice.AllocatedResourcesTranslated->List[0].PartialResourceList.PartialDescriptors[i]);
	
	switch(pointer->Type)
	{
		case CmResourceTypePort: DbgPrint("LOOK HE FOND ResourcePORT .... \r\n"); break;
		case CmResourceTypeMemory: DbgPrint("LOOK HE FOND ResourceMEMORY .... \r\n"); break;
	}
	switch(pointerTranslated->Type)
	{
		case CmResourceTypePort: DbgPrint("LOOK HE FOND ResourceTranslatedPORT .... \r\n"); break;
		case CmResourceTypeMemory: DbgPrint("LOOK HE FOND ResourceTranslatedMEMORY .... \r\n"); break;
	}
	}
	DbgPrint("LOOK HE DID SOMETHING .... \r\n");
    DbgPrint("%d", count);
	p_DVCEXT->SourceSize = pointer->u.Port.Length;
	p_DVCEXT->SourcePointer = pointer->u.Port.Start.u.LowPart;
	DbgPrint("Size = %d \r\n", p_DVCEXT->SourceSize);
	DbgPrint("Pointer = %d \r\n", p_DVCEXT->SourcePointer);
	DbgPrint("Start Device .... \r\n");
	return STATUS_SUCCESS;
}
NTSTATUS
	StopDevice(
		IN PDEVICE_OBJECT DeviceObject,
		IN PIRP Irp)
{
	DbgPrint("Stop Device .... \r\n");
return STATUS_SUCCESS;
}
NTSTATUS
	RemoveDevice(
		IN PDEVICE_OBJECT DeviceObject,
		IN PIRP Irp)
{
	PDEVICE_EXTENSION p_DVCEXT;
	DbgPrint("Remove Device .... \r\n");
#if 0
	p_DVCEXT = DeviceObject -> DeviceExtension;
	IoDetachDevice(
	p_DVCEXT -> DeviceObject);
	IoDeleteDevice(
	p_DVCEXT -> NextDeviceObject);
#endif
	return STATUS_SUCCESS;
}
NTSTATUS
	QueryCapability(
		IN PDEVICE_OBJECT DeviceObject,
		IN PIRP Irp)
{
#if 1
	PIO_STACK_LOCATION p_IO_STK;
	PDEVICE_EXTENSION p_DVCEXT;
	NTSTATUS Status;
	KEVENT event;
	ULONG IdxPwrState;

	DbgPrint("Query Device Capability .... \r\n");
	DbgPrint("Ready to pass IRP down \r\n");

	p_IO_STK = IoGetCurrentIrpStackLocation(Irp);
	p_DVCEXT = DeviceObject -> DeviceExtension;

	KeInitializeEvent (&event, NotificationEvent, FALSE);

	IoCopyCurrentIrpStackLocationToNext(Irp);

	IoSetCompletionRoutine(
		Irp,
		(PIO_COMPLETION_ROUTINE)CompletionQueryCapability,
		(PVOID) &event,
		TRUE,
		TRUE,
		TRUE);

Status = IoCallDriver(
		p_DVCEXT -> NextDeviceObject,
		Irp);

KeWaitForSingleObject(&event, Executive, KernelMode, FALSE, NULL);

if (NT_SUCCESS(Irp -> IoStatus.Status)){
	p_IO_STK = IoGetCurrentIrpStackLocation(Irp);
	p_DVCEXT = DeviceObject -> DeviceExtension;
p_DVCEXT -> pdc = *p_IO_STK -> Parameters.DeviceCapabilities.Capabilities;
#if 1
	Global_PowerInfo_Ptr->SupportQueryCapability = TRUE;
	Global_PowerInfo_Ptr->DeviceD1 = p_DVCEXT->pdc.DeviceD1;
	Global_PowerInfo_Ptr->DeviceD2 = p_DVCEXT->pdc.DeviceD2;
	Global_PowerInfo_Ptr->WakeFromD0 = p_DVCEXT->pdc.WakeFromD0;
	Global_PowerInfo_Ptr->WakeFromD1 = p_DVCEXT->pdc.WakeFromD1;
	Global_PowerInfo_Ptr->WakeFromD2 = p_DVCEXT->pdc.WakeFromD2;
	Global_PowerInfo_Ptr->WakeFromD3 = p_DVCEXT->pdc.WakeFromD3;
	Global_PowerInfo_Ptr->DeviceWake = p_DVCEXT->pdc.SystemWake;
	Global_PowerInfo_Ptr->SystemWake = p_DVCEXT->pdc.DeviceWake;
for (IdxPwrState = 0; 
              IdxPwrState < PowerSystemMaximum;
              IdxPwrState++)
          {
              Global_PowerInfo_Ptr->DeviceState[IdxPwrState] = 
                  p_DVCEXT->pdc.DeviceState[IdxPwrState];
          }
#else
          
          DbgPrint("WakeFromD0 : %d\r\n", p_DVCEXT->pdc.WakeFromD0);
          DbgPrint("WakeFromD1 : %d\r\n", p_DVCEXT->pdc.WakeFromD1);
          DbgPrint("WakeFromD2 : %d\r\n", p_DVCEXT->pdc.WakeFromD2);
          DbgPrint("WakeFromD3 : %d\r\n", p_DVCEXT->pdc.WakeFromD3);
          DbgPrint("SystemWake : %d\r\n", p_DVCEXT->pdc.SystemWake);
          DbgPrint("DeviceWake : %d\r\n", p_DVCEXT->pdc.DeviceWake);
for (IdxPwrState = 0; 
              IdxPwrState < PowerSystemMaximum;
              IdxPwrState++)
{
              DbgPrint("DeviceState[%d] : %d\r\n", 
                  IdxPwrState, 
                  p_DVCEXT->pdc.DeviceState[IdxPwrState]);
          }
#endif
} else {
          DbgPrint("Failed to handle IRP_MN_QUERY_CAPABILITIES");
      }
      return Irp->IoStatus.Status;
}
NTSTATUS
	CompletionQueryCapability(
		IN PDEVICE_OBJECT DeviceObject,
		IN PIRP Irp,
		IN PVOID Context
)
{
	PIO_STACK_LOCATION p_IO_STK;
	PDEVICE_EXTENSION p_DVCEXT;
NTSTATUS Status = STATUS_SUCCESS;
	PIO_STATUS_BLOCK p_IO_Status;
	ULONG IdxPwrState;
PKEVENT pev;

DbgPrint("In Cmpletion Routine for IRP_MN_QUERY_CAPABILITIES ....\r\n");
p_IO_STK = IoGetCurrentIrpStackLocation(Irp);
pev = (PKEVENT)Context;
KeSetEvent(pev, 0, FALSE);
DbgPrint("return from IoCompletion Routine for IRP_MN_QUERY_CAPABILITIES\r\n");
return STATUS_MORE_PROCESSING_REQUIRED;
#endif
}