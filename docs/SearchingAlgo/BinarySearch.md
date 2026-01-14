# Binary Search

## Link
https://www.geeksforgeeks.org/dsa/binary-search/

## Condition
- Sorted array (ascending)

## Algorithm (step-by-step)
1. Initialize low = 0, high = n - 1
2. While low <= high:
   - mid = floor((low + high) / 2)
   - If A[mid] == key: return mid (found)
   - Else if key < A[mid]: high = mid - 1
   - Else: low = mid + 1
3. If loop ends, return -1 (not found)

## Plantuml flow
  @startuml
' Optional styling
skinparam activityBackgroundColor #FEF3C7
skinparam activityBorderColor #92400E
skinparam activityDiamondBackgroundColor #DBEAFE
skinparam activityDiamondBorderColor #1E3A8A

start
:Initialize low = 0; high = n - 1;
while (low <= high?) is (yes)
  :mid = (low + high) // 2;
  if (A[mid] == key?) then (yes)
    :Return mid;
    stop
  else (no)
    if (key < A[mid]?) then (yes)
      :high = mid - 1;
    else (no)
      :low = mid + 1;
    endif
  endif
endwhile (no)
:Return -1;
stop
@enduml

## Binary Search (flowchart)

```mermaid
flowchart TD
  Start([Start]) --> Input[/Get sorted array & key/]
  Input --> Check{low <= high?}
  Check -- No --> NotFound["Return - 1"]
  Check -- Yes --> Calc["mid = (low + high) // 2"]
  Calc --> Compare{"A[mid] == key?"}
  Compare -- Yes --> Found["Return index"]
  Compare -- No --> Less{"key < A[mid]?"}
  Less -- Yes --> SetHigh["high = mid - 1"] --> Check
  Less -- No --> SetLow["low = mid + 1"] --> Check

  classDef startend fill:#A7F3D0,stroke:#065F46,color:#065F46;
  classDef process  fill:#FEF3C7,stroke:#92400E,color:#92400E;
  classDef decision fill:#DBEAFE,stroke:#1E3A8A,color:#1E3A8A;
  classDef endNode  fill:#FECACA,stroke:#991B1B,color:#991B1B;

  class Start,NotFound,Found startend;
  class Input,Calc,SetHigh,SetLow process;
  class Check,Compare,Less decision;
  class Found,NotFound endNode;