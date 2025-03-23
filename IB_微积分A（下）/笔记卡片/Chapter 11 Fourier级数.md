# Chapter 11 Fourier级数

## §1. 三角级数与Fourier级数

### 1. 三角级数

$$
f(x)=\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos n x + b_n \sin n x\right)
$$

##### **Def**: 三角级数
称$\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos n x + b_n \sin n x\right)$为三角级数，其中$a_n, b_n \in \mathbb{R}$。

> **Remark**:
>
> 1. 三角级数不依赖于任何具体函数。
> 2. $\frac{1}{2}$仅是技术处理。
> 3. 由$\cos x = \frac{e^{i x} + e^{-i x}}{2}$和$\sin x = \frac{e^{i x} - e^{-i x}}{2i}$，可将三角级数改写为$\sum_{n=-\infty}^{\infty} C_n e^{i n x}$。

### 2. 三角函数系（集合）的正交性

$\{1, \cos x, \sin x, \cos 2x, \sin 2x, \cdots\}$

对于$f, g \in R[-\pi, \pi]$，定义内积为：

$$
(f, g) = \int_{-\pi}^{\pi} f(x) g(x) \, dx
$$

其性质有：

1. $(1, 1) = 2\pi$
   
   $(\cos n x, \cos n x) = \pi$, $\forall n = 1, 2, \cdots$
   
   $(\sin n x, \sin n x) = \pi$, $\forall n = 1, 2, \cdots$

2. $(\cos n x, \cos m x) = 0$, $\forall n \neq m$
   
   $(\sin n x, \sin m x) = 0$, $\forall n \neq m$

3. $(\cos n x, \sin m x) = 0$, $\forall n, m$

### 3. Fourier级数

设$f$为$2\pi$周期函数，$f\in R[-\pi,\pi]$

$$
f(x)=\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos n x + b_n \sin n x\right)
$$

利用正交性计算系数：

$(f,1)=\left(\frac{a_0}{2},1\right)=\frac{a_0}{2}(1,1)=\pi a_0$

$$
a_0=\frac{1}{\pi}\int_{-\pi}^{\pi} f(x) \, dx
$$

$(f,\cos n x)=a_n(\cos n x,\cos n x)=\pi a_n$

$$
a_n=\frac{1}{\pi}\int_{-\pi}^{\pi} f(x)\cos n x \, dx, \quad n=1,2,3,\ldots
$$

$(f,\sin n x)=b_n(\sin n x,\sin n x)=\pi b_n$

$$
b_n=\frac{1}{\pi}\int_{-\pi}^{\pi} f(x)\sin n x \, dx, \quad n=1,2,3,\ldots
$$

##### **Def**: 傅里叶级数
假设$f$为$2\pi$周期函数，且$f\in R[-\pi,\pi]$，则称

$$
a_n=\frac{1}{\pi}\int_{-\pi}^{\pi} f(x)\cos n x \, dx, \quad n=0,1,2,\ldots
$$

$$
b_n=\frac{1}{\pi}\int_{-\pi}^{\pi} f(x)\sin n x \, dx, \quad n=0,1,2,\ldots
$$

为$f$的Fourier系数；

称

$$
\frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos n x + b_n \sin n x\right)
$$

为$f(x)$的Fourier级数，可记作：

$$
f(x) \sim \frac{a_0}{2}+\sum_{n=1}^{\infty}\left(a_n \cos n x + b_n \sin n x\right)
$$

###### **Example 11.01**: 
假设$f$为$2\pi$周期函数，

$$
f(x)=\begin{cases}
x, & -\pi < x < \pi, \\
\pi, & x=\pi.
\end{cases}
$$

求$f$的Fourier级数。

**Solution**:

由

$$
a_n=\frac{1}{\pi}\int_{-\pi}^{\pi} f(x)\cos n x \, dx=\frac{1}{\pi}\int_{-\pi}^{\pi} x\cos n x \, dx=0, \quad n=0,1,2,\ldots
$$

$$
b_n=\frac{1}{\pi}\int_{-\pi}^{\pi} f(x)\sin n x \, dx=\frac{1}{\pi}\int_{-\pi}^{\pi} x\sin n x \, dx=(-1)^{n+1}\frac{2}{n}, \quad n=1,2,\ldots
$$

故

$$
f(x) \sim \sum_{n=1}^{\infty} (-1)^{n-1}\frac{2}{n}\sin n x
$$

###### **Example 11.02**: 
设$g(x)$为$2\pi$周期函数，

