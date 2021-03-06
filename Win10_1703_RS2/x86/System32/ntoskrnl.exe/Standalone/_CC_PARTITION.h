typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _SHARED_CACHE_MAP_LIST_CURSOR
{
  /* 0x0000 */ struct _LIST_ENTRY SharedCacheMapLinks;
  /* 0x0008 */ unsigned long Flags;
} SHARED_CACHE_MAP_LIST_CURSOR, *PSHARED_CACHE_MAP_LIST_CURSOR; /* size: 0x000c */

typedef struct _EX_PUSH_LOCK
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long Locked : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long Waiting : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long Waking : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long MultipleShared : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long Shared : 28; /* bit position: 4 */
    }; /* bitfield */
    /* 0x0000 */ unsigned long Value;
    /* 0x0000 */ void* Ptr;
  }; /* size: 0x0004 */
} EX_PUSH_LOCK, *PEX_PUSH_LOCK; /* size: 0x0004 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
    struct
    {
      /* 0x0000 */ unsigned char Type;
      /* 0x0001 */ unsigned char Signalling;
      /* 0x0002 */ unsigned char Size;
      /* 0x0003 */ unsigned char Reserved1;
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char TimerType;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
            /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
            /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
          }; /* bitfield */
          /* 0x0002 */ unsigned char Hand;
          union
          {
            /* 0x0003 */ unsigned char TimerMiscFlags;
            struct /* bitfield */
            {
              /* 0x0003 */ unsigned char Index : 1; /* bit position: 0 */
              /* 0x0003 */ unsigned char Processor : 5; /* bit position: 1 */
              /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
              /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
            }; /* bitfield */
          }; /* size: 0x0001 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char Timer2Type;
      union
      {
        /* 0x0001 */ unsigned char Timer2Flags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0001 */ unsigned char Timer2Inserted : 1; /* bit position: 0 */
            /* 0x0001 */ unsigned char Timer2Expiring : 1; /* bit position: 1 */
            /* 0x0001 */ unsigned char Timer2CancelPending : 1; /* bit position: 2 */
            /* 0x0001 */ unsigned char Timer2SetPending : 1; /* bit position: 3 */
            /* 0x0001 */ unsigned char Timer2Running : 1; /* bit position: 4 */
            /* 0x0001 */ unsigned char Timer2Disabled : 1; /* bit position: 5 */
            /* 0x0001 */ unsigned char Timer2ReservedFlags : 2; /* bit position: 6 */
          }; /* bitfield */
          /* 0x0002 */ unsigned char Timer2ComponentId;
          /* 0x0003 */ unsigned char Timer2RelativeId;
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char QueueType;
      union
      {
        /* 0x0001 */ unsigned char QueueControlFlags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0001 */ unsigned char Abandoned : 1; /* bit position: 0 */
            /* 0x0001 */ unsigned char DisableIncrement : 1; /* bit position: 1 */
            /* 0x0001 */ unsigned char QueueReservedControlFlags : 6; /* bit position: 2 */
          }; /* bitfield */
          /* 0x0002 */ unsigned char QueueSize;
          /* 0x0003 */ unsigned char QueueReserved;
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char ThreadType;
      /* 0x0001 */ unsigned char ThreadReserved;
      union
      {
        /* 0x0002 */ unsigned char ThreadControlFlags;
        struct
        {
          struct /* bitfield */
          {
            /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
            /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
            /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
            /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
            /* 0x0002 */ unsigned char Tagged : 1; /* bit position: 4 */
            /* 0x0002 */ unsigned char EnergyProfiling : 1; /* bit position: 5 */
            /* 0x0002 */ unsigned char Instrumented : 1; /* bit position: 6 */
            /* 0x0002 */ unsigned char ThreadReservedControlFlags : 1; /* bit position: 7 */
          }; /* bitfield */
          /* 0x0003 */ unsigned char DebugActive;
        }; /* size: 0x0002 */
      }; /* size: 0x0002 */
    }; /* size: 0x0004 */
    struct
    {
      /* 0x0000 */ unsigned char MutantType;
      /* 0x0001 */ unsigned char MutantSize;
      /* 0x0002 */ unsigned char DpcActive;
      /* 0x0003 */ unsigned char MutantReserved;
    }; /* size: 0x0004 */
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0010 */

