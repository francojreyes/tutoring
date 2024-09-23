**Adaptive**: Takes advantage of the 'sortedness' of the input - it runs faster when sorted

**Stable**: Preserve order of items with same value

| Sort            | Sorted | Reverse | Random | Move first to back | Adaptive? | Stable? |
|-----------------|--------|---------|--------|--------------------|-----------|---------|
| **bubble**      | n      | n^2     | n^2    | n^2                | y         | y       |
| **insertion**   | n      | n^2     | n^2    | n                  | y         | y       |
| **select**      | n      | n       | n      |                    | n         | n       |
| **merge**       | nlogn  | nlogn   | nlogn  |                    | n         | y       |
| **naive quick** | n^2    | n^2     | nlogn  |                    | n         | n       |
| **mo3 quick**   | nlogn  | nlogn   | nlogn  |                    | n         | n       |