$$
g(x)=\begin{cases}
\pi, & 0 < x < 2\pi, \\
0, & x=0,2\pi.
\end{cases}
$$

求$g(x)$的Fourier级数。

**Solution**:

由

$$
a_0=\frac{1}{\pi}\int_{-\pi}^{\pi} g(x) \, dx=\frac{1}{\pi}\int_{0}^{2\pi} g(x) \, dx=2\pi
$$

$$
a_n=\frac{1}{\pi}\int_{-\pi}^{\pi} g(x)\cos n x \, dx=\frac{1}{\pi}\int_{0}^{2\pi} x\cos n x \, dx=0, \quad n=1,2,\ldots
$$

$$
b_n=\frac{1}{\pi}\int_{-\pi}^{\pi} g(x)\sin n x \, dx=\frac{1}{\pi}\int_{0}^{2\pi} x\sin n x \, dx=-\frac{2}{n}, \quad n=1,2,\ldots
$$

故

$$
g(x) \sim \pi - \sum_{n=1}^{\infty} \frac{2}{n}\sin n x
$$

### 4. Riemann引理

#### 1) Dirichlet核
$f(x)\sim\frac{1}{2}a_0+\sum_{n=1}^{\infty}(a_n\cos nx+b_n\sin nx)$ 是否收敛

令
$$
S_n(x)=\frac{1}{2}a_0+\sum_{k=1}^{n}(a_k\cos kx +b_k\sin kx)
$$
$$
=\frac{1}{2}\cdot\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)dt+\sum_{k=1}^{n}\left(\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)\cos kt dt\cdot\cos kx+\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)\sin kt dt\cdot\sin kx\right)
$$
$$
=\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)\left[\frac{1}{2}+\sum_{k=1}^{n}\cos k(t-x)\right]dt
$$
$$
=\frac{1}{\pi}\int_{-\pi}^{\pi}f(u+x)\left[\frac{1}{2}+\sum_{k=1}^{n}\cos ku\right]du
$$

记: $D_n(u)=\frac{1}{2}+\sum_{k=1}^{n}\cos ku$ 称为Dirichlet核（积分核）

其性质有:
1. $D_n(u)=\frac{\sin\left(n+\frac{1}{2}\right)u}{2\sin\frac{1}{2}u}$
2. $D_n(0)=n+\frac{1}{2}$
3. $\int_{-\pi}^{\pi}D_n(u)du=\pi$

#### 2) Riemann Theorem:

设 $f \in R[a, b]$，

则 $\lim_{n \rightarrow \infty} \int_{a}^{b} f(x) \cos n x \, dx = 0$

及 $\lim_{n \rightarrow \infty} \int_{a}^{b} f(x) \sin n x \, dx = 0$

**Proof**:

由 $f \in R[a, b]$，故 $\exists M > 0$，$|f(x)| \leq M$

$\forall \varepsilon > 0$, $\exists \delta > 0$，对划分 $P: a = x_0 < x_1 < \cdots < x_n = b$

当 $|P| < \delta$ 时，有 $\sum_{i=1}^{n} \omega_i \Delta x_i < \frac{\varepsilon}{2}$

取 $\lambda = \max \left( \frac{6}{\delta}, \frac{6M}{\varepsilon} \right) > 0$，当 $\lambda > X$ 时，有 $\frac{6}{\lambda} < \delta$，$\frac{2M}{\lambda} < \frac{\varepsilon}{3}$

存在整数 $p < q$，s.t. $(p - 1)\pi + \frac{\pi}{2} < \lambda a \leq p\pi + \frac{\pi}{2}$

$q\pi + \frac{\pi}{2} \leq \lambda b < (q + 1)\pi + \frac{\pi}{2}$

$\int_{a}^{b} f(x) \cos \lambda x \, dx = \frac{1}{\lambda} \int_{\lambda a}^{\lambda b} f\left( \frac{x}{\lambda} \right) \cos x \, dx$

$$\begin{aligned}
&= \frac{1}{\lambda} \int_{q\pi + \frac{\pi}{2}}^{\lambda b} f\left( \frac{x}{\lambda} \right) \cos x \, dx + \frac{1}{\lambda} \int_{\lambda a}^{p\pi + \frac{\pi}{2}} f\left( \frac{x}{\lambda} \right) \cos x \, dx \\
&\quad + \frac{1}{\lambda} \sum_{k = p}^{q - 1} \int_{k\pi + \frac{\pi}{2}}^{(k + 1)\pi + \frac{\pi}{2}} f\left( \frac{x}{\lambda} \right) \cos x \, dx
\end{aligned}$$

