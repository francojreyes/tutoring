**Adaptive**: Best and worst case are different

**Stable**: Preserve order of items with same value

| Sort           | Best case(s) | Worst case(s)  | Adpative? | Stable? |
| ---            | ---          | ---            | ---       | ---     |
|**bubble**      |  sorted O(n)            |  reverse/almost sorted O(n^2)          | Yes           |  Yes       |
|**insertion**   |  sorted/almost sorted O(n)            |  reverse O(n^2)             |  Yes         |    Yes     |
|**select**      |   all O(n^2)           |   all O(n^2)             |  No         |    No     |
|**merge**       |   all O(nlogn)            |   all O(nlogn)        |  No       | Yes |
|**naive quick** |   O(nlogn)           |   sorted/reverse O(n^2)             |   Yes       |    No    |
|**mo3 quick**   |   O(nlogn)           |   all same O(n^2)            |      Yes     |    No      |
|**random quick**|    O(nlogn)          |     all same O(n^2)            |    Yes        |   No      |