typedef struct _SINGLE_LIST_ENTRY
{
  /* 0x0000 */ struct _SINGLE_LIST_ENTRY* Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY; /* size: 0x0004 */

typedef struct _KDPC
{
  union
  {
    /* 0x0000 */ unsigned long TargetInfoAsUlong;
    struct
    {
      /* 0x0000 */ unsigned char Type;
      /* 0x0001 */ unsigned char Importance;
      /* 0x0002 */ volatile unsigned short Number;
    }; /* size: 0x0004 */
  }; /* size: 0x0004 */
  /* 0x0004 */ struct _SINGLE_LIST_ENTRY DpcListEntry;
  /* 0x0008 */ unsigned long ProcessorHistory;
  /* 0x000c */ void* DeferredRoutine /* function */;
  /* 0x0010 */ void* DeferredContext;
  /* 0x0014 */ void* SystemArgument1;
  /* 0x0018 */ void* SystemArgument2;
  /* 0x001c */ void* DpcData;
} KDPC, *PKDPC; /* size: 0x0020 */

typedef union _ULARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ unsigned long HighPart;
    }; /* size: 0x0008 */
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ unsigned long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ unsigned __int64 QuadPart;
  }; /* size: 0x0008 */
} ULARGE_INTEGER, *PULARGE_INTEGER; /* size: 0x0008 */

typedef struct _KTIMER
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0010 */ union _ULARGE_INTEGER DueTime;
  /* 0x0018 */ struct _LIST_ENTRY TimerListEntry;
  /* 0x0020 */ struct _KDPC* Dpc;
  /* 0x0024 */ unsigned long Period;
} KTIMER, *PKTIMER; /* size: 0x0028 */

typedef struct _LAZY_WRITER
{
  /* 0x0000 */ struct _KDPC ScanDpc;
  /* 0x0020 */ struct _KTIMER ScanTimer;
  /* 0x0048 */ unsigned char ScanActive;
  /* 0x0049 */ unsigned char OtherWork;
  /* 0x004a */ unsigned char PendingTeardownScan;
  /* 0x004b */ unsigned char PendingPeriodicScan;
  /* 0x004c */ unsigned char PendingLowMemoryScan;
  /* 0x004d */ unsigned char PendingPowerScan;
  /* 0x004e */ unsigned char PendingCoalescingFlushScan;
  /* 0x004f */ char __PADDING__[1];
} LAZY_WRITER, *PLAZY_WRITER; /* size: 0x0050 */

typedef struct _DIRTY_PAGE_STATISTICS
{
  /* 0x0000 */ unsigned long DirtyPages;
  /* 0x0004 */ unsigned long DirtyPagesLastScan;
  /* 0x0008 */ unsigned long DirtyPagesScheduledLastScan;
} DIRTY_PAGE_STATISTICS, *PDIRTY_PAGE_STATISTICS; /* size: 0x000c */

typedef struct _DIRTY_PAGE_THRESHOLDS
{
  /* 0x0000 */ unsigned long DirtyPageThreshold;
  /* 0x0004 */ unsigned long DirtyPageThresholdTop;
  /* 0x0008 */ unsigned long DirtyPageThresholdBottom;
  /* 0x000c */ unsigned long DirtyPageTarget;
  /* 0x0010 */ unsigned __int64 AggregateAvailablePages;
  /* 0x0018 */ unsigned __int64 AggregateDirtyPages;
  /* 0x0020 */ unsigned long AvailableHistory;
  /* 0x0024 */ long __PADDING__[1];
} DIRTY_PAGE_THRESHOLDS, *PDIRTY_PAGE_THRESHOLDS; /* size: 0x0028 */

typedef union _LARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    }; /* size: 0x0008 */
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ __int64 QuadPart;
  }; /* size: 0x0008 */
} LARGE_INTEGER, *PLARGE_INTEGER; /* size: 0x0008 */

