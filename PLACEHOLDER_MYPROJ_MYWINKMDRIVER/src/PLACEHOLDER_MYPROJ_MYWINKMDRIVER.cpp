#include <ntddk.h>
#include "PLACEHOLDER_MYPROJ_MYWINKMLIB.hpp"

extern "C" DRIVER_INITIALIZE DriverEntry;

#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT, DriverEntry)
#endif

VOID DriverUnload(
    _In_ PDRIVER_OBJECT DriverObject
)
{
    UNREFERENCED_PARAMETER(DriverObject);

    DbgPrint("Driver(simple) unloaded DriverObject=%p\n", DriverObject);
}

NTSTATUS DriverEntry(
    _In_ PDRIVER_OBJECT DriverObject,
    _In_ PUNICODE_STRING RegistryPath
)
{
    UNREFERENCED_PARAMETER(RegistryPath);

    DbgPrint("Driver(simple) loaded DriverObject=%p\n", DriverObject);
    PLACEHOLDER_MYPROJ_MYWINKMLIB::func();

    DriverObject->DriverUnload = DriverUnload;

    return STATUS_SUCCESS;
}

