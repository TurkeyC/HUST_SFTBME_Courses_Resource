# Chapter10 函数列与函数项级数

## §1. 基本概念

### 1. 函数列

##### **Def**:
设函数列 $\{f_n(x)\}$ 定义在集合 $X$ 上，若对每个 $x \in X$，数列 $\{f_n(x)\}$ 收敛，则称 $\{f_n(x)\}$ 在 $X$ 上逐点收敛。记其极限函数为
$$
S(x) = \lim_{n \to \infty} f_n(x), \quad \forall x \in X
$$

### 2. 函数列与函数项级数

##### **Def**:
设 $f_n(x)$, $n=1,2,\cdots$ 在集合 $X$ 上有定义，则称 $\{f_n(x)\}$ 为 $X$ 上的函数列。

对 $x_0 \in X$，若 $\{f_n(x_0)\}$ 收敛，则称 $x_0$ 为函数列 $\{f_n(x)\}$ 的一个收敛点。将 $\{f_n(x)\}$ 在 $X$ 上所有收敛点构成的集合 $I$ 称为收敛域。

记
$$
S(x) = \lim_{n \to \infty} f_n(x), \quad \forall x \in I
$$
称为 $\{f_n(x)\}$ 的极限函数。

###### **Example**:
设 $f_n(x) = n e^{-n x}$, $n=1,2,\cdots$, $x \in \mathbb{R}$，求 $\{f_n(x)\}$ 的收敛域与极限函数。

**Solution**:
当 $x \leq 0$ 时，$n e^{-n x} \geq n$，故 $f_n(x)$ 发散；
当 $x > 0$ 时，$\lim_{n \to \infty} n e^{-n x} = 0$，故 $f_n(x)$ 收敛。
因此，收敛域 $I = (0, +\infty)$，极限函数 $S(x) = 0$。

##### **Def**:
设 $u_1(x), u_2(x), \cdots, u_n(x), \cdots$ 在 $X$ 上有定义，称
$$
u_1(x) + u_2(x) + \cdots + u_n(x) + \cdots
$$
为 $X$ 上的函数项级数。

称 $S_n(x) = \sum_{k=1}^n u_k(x)$ 为部分和函数列。

对 $x_0 \in X$，若 $\lim_{n \to \infty} S_n(x_0)$ 存在，则称 $x_0$ 为 $\sum_{n=1}^\infty u_n(x)$ 的收敛点。所有收敛点构成的集合 $I$ 称为收敛域。

$\forall x \in I$，记 $S(x) = \sum_{n=1}^\infty u_n(x)$ 为和函数。

###### **Example**: 求 $\sum_{n=1}^\infty e^{-n x}$ 的收敛域以及和函数

**Solution**:
当 $x \leq 0$ 时，$e^{-n x} \geq 1$，故 $\sum_{n=1}^\infty e^{-n x}$ 发散；
当 $x > 0$ 时，$S_n(x) = \sum_{n=1}^N e^{-n x} = e^{-x} \frac{1 - e^{-N x}}{1 - e^{-x}}$，$\lim_{n \to \infty} S_n(x) = \frac{1}{e^x - 1}$。

故收敛域 $x \in (0, +\infty)$。

###### **Example**: 求 $\sum_{n=1}^\infty \frac{x^n}{1 + x^n}$ 的收敛域

**Solution**:
当 $|x| < 1$ 时，$\left|\frac{x^n}{1 + x^n}\right| < |x|^n$，由 $\sum_{n=1}^\infty |x|^n$ 收敛，故 $\sum_{n=1}^\infty \frac{x^n}{1 + x^n}$ 收敛；
当 $|x| > 1$ 时，由 $\left|\frac{x^n}{1 + x^n}\right| < \left|\frac{1}{x}\right|^n$，由于 $\sum_{n=1}^\infty \left|\frac{1}{x}\right|^n$ 收敛，故 $\sum_{n=1}^\infty \frac{x^n}{1 + x^n}$ 收敛；
当 $|x| = 1$ 时，代入知发散。

故收敛域 $x \in (-\infty, -1) \cup (-1, 1) \cup (1, +\infty)$。

### 3. 性质