1. $\left| \frac{1}{\lambda} \int_{q\pi + \frac{\pi}{2}}^{\lambda b} f\left( \frac{x}{\lambda} \right) \cos x \, dx \right| \leq \frac{2M}{\lambda} < \frac{\varepsilon}{6}$

2. $\left| \frac{1}{\lambda} \int_{\lambda a}^{p\pi + \frac{\pi}{2}} f\left( \frac{x}{\lambda} \right) \cos x \, dx \right| \leq \frac{2M}{\lambda} < \frac{\varepsilon}{6}$

3. $\left| \frac{1}{\lambda} \sum_{k=p}^{q-1} \int_{k\pi + \frac{\pi}{2}}^{(k+1)\pi + \frac{\pi}{2}} f\left( \frac{x}{\lambda} \right) \cos x \, dx \right|$

对于：$$\begin{aligned}
&\left| \frac{1}{\lambda} \sum_{k=p}^{q-1} \int_{k\pi + \frac{\pi}{2}}^{(k+1)\pi + \frac{\pi}{2}} f\left( \frac{x}{\lambda} \right) \cos x \, dx \right| \\
&= \left| \frac{1}{\lambda} \sum_{k=p}^{q-1} \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + (k+1)\pi}{\lambda} \right) \cos(z + (k+1)\pi) \, dz \right| \\
&= \left| \frac{1}{\lambda} \sum_{k=p}^{q-1} (-1)^{k+1} \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + (k+1)\pi}{\lambda} \right) \cos z \, dz \right| \\
&\leq \frac{1}{\lambda} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + p\pi}{\lambda} \right) \cos z \, dz \right| \\
&\quad + \frac{1}{\lambda} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + q\pi}{\lambda} \right) \cos z \, dz \right| \\
&\quad + \frac{1}{2} \cdot \frac{1}{\lambda} \sum_{k=p}^{q-1} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} \left[ f\left( \frac{z + (k+1)\pi}{\lambda} \right) - f\left( \frac{z + k\pi}{\lambda} \right) \right] \cos z \, dz \right|
\end{aligned}$$
拆开分别讨论：
(i) $\frac{1}{2} \cdot \frac{1}{\lambda} \sum_{k=p}^{q-1} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} \left[ f\left( \frac{z + (k+1)\pi}{\lambda} \right) - f\left( \frac{z + k\pi}{\lambda} \right) \right] \cos z \, dz \right|$

$$\begin{aligned}
&\frac{1}{2} \cdot \frac{1}{\lambda} \sum_{k=p}^{q-1} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} \left[ f\left( \frac{z + (k+1)\pi}{\lambda} \right) - f\left( \frac{z + k\pi}{\lambda} \right) \right] \cos z \, dz \right| \\
&\leq \frac{1}{2} \cdot \frac{1}{\lambda} \sum_{k=p}^{q-1} \omega_k \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} |\cos z| \, dz \\
&\leq \frac{2}{\lambda} \sum_{k=p}^{q-1} \omega_k < \frac{\varepsilon}{6}
\end{aligned}$$

(ii) $\frac{1}{2} \cdot \frac{1}{\lambda} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + p\pi}{\lambda} \right) \cos z \, dz \right| + \frac{1}{2} \cdot \frac{1}{\lambda} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + q\pi}{\lambda} \right) \cos z \, dz \right|$

$$\begin{aligned}
&\frac{1}{2} \cdot \frac{1}{\lambda} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + p\pi}{\lambda} \right) \cos z \, dz \right| + \frac{1}{2} \cdot \frac{1}{\lambda} \left| \int_{-\frac{\pi}{2}}^{\frac{\pi}{2}} f\left( \frac{z + q\pi}{\lambda} \right) \cos z \, dz \right| \\
&\leq \frac{2M}{\lambda} < \frac{\varepsilon}{6}
\end{aligned}$$

综上，当 $\lambda > X$ 时，

$\left| \int_{a}^{b} f(x) \cos \lambda x \, dx \right| \leq \frac{\varepsilon}{6} + \frac{\varepsilon}{6} + \frac{\varepsilon}{2} + \frac{\varepsilon}{6} = \varepsilon$

类似可证 $\lim_{n \rightarrow \infty} \int_{a}^{b} f(x) \sin n x \, dx = 0$

## §2. Fourier级数的收敛性定理

### 1. 局部化原理

设函数$f(x)$的傅里叶级数在点$x_0$处的收敛性仅与$f$在$x_0$附近的性质有关。

