**Adaptive**: Takes advantage of the 'sortedness' of the input - it runs faster when sorted

**Stable**: Preserve order of items with same value

| Sort             | Sorted | Reverse | Random | Other                                                           | Adaptive? | Stable?                   |
|------------------|--------|---------|--------|-----------------------------------------------------------------|-----------|---------------------------|
| **bubble**       | n      | n^2     | n^2    | almost sorted - n^2                                             | Yes       | Yes - if don't swap equal |
| **insertion**    | n      | n^2     | n^2    | almost sorted - n                                               | Yes       | Yes - if don't swap equal |
| **select**       | n^2    | n^2     | n^2    |                                                                 | No        | No                        |
| **merge**        | nlogn  | nlogn   | nlogn  |                                                                 | No        | Yes - if prio left half   |
| **naive quick**  | n^2    | n^2     | nlogn  |                                                                 | No        | No                        |
| **mo3 quick**    | nlogn  | nlogn   | nlogn  |                                                                 | No        | No                        |
| **random quick** | nlogn  | nlogn   | nlogn  | non-deterministic - different results if you run multiple times | No        | No                        |
