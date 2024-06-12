**Adaptive**: Takes advantage of the 'sortedness' of the input - it runs faster when sorted

**Stable**: Preserve order of items with same value

**Almost sorted**: Smallest element moved to back e.g. 2 3 4 5 1

sorted =1, random=2 => sorted = 4, random = 8

| Sort             | Sorted | Reverse | Random | Other               | Adaptive? | Stable?                     |
|------------------|--------|---------|--------|---------------------|-----------|-----------------------------|
| **bubble**       | n      | n^2     | n^2    | almost sorted - n^2 | Yes       | Yes - don't swap equal      |
| **insertion**    | n      | n^2     | n^2    | almost sorted - n   | Yes       | Yes - don't swap equal      |
| **select**       | n^2    | n^2     | n^2    |                     | No        | No                          |
| **merge**        | nlogn  | nlogn   | nlogn  |                     | No        | Yes - merge from left first |
| **naive quick**  | n^2    | n^2     | nlogn  |                     | No        | No                          |
| **mo3 quick**    | nlogn  | nlogn   | nlogn  |                     | No        | Yes                         |