设
$$
S_n(x_0)=\frac{1}{\pi}\int_0^\pi\frac{f(x_0+t)+f(x_0-t)}{2\sin\frac{t}{2}}\sin\left(n+\frac{1}{2}\right) t dt
$$

**Theorem:** 设$2\pi$周期函数$f\in R[-\pi,\pi]$，则$f$的傅里叶级数在点$x_0$处收敛与否及收敛值仅与$x_0$的邻域相关。

### 2. 收敛性定理（Dini判别）

**Theorem:** 设$2\pi$周期函数$f\in R[-\pi,\pi]$，$S\in R$，记
$$
\varphi(t)=f(x_0+t)+f(x_0-t)-2S
$$
若$\frac{\varphi(t)}{t}\in R[0,\pi]$，则$f$的傅里叶级数在点$x_0$处收敛于$S$。

**证明思路：**
$$
\begin{aligned}
S_n(x_0)-S &= \frac{1}{\pi}\int_0^\pi\frac{f(x_0+t)+f(x_0-t)}{2\sin\frac{t}{2}}\sin\left(n+\frac{1}{2}\right) t dt - S \\
&= \frac{1}{\pi}\int_0^\pi\frac{f(x_0+t)+f(x_0-t)}{2\sin\frac{t}{2}}\sin\left(n+\frac{1}{2}\right) t dt - S \cdot \frac{1}{\pi}\int_0^\pi 2\frac{\sin\left(n+\frac{1}{2}\right) t}{2\sin\frac{t}{2}} dt \\
&= \frac{1}{\pi}\int_0^\pi\frac{f(x_0+t)+f(x_0-t)-2S}{2\sin\frac{t}{2}}\sin\left(n+\frac{1}{2}\right) t dt \\
&= \frac{1}{\pi}\int_0^\pi\frac{f(x_0+t)+f(x_0-t)-2S}{t} \cdot \frac{t}{2\sin\frac{t}{2}}\sin\left(n+\frac{1}{2}\right) t dt \\
&\rightarrow 0 \quad (n\rightarrow+\infty)
\end{aligned}
$$

### 3. 更一般的收敛条件

**Theorem:** 设$2\pi$周期函数$f\in R[-\pi,\pi]$，若$f$在$x_0$处存在左右极限，且满足$\alpha$阶Lipschitz条件，即存在$\delta>0$，$L>0$，$\alpha\in(0,1]$，使得
$$
|f(x_0+t)-f(x_0+0)|\leq L t^\alpha, \quad |f(x_0-t)-f(x_0-0)|\leq L t^\alpha, \quad t\in(0,\delta]
$$
则$f$的傅里叶级数在点$x_0$处收敛于$\frac{f(x_0+0)+f(x_0-0)}{2}$。

**Corollary:** 若$f$在$x_0$处可导，则$f$的傅里叶级数在$x_0$处收敛于$f(x_0)$。

**证明思路：**

考虑
$$
\left|\frac{f(x_0+t)-f(x_0)}{t}\right|\leq L
$$
即
$$
|f(x_0+t)-f(x_0)|\leq L|t|
$$
进一步，对于
$$
\frac{f(x_0+t)+f(x_0-t)-2f(x_0)}{t}
$$
有：

(i) $\alpha=1 \quad \varphi(t)\in R[0,\pi]$

(ii) $0<\alpha<1 \quad \frac{\varphi(t)}{t}$在$0$附近可积，绝对收敛

因此，根据Dini判别法，傅里叶级数在$x_0$处收敛于$\frac{f(x_0+0)+f(x_0-0)}{2}$。

> **Remark:** 该定理说明，只要函数在某点满足一定的光滑性条件（如Lipschitz条件），其傅里叶级数在该点收敛于函数的左右极限的平均值。特别地，若函数在该点可导，则收敛于函数值本身。


**Theorem:** 设$2\pi$周期函数$f\in R[-\pi,\pi]$

(1) 若$f$在点$x_0$处单侧极限存在，则$f$的Fourier级数在点$x_0$处收敛于$f(x_0)$

(2) 若$f$在点$x_0$处有单侧极限且存在极限 $\lim_{t\to 0^+}\frac{f(x_0+t)-f(x_0)}{t}$ 及 $\lim_{t\to 0^+}\frac{f(x_0-t)-f(x_0)}{-t}$，
则$f$的Fourier级数在点$x_0$处收敛于$\frac{f(x_0+0)+f(x_0-0)}{2}$.