typedef struct _CC_PARTITION
{
  /* 0x0000 */ short NodeTypeCode;
  /* 0x0002 */ short NodeByteSize;
  /* 0x0040 */ unsigned long MasterLock;
  /* 0x0080 */ unsigned long WorkQueueLock;
  /* 0x0084 */ unsigned short PartitionID;
  /* 0x0088 */ struct _LIST_ENTRY PartitionLinks;
  /* 0x0090 */ struct _LIST_ENTRY CleanSharedCacheMapList;
  /* 0x0098 */ struct _LIST_ENTRY CleanSharedCacheMapWithLogHandleList;
  /* 0x00a0 */ struct _SHARED_CACHE_MAP_LIST_CURSOR DirtySharedCacheMapList;
  /* 0x00ac */ struct _SHARED_CACHE_MAP_LIST_CURSOR LazyWriterCursor;
  /* 0x00b8 */ struct _LIST_ENTRY DirtySharedCacheMapWithLogHandleList;
  /* 0x00c0 */ struct _EX_PUSH_LOCK ChangeSharedCacheMapFileLock;
  /* 0x00c4 */ unsigned long ConsecutiveWorklessLazyScanCount;
  /* 0x00c8 */ unsigned char ForcedDisableLazywriteScan;
  /* 0x00cc */ unsigned long NumberWorkerThreads;
  /* 0x00d0 */ unsigned long NumberActiveWorkerThreads;
  /* 0x00d4 */ struct _LIST_ENTRY IdleWorkerThreadList;
  /* 0x00dc */ struct _LIST_ENTRY FastTeardownWorkQueue;
  /* 0x00e4 */ struct _LIST_ENTRY ExpressWorkQueue;
  /* 0x00ec */ struct _LIST_ENTRY RegularWorkQueue;
  /* 0x00f4 */ struct _LIST_ENTRY PostTickWorkQueue;
  /* 0x00fc */ struct _LIST_ENTRY IdleExtraWriteBehindThreadList;
  /* 0x0104 */ unsigned long ActiveExtraWriteBehindThreads;
  /* 0x0108 */ unsigned long MaxExtraWriteBehindThreads;
  /* 0x010c */ unsigned char QueueThrottle;
  /* 0x0110 */ unsigned long PostTickWorkItemCount;
  /* 0x0114 */ unsigned long ThreadsActiveBeforeThrottle;
  /* 0x0118 */ unsigned long ExtraWBThreadsActiveBeforeThrottle;
  /* 0x011c */ unsigned long ExecutingWriteBehindWorkItems;
  /* 0x0120 */ unsigned long ExecutingHighPriorityWorkItem;
  /* 0x0124 */ struct _KEVENT LowMemoryEvent;
  /* 0x0134 */ struct _KEVENT PowerEvent;
  /* 0x0144 */ struct _KEVENT PeriodicEvent;
  /* 0x0154 */ struct _KEVENT WaitingForTeardownEvent;
  /* 0x0164 */ struct _KEVENT CoalescingFlushEvent;
  /* 0x0174 */ unsigned long PagesYetToWrite;
  /* 0x0178 */ struct _LAZY_WRITER LazyWriter;
  /* 0x01c8 */ struct _DIRTY_PAGE_STATISTICS DirtyPageStatistics;
  /* 0x01d8 */ struct _DIRTY_PAGE_THRESHOLDS DirtyPageThresholds;
  /* 0x0200 */ struct _WRITE_BEHIND_THROUGHPUT* ThroughputStats;
  /* 0x0204 */ long ThroughputTrend;
  /* 0x0208 */ unsigned __int64 AverageAvailablePages;
  /* 0x0210 */ unsigned __int64 AverageDirtyPages;
  /* 0x0218 */ unsigned __int64 PagesSkippedDueToHotSpot;
  /* 0x0220 */ union _LARGE_INTEGER PrevRegularQueueItemRunTime;
  /* 0x0228 */ union _LARGE_INTEGER PrevExtraWBThreadCheckTime;
  /* 0x0230 */ unsigned char AddExtraWriteBehindThreads;
  /* 0x0231 */ unsigned char RemoveExtraThreadPending;
  /* 0x0234 */ struct _LIST_ENTRY DeferredWrites;
  /* 0x0240 */ unsigned long DeferredWriteSpinLock;
  /* 0x0244 */ struct _LIST_ENTRY* IdleAsyncReadWorkerThreadList;
  /* 0x0248 */ unsigned long* NumberActiveAsyncReadWorkerThreads;
  /* 0x024c */ unsigned long* NumberActiveCompleteAsyncReadWorkItems;
  /* 0x0250 */ struct _LIST_ENTRY* AsyncReadWorkQueue;
  /* 0x0254 */ struct _LIST_ENTRY* AsyncReadCompletionWorkQueue;
  /* 0x0258 */ struct _KEVENT* NewAsyncReadRequestEvent;
  /* 0x025c */ struct _ASYNC_READ_THREAD_STATS* ReaderThreadsStats;
  /* 0x0260 */ struct _EX_PUSH_LOCK AsyncReadWorkQueueLock;
  /* 0x0264 */ long __PADDING__[7];
} CC_PARTITION, *PCC_PARTITION; /* size: 0x0280 */

