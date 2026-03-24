# Memory Analysis Report

## 1. stack_example.c: Recursion and Stack Frames

### Memory Layout & Behavior
- **Stack Frames:** Each call to `walk_stack()` pushes a new frame onto the stack. This frame contains the local variables `marker`, `local_int`, and `local_buf`.
- **Stack Growth:** By observing the output of `&marker`, we can see that the memory addresses decrease as `depth` increases. This confirms that the stack grows downwards in memory on this system.
- **Automatic Lifetime:** When a function reaches its "exit" point, its stack frame is automatically deallocated. The variables inside are no longer valid.

### Heap Memory
- **Analysis:** This program does not use the heap. There are no calls to `malloc()`, `calloc()`, or `realloc()`. All memory management is handled automatically by the CPU via the stack pointer.

### Critical AI Review (Correction of Errors)
> **AI Hypothesis:** "The variable `local_int` is stored in the Global Data Segment because it is inside a `static` function, meaning its value is preserved between recursive calls."
>
> **Correction:** This is **incorrect**. The `static` keyword on a function (internal linkage) only restricts the function's scope to the current file. It has no effect on the storage class of variables defined *inside* it. `local_int` is an `auto` variable (by default) and resides on the **Stack**. My manual trace of `&local_int` shows that a new, distinct address is created for every recursive call, proving it is not a global/static variable.

## 2. heap_example.c: Dynamic Allocation and Memory Leaks

### Memory Layout & Behavior
- **Heap Allocation:** This program uses `malloc()` to allocate memory for a `Person` struct and a separate block for the `name` string. These reside in the **Heap**.
- **Independant Blocks:** The structure and the string are two distinct blocks of memory on the heap. The pointer `p->name` simply stores the address of the second block.
- **The Memory Leak:** While `bob` is correctly freed (both the name and the struct), `alice` is freed using `person_free_partial()`. This function only frees the struct, leaving the string "Alice" allocated in memory with no pointer left to reach it.

### Critical AI Review (Correction of Errors)
> **AI Hypothesis:** "Freeing the structure `Person` automatically frees the `name` pointer inside it because they are part of the same object."
>
> **Correction:** This is **incorrect**. In C, `free()` only deallocates the specific block of memory pointed to by the argument. It does not look inside the block for other pointers to free. Since `name` was allocated with its own `malloc()`, it requires its own `free()`. My analysis confirms that `person_free_partial` causes a **memory leak** of 6 bytes (the length of "Alice" + null terminator).

---

## 3. aliasing_example.c: Aliasing and Use-After-Free

### Memory Layout & Behavior
- **Pointer Aliasing:** After the assignment `b = a;`, both pointers are aliases. They store the same hexadecimal address pointing to a single allocation on the **Heap**.
- **Memory Release:** When `free(a)` is executed, the heap manager deallocates the memory block. The pointer `a` (and its alias `b`) now point to "unallocated" memory.
- **Dangling Pointer:** The variable `b` becomes a dangling pointer. It still holds the old address, but accessing it is **Undefined Behavior**.
- **Build Failure:** The compiler (with `-Werror`) prevents the execution because it detects that `b` is used after the memory it references has been freed via `a`.

### Critical AI Review (Correction of Errors)
> **AI Hypothesis:** "The memory remains valid for pointer `b` because `free()` was only called on pointer `a`, and `b` is an independent copy."
>
> **Correction:** This is **false**. In C, pointers store addresses, not the data itself. Freeing the memory via any alias invalidates all pointers to that address. `b` does not own a separate copy of the integers; it simply "pointed to" the same block as `a`. My manual trace confirms that after `free(a)`, any access through `b` results in a **Use-After-Free** bug, which is exactly why the compiler blocked the build.

---

## 4. crash_example.c: Deterministic NULL Dereference

### Memory Layout & Behavior
- **Logic Flow:** The variable `n` is initialized to `0`. When `allocate_numbers(0)` is called, the function hits its safety check (`if (n <= 0)`) and explicitly returns `NULL`.
- **The Pointer State:** In `main`, the pointer `nums` is now equal to `0x0` (NULL).
- **The Crash:** The program attempts to perform `nums[0] = 42;`. This is a **NULL pointer dereference**. Since address `0` is reserved by the Operating System and is never mapped to a valid physical memory location for the process, the CPU triggers a hardware exception.
- **Outcome:** The OS sends a `SIGSEGV` signal to the process, resulting in a **Segmentation Fault**.

### Critical AI Review (Correction of Errors)
> **AI Hypothesis:** "The crash occurs because the system ran out of RAM (memory exhaustion) and malloc failed to allocate space for 0 integers."
>
> **Correction:** This is **incorrect**. The program never even attempted to call `malloc()` because the internal logic of `allocate_numbers` returned `NULL` immediately due to `n = 0`. The crash is not a resource issue (lack of RAM) but a **logic error** (lack of a NULL check). My analysis confirms that the programmer failed to check if `nums` was valid before dereferencing it, which is the direct and deterministic cause of the segmentation fault.