**Cauchy收敛准则**:
1. $x$ 为 $\{f_n(x)\}$ 的收敛点 $\Leftrightarrow \forall \varepsilon > 0$，$\exists N$，$n, m > N$ 时，$|f_n(x) - f_m(x)| < \varepsilon$
2. $x$ 为 $\sum_{n=1}^\infty u_n(x)$ 的收敛点 $\Leftrightarrow \forall \varepsilon > 0$，$\exists N$，$n > m > N$ 时，$\left|\sum_{k=m+1}^n u_k(x)\right| < \varepsilon$

**绝对收敛**:
设 $\{a_n(x)\}, \{b_n(x)\}$ 为函数列，满足 $|a_n(x)| \leq |b_n(x)|$ 单调递减
1. 若 $\sum b_n(x)$ 收敛，则 $\sum a_n(x)$ 收敛
2. 若 $\sum a_n(x)$ 发散，则 $\sum a_n(x)b_n(x)$ 收敛

**比较判别法**:
设 $\{a_n(x)\}, \{b_n(x)\}$ 为函数列，满足 $|a_n(x)| \leq |b_n(x)|$ 单调递增至 $0$
1. 若 $\sum b_n(x)$ 收敛，则 $\sum a_n(x)$ 收敛
2. 若 $\sum a_n(x)$ 发散，则 $\sum a_n(x)b_n(x)$ 收敛

### 4. 4个有关分析性质的例子

###### **Example 1**: 设 $f_n(x) = x^n, x \in [0, 1]$

显然 $f_n(x) \in C[0, 1]$

$\forall \delta \in (0, 1]$

$S_n(x) = \lim_{n \to \infty} f_n(x) = \begin{cases} 
0, & x \in [0, 1) \\
1, & x = 1 
\end{cases} \notin [0, 1]$

发现 $\lim_{n \to \infty} (\lim_{x \to 0} f_n(x)) \neq \lim_{x \to 0} (\lim_{n \to \infty} f_n(x))$

###### **Example 2**: 设 $f_n(x) = 2nxe^{-nx}, x \in [0, 1]$

求 $\int_0^1 \lim_{n \to \infty} f_n(x) dx$ 及 $\lim_{n \to \infty} \int_0^1 f_n(x) dx$

**Solution**: 发现前者积分0，后者为1

## §2. 一致收敛

### 1. 引例

设 $f_n(x) = \begin{cases} 
n x^{n-1}, & x \in [0, 1) \\
0, & x = 1 
\end{cases}$

1. $\forall x \in [0, 1], f_n(x) \to 0 \quad (n \to \infty)$ 记作 $f(x)$
2. $\int_0^1 f_n(x) dx = 1 \to 1 \quad (n \to \infty)$
3. $\int_0^1 f(x) dx = 0$

故此时 $\lim_{n \to \infty} \int_0^1 f_n(x) dx \neq \int_0^1 \lim_{n \to \infty} f_n(x) dx$

为了使二者相等

则要 $\forall \varepsilon, \exists M, n > M$ 时，$\left|\int_0^1 f_n(x) dx - \int_0^1 f(x) dx\right| < \varepsilon$

又：$\left|\int_0^1 (f_n(x) - f(x)) dx\right| \leq \int_0^1 |f_n(x) - f(x)| dx$

故要：$\forall \varepsilon, \exists N, n > N$ 时对 $\forall x \in I$，有 $|f_n(x) - f(x)| < \varepsilon$

### 2. 一致收敛（只是积分极限与极限积分的充分条件）

##### 1) **Def**: 
设集合 $I$ 上有函数列 $\{f_n(x)\}$ 及 $f(x)$，若 $\forall \varepsilon > 0$，存在不依赖于 $x$ 的 $N$，当 $n > N$ 时，$|f_n(x) - f(x)| < \varepsilon \quad (\forall x \in I)$。

则称 $\{f_n(x)\}$ 一致收敛于 $f(x)$

**Remarks**:
1. 一致收敛一定是逐点收敛
2. 几何解释
3. 一致收敛与所考虑的区间 $I$ 密切相关

##### 2) Def: 函数项的一致收敛

设函数项级数 $\sum_{n=1}^\infty u_n(x)$ 的部分和数列 $\{S_n(x)\}$ 在区间 $I$ 上一致收敛到 $S(x)$，则称该级数在 $I$ 上一致收敛到 $S(x)$。即对于任意的 $\varepsilon > 0$，存在正整数 $N$，当 $n > N$ 时，对一切 $x \in I$，都有 $|S_n(x) - S(x)| < \varepsilon$。

