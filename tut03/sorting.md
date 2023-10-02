**Adaptive**: Takes advantage of the 'sortedness' of the input - it runs faster when sorted

**Stable**: Preserve order of items with same value

| Sort            | Sorted   | Reverse  | Random    | Other     | Adaptive? | Stable?   |
| ---             |   ---   |     ---     |     ---      |      ---     |      ---     |     ---      |
|**bubble**       |     O(n)     |   O(n^2)       |    O(n^2)       | almost sorted O(n^2)         |    Yes       |    Yes - if dont swap equal       |
|**insertion**    |    O(n)      |  O(n^2)        |     O(n^2)      | almost sorted O(n)          |    Yes       |     Yes - if dont swap equal      |
|**select**       |    O(n^2)      |    O(n^2)      |    O(n^2)       |           |   No        |   No        |
|**merge**        |    O(nlogn)      |   O(nlogn)       |   O(nlogn)        |           |    No       |  Yes - if prioritise left         |
|**naive quick**  |          |          |           |           |           |           |
|**mo3 quick**    |          |          |           |           |           |           |
|**random quick** |          |          |           |           |           |           |
