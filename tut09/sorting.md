**Adaptive**: Best and worst case are different

**Stable**: Preserve order of items with same value

| Sort            | Sorted   | Reverse  | Random    | Other     | Adaptive? | Stable?   |
| ---             | ---      | ---      | ---       |  ---      |  ---      |   ----    |
|**bubble**       |    n      |   n^2       |   n^2        |     almost sorted (2,3..1) - n^2      |    yes       |   yes - if dont swap ==        |
|**insertion**    |    n      |   n^2       |     n^2      |    almost sorted (2,3..1) - n       |    yes      |   yes - if dont swap ==        |
|**select**       |    n^2      |    n^2      |    n^2      |           |   no        |   no        |
|**merge**        |     nlogn     |   nlogn       |     nlogn      |           |  no         |   yes - if prio left when ==        |
|**naive quick**  |    n^2      |    n^2      |      nlogn     |           |      yes     |     no      |
|**mo3 quick**    |   nlogn       |  nlogn        |    nlogn       |           |    no       |   no        |
|**random quick** |    nlogn      |    nlogn      |    nlogn       |   non-deterministic (with equal elems)        |    no       |   no        |