###### **Example:** 证明 $S_n(x) = \frac{x}{1 + n^2 x^2}$ 在 $\mathbb{R}$ 上一致收敛。

**Proof:** 对于任意的 $x \in \mathbb{R}$，

$$
\lim_{n \to \infty} S_n(x) = \lim_{n \to \infty} \frac{x}{1 + n^2 x^2} = 0 \quad (\text{记作 } S(x))
$$

对于任意的 $\varepsilon > 0$，取 $N = \left[\frac{1}{2\varepsilon}\right] + 1$，当 $n > N$ 时，有

$$
|S_n(x) - S(x)| = \left|\frac{x}{1 + n^2 x^2}\right| \leq \frac{|x|}{n^2 x^2} = \frac{1}{n^2 |x|} \leq \frac{1}{n^2 \cdot \frac{1}{n}} = \frac{1}{n} < \varepsilon
$$

这里利用了当 $|x| \geq \frac{1}{n}$ 时，$\frac{1}{n^2 |x|} \leq \frac{1}{n^2 \cdot \frac{1}{n}} = \frac{1}{n}$；当 $|x| < \frac{1}{n}$ 时，$\frac{|x|}{1 + n^2 x^2} < \frac{1}{n}$。

###### Example: 设 $S_n(x) = \frac{n x}{1 + n^2 x}$

1. 讨论在 $[\delta, 1]$，$0 < \delta < 1$ 上的一致收敛性。

2. 讨论在 $(0, 1]$ 上的一致收敛性。

**Solution:** 首先，对于任意 $x \in [\delta, 1]$，有 $\lim_{n \to \infty} S_n(x) = \lim_{n \to \infty} \frac{n x}{1 + n^2 x} = 0$（记作 $S(x)$）。

1. 对于任意的 $\varepsilon > 0$，取 $N = \left[\frac{1}{\delta \varepsilon}\right] + 1$，当 $n > N$ 时，有

$$
|S_n(x) - S(x)| = \left|\frac{n x}{1 + n^2 x}\right| \leq \frac{n x}{n^2 x^2} = \frac{1}{n x} \leq \frac{1}{n \delta} < \varepsilon \quad (\forall x \in [\delta, 1])
$$

2. 当 $0 < \varepsilon < \frac{1}{2}$，取 $x = \frac{1}{n}$，则

$$
|S_n(x) - S(x)| = \left|\frac{n \cdot \frac{1}{n}}{1 + n^2 \cdot \frac{1}{n^2}}\right| = \frac{1}{2} \geq \varepsilon
$$

因此，$S_n(x)$ 在 $(0, 1]$ 上不一致收敛于 $S(x) = 0$。

### 3. 判别法

#### 1) 魏尔斯特拉斯判别法

**Theorem:** 设 $\{S_n\}$ 在 $I$ 上一致收敛于 $S(x)$，且存在收敛的正项级数 $\sum a_n$，使得对于一切 $x \in I$ 和 $n \geq 1$，有 $|S_n(x) - S_{n-1}(x)| \leq a_n$，则 $\{S_n\}$ 在 $I$ 上一致收敛。

#### 2) Cauchy收敛准则

**Theorem:** 函数列 $\{S_n\}$ 在 $I$ 上一致收敛的充要条件是：对于任意的 $\varepsilon > 0$，存在正整数 $N$，当 $m, n > N$ 时，对一切 $x \in I$，都有 $|S_n(x) - S_m(x)| < \varepsilon$。

### 3. 判别法

#### 1) 等价刻画

#### **Theorem**:  
$\{S_n\}$  在  $I$  上一致收敛于  $S_0$ ,

当且仅当  $\forall \varepsilon > 0$ ,  $\exists N$ ,  $n > N$  时, s.t


 $$
\sup_{n \geq 2} |S_n(n) - S_{n-1}| < \varepsilon \quad \left( \sup_{n \geq 2} \left| \sum_{k=n}^{\infty} u_k(n) \right| < \varepsilon \right)
$$ 

#### 2) Cauchy 收敛准则

#### **Theorem**:  
$\{S_n\}$  在  $I$  上一致收敛，

当且仅当  $\forall \varepsilon > 0$ ,  $\exists N$ ,  $n > m > N$  时, s.t.


 $$
|S_n(n) - S_m(n)| < \varepsilon, \forall x \in I
$$ 

