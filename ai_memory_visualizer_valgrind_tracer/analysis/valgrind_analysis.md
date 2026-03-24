## 1. heap_example.c - Memory Leak
- **Error detected:** 6 bytes "definitely lost".
- **Origin:** Allocated at `heap_example.c:21` (inside `person_new`).
- **Reason:** The function `person_free_partial` only frees the `Person` struct but fails to free the `name` string member. Since the name was allocated independently on the heap, it remains there with no reference left to it.
- **AI Correction:** An AI might say the memory is automatically freed at the end of `main`. My Valgrind trace proves this is false: "definitely lost" means the memory is still occupied when the program exits.

## 2. aliasing_example.c - Use-After-Free
- **Error detected:** Compiler Error (`-Werror=use-after-free`).
- **Origin:** `main` at `aliasing_example.c:45`.
- **Reason:** Pointer `b` is an alias of `a`. After `free(a)`, the memory block is invalid. Accessing `b[3]` is a "Use-After-Free" violation.
- **Observation:** In this case, the compiler was so efficient that it caught the memory misuse before the program could even be tested with Valgrind.

## 3. crash_example.c - Segmentation Fault (NULL Dereference)

### Valgrind Output Analysis
- **Error Type:** `Invalid write of size 4`.
- **Address:** `0x0` (NULL).
- **Signal:** `Process terminating with default action of signal 11 (SIGSEGV)`.
- **Location:** `main` at `crash_example.c:32`.

### Technical Explanation
The program crashes because it attempts to write the value `42` to the memory address `0x0`.
1. The function `allocate_numbers(0)` returns `NULL` because the input `n` is zero.
2. In `main`, the pointer `nums` is assigned this `NULL` value.
3. At line 32, `nums[0] = 42;` attempts to access memory at the base address of the pointer. Since the address is `0x0` (a protected region of memory not mapped to the process), the CPU triggers a Segmentation Fault.

### AI Correction
> **AI Claim:** "The crash is due to a stack overflow because the program requested too much memory."
> **My Correction:** This is **incorrect**. Valgrind clearly states: "Access not within mapped region at address 0x0". This is not a stack size issue, but a logic error where a pointer was used without checking if it was `NULL` first. The stack was at its default 8MB size and was nowhere near being full.
