typedef enum _NDIS_RFC6877_464XLAT_OFFLOAD_OPTIONS
{
  NDIS_RFC6877_464XLAT_OFFLOAD_NOT_SUPPORTED = 0,
  NDIS_RFC6877_464XLAT_OFFLOAD_DISABLED = 1,
  NDIS_RFC6877_464XLAT_OFFLOAD_ENABLED = 2,
  NDIS_RFC6877_464XLAT_OFFLOAD_ON_DEMAND = 3,
} NDIS_RFC6877_464XLAT_OFFLOAD_OPTIONS, *PNDIS_RFC6877_464XLAT_OFFLOAD_OPTIONS;

typedef struct _NDIS_RFC6877_464XLAT_OFFLOAD
{
  /* 0x0000 */ enum _NDIS_RFC6877_464XLAT_OFFLOAD_OPTIONS XlatOffload;
  /* 0x0004 */ unsigned long Flags;
} NDIS_RFC6877_464XLAT_OFFLOAD, *PNDIS_RFC6877_464XLAT_OFFLOAD; /* size: 0x0008 */