等价于： $\left| \sum_{k=n}^{\infty} u_k(n) \right| < \varepsilon, \forall x \in I$  
等价于： $\sup_{x \in I} \left| \sum_{k=n}^{\infty} u_k(n) \right| < \varepsilon$ 

> **Remark**: 若  $\sum_{n=1}^{\infty} u_n(x)$  在  $I$  上一致收敛
> 
> 则  $\forall \varepsilon > 0$ ,  $\exists N$ ,  $n > N$  时,
> 
> 
>$$\sup_{x \in I} |u_n(n)| < \varepsilon$$ 
> 
> ( $u_n(x)$  在  $I$  上一致收敛于 0 )

#### 3) Weierstrass (M-判别法)

#### **Theorem**: 
设  $\sum_{n=1}^{\infty} u_n(x)$  在  $I$  上满足：

 $$ |u_n(x)| \leq a_n, \forall x \in I $$ 

且  $\sum_{n=1}^{\infty} a_n$  收敛，

则  $\sum_{n=1}^{\infty} u_n(x)$  在  $I$  上一致收敛

###### **Example**:  $\forall \frac{1}{n^2} \cos nx, \forall x \in R$ 

 $\sum_{n=1}^{\infty} \frac{1}{n^2} \cos nx$  在  $[a, b]$ ,  $0 < a < b$  上一致收敛

#### 4) A-D判别法

设  $\sum a_n(x) \cdot b_n(x)$  满足

若  $\omega$   $a_n(n)$  单调且一致有界,  $\omega$   $\sum b_n(n)$  一致收敛

或  $\omega$   $a_n(n)$  单调且一致趋于 0,  $\omega$   $\sum b_n(n)$  的部分和数列  $\left| \sum_{k=1}^{n} b_k \right|$  在  $I$  上一致有界

则  $\sum a_n(x) \cdot b_n(x)$  在  $I$  上一致收敛

**Proof**: 用 Abel 判别法和 Dirichlet 判别法, 从而可证明 A-D 判别

###### **Example**:  $\sum_{n=1}^{\infty} \frac{\cos nx}{n}$  在  $[0, 2\pi]$  上的一致收敛性 (0 <  $\xi$  <  $\pi$ )

 $\forall x$  且  $\omega > 0$ ;  $\alpha \left| \sum_{k=1}^{n} \cos kx \right| \left| \frac{\sin(n+1)x - \sin x}{2\sin \frac{x}{2}} \right| < \frac{1}{\sin \frac{x}{2}}$  一致有界

故一致收敛









## §5. 和函数及函数的幂级数展开

### 1. 和函数

###### Example: 求$\sum_{n=1}^{+\infty}\frac{x^n}{n}$的收敛域及和函数

**Solution:**

1. **收敛半径：** $R = \frac{1}{\limsup_{n \to \infty} \sqrt[n]{1/n}} = 1$

2. **端点分析：**
   - 当$x=1$时，级数发散。
   - 当$x=-1$时，级数收敛（交错级数）。
   - 故收敛域为$[-1, 1)$。

3. **求和函数：**
   - 设$S(x) = \sum_{n=1}^{+\infty}\frac{x^n}{n}$，$x \in [-1,1)$。
   - 对$S(x)$求导得：$S'(x) = \sum_{n=1}^{+\infty}x^{n-1} = \lim_{n \to \infty} \frac{1 - x^n}{1 - x} = \frac{1}{1 - x}$。
   - 积分得：$S(x) = \int_0^x \frac{1}{1 - t} dt + S(0) = -\ln(1 - x)$。

**Remark:**
1. $S(x) = \sum_{n=1}^{+\infty} \int_0^x t^{n-1} dt = \int_0^x \sum_{n=1}^{+\infty} t^{n-1} dt$
2. $S(x) = -\ln(1 - x)$，$\forall x \in (-1,1)$

###### Example: 求$\sum_{n=1}^{\infty}\frac{n}{2^n}$

**Solution:**
1. **构造函数：** 令$S(x) = \sum_{n=1}^{\infty} n x^n$，显然收敛半径$R = 1$。
2. **在$(-1,1)$内：**
   - $S(x) = x \sum_{n=1}^{\infty} (x^n)' = x (\sum_{n=1}^{\infty} x^n)' = x \cdot \frac{x}{(1 - x)^2} = \frac{x^2}{(1 - x)^2}$。
