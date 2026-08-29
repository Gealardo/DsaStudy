
                 ┌────────────────────┐
                 │  TAKE / DON'T TAKE │
                 └─────────┬──────────┘
                           │
                           ▼
                    WHAT IS ASKED?
                           │
          ┌────────────────┼────────────────┐
          ↓                ↓                ↓
      MAXIMUM?          POSSIBLE?(rem==0)   COUNT? (i<0) rem==0 return 1 else 0
          │                │                │
         max               OR                +
          │                │                │
          ↓                ↓                ↓
     #1 KNAPSACK       #2 SUBSET SUM     #4 COUNT SUBSETS
                           │                │
                           │                │
                           ▼                ▼
                    #3 EQUAL PARTITION   #5 TARGET SUM
                                         │
                                         ↓
                              COUNT PARTITIONS
                                  WITH DIFF D
