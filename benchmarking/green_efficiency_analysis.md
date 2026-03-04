#Green Efficiency Analysis

##Measurement Methodology

To ensure scientific rigor, all programs were compiled using the gcc compiler with strict flags (-Wall -Werror -Wextra -pedantic -std=gnu89). Performance was measured using the clock() function from the <time.h> library, which captures the CPU time consumed by the process. Each experiment was repeated three consecutive times to account for system variability. The time in clock ticks was converted to seconds by dividing by the CLOCKS_PER_SEC constant, providing a standardized metric for comparison.

##Observed Performance Differences

The data reveals a massive gap between optimized and non-optimized code. In the second experiment, the Naive algorithm averaged approximately 0.578 seconds, while the Single-pass algorithm averaged a mere 0.000021 seconds.
- Calculation: The Naive version is roughly 27,500 times slower than the Single-pass version.
This illustrates the impact of algorithmic complexity: moving from a quadratic $O(n^2)$ approach to a linear $O(n)$ approach drastically reduces the computational burden for the same result (a checksum of 625025000). In the third experiment, instrumentation showed that PROCESS_DATA and BUILD_DATA are the most time-consuming phases, while REDUCE remains the most efficient.

##Relation Between Runtime and Energy Consumption

In computing, execution time serves as a direct proxy for energy consumption. A CPU remains in a high-power state as long as it is processing instructions. By running the Naive algorithm, the processor stays active 27,000 times longer than necessary, dissipating energy as heat for a task that could have been completed in microseconds. Efficient code is therefore "green" code; optimizing algorithms is not just about speed, it is a primary method for reducing the carbon footprint of digital infrastructure at scale.

##Limitations of the Experiment

The primary limitation is system noise. In the Baseline Loop (Task 0), the third run (0.154s) was nearly double the first run (0.080s), despite the code being identical. This shows that background OS processes interfere with measurements. Additionally, clock() measures CPU time but ignores other energy-intensive components like RAM or disk I/O. Finally, the experiment does not measure real-time power draw (Watts), meaning we can only infer energy savings from time reductions rather than observing them directly.

##Practical Engineering Takeaway

The most important lesson is that algorithmic choice outweighs hardware power. No amount of CPU overclocking can compensate for an inefficient $O(n^2)$ complexity when an $O(n)$ alternative exists. As engineers, we must use instrumentation and benchmarking not only to fix bugs but to validate the sustainability of our code. Measurement discipline allows us to move from guessing to evidence-based reasoning, ensuring that our software is both performant and environmentally responsible.