3. **代入$x = \frac{1}{2}$：**
   - $S\left(\frac{1}{2}\right) = \frac{\left(\frac{1}{2}\right)^2}{\left(1 - \frac{1}{2}\right)^2} = \frac{\frac{1}{4}}{\left(\frac{1}{2}\right)^2} = 1$。
   - 故$\sum_{n=1}^{\infty}\frac{n}{2^n} = 2 \times 1 = 2$。

### 2. 函数的幂级数展开

#### 1) 前置问题

假设 $f(x) = a_0 + a_1(x - x_0) + a_2(x - x_0)^2 + \cdots + a_n(x - x_0)^n + \cdots$，需要考虑以下问题：

1. **等号成立的条件是什么？**
2. **$f(x)$ 在 $x_0$ 附近有什么性质？** 有任意阶导数。
3. **如何求 $a_n$？** $a_n = \frac{f^{(n)}(x_0)}{n!}$，$n = 0,1,2,\ldots$

#### 2) Taylor 级数

设 $f(x)$ 在 $x_0$ 的某邻域内有任意阶导数，则称

$$
\sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!} (x - x_0)^n
$$

为 $f(x)$ 在 $x_0$ 处的 Taylor 级数。

###### Example:

设 $f(x) = \begin{cases} e^{-\frac{1}{x^2}}, & x \neq 0 \\ 0, & x = 0 \end{cases}$

会发现

$$
\sum_{n=0}^{\infty} \frac{f^{(n)}(0)}{n!} x^n \equiv 0 \neq f(x)
$$

这说明即使函数在某点有任意阶导数，其 Taylor 级数也可能不收敛到原函数。

### 展开条件

若 Taylor 级数的收敛半径为 $R$，且对任意 $x \in (x_0 - R, x_0 + R)$，

$$
f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!} (x - x_0)^n
$$

则称 Taylor 级数为 $f(x)$ 在点 $x_0$ 处的幂级数展开。特别地，当 $x_0 = 0$ 时，称为 Maclaurin 级数。

### Theorem: Taylor 级数展开的条件

设 $f$ 在点 $x_0$ 处有任意阶导数，$R$ 为 $f$ 的 Taylor 级数的收敛半径，则 $\forall x \in (x_0 - R, x_0 + R)$，有

$$
f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!} (x - x_0)^n
$$

的充要条件为：

$$
\lim_{n \to \infty} \sum_{k=n+1}^{\infty} \frac{f^{(k)}(x_0)}{k!} (x - x_0)^k = 0
$$

### Theorem: Taylor 级数展开的充分条件

若 $\forall [a, b] \subset (x_0 - R, x_0 + R)$，存在 $M > 0$，使得 $\forall n = 1, 2, \ldots$，$\forall x \in [a, b]$，有 $|f^{(n)}(x)| \leq M$，则

$$
f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!} (x - x_0)^n
$$

**Proof:**

$\forall n$, $0 < \rho < R$，$\forall x \in [x_0 - \rho, x_0 + \rho]$，由 Taylor 公式有：

$$
f(x) = \sum_{k=0}^{n} \frac{f^{(k)}(x_0)}{k!} (x - x_0)^k + \frac{f^{(n+1)}(x_0 + \theta(x - x_0))}{(n + 1)!} (x - x_0)^{n+1}
$$

于是，

$$
\begin{aligned}
& \left| f(x) - \sum_{k=0}^{n} \frac{f^{(k)}(x_0)}{k!} (x - x_0)^k \right| \\
&= \left| \frac{f^{(n+1)}(x_0 + \theta(x - x_0))}{(n + 1)!} (x - x_0)^{n+1} \right| \\
&\leq \frac{M}{(n + 1)!} |x - x_0|^{n+1} \\
&\leq M \frac{\rho^{n+1}}{(n + 1)!}
\end{aligned}
$$

显然，

$$
\lim_{n \to \infty} M \frac{\rho^{n+1}}{(n + 1)!} = 0
$$

故

$$
f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!} (x - x_0)^n
$$

###### Example 6: 将 $e^x$ 展开成 Maclaurin 级数

**Solution:**

由于 $(e^x)^{(n)} = e^x$，故 $a_n = \frac{1}{n!}$。

所以 $e^x$ 的 Maclaurin 级数为：

$$
\sum_{n=0}^{\infty} \frac{1}{n!} x^n
$$

显然，该级数的收敛半径为 $+\infty$。

