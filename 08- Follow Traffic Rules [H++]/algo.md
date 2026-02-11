# Follow Traffic Rules

**Problem Reference:** [Codeforces 5D - Follow Traffic Rules](https://codeforces.com/contest/5/problem/D)  
**Difficulty:** H++  
**Algorithm:** Physics (kinematics) — two-phase optimization  
**Complexity:** $O(1)$ Time | $O(1)$ Space  

## 1. Problem Definition

You drive from position $0$ to position $L$ (total road length) with:

- Constant **acceleration** $a$
- **Maximum speed** $V_{\max}$
- A **speed camera** at position $d$: you must have speed $\le w$ when you pass it

Find the **minimum total time** to travel the full distance while satisfying the camera constraint.

**Input:** $a$, $V_{\max}$, $L$, $d$, $w$ (all positive reals)

## 2. Key Insight

The journey splits into two independent phases:

1. **Phase 1 (start → camera):** Minimize time to cover distance $d$ and **arrive at the camera with speed exactly $\le w$**. Optimal strategy is accelerate → (optionally cruise) → brake to $w$ if the limit matters.
2. **Phase 2 (camera → finish):** Minimize time over remaining distance $L - d$, **starting at speed** (whatever we had at the camera, at most $w$) and accelerating as much as possible (no more constraints).

So the only coupling is: Phase 1 gives us a **final speed** at the camera; Phase 2 uses that as **initial speed**.

## 3. Phase 1: Start → Camera

- If **$w \ge V_{\max}$** or we can’t even reach $w$ within distance $d$ (i.e. $w^2/(2a) \ge d$), the limit is irrelevant. Then we use the standard “accelerate then possibly cruise” profile over distance $d$ and compute time (and exit speed) from kinematics.
- Otherwise we **must** slow to $w$ at the camera. The optimal strategy is:
  - Accelerate to some **peak speed** $V_{\text{peak}}$ (possibly capped by $V_{\max}$),
  - Then decelerate to **exactly** $w$ at the camera.

**Derivation of $V_{\text{peak}}$ when not capped:**  
We travel total distance $d$ and end at speed $w$. Under constant $a$ (accel then decel), the distance covered is  
$s_{\text{accel}} = V_{\text{peak}}^2/(2a)$ and  
$s_{\text{decel}} = (V_{\text{peak}}^2 - w^2)/(2a)$.  
So  
$d = s_{\text{accel}} + s_{\text{decel}} = (2 V_{\text{peak}}^2 - w^2)/(2a)$,  
giving  
$V_{\text{peak}}^2 = (2ad + w^2)/2$, i.e.  
$V_{\text{peak}} = \sqrt{(2ad + w^2)/2}$.

- If $V_{\text{peak}} \le V_{\max}$: use this peak; time = $V_{\text{peak}}/a + (V_{\text{peak}} - w)/a$.
- If $V_{\text{peak}} > V_{\max}$: cap at $V_{\max}$ — accelerate to $V_{\max}$, cruise for the middle segment, then brake to $w$ at the camera. Times and distances follow from $v^2 = v_0^2 + 2as$ and $s = v_0 t + \frac{1}{2}at^2$.

Phase 1 yields **total time** and **speed at camera** (either $V_{\max}$ when limit doesn’t matter, or $w$ when it does).

## 4. Phase 2: Camera → Finish

Remaining distance: $L - d$. Initial speed: $v_0$ (output of Phase 1).

- Compute time and distance to reach $V_{\max}$ from $v_0$ with acceleration $a$.
- If that distance $\ge L - d$: we never reach $V_{\max}$; solve  
  $L - d = v_0 t + \frac{1}{2} a t^2$ for $t$ (positive root).
- Else: time = (time to $V_{\max}$) + (remaining distance) / $V_{\max}$.

Add this time to the Phase 1 time and output.

## 5. Complexity

All operations are constant-time formulas; no loops or recursion.  
**Time:** $O(1)$  
**Space:** $O(1)$  

## 6. Conclusion

The H++ difficulty comes from: (1) correctly splitting into two phases, (2) deriving the optimal peak speed when the camera limit applies, (3) handling all cases (limit irrelevant, peak below/above $V_{\max}$, and Phase 2 with/without reaching $V_{\max}$) without off-by-one or sign errors. Careful use of kinematics ($v^2 = v_0^2 + 2as$, $s = v_0 t + \frac{1}{2}at^2$) and consistent units (time, distance, speed) keeps the implementation manageable.

This problem politely invites you in… and then traps you in a physics exam you didn’t sign up for. If you don’t stay laser-focused and respect the math, you’ll wander in circles wondering why your car needs 14 hours to go 5 km. Precision isn’t optional here — it’s survival. 😂😂

*Written by: George Yanni*