$\forall [a, b] \subset (-\infty, +\infty)$，$\forall x \in [a, b]$，有：

$$
|(e^x)^{(n)}| = e^x \leq e^{\max\{a, b\}}
$$

故

$$
e^x = \sum_{n=0}^{\infty} \frac{1}{n!} x^n, \quad \forall x \in (-\infty, +\infty)
$$

**Remark:**

$$
e = \sum_{n=0}^{\infty} \frac{1}{n!}
$$


###### Example: 求 $\sin x$ 和 $\cos x$ 的 Maclaurin 级数展开

**Solution:**

**法一：**

由 $(\sin x)^{(n)}|_{x=0} = \sin \frac{n\pi}{2}$，$n=0,1,2,\ldots$

- 当 $n$ 为偶数时，$(\sin x)^{(n)}|_{x=0} = 0$
- 当 $n$ 为奇数时，$(\sin x)^{(n)}|_{x=0} = (-1)^k$，其中 $n=2k+1$

又因为对于 $\forall n=1,2,\ldots$，$\forall x \in \mathbb{R}$，有 $|(\sin x)^{(n)}| = |\sin(x + \frac{n\pi}{2})| \leq 1$

所以 $\sin x$ 的 Maclaurin 级数为：

$$
\sin x = \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n+1)!} x^{2n+1}, \quad \forall x \in \mathbb{R}
$$

对上式求导得：

$$
\cos x = \left( \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n+1)!} x^{2n+1} \right)' = \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n)!} x^{2n}
$$

**法二：**

利用 $\sin x = \frac{e^{ix} - e^{-ix}}{2i}$

由 $e^x = \sum_{n=0}^{\infty} \frac{x^n}{n!}$，可得 $e^{ix}$ 和 $e^{-ix}$ 的展开式，进而得到 $\sin x$ 的级数展开。

###### Example: 求 $\ln(1+x)$ 的 Maclaurin 级数展开

**Solution:**

由于 $\frac{1}{1+x} = \sum_{n=0}^{\infty} (-1)^n x^n$，$|x| < 1$

对两边积分得：

$$
\begin{aligned}
\int_0^x \frac{1}{1+t} dt &= \int_0^x \left( \sum_{n=0}^{\infty} (-1)^n t^n \right) dt \\
&= \sum_{n=0}^{\infty} (-1)^n \int_0^x t^n dt \\
&= \sum_{n=0}^{\infty} (-1)^n \frac{x^{n+1}}{n+1}
\end{aligned}
$$

所以：

$$
\ln(1+x) = \sum_{n=0}^{\infty} \frac{(-1)^n}{n+1} x^{n+1}, \quad |x| < 1
$$

进一步，可以写成：

$$
\ln(1+x) = \sum_{n=1}^{\infty} \frac{(-1)^{n-1}}{n} x^n, \quad x \in (-1, 1]
$$

###### Example: 求 $\arctan x$ 的 Maclaurin 级数展开

由 $\arctan x = \int_0^x \frac{1}{1+t^2} dt$

又因为 $\frac{1}{1+t^2} = \sum_{n=0}^{\infty} (-1)^n t^{2n}$，$|t| < 1$

所以：

$$
\arctan x = \sum_{n=0}^{\infty} \frac{(-1)^n}{2n+1} x^{2n+1}, \quad x \in [-1, 1]
$$

###### Example: 求 $\lim_{n \to \infty} \sin(2\pi n! e)$

提示：利用 $e = 1 + \frac{1}{1!} + \frac{1}{2!} + \cdots + \frac{1}{n!} + \cdots$


---

图片中的笔记是我在上“微积分/傅里叶级数/三角函数与傅里叶级数/三角级数”这节课时做的部分笔记，由于上课不是很认真，笔记中可能存在着一些错误与遗漏，请你帮我纠正以后转换为可复制的markdown代码块。

笔记Markdown的格式要求如下：
   - Chapter部分使用 `#` 表示一级标题，§部分使用`##` 表示二级标题，`###` 表示三级标题。
   - 使用 `$$` 包裹的公式表示行间公式，使用`$`包裹的公式表示行内公式。
   - 使用 `##### **Def**:` 表示定义部分。
   - 使用 `> **Remark**:` 表示注解部分。
   - 使用 `###### **Example**:` 表示例题部分。
   - 使用 `**Analysis**:`、`**Solution**:`、`**Proof**:` 分别表示分析、解题和证明部分